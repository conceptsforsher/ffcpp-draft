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

inline bool IsAsciiWhitespace(char c) {
  return c == '\r' || c == '\n' || c == '\t';
}

// translation of nsCRT::strncasecmp
int AsciiStrNCmpCaseInsensitive(const char* a, const char* b, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    const unsigned char ca = static_cast<unsigned char>(a[i]);
    const unsigned char cb = static_cast<unsigned char>(b[i]);
    const unsigned char la = (ca >= 'A' && ca <= 'Z') ? (ca + 32) : ca;
    const unsigned char lb = (cb >= 'A' && cb <= 'Z') ? (cb + 32) : cb;
    if (la != lb) {
      return static_cast<int>(la) - static_cast<int>(lb);
    }
    if (ca == '\0') {
      return 0;
    }
  }
  return 0;
}

// translation of the max length enforced through
// StaticPrefs::network_standard_url_max_length().  The pref default is 1 MiB;
// the port keeps it as a constant because there is no pref service here.
constexpr uint32_t kMaxUrlLength = 1048576u;

}  // namespace

//----------------------------------------------------------------------------
// miscellaneous (net_ToLowerCase and the net_FindChar* family)
//----------------------------------------------------------------------------

void ToLower(char& c) {
  if ((unsigned)(c - 'A') <= (unsigned)('Z' - 'A')) c += 'a' - 'A';
}

char* ToLowerCase(char* str, uint32_t length) {
  for (char* end = str + length; str < end; ++str) ToLower(*str);
  return str;
}

char* ToLowerCase(char* str) {
  for (; *str; ++str) ToLower(*str);
  return str;
}

char* FindCharInSet(const char* iter, const char* stop, const char* set) {
  for (; iter != stop && *iter; ++iter) {
    for (const char* s = set; *s; ++s) {
      if (*iter == *s) return const_cast<char*>(iter);
    }
  }
  return const_cast<char*>(iter);
}

char* FindCharNotInSet(const char* iter, const char* stop, const char* set) {
repeat:
  for (const char* s = set; *s; ++s) {
    if (*iter == *s) {
      if (++iter == stop) break;
      goto repeat;
    }
  }
  return const_cast<char*>(iter);
}

char* RFindCharNotInSet(const char* stop, const char* iter, const char* set) {
  --iter;
  --stop;

  if (iter == stop) return const_cast<char*>(iter);

repeat:
  for (const char* s = set; *s; ++s) {
    if (*iter == *s) {
      if (--iter == stop) break;
      goto repeat;
    }
  }
  return const_cast<char*>(iter);
}

//----------------------------------------------------------------------------
// scheme fu (net_ExtractURLScheme, net_IsAbsoluteURL)
//----------------------------------------------------------------------------

namespace {

// Both net_ExtractURLScheme and net_IsAbsoluteURL start by skipping the leading
// C0 controls and space.
std::string_view StripLeadingControlAndSpace(std::string_view in) {
  size_t pos = 0;
  while (pos < in.size() && static_cast<uint8_t>(in[pos]) <= 0x20) {
    ++pos;
  }
  return in.substr(pos);
}

}  // namespace

Result ExtractURLScheme(std::string_view inUri, std::string& scheme) {
  scheme.clear();

  const std::string_view input = StripLeadingControlAndSpace(inUri);
  size_t pos = 0;

  // First char must be alpha
  if (pos >= input.size() || !IsAsciiAlpha(input[pos])) {
    return Result::ErrorMalformedUri;
  }
  ++pos;

  // Skip valid scheme characters or \r\n\t
  while (pos < input.size() &&
         (IsValidSchemeChar(static_cast<unsigned char>(input[pos])) ||
          IsAsciiWhitespace(input[pos]))) {
    ++pos;
  }

  if (pos >= input.size() || input[pos] != ':') {
    return Result::ErrorMalformedUri;
  }

  // The claimed scheme still contains the \r\n\t characters that were skipped
  // above, they are stripped here (StripTaggedASCII(mask CRLF tab)).
  std::string claimed(input.substr(0, pos));
  std::string stripped;
  stripped.reserve(claimed.size());
  for (const char c : claimed) {
    if (!IsAsciiWhitespace(c)) {
      stripped.push_back(c);
    }
  }
  ToLowerCase(stripped.data(), static_cast<uint32_t>(stripped.size()));
  scheme = std::move(stripped);
  return Result::Ok;
}

