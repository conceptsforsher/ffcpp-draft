/* MPL 2.0 - network/url
 * See url_params.hpp for the upstream sources this file translates.
 */

#include "network/url/url_params.hpp"

#include <algorithm>
#include <cstdio>

namespace network::url {

namespace {

// translation of MakeNameMatcher.  The lambda stays generic because Param is
// private to UrlParams.
auto MakeNameMatcher(std::string_view name) {
  return [name](const auto& param) { return param.key == name; };
}

// translation of AssignMaybeInvalidUTF8String: Gecko validates (and repairs)
// the UTF-8 here; this port has no converter and passes the bytes through.
void AssignMaybeInvalidUtf8String(std::string_view source, std::string& dest) {
  if (source.data() == dest.data()) {
    // Gecko validates/repairs in place here; nothing to do without a
    // converter.
    return;
  }
  dest.assign(source);
}

}  // namespace

bool UrlParams::Has(std::string_view name) const {
  return std::any_of(params_.cbegin(), params_.cend(), MakeNameMatcher(name));
}

bool UrlParams::Has(std::string_view name, std::string_view value) const {
  return std::any_of(params_.cbegin(), params_.cend(),
                     [name, value](const Param& param) {
                       return param.key == name && param.value == value;
                     });
}

void UrlParams::Get(std::string_view name, std::string& retval) {
  // Gecko marks retval void here; clearing it has the same effect for the
  // caller, which can test retval.empty().
  retval.clear();

  const auto end = params_.cend();
  const auto it = std::find_if(params_.cbegin(), end, MakeNameMatcher(name));
  if (it != end) {
    retval = it->value;
  }
}

void UrlParams::GetAll(std::string_view name,
                       std::vector<std::string>& retval) {
  retval.clear();

  for (const Param& param : params_) {
    if (param.key == name) {
      retval.push_back(param.value);
    }
  }
}

void UrlParams::Append(std::string_view name, std::string_view value) {
  params_.push_back(Param{std::string(name), std::string(value)});
}

void UrlParams::Set(std::string_view name, std::string_view value) {
  // The index is tracked instead of a pointer (Gecko keeps a Param*) because
  // erasing duplicates may move the elements of the vector.
  int32_t found = -1;
  for (uint32_t i = 0, len = static_cast<uint32_t>(params_.size()); i < len;) {
    if (params_[i].key != name) {
      ++i;
      continue;
    }
    if (found < 0) {
      found = static_cast<int32_t>(i);
      ++i;
      continue;
    }
    // Remove duplicates.
    params_.erase(params_.begin() + i);
    --len;
  }

  if (found < 0) {
    params_.push_back(Param{std::string(name), std::string()});
    found = static_cast<int32_t>(params_.size() - 1);
  }

  params_[static_cast<size_t>(found)].value.assign(value);
}

void UrlParams::Delete(std::string_view name) {
  params_.erase(std::remove_if(params_.begin(), params_.end(),
                               MakeNameMatcher(name)),
                params_.end());
}

void UrlParams::Delete(std::string_view name, std::string_view value) {
  params_.erase(std::remove_if(params_.begin(), params_.end(),
                               [name, value](const Param& param) {
                                 return param.key == name &&
                                        param.value == value;
                               }),
                params_.end());
}

/* static */
void UrlParams::DecodeString(std::string_view input, std::string& output) {
  const char* const end = input.data() + input.size();
  for (const char* iter = input.data(); iter != end;) {
    // replace '+' with U+0020
    if (*iter == '+') {
      output.push_back(' ');
      ++iter;
      continue;
    }

    // Percent decode algorithm
    if (*iter == '%') {
      const char* const first = iter + 1;
      const char* const second = first + 1;

      const auto asciiHexDigit = [](char x) {
        return (x >= 0x41 && x <= 0x46) || (x >= 0x61 && x <= 0x66) ||
               (x >= 0x30 && x <= 0x39);
      };

      const auto hexDigit = [](char x) {
        return x >= 0x30 && x <= 0x39
                   ? x - 0x30
                   : (x >= 0x41 && x <= 0x46 ? x - 0x37 : x - 0x57);
      };

      if (first != end && second != end && asciiHexDigit(*first) &&
          asciiHexDigit(*second)) {
        output.push_back(static_cast<char>(hexDigit(*first) * 16 +
                                           hexDigit(*second)));
        iter = second + 1;
      } else {
        output.push_back('%');
        ++iter;
      }

      continue;
    }

    output.push_back(*iter);
    ++iter;
  }
  AssignMaybeInvalidUtf8String(output, output);
}

/* static */
bool UrlParams::ParseNextInternal(const char*& start, const char* const end,
                                  bool shouldDecode, std::string* outputName,
                                  std::string* outputValue) {
  std::string_view string;

  const char* const iter = std::find(start, end, '&');
  if (iter != end) {
    string = std::string_view(start, static_cast<size_t>(iter - start));
    start = iter + 1;
  } else {
    string = std::string_view(start, static_cast<size_t>(end - start));
    start = end;
  }

  if (string.empty()) {
    return false;
  }

  const char* const eqStart = string.data();
  const char* const eqEnd = eqStart + string.size();
  const char* const eqIter = std::find(eqStart, eqEnd, '=');

  std::string_view name;
  std::string_view value;

  if (eqIter != eqEnd) {
    name = std::string_view(eqStart, static_cast<size_t>(eqIter - eqStart));
    value = std::string_view(eqIter + 1,
                             static_cast<size_t>(eqEnd - eqIter - 1));
  } else {
    name = string;
  }

  if (shouldDecode) {
    DecodeString(name, *outputName);
    DecodeString(value, *outputValue);
    return true;
  }

  AssignMaybeInvalidUtf8String(name, *outputName);
  AssignMaybeInvalidUtf8String(value, *outputValue);
  return true;
}

/* static */
bool UrlParams::Extract(std::string_view input, std::string_view name,
                        std::string& value) {
  value.clear();
  return !UrlParams::Parse(
      input, true, [name, &value](const std::string& parsedName,
                                  std::string&& parsedValue) {
        if (name == parsedName) {
          value = std::move(parsedValue);
          return false;
        }
        return true;
      });
}

void UrlParams::ParseInput(std::string_view input) {
  // Remove all the existing data before parsing a new input.
  DeleteAll();

  UrlParams::Parse(input, true, [this](std::string&& name,
                                       std::string&& value) {
    params_.push_back(Param{std::move(name), std::move(value)});
    return true;
  });
}

void UrlParams::SerializeString(std::string_view input, std::string& value) {
  const unsigned char* p =
      reinterpret_cast<const unsigned char*>(input.data());
  const unsigned char* end = p + input.size();

  while (p != end) {
    // ' ' to '+'
    if (*p == 0x20) {
      value.push_back(0x2B);
      // Percent Encode algorithm
    } else if (*p == 0x2A || *p == 0x2D || *p == 0x2E ||
               (*p >= 0x30 && *p <= 0x39) || (*p >= 0x41 && *p <= 0x5A) ||
               *p == 0x5F || (*p >= 0x61 && *p <= 0x7A)) {
      value.push_back(static_cast<char>(*p));
    } else {
      char escaped[4];
      std::snprintf(escaped, sizeof(escaped), "%%%.2X", *p);
      value.append(escaped);
    }

    ++p;
  }
}

void UrlParams::Serialize(std::string& value, bool encode) const {
  value.clear();
  bool first = true;

  for (const Param& param : params_) {
    if (first) {
      first = false;
    } else {
      value.push_back('&');
    }

    // XXX Actually, it's not necessary to build a new string object. Generally,
    // such cases could just convert each codepoint one-by-one.
    if (encode) {
      SerializeString(param.key, value);
      value.push_back('=');
      SerializeString(param.value, value);
    } else {
      value.append(param.key);
      value.push_back('=');
      value.append(param.value);
    }
  }
}

void UrlParams::Sort() {
  std::stable_sort(params_.begin(), params_.end(),
                   [](const Param& lhs, const Param& rhs) {
                     // Gecko compares the keys as UTF-16 code points (see the
                     // FIXME about bug 1888901 upstream); this port compares
                     // the UTF-8 bytes instead.
                     return lhs.key < rhs.key;
                   });
}

}  // namespace network::url
