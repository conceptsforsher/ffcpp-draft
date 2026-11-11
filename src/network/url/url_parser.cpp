/* MPL 2.0 - network/url
 *
 * C++ translation of netwerk/base/nsURLParsers.cpp.
 * Declarations live in url_parser.hpp (translation of nsURLParsers.h).
 */

#include <cstring>
#include <limits>
#include <string_view>

#include "network/url/url_helper.hpp"
#include "network/url/url_parser.hpp"

namespace network::url {

namespace {

uint32_t CountConsecutiveSlashes(const char* str, int32_t len) {
  const char* p = str;
  uint32_t count = 0;
  while (len-- && *p++ == '/') {
    ++count;
  }
  return count;
}

inline bool IsAsciiAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// translation of the nsAutoCString + ToInteger block of
// nsAuthURLParser::ParseServerInfo: digits only, then an integer that has to fit
// into a 16 bit port number.
Result ParsePortDigits(const char* buf, size_t len, int32_t* port) {
  if (len == 0) {
    *port = -1;
    return Result::Ok;
  }
  for (size_t i = 0; i < len; ++i) {
    if (buf[i] < '0' || buf[i] > '9') {
      return Result::ErrorMalformedUri;
    }
  }

  const char* p = buf;
  bool negative = false;
  if (*p == '-') {
    negative = true;
    ++p;
  } else if (*p == '+') {
    ++p;
  }
  if (p == buf + len) {
    return Result::ErrorMalformedUri;
  }

  int64_t value = 0;
  for (; p < buf + len; ++p) {
    value = value * 10 + (*p - '0');
    if (value > static_cast<int64_t>(std::numeric_limits<int32_t>::max())) {
      break;
    }
  }
  if (negative) {
    value = -value;
  }
  if (value < 0 ||
      value > static_cast<int64_t>(std::numeric_limits<uint16_t>::max())) {
    return Result::ErrorMalformedUri;
  }
  *port = static_cast<int32_t>(value);
  return Result::Ok;
}

}  // namespace

//----------------------------------------------------------------------------
// The SET_RESULT / OFFSET_RESULT helpers of nsURLParsers.cpp.  Every out
// parameter of this parser is optional, so each write is guarded the same way
// Gecko guards it.
//----------------------------------------------------------------------------
#define SET_RESULT(component, pos, len)                          \
  do {                                                           \
    if (component##Pos) *component##Pos = static_cast<uint32_t>(pos); \
    if (component##Len) *component##Len = static_cast<int32_t>(len);  \
  } while (0)

#define OFFSET_RESULT(component, offset)                     \
  do {                                                       \
    if (component##Pos) *component##Pos += static_cast<uint32_t>(offset); \
  } while (0)

//----------------------------------------------------------------------------
// nsBaseURLParser implementation
//----------------------------------------------------------------------------

Result BaseUrlParser::ParseURL(const char* spec, int32_t specLen,
                               uint32_t* schemePos, int32_t* schemeLen,
                               uint32_t* authorityPos, int32_t* authorityLen,
                               uint32_t* pathPos, int32_t* pathLen) {
  if (!spec) {
    return Result::ErrorInvalidPointer;
  }

  if (specLen < 0) {
    specLen = static_cast<int32_t>(strlen(spec));
  }

  const char* stop = nullptr;
  const char* colon = nullptr;
  const char* slash = nullptr;
  const char* p = spec;
  uint32_t offset = 0;
  int32_t len = specLen;

  // skip leading whitespace
  while (len && (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t')) {
    spec++;
    specLen--;
    offset++;

    p++;
    len--;
  }

  for (; len && *p && !colon && !slash; ++p, --len) {
    switch (*p) {
      case ':':
        if (!colon) colon = p;
        break;
      case '/':  // start of filepath
      case '?':  // start of query
      case '#':  // start of ref
        if (!slash) slash = p;
        break;
      case '@':  // username@hostname
      case '[':  // start of IPv6 address literal
        if (!stop) stop = p;
        break;
    }
  }
  // disregard the first colon if it follows an '@' or a '['
  if (colon && stop && colon > stop) colon = nullptr;

  // if the spec only contained whitespace ...
  if (specLen == 0) {
    SET_RESULT(scheme, 0, -1);
    SET_RESULT(authority, 0, 0);
    SET_RESULT(path, 0, 0);
    return Result::Ok;
  }

  // ignore trailing whitespace and control characters
  for (p = spec + specLen - 1; ((unsigned char)*p <= ' ') && (p != spec); --p) {
    ;
  }

  specLen = static_cast<int32_t>(p - spec + 1);

  if (colon && (colon < slash || !slash)) {
    //
    // spec = <scheme>:/<the-rest>
    //
    // or
    //
    // spec = <scheme>:<authority>
    // spec = <scheme>:<path-no-slashes>
    //
    if (!IsValidScheme(std::string_view(spec, colon - spec))) {
      return Result::ErrorMalformedUri;
    }
    SET_RESULT(scheme, offset, colon - spec);
    if (authorityLen || pathLen) {
      uint32_t schemeLen = static_cast<uint32_t>(colon + 1 - spec);
      offset += schemeLen;
      ParseAfterScheme(colon + 1, specLen - static_cast<int32_t>(schemeLen),
                       authorityPos, authorityLen, pathPos, pathLen);
      OFFSET_RESULT(authority, offset);
      OFFSET_RESULT(path, offset);
    }
  } else {
    //
    // spec = <authority-no-port-or-password>/<path>
    // spec = <path>
    //
    // or
    //
    // spec = <authority-no-port-or-password>/<path-with-colon>
    // spec = <path-with-colon>
    //
    // or
    //
    // spec = <authority-no-port-or-password>
    // spec = <path-no-slashes-or-colon>
    //
    SET_RESULT(scheme, 0, -1);
    if (authorityLen || pathLen) {
      ParseAfterScheme(spec, specLen, authorityPos, authorityLen, pathPos,
                       pathLen);
      OFFSET_RESULT(authority, offset);
      OFFSET_RESULT(path, offset);
    }
  }
  return Result::Ok;
}

Result BaseUrlParser::ParseAuthority(const char* auth, int32_t authLen,
                                     uint32_t* usernamePos,
                                     int32_t* usernameLen,
                                     uint32_t* passwordPos,
                                     int32_t* passwordLen,
                                     uint32_t* hostnamePos,
                                     int32_t* hostnameLen, int32_t* port) {
  if (!auth) {
    return Result::ErrorInvalidPointer;
  }

  if (authLen < 0) authLen = static_cast<int32_t>(strlen(auth));

  SET_RESULT(username, 0, -1);
  SET_RESULT(password, 0, -1);
  SET_RESULT(hostname, 0, authLen);
  if (port) *port = -1;
  return Result::Ok;
}

Result BaseUrlParser::ParseUserInfo(const char* userinfo, int32_t userinfoLen,
                                    uint32_t* usernamePos,
                                    int32_t* usernameLen,
                                    uint32_t* passwordPos,
                                    int32_t* passwordLen) {
  SET_RESULT(username, 0, -1);
  SET_RESULT(password, 0, -1);
  return Result::Ok;
}

Result BaseUrlParser::ParseServerInfo(const char* serverinfo,
                                      int32_t serverinfoLen,
                                      uint32_t* hostnamePos,
                                      int32_t* hostnameLen, int32_t* port) {
  SET_RESULT(hostname, 0, -1);
  if (port) *port = -1;
  return Result::Ok;
}

Result BaseUrlParser::ParsePath(const char* path, int32_t pathLen,
                                uint32_t* filepathPos, int32_t* filepathLen,
                                uint32_t* queryPos, int32_t* queryLen,
                                uint32_t* refPos, int32_t* refLen) {
  if (!path) {
    return Result::ErrorInvalidPointer;
  }

  if (pathLen < 0) pathLen = static_cast<int32_t>(strlen(path));

  // path = [/]<segment1>/<segment2>/<...>/<segmentN>?<query>#<ref>

  // search for first occurrence of either ? or #
  const char* query_beg = nullptr;
  const char* query_end = nullptr;
  const char* ref_beg = nullptr;
  const char* p = nullptr;
  for (p = path; p < path + pathLen; ++p) {
    // only match the query string if it precedes the reference fragment
    if (!ref_beg && !query_beg && *p == '?') {
      query_beg = p + 1;
    } else if (*p == '#') {
      ref_beg = p + 1;
      if (query_beg) query_end = p;
      break;
    }
  }

  if (query_beg) {
    if (query_end) {
      SET_RESULT(query, query_beg - path, query_end - query_beg);
    } else {
      SET_RESULT(query, query_beg - path, pathLen - (query_beg - path));
    }
  } else {
    SET_RESULT(query, 0, -1);
  }

  if (ref_beg) {
    SET_RESULT(ref, ref_beg - path, pathLen - (ref_beg - path));
  } else {
    SET_RESULT(ref, 0, -1);
  }

  const char* end;
  if (query_beg) {
    end = query_beg - 1;
  } else if (ref_beg) {
    end = ref_beg - 1;
  } else {
    end = path + pathLen;
  }

  // an empty file path is no file path
  if (end != path) {
    SET_RESULT(filepath, 0, end - path);
  } else {
    SET_RESULT(filepath, 0, -1);
  }
  return Result::Ok;
}

Result BaseUrlParser::ParseFilePath(const char* filepath, int32_t filepathLen,
                                    uint32_t* directoryPos,
                                    int32_t* directoryLen,
                                    uint32_t* basenamePos,
                                    int32_t* basenameLen,
                                    uint32_t* extensionPos,
                                    int32_t* extensionLen) {
  if (!filepath) {
    return Result::ErrorInvalidPointer;
  }

  if (filepathLen < 0) filepathLen = static_cast<int32_t>(strlen(filepath));

  if (filepathLen == 0) {
    SET_RESULT(directory, 0, -1);
    SET_RESULT(basename, 0, 0);  // assume a zero length file basename
    SET_RESULT(extension, 0, -1);
    return Result::Ok;
  }

  const char* p;
  const char* end = filepath + filepathLen;

  // search backwards for filename
  for (p = end - 1; *p != '/' && p > filepath; --p) {
    ;
  }
  if (*p == '/') {
    // catch /.. and /.
    if ((p + 1 < end && *(p + 1) == '.') &&
        (p + 2 == end || (*(p + 2) == '.' && p + 3 == end))) {
      p = end - 1;
    }
    // filepath = <directory><filename>.<extension>
    SET_RESULT(directory, 0, p - filepath + 1);
    ParseFileName(p + 1, static_cast<int32_t>(end - (p + 1)), basenamePos,
                  basenameLen, extensionPos, extensionLen);
    OFFSET_RESULT(basename, p + 1 - filepath);
    OFFSET_RESULT(extension, p + 1 - filepath);
  } else {
    // filepath = <filename>.<extension>
    SET_RESULT(directory, 0, -1);
    ParseFileName(filepath, filepathLen, basenamePos, basenameLen, extensionPos,
                  extensionLen);
  }
  return Result::Ok;
}

Result BaseUrlParser::ParseFileName(const char* filename, int32_t filenameLen,
                                    uint32_t* basenamePos,
                                    int32_t* basenameLen,
                                    uint32_t* extensionPos,
                                    int32_t* extensionLen) {
  if (!filename) {
    return Result::ErrorInvalidPointer;
  }

  if (filenameLen < 0) filenameLen = static_cast<int32_t>(strlen(filename));

  // no extension if filename ends with a '.'
  if (filename[filenameLen - 1] != '.') {
    // ignore '.' at the beginning
    for (const char* p = filename + filenameLen - 1; p > filename; --p) {
      if (*p == '.') {
        // filename = <basename.extension>
        SET_RESULT(basename, 0, p - filename);
        SET_RESULT(extension, p + 1 - filename,
                   filenameLen - (p - filename + 1));
        return Result::Ok;
      }
    }
  }
  // filename = <basename>
  SET_RESULT(basename, 0, filenameLen);
  SET_RESULT(extension, 0, -1);
  return Result::Ok;
}

//----------------------------------------------------------------------------
// nsNoAuthURLParser implementation
//----------------------------------------------------------------------------

Result NoAuthUrlParser::ParseAuthority(const char* auth, int32_t authLen,
                                       uint32_t* usernamePos,
                                       int32_t* usernameLen,
                                       uint32_t* passwordPos,
                                       int32_t* passwordLen,
                                       uint32_t* hostnamePos,
                                       int32_t* hostnameLen, int32_t* port) {
  // Gecko: MOZ_ASSERT_UNREACHABLE("Shouldn't parse auth in a NoAuthURL!");
  return Result::ErrorUnexpected;
}

void NoAuthUrlParser::ParseAfterScheme(const char* spec, int32_t specLen,
                                       uint32_t* authPos, int32_t* authLen,
                                       uint32_t* pathPos, int32_t* pathLen) {
  // everything is the path
  uint32_t pos = 0;
  switch (CountConsecutiveSlashes(spec, specLen)) {
    case 0:
    case 1:
      break;
    case 2: {
      const char* p = nullptr;
      if (specLen > 2) {
        // looks like there is an authority section

        // if the authority looks like a drive number then we
        // really want to treat it as part of the path
        // [a-zA-Z][:|]{/\}
        // i.e one of:   c:   c:\foo  c:/foo  c|  c|\foo  c|/foo
        if ((specLen > 3) && (spec[3] == ':' || spec[3] == '|') &&
            IsAsciiAlpha(spec[2]) &&
            ((specLen == 4) || (spec[4] == '/') || (spec[4] == '\\'))) {
          pos = 1;
          break;
        }
        // Ignore apparent authority; path is everything after it
        for (p = spec + 2; p < spec + specLen; ++p) {
          if (*p == '/' || *p == '?' || *p == '#') break;
        }
      }
      SET_RESULT(auth, 0, -1);
      if (p && p != spec + specLen) {
        SET_RESULT(path, p - spec, specLen - (p - spec));
      } else {
        SET_RESULT(path, 0, -1);
      }
      return;
    }
    default:
      pos = 2;
      break;
  }
  SET_RESULT(auth, pos, 0);
  SET_RESULT(path, pos, specLen - static_cast<int32_t>(pos));
}

//----------------------------------------------------------------------------
// nsAuthURLParser implementation
//----------------------------------------------------------------------------

Result AuthUrlParser::ParseAuthority(const char* auth, int32_t authLen,
                                     uint32_t* usernamePos,
                                     int32_t* usernameLen,
                                     uint32_t* passwordPos,
                                     int32_t* passwordLen,
                                     uint32_t* hostnamePos,
                                     int32_t* hostnameLen, int32_t* port) {
  Result rv;

  if (!auth) {
    return Result::ErrorInvalidPointer;
  }

  if (authLen < 0) authLen = static_cast<int32_t>(strlen(auth));

  if (authLen == 0) {
    SET_RESULT(username, 0, -1);
    SET_RESULT(password, 0, -1);
    SET_RESULT(hostname, 0, 0);
    if (port) *port = -1;
    return Result::Ok;
  }

  // search backwards for @
  const char* p = auth + authLen - 1;
  for (; (*p != '@') && (p > auth); --p) {
  }
  if (*p == '@') {
    // auth = <user-info@server-info>
    rv = ParseUserInfo(auth, static_cast<int32_t>(p - auth), usernamePos,
                       usernameLen, passwordPos, passwordLen);
    if (Failed(rv)) return rv;
    rv = ParseServerInfo(p + 1, authLen - static_cast<int32_t>(p - auth + 1),
                         hostnamePos, hostnameLen, port);
    if (Failed(rv)) return rv;
    OFFSET_RESULT(hostname, p + 1 - auth);

    // malformed if has a username or password
    // but no host info, such as: http://u:p@/
    const int32_t hostLen = hostnameLen ? *hostnameLen : 0;
    if ((usernamePos || passwordPos) && (!hostnamePos || hostLen == 0)) {
      return Result::ErrorMalformedUri;
    }
  } else {
    // auth = <server-info>
    SET_RESULT(username, 0, -1);
    SET_RESULT(password, 0, -1);
    rv = ParseServerInfo(auth, authLen, hostnamePos, hostnameLen, port);
    if (Failed(rv)) return rv;
  }
  return Result::Ok;
}

Result AuthUrlParser::ParseUserInfo(const char* userinfo, int32_t userinfoLen,
                                    uint32_t* usernamePos,
                                    int32_t* usernameLen,
                                    uint32_t* passwordPos,
                                    int32_t* passwordLen) {
  if (!userinfo) {
    return Result::ErrorInvalidPointer;
  }

  if (userinfoLen < 0) userinfoLen = static_cast<int32_t>(strlen(userinfo));

  if (userinfoLen == 0) {
    SET_RESULT(username, 0, -1);
    SET_RESULT(password, 0, -1);
    return Result::Ok;
  }

  const char* p = static_cast<const char*>(memchr(userinfo, ':', userinfoLen));
  if (p) {
    // userinfo = <username:password>
    SET_RESULT(username, 0, p - userinfo);
    SET_RESULT(password, p - userinfo + 1, userinfoLen - (p - userinfo + 1));
  } else {
    // userinfo = <username>
    SET_RESULT(username, 0, userinfoLen);
    SET_RESULT(password, 0, -1);
  }
  return Result::Ok;
}

Result AuthUrlParser::ParseServerInfo(const char* serverinfo,
                                      int32_t serverinfoLen,
                                      uint32_t* hostnamePos,
                                      int32_t* hostnameLen, int32_t* port) {
  if (!serverinfo) {
    return Result::ErrorInvalidPointer;
  }

  if (serverinfoLen < 0) {
    serverinfoLen = static_cast<int32_t>(strlen(serverinfo));
  }

  if (serverinfoLen == 0) {
    SET_RESULT(hostname, 0, 0);
    if (port) *port = -1;
    return Result::Ok;
  }

  // search backwards for a ':' but stop on ']' (IPv6 address literal
  // delimiter).  check for illegal characters in the hostname.
  const char* p = serverinfo + serverinfoLen - 1;
  const char* colon = nullptr;
  const char* bracket = nullptr;
  for (; p > serverinfo; --p) {
    switch (*p) {
      case ']':
        bracket = p;
        break;
      case ':':
        if (bracket == nullptr) colon = p;
        break;
      case ' ':
        // hostname must not contain a space
        return Result::ErrorMalformedUri;
    }
  }

  if (colon) {
    // serverinfo = <hostname:port>
    SET_RESULT(hostname, 0, colon - serverinfo);
    if (port) {
      Result rv = ParsePortDigits(
          colon + 1, static_cast<size_t>(serverinfoLen - (colon + 1 - serverinfo)),
          port);
      if (Failed(rv)) return rv;
    }
  } else {
    // serverinfo = <hostname>
    SET_RESULT(hostname, 0, serverinfoLen);
    if (port) *port = -1;
  }

  // In case of IPv6 address check its validity.
  // (Gecko dereferences hostnamePos/hostnameLen directly here; this translation
  // reads them through local copies so that callers may pass null.)
  const uint32_t hostPos = hostnamePos ? *hostnamePos : 0u;
  const int32_t hostLen = hostnameLen ? *hostnameLen : 0;
  if (hostLen > 1 && *(serverinfo + hostPos) == '[' &&
      *(serverinfo + hostPos + hostLen - 1) == ']' &&
      !IsValidIPv6Addr(std::string_view(serverinfo + hostPos + 1,
                                        static_cast<size_t>(hostLen - 2)))) {
    return Result::ErrorMalformedUri;
  }

  return Result::Ok;
}

void AuthUrlParser::ParseAfterScheme(const char* spec, int32_t specLen,
                                     uint32_t* authPos, int32_t* authLen,
                                     uint32_t* pathPos, int32_t* pathLen) {
  const uint32_t nslash = CountConsecutiveSlashes(spec, specLen);

  // search for the end of the authority section
  const char* end = spec + specLen;
  const char* p;
  for (p = spec + nslash; p < end; ++p) {
    if (*p == '/' || *p == '?' || *p == '#') break;
  }
  if (p < end) {
    // spec = [/]<auth><path>
    SET_RESULT(auth, nslash, p - (spec + nslash));
    SET_RESULT(path, p - spec, specLen - (p - spec));
  } else {
    // spec = [/]<auth>
    SET_RESULT(auth, nslash, specLen - static_cast<int32_t>(nslash));
    SET_RESULT(path, 0, -1);
  }
}

//----------------------------------------------------------------------------
// nsStdURLParser implementation
//----------------------------------------------------------------------------

void StdUrlParser::ParseAfterScheme(const char* spec, int32_t specLen,
                                    uint32_t* authPos, int32_t* authLen,
                                    uint32_t* pathPos, int32_t* pathLen) {
  const uint32_t nslash = CountConsecutiveSlashes(spec, specLen);

  // search for the end of the authority section
  const char* end = spec + specLen;
  const char* p;
  for (p = spec + nslash; p < end; ++p) {
    if (strchr("/?#;", *p)) break;
  }
  switch (nslash) {
    case 0:
    case 2:
      if (p < end) {
        // spec = (//)<auth><path>
        SET_RESULT(auth, nslash, p - (spec + nslash));
        SET_RESULT(path, p - spec, specLen - (p - spec));
      } else {
        // spec = (//)<auth>
        SET_RESULT(auth, nslash, specLen - static_cast<int32_t>(nslash));
        SET_RESULT(path, 0, -1);
      }
      break;
    case 1:
      // spec = /<path>
      SET_RESULT(auth, 0, -1);
      SET_RESULT(path, 0, specLen);
      break;
    default:
      // spec = ///[/]<path>
      SET_RESULT(auth, 2, 0);
      SET_RESULT(path, 2, specLen - 2);
  }
}

}  // namespace network::url