bool IsAbsoluteURL(std::string_view uri) {
  const std::string_view input = StripLeadingControlAndSpace(uri);
  size_t pos = 0;

  // First char must be alpha
  if (pos >= input.size() || !IsAsciiAlpha(input[pos])) {
    return false;
  }
  ++pos;

  while (pos < input.size() &&
         (IsValidSchemeChar(static_cast<unsigned char>(input[pos])) ||
          IsAsciiWhitespace(input[pos]))) {
    ++pos;
  }
  if (pos >= input.size() || input[pos] != ':') {
    return false;
  }
  ++pos;

  // SkipWhites
  while (pos < input.size() && IsAsciiWhitespace(input[pos])) {
    ++pos;
  }
  if (pos >= input.size() || input[pos] != '/') {
    return false;
  }
  ++pos;

  while (pos < input.size() && IsAsciiWhitespace(input[pos])) {
    ++pos;
  }
  if (pos < input.size() && input[pos] == '/') {
    // aSpec is really absolute. Ignore aBaseURI in this case
    return true;
  }
  return false;
}

//----------------------------------------------------------------------------
// net_FilterURIString
//----------------------------------------------------------------------------

void FilterURIString(std::string_view input, std::string& result) {
  result.clear();

  const char* start = input.data();
  const char* end = input.data() + input.size();

  // Trim off leading and trailing invalid chars.
  auto charFilter = [](char c) { return static_cast<uint8_t>(c) > 0x20; };
  const char* newStart = start;
  while (newStart != end && !charFilter(*newStart)) {
    ++newStart;
  }
  const char* newEnd = end;
  while (newEnd != newStart && !charFilter(*(newEnd - 1))) {
    --newEnd;
  }

  // Check if chars need to be stripped.
  bool needsStrip = false;
  for (const char* itr = start; itr != end; ++itr) {
    if (IsAsciiWhitespace(*itr)) {
      needsStrip = true;
      break;
    }
  }

  // Just use the passed in string rather than creating new copies if no
  // changes are necessary.
  if (newStart == start && newEnd == end && !needsStrip) {
    result.assign(input);
    return;
  }

  const std::string_view trimmed(newStart,
                                 static_cast<size_t>(newEnd - newStart));
  if (needsStrip) {
    result.reserve(trimmed.size());
    for (const char c : trimmed) {
      if (!IsAsciiWhitespace(c)) {
        result.push_back(c);
      }
    }
  } else {
    result.assign(trimmed);
  }
}

//----------------------------------------------------------------------------
// DNS host validation (net_IsValidDNSHost)
//----------------------------------------------------------------------------

bool HostIsIPLiteral(std::string_view host) {
  return host.size() > 1 && host.front() == '[' && host.back() == ']';
}

bool IsValidDNSHost(std::string_view host) {
  // The host name is limited to 253 ascii characters.
  if (host.size() > 253) {
    return false;
  }

  const char* end = host.data() + host.size();

  // Whitelist for DNS names (RFC 1035) with extra characters added
  // for pragmatic reasons "$+_"
  // see https://bugzilla.mozilla.org/show_bug.cgi?id=355181#c2
  if (FindCharNotInSet(host.data(), end,
                       "abcdefghijklmnopqrstuvwxyz"
                       ".-0123456789"
                       "ABCDEFGHIJKLMNOPQRSTUVWXYZ$+_") == end) {
    return true;
  }

  // Might be a valid IPv6 link-local address containing a percent sign
  return HostIsIPLiteral(host);
}

//----------------------------------------------------------------------------
// net_CoalesceDirs
//----------------------------------------------------------------------------

