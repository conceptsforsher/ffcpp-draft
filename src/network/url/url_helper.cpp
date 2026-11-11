/* MPL 2.0 - network/url
 * See url_helper.hpp for the upstream sources this file translates.
 */

#include "network/url/url_helper.hpp"

namespace network::url {
namespace {

inline bool IsAsciiDigit(char c) { return c >= '0' && c <= '9'; }

inline bool IsAsciiAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

inline bool IsAsciiAlphaNumeric(char c) {
  return IsAsciiAlpha(c) || IsAsciiDigit(c);
}

inline bool IsAsciiHexDigit(char c) {
  return IsAsciiDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

// translation of try_apply_digit: current_octet.checked_mul(10)?.checked_add(digit)
// i.e. the arithmetic must stay inside u8, otherwise the address is invalid.
inline bool TryApplyDigit(uint8_t currentOctet, uint8_t digitToApply,
                          uint8_t* out) {
  const uint16_t applied =
      static_cast<uint16_t>(static_cast<uint16_t>(currentOctet) * 10u +
                            static_cast<uint16_t>(digitToApply));
  if (applied > 255u) {
    return false;
  }
  *out = static_cast<uint8_t>(applied);
  return true;
}

}  // namespace

bool IsValidSchemeChar(unsigned char aChar) {
  const char c = static_cast<char>(aChar);
  return IsAsciiAlphaNumeric(c) || c == '+' || c == '.' || c == '-';
}

bool IsValidScheme(std::string_view scheme) {
  if (scheme.empty()) {
    return false;
  }

  // first char must be alpha
  if (!IsAsciiAlpha(scheme[0])) {
    return false;
  }

  for (size_t i = 1; i < scheme.size(); ++i) {
    if (!IsValidSchemeChar(static_cast<unsigned char>(scheme[i]))) {
      return false;
    }
  }
  return true;
}

bool IsValidIPv4Addr(std::string_view addr) {
  // `currentOctet` mirrors Rust's Option<u8>: nullopt until a digit of the
  // current octet has been seen.
  int currentOctet = -1;  // -1 == Rust's None
  uint8_t dots = 0;

  for (const char c : addr) {
    if (c == '.') {
      if (currentOctet < 0) {
        // starting an octet with a . is not allowed
        return false;
      }
      dots += 1;
      currentOctet = -1;
    } else if (!IsAsciiDigit(c)) {
      // The character is not a digit
      return false;
    } else {
      const uint8_t digit = static_cast<uint8_t>(c - '0');
      if (currentOctet < 0) {
        currentOctet = static_cast<int>(digit);
      } else {
        if (currentOctet == 0) {
          // Leading 0 is not allowed
          return false;
        }
        uint8_t applied = 0;
        if (!TryApplyDigit(static_cast<uint8_t>(currentOctet), digit,
                           &applied)) {
          // Multiplication or Addition overflowed
          return false;
        }
        currentOctet = static_cast<int>(applied);
      }
    }
  }

  return dots == 3 && currentOctet >= 0;
}

bool IsValidIPv6Addr(std::string_view addr) {
  bool doubleColon = false;
  bool colonBefore = false;
  uint8_t digits = 0;
  uint8_t blocks = 0;

  // The smallest ipv6 is unspecified (::)
  // The IP starts with a single colon
  if (addr.size() < 2 || (addr[0] == ':' && addr[1] != ':')) {
    return false;
  }

  for (size_t i = 0; i < addr.size(); ++i) {
    const char c = addr[i];
    if (IsAsciiHexDigit(c)) {
      // Too many digits in the block
      if (digits == 4) {
        return false;
      }
      colonBefore = false;
      digits += 1;
    } else if (c == ':') {
      // Too many columns
      if ((doubleColon && colonBefore) || blocks == 8) {
        return false;
      }
      if (!colonBefore) {
        if (digits != 0) {
          blocks += 1;
        }
        digits = 0;
        colonBefore = true;
      } else if (!doubleColon) {
        doubleColon = true;
      }
    } else if (c == '.') {
      // IPv4 from the last block
      if (IsValidIPv4Addr(addr.substr(i - digits))) {
        return (doubleColon && blocks < 6) || (!doubleColon && blocks == 6);
      }
      return false;
    } else {
      // Invalid character
      return false;
    }
  }

  if (colonBefore && !doubleColon) {
    // The IP ends with a single colon
    return false;
  }
  if (digits != 0) {
    blocks += 1;
  }

  return (doubleColon && blocks < 8) || (!doubleColon && blocks == 8);
}

}  // namespace network::url
