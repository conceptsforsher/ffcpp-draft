/* MPL 2.0 - network/url
 *
 * C++ translation of:
 *   - netwerk/base/nsIURLParser.h / nsIURLParser.idl  (the parser interface)
 *   - netwerk/base/nsURLParsers.h                     (the parser classes)
 * and implemented in url_parser.cpp, which translates netwerk/base/nsURLParsers.cpp.
 *
 * Gecko's parsers report every component as a (position, length) pair inside the
 * original spec; a length of -1 means "this component is not present".  That
 * convention is kept verbatim here, only nsresult is replaced by network::Result.
 */
#pragma once

#include <cstdint>

namespace network::url {

// translation of nsresult values used by nsURLParsers.cpp
enum class Result : uint32_t {
  Ok = 0u,
  // NS_ERROR_INVALID_POINTER
  ErrorInvalidPointer = 0x80004003u,
  // NS_ERROR_MALFORMED_URI
  ErrorMalformedUri = 0x804B000Au,
  // NS_ERROR_UNEXPECTED
  ErrorUnexpected = 0x8000FFFFu,
};

constexpr bool Failed(Result r) { return static_cast<uint32_t>(r) != 0u; }

// translation of nsIURLParser
class UrlParser {
 public:
  virtual ~UrlParser() = default;

  virtual Result ParseURL(const char* spec, int32_t specLen,
                          uint32_t* schemePos, int32_t* schemeLen,
                          uint32_t* authorityPos, int32_t* authorityLen,
                          uint32_t* pathPos, int32_t* pathLen) = 0;

  virtual Result ParseAuthority(const char* auth, int32_t authLen,
                                uint32_t* usernamePos, int32_t* usernameLen,
                                uint32_t* passwordPos, int32_t* passwordLen,
                                uint32_t* hostnamePos, int32_t* hostnameLen,
                                int32_t* port) = 0;

  virtual Result ParseUserInfo(const char* userinfo, int32_t userinfoLen,
                               uint32_t* usernamePos, int32_t* usernameLen,
                               uint32_t* passwordPos,
                               int32_t* passwordLen) = 0;

  virtual Result ParseServerInfo(const char* serverinfo, int32_t serverinfoLen,
                                 uint32_t* hostnamePos, int32_t* hostnameLen,
                                 int32_t* port) = 0;

  virtual Result ParsePath(const char* path, int32_t pathLen,
                           uint32_t* filepathPos, int32_t* filepathLen,
                           uint32_t* queryPos, int32_t* queryLen,
                           uint32_t* refPos, int32_t* refLen) = 0;

  virtual Result ParseFilePath(const char* filepath, int32_t filepathLen,
                               uint32_t* directoryPos, int32_t* directoryLen,
                               uint32_t* basenamePos, int32_t* basenameLen,
                               uint32_t* extensionPos,
                               int32_t* extensionLen) = 0;

  virtual Result ParseFileName(const char* filename, int32_t filenameLen,
                               uint32_t* basenamePos, int32_t* basenameLen,
                               uint32_t* extensionPos,
                               int32_t* extensionLen) = 0;
};

//----------------------------------------------------------------------------
// translation of nsBaseURLParser: base class for url parsers
//----------------------------------------------------------------------------
class BaseUrlParser : public UrlParser {
 public:
  Result ParseURL(const char* spec, int32_t specLen, uint32_t* schemePos,
                  int32_t* schemeLen, uint32_t* authorityPos,
                  int32_t* authorityLen, uint32_t* pathPos,
                  int32_t* pathLen) override;

  Result ParseAuthority(const char* auth, int32_t authLen,
                        uint32_t* usernamePos, int32_t* usernameLen,
                        uint32_t* passwordPos, int32_t* passwordLen,
                        uint32_t* hostnamePos, int32_t* hostnameLen,
                        int32_t* port) override;

  Result ParseUserInfo(const char* userinfo, int32_t userinfoLen,
                       uint32_t* usernamePos, int32_t* usernameLen,
                       uint32_t* passwordPos, int32_t* passwordLen) override;

  Result ParseServerInfo(const char* serverinfo, int32_t serverinfoLen,
                         uint32_t* hostnamePos, int32_t* hostnameLen,
                         int32_t* port) override;