std::optional<CoalescedPath> CoalesceDirs(char* path) {
  /* Stolen from the old netlib's mkparse.c.
   *
   * modifies a url of the form   /foo/../foo1  ->  /foo1
   *                       and    /foo/./foo1   ->  /foo/foo1
   *                       and    /foo/foo1/..  ->  /foo/
   */
  char* fwdPtr = path;
  char* urlPtr = path;

  if (*path != '/') {
    return std::nullopt;
  }

  // This function checks if the character terminates the path segment,
  // meaning it is / or ? or # or null.
  auto isSegmentEnd = [](char aChar) {
    return aChar == '/' || aChar == '?' || aChar == '#' || aChar == '\0';
  };

  // replace all %2E, %2e, %2e%2e, %2e%2E, %2E%2e, %2E%2E, etc with . or ..
  // respectively if between two "/"s or "/" and NULL terminator
  constexpr int PERCENT_2E_LENGTH = sizeof("%2e") - 1;
  constexpr uint32_t PERCENT_2E_WITH_PERIOD_LENGTH = PERCENT_2E_LENGTH + 1;

  for (; (*fwdPtr != '\0') && (*fwdPtr != '?') && (*fwdPtr != '#'); ++fwdPtr) {
    // Assuming that we are currently at '/'
    if (*fwdPtr == '/' &&
        AsciiStrNCmpCaseInsensitive(fwdPtr + 1, "%2e", PERCENT_2E_LENGTH) == 0 &&
        isSegmentEnd(*(fwdPtr + PERCENT_2E_LENGTH + 1))) {
      *urlPtr++ = '/';
      *urlPtr++ = '.';
      fwdPtr += PERCENT_2E_LENGTH;
    }
    // If the remaining pathname is "%2e%2e" between "/"s, add ".."
    else if (*fwdPtr == '/' &&
             AsciiStrNCmpCaseInsensitive(fwdPtr + 1, "%2e%2e",
                                         PERCENT_2E_LENGTH * 2) == 0 &&
             isSegmentEnd(*(fwdPtr + PERCENT_2E_LENGTH * 2 + 1))) {
      *urlPtr++ = '/';
      *urlPtr++ = '.';
      *urlPtr++ = '.';
      fwdPtr += PERCENT_2E_LENGTH * 2;
    }
    // If the remaining pathname is "%2e." or ".%2e" between "/"s, add ".."
    else if (*fwdPtr == '/' &&
             (AsciiStrNCmpCaseInsensitive(fwdPtr + 1, "%2e.",
                                          PERCENT_2E_WITH_PERIOD_LENGTH) == 0 ||
              AsciiStrNCmpCaseInsensitive(fwdPtr + 1, ".%2e",
                                          PERCENT_2E_WITH_PERIOD_LENGTH) == 0) &&
             isSegmentEnd(*(fwdPtr + PERCENT_2E_WITH_PERIOD_LENGTH + 1))) {
      *urlPtr++ = '/';
      *urlPtr++ = '.';
      *urlPtr++ = '.';
      fwdPtr += PERCENT_2E_WITH_PERIOD_LENGTH;
    } else {
      *urlPtr++ = *fwdPtr;
    }
  }
  // Copy remaining stuff past the #?;
  for (; *fwdPtr != '\0'; ++fwdPtr) {
    *urlPtr++ = *fwdPtr;
  }
  *urlPtr = '\0';  // terminate the url

  // start again, this time for real
  fwdPtr = path;
  urlPtr = path;

  for (; (*fwdPtr != '\0') && (*fwdPtr != '?') && (*fwdPtr != '#'); ++fwdPtr) {
    if (*fwdPtr == '/' && *(fwdPtr + 1) == '.' && *(fwdPtr + 2) == '/') {
      // remove . followed by slash
      ++fwdPtr;
    } else if (*fwdPtr == '/' && *(fwdPtr + 1) == '.' && *(fwdPtr + 2) == '.' &&
               isSegmentEnd(*(fwdPtr + 3))) {
      // This will take care of something like foo/bar/..#sometag
      // remove foo/..
      // reverse the urlPtr to the previous slash if possible
      // if url does not allow relative root then drop .. above root
      // otherwise retain them in the path
      if (urlPtr != path) urlPtr--;  // we must be going back at least by one
      for (; *urlPtr != '/' && urlPtr != path; urlPtr--) {
        ;  // null body
      }
      // forward the fwdPtr past the ../
      fwdPtr += 2;
      // special case if we have reached the end
      // to preserve the last /
      if (*fwdPtr == '.' && (*(fwdPtr + 1) == '\0' || *(fwdPtr + 1) == '?' ||
                             *(fwdPtr + 1) == '#')) {
        ++urlPtr;
      }
    } else {
      // copy the url incrementaly
      *urlPtr++ = *fwdPtr;
    }
  }

  /*
   *  Now lets remove trailing . case
   *     /foo/foo1/.   ->  /foo/foo1/
   */

  if ((urlPtr > (path + 1)) && (*(urlPtr - 1) == '.') &&
      (*(urlPtr - 2) == '/')) {
    urlPtr--;
  }

  // Before we start copying past ?#, we must make sure we don't overwrite
  // the first / character.  If fwdPtr is also unchanged, just copy everything
  // (this shouldn't happen unless we could get in here without a leading
  // slash).
  if (urlPtr == path && fwdPtr != path) {
    urlPtr++;
  }

  // Copy remaining stuff past the #?;
  for (; *fwdPtr != '\0'; ++fwdPtr) {
    *urlPtr++ = *fwdPtr;
  }
  *urlPtr = '\0';  // terminate the url

  uint32_t lastSlash = 0;
  uint32_t endOfBasename = 0;

  // find the last slash before # or ?
  // find the end of basename (i.e. hash, query, or end of string)
  for (; (*(path + endOfBasename) != '\0') &&
         (*(path + endOfBasename) != '?') && (*(path + endOfBasename) != '#');
       ++endOfBasename) {
  }

  // Now find the last slash starting from the end
  lastSlash = endOfBasename;
  if (lastSlash != 0 && *(path + lastSlash) == '\0') {
    --lastSlash;
  }
  // search the slash
  for (; lastSlash != 0 && *(path + lastSlash) != '/'; --lastSlash) {
  }

  return CoalescedPath{lastSlash, endOfBasename};
}

//----------------------------------------------------------------------------
// file:// URL parsing (net_ParseFileURL)
//----------------------------------------------------------------------------

Result ParseFileURL(std::string_view inUrl, std::string& outDirectory,
                    std::string& outFileBaseName,
                    std::string& outFileExtension) {
  outDirectory.clear();
  outFileBaseName.clear();
  outFileExtension.clear();

  if (inUrl.size() > kMaxUrlLength) {
    return Result::ErrorMalformedUri;
  }

  std::string scheme;
  Result rv = ExtractURLScheme(inUrl, scheme);
  if (Failed(rv)) return rv;

  if (scheme != "file") {
    // Gecko: NS_ERROR("must be a file:// url")
    return Result::ErrorUnexpected;
  }

  // The no-auth url parser is a singleton in Gecko (net_GetNoAuthURLParser());
  // the translated parser is stateless, so one instance is enough here too.
  static NoAuthUrlParser parser;

  uint32_t pathPos = 0, filepathPos = 0, directoryPos = 0, basenamePos = 0,
           extensionPos = 0;
  int32_t pathLen = 0, filepathLen = 0, directoryLen = 0, basenameLen = 0,
          extensionLen = 0;

  // invoke the parser to extract the URL path
  rv = parser.ParseURL(inUrl.data(), static_cast<int32_t>(inUrl.size()),
                       nullptr,
                       nullptr,           // don't care about scheme
                       nullptr, nullptr,  // don't care about authority
                       &pathPos, &pathLen);
  if (Failed(rv)) return rv;

  // invoke the parser to extract filepath from the path
  rv = parser.ParsePath(inUrl.data() + pathPos, pathLen, &filepathPos,
                        &filepathLen,
                        nullptr, nullptr,   // don't care about query
                        nullptr, nullptr);  // don't care about ref
  if (Failed(rv)) return rv;

  filepathPos += pathPos;

  // invoke the parser to extract the directory and filename from filepath
  rv = parser.ParseFilePath(inUrl.data() + filepathPos, filepathLen,
                            &directoryPos, &directoryLen, &basenamePos,
                            &basenameLen, &extensionPos, &extensionLen);
  if (Failed(rv)) return rv;

  if (directoryLen > 0) {
    outDirectory =
        std::string(inUrl.substr(filepathPos + directoryPos,
                                 static_cast<size_t>(directoryLen)));
  }
  if (basenameLen > 0) {
    outFileBaseName = std::string(inUrl.substr(
        filepathPos + basenamePos, static_cast<size_t>(basenameLen)));
  }
  if (extensionLen > 0) {
    outFileExtension = std::string(inUrl.substr(
        filepathPos + extensionPos, static_cast<size_t>(extensionLen)));
  }
  // since we are using a no-auth url parser, there will never be a host
  // XXX not strictly true... file://localhost/foo/bar.html is a valid URL

  return Result::Ok;
}

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