  Result ParsePath(const char* path, int32_t pathLen, uint32_t* filepathPos,
                   int32_t* filepathLen, uint32_t* queryPos, int32_t* queryLen,
                   uint32_t* refPos, int32_t* refLen) override;

  Result ParseFilePath(const char* filepath, int32_t filepathLen,
                       uint32_t* directoryPos, int32_t* directoryLen,
                       uint32_t* basenamePos, int32_t* basenameLen,
                       uint32_t* extensionPos, int32_t* extensionLen) override;

  Result ParseFileName(const char* filename, int32_t filenameLen,
                       uint32_t* basenamePos, int32_t* basenameLen,
                       uint32_t* extensionPos, int32_t* extensionLen) override;

 protected:
  // implemented by subclasses
  virtual void ParseAfterScheme(const char* spec, int32_t specLen,
                                uint32_t* authPos, int32_t* authLen,
                                uint32_t* pathPos, int32_t* pathLen) = 0;
};

//----------------------------------------------------------------------------
// translation of nsNoAuthURLParser: an url parser for urls that do not have an
// authority section
//
// eg. file:foo/bar.txt
//     file:/foo/bar.txt      (treated equivalently)
//     file:///foo/bar.txt
//
// eg. file:////foo/bar.txt   (UNC-filepath = \\foo\bar.txt)
//
// XXX except in this case:
//     file://foo/bar.txt     (the authority "foo"  is ignored)
//----------------------------------------------------------------------------
class NoAuthUrlParser final : public BaseUrlParser {
 public:
  Result ParseAuthority(const char* auth, int32_t authLen,
                        uint32_t* usernamePos, int32_t* usernameLen,
                        uint32_t* passwordPos, int32_t* passwordLen,
                        uint32_t* hostnamePos, int32_t* hostnameLen,
                        int32_t* port) override;

 protected:
  void ParseAfterScheme(const char* spec, int32_t specLen, uint32_t* authPos,
                        int32_t* authLen, uint32_t* pathPos,
                        int32_t* pathLen) override;
};

//----------------------------------------------------------------------------
// translation of nsAuthURLParser: an url parser for urls that must have an
// authority section
//
// eg. http:www.foo.com/bar.html
//     http:/www.foo.com/bar.html
//     http://www.foo.com/bar.html    (treated equivalently)
//     http:///www.foo.com/bar.html
//----------------------------------------------------------------------------
class AuthUrlParser : public BaseUrlParser {
 public:
  Result ParseAuthority(const char* auth, int32_t authLen,
                        uint32_t* usernamePos, int32_t* usernameLen,
                        uint32_t* passwordPos, int32_t* passwordLen,
                        uint32_t* hostnamePos, int32_t* hostnameLen,
                        int32_t* port) override;

  Result ParseUserInfo(const char* userinfo, int32_t userinfoLen,
                       uint32_t* usernamePos, int32_t* usernameLen,
                       uint32_t* passwordPos, int32_t* passwordLen) override;

  Result ParseServerInfo(const char* serverinfo, int32_t serverinfoLen,
                         uint32_t* hostnamePos, int32_t* hostnameLen,
                         int32_t* port) override;

 protected:
  void ParseAfterScheme(const char* spec, int32_t specLen, uint32_t* authPos,
                        int32_t* authLen, uint32_t* pathPos,
                        int32_t* pathLen) override;
};

//----------------------------------------------------------------------------
// translation of nsStdURLParser: an url parser for urls that may or may not
// have an authority section
//
// eg. http:www.foo.com              (www.foo.com is authority)
//     http:www.foo.com/bar.html     (www.foo.com is authority)
//     http:/www.foo.com/bar.html    (www.foo.com is part of file path)
//     http://www.foo.com/bar.html   (www.foo.com is authority)
//     http:///www.foo.com/bar.html  (www.foo.com is part of file path)
//----------------------------------------------------------------------------
class StdUrlParser final : public AuthUrlParser {
 protected:
  void ParseAfterScheme(const char* spec, int32_t specLen, uint32_t* authPos,
                        int32_t* authLen, uint32_t* pathPos,
                        int32_t* pathLen) override;
};

}  // namespace network::url
