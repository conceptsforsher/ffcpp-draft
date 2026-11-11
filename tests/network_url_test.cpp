/* MPL 2.0 - network/url
 *
 * Behavioural tests for the netwerk/base/nsURLParsers translation.
 *
 * Every expectation below is derived from Gecko's own parser conventions:
 * components are reported as (position, length) pairs into the original spec,
 * and -1 means "component not present".
 */

#include <cstdio>
#include <cstdint>
#include <string>

#include "network/url/url_helper.hpp"
#include "network/url/url_parser.hpp"

namespace {

int gFailures = 0;

void Check(bool ok, const char* expr, int line) {
  if (!ok) {
    ++gFailures;
    std::fprintf(stderr, "FAIL (line %d): %s\n", line, expr);
  }
}

#define CHECK(expr) Check((expr), #expr, __LINE__)

using network::url::Result;

//--------------------------------------------------------------------------
// netwerk/base/rust-helper helpers (via netwerk/base/nsURLHelper.cpp)
//--------------------------------------------------------------------------
void TestSchemeHelpers() {
  CHECK(network::url::IsValidScheme("http"));
  CHECK(network::url::IsValidScheme("https"));
  CHECK(network::url::IsValidScheme("h"));
  CHECK(network::url::IsValidScheme("ht+tp"));
  CHECK(network::url::IsValidScheme("ht-1.tp"));
  CHECK(!network::url::IsValidScheme(""));
  CHECK(!network::url::IsValidScheme("1http"));
  CHECK(!network::url::IsValidScheme("ht tp"));

  CHECK(network::url::IsValidSchemeChar('a'));
  CHECK(network::url::IsValidSchemeChar('Z'));
  CHECK(network::url::IsValidSchemeChar('0'));
  CHECK(network::url::IsValidSchemeChar('+'));
  CHECK(network::url::IsValidSchemeChar('.'));
  CHECK(network::url::IsValidSchemeChar('-'));
  CHECK(!network::url::IsValidSchemeChar('/'));
  CHECK(!network::url::IsValidSchemeChar(':'));
}

void TestIPv4Helper() {
  CHECK(network::url::IsValidIPv4Addr("127.0.0.1"));
  CHECK(network::url::IsValidIPv4Addr("0.0.0.0"));
  CHECK(network::url::IsValidIPv4Addr("255.255.255.255"));
  // leading zeroes are rejected
  CHECK(!network::url::IsValidIPv4Addr("01.2.3.4"));
  // octet overflow is rejected
  CHECK(!network::url::IsValidIPv4Addr("256.1.1.1"));
  // wrong number of dots
  CHECK(!network::url::IsValidIPv4Addr("1.2.3"));
  CHECK(!network::url::IsValidIPv4Addr("1.2.3.4."));
  CHECK(!network::url::IsValidIPv4Addr(".1.2.3"));
  // non digits
  CHECK(!network::url::IsValidIPv4Addr("1.2.3.a"));
}

void TestIPv6Helper() {
  CHECK(network::url::IsValidIPv6Addr("::"));
  CHECK(network::url::IsValidIPv6Addr("::1"));
  CHECK(network::url::IsValidIPv6Addr("2001:db8::1"));
  CHECK(network::url::IsValidIPv6Addr("1:2:3:4:5:6:7:8"));
  // too few blocks without a double colon
  CHECK(!network::url::IsValidIPv6Addr("1:2:3:4:5:6:7"));
  // three colons in a row
  CHECK(!network::url::IsValidIPv6Addr(":::1"));
  // single leading colon only
  CHECK(!network::url::IsValidIPv6Addr(":1:2:3:4:5:6:7:8"));
  // invalid character
  CHECK(!network::url::IsValidIPv6Addr("2001:db8::g1"));
}

//--------------------------------------------------------------------------
// nsStdURLParser
//--------------------------------------------------------------------------
void TestStdUrlParserParseURL() {
  network::url::StdUrlParser parser;

  // http://www.foo.com/bar.html
  //       ^     ^        ^
  //  scheme:0/4  auth:7/11  path:18/9
  uint32_t schemePos = 0, authorityPos = 0, pathPos = 0;
  int32_t schemeLen = 0, authorityLen = 0, pathLen = 0;
  CHECK(parser.ParseURL("http://www.foo.com/bar.html", -1, &schemePos,
                        &schemeLen, &authorityPos, &authorityLen, &pathPos,
                        &pathLen) == Result::Ok);
  CHECK(schemePos == 0 && schemeLen == 4);
  CHECK(authorityPos == 7 && authorityLen == 11);
  CHECK(pathPos == 18 && pathLen == 9);

  // leading whitespace is skipped and accounted for in the offsets
  CHECK(parser.ParseURL("  http://www.foo.com/bar.html", -1, &schemePos,
                        &schemeLen, &authorityPos, &authorityLen, &pathPos,
                        &pathLen) == Result::Ok);
  CHECK(schemePos == 2 && schemeLen == 4);
  CHECK(authorityPos == 9 && authorityLen == 11);
  CHECK(pathPos == 20 && pathLen == 9);

  // trailing whitespace is ignored
  CHECK(parser.ParseURL("http://www.foo.com/bar.html   ", -1, &schemePos,
                        &schemeLen, &authorityPos, &authorityLen, &pathPos,
                        &pathLen) == Result::Ok);
  CHECK(schemePos == 0 && schemeLen == 4);
  CHECK(authorityPos == 7 && authorityLen == 11);
  CHECK(pathPos == 18 && pathLen == 9);

  // http:www.foo.com/bar.html -- one slash is missing, the host is still the
  // authority for a standard URL
  CHECK(parser.ParseURL("http:www.foo.com/bar.html", -1, &schemePos, &schemeLen,
                        &authorityPos, &authorityLen, &pathPos,
                        &pathLen) == Result::Ok);
  CHECK(schemePos == 0 && schemeLen == 4);
  CHECK(authorityPos == 5 && authorityLen == 11);
  CHECK(pathPos == 16 && pathLen == 9);

  // a path without any scheme at all
  CHECK(parser.ParseURL("www.foo.com/bar.html", -1, &schemePos, &schemeLen,
                        &authorityPos, &authorityLen, &pathPos,
                        &pathLen) == Result::Ok);
  CHECK(schemeLen == -1);
  CHECK(authorityPos == 0 && authorityLen == 11);
  CHECK(pathPos == 11 && pathLen == 9);

  // invalid scheme characters make the URL malformed
  CHECK(parser.ParseURL("ht tp://www.foo.com/bar.html", -1, &schemePos,
                        &schemeLen, &authorityPos, &authorityLen, &pathPos,
                        &pathLen) == Result::ErrorMalformedUri);

  // a null spec is an invalid pointer
  CHECK(parser.ParseURL(nullptr, -1, &schemePos, &schemeLen, &authorityPos,
                        &authorityLen, &pathPos,
                        &pathLen) == Result::ErrorInvalidPointer);
}

void TestAuthUrlParser() {
  network::url::AuthUrlParser parser;

  uint32_t usernamePos = 0, passwordPos = 0, hostnamePos = 0;
  int32_t usernameLen = 0, passwordLen = 0, hostnameLen = 0;
  int32_t port = 0;

  // <hostname:port>
  CHECK(parser.ParseServerInfo("www.foo.com:8080", -1, &hostnamePos,
                               &hostnameLen, &port) == Result::Ok);
  CHECK(hostnamePos == 0 && hostnameLen == 11);
  CHECK(port == 8080);

  // <hostname> without port
  CHECK(parser.ParseServerInfo("www.foo.com", -1, &hostnamePos, &hostnameLen,
                               &port) == Result::Ok);
  CHECK(hostnamePos == 0 && hostnameLen == 11);
  CHECK(port == -1);

  // IPv6 literal: the reverse scan must stop at ']' so the port is found after
  // the closing bracket.
  CHECK(parser.ParseServerInfo("[::1]:80", -1, &hostnamePos, &hostnameLen,
                               &port) == Result::Ok);
  CHECK(hostnamePos == 0 && hostnameLen == 5);
  CHECK(port == 80);

  // an invalid IPv6 literal is malformed
  CHECK(parser.ParseServerInfo("[:::1]:80", -1, &hostnamePos, &hostnameLen,
                               &port) == Result::ErrorMalformedUri);

  // ports outside the 16 bit range are malformed
  CHECK(parser.ParseServerInfo("www.foo.com:65536", -1, &hostnamePos,
                               &hostnameLen, &port) == Result::ErrorMalformedUri);

  // a space in the hostname is malformed
  CHECK(parser.ParseServerInfo("www.foo com:80", -1, &hostnamePos, &hostnameLen,
                               &port) == Result::ErrorMalformedUri);

  // <username:password>
  CHECK(parser.ParseUserInfo("user:pw", -1, &usernamePos, &usernameLen,
                             &passwordPos, &passwordLen) == Result::Ok);
  CHECK(usernamePos == 0 && usernameLen == 4);
  CHECK(passwordPos == 5 && passwordLen == 2);

  // <username> without password
  CHECK(parser.ParseUserInfo("user", -1, &usernamePos, &usernameLen,
                             &passwordPos, &passwordLen) == Result::Ok);
  CHECK(usernamePos == 0 && usernameLen == 4);
  CHECK(passwordLen == -1);

  // <user-info@server-info>
  CHECK(parser.ParseAuthority("user@host:8080", -1, &usernamePos, &usernameLen,
                              &passwordPos, &passwordLen, &hostnamePos,
                              &hostnameLen, &port) == Result::Ok);
  CHECK(usernamePos == 0 && usernameLen == 4);
  CHECK(passwordLen == -1);
  CHECK(hostnamePos == 5 && hostnameLen == 4);
  CHECK(port == 8080);

  // user info without a host is malformed
  CHECK(parser.ParseAuthority("u:p@", -1, &usernamePos, &usernameLen,
                              &passwordPos, &passwordLen, &hostnamePos,
                              &hostnameLen, &port) == Result::ErrorMalformedUri);
}

void TestNoAuthUrlParser() {
  network::url::NoAuthUrlParser parser;

  uint32_t schemePos = 0, authorityPos = 0, pathPos = 0;
  int32_t schemeLen = 0, authorityLen = 0, pathLen = 0;

  // file:///foo/bar.txt -> everything after "//" is the path, the authority is
  // empty.
  CHECK(parser.ParseURL("file:///foo/bar.txt", -1, &schemePos, &schemeLen,
                        &authorityPos, &authorityLen, &pathPos,
                        &pathLen) == Result::Ok);
  CHECK(schemePos == 0 && schemeLen == 4);
  CHECK(authorityPos == 7 && authorityLen == 0);
  CHECK(pathPos == 7 && pathLen == 12);

  // a no-auth URL never has an authority section to parse
  uint32_t usernamePos = 0, passwordPos = 0, hostnamePos = 0;
  int32_t usernameLen = 0, passwordLen = 0, hostnameLen = 0, port = 0;
  CHECK(parser.ParseAuthority("x", -1, &usernamePos, &usernameLen, &passwordPos,
                              &passwordLen, &hostnamePos, &hostnameLen,
                              &port) == Result::ErrorUnexpected);
}

//--------------------------------------------------------------------------
// nsBaseURLParser path helpers
//--------------------------------------------------------------------------
void TestParsePath() {
  network::url::StdUrlParser parser;

  uint32_t filepathPos = 0, queryPos = 0, refPos = 0;
  int32_t filepathLen = 0, queryLen = 0, refLen = 0;

  // /foo/bar.html?q#r
  // filepath 0/13, query 14/1, ref 16/1
  CHECK(parser.ParsePath("/foo/bar.html?q#r", -1, &filepathPos, &filepathLen,
                         &queryPos, &queryLen, &refPos, &refLen) == Result::Ok);
  CHECK(filepathPos == 0 && filepathLen == 13);
  CHECK(queryPos == 14 && queryLen == 1);
  CHECK(refPos == 16 && refLen == 1);

  // no query, no ref
  CHECK(parser.ParsePath("/foo/bar.html", -1, &filepathPos, &filepathLen,
                         &queryPos, &queryLen, &refPos, &refLen) == Result::Ok);
  CHECK(filepathPos == 0 && filepathLen == 13);
  CHECK(queryLen == -1);
  CHECK(refLen == -1);

  // ref without query
  CHECK(parser.ParsePath("/foo/bar.html#r", -1, &filepathPos, &filepathLen,
                         &queryPos, &queryLen, &refPos, &refLen) == Result::Ok);
  CHECK(filepathPos == 0 && filepathLen == 13);
  CHECK(queryLen == -1);
  CHECK(refPos == 14 && refLen == 1);

  // query only
  CHECK(parser.ParsePath("/foo/bar.html?a=b", -1, &filepathPos, &filepathLen,
                         &queryPos, &queryLen, &refPos, &refLen) == Result::Ok);
  CHECK(filepathPos == 0 && filepathLen == 13);
  CHECK(queryPos == 14 && queryLen == 3);
  CHECK(refLen == -1);
}

void TestParseFilePath() {
  network::url::StdUrlParser parser;

  uint32_t directoryPos = 0, basenamePos = 0, extensionPos = 0;
  int32_t directoryLen = 0, basenameLen = 0, extensionLen = 0;

  // /foo/bar.html -> directory "/foo/" 0/5, basename "bar" 5/3,
  //                  extension "html" 9/4
  CHECK(parser.ParseFilePath("/foo/bar.html", -1, &directoryPos, &directoryLen,
                             &basenamePos, &basenameLen, &extensionPos,
                             &extensionLen) == Result::Ok);
  CHECK(directoryPos == 0 && directoryLen == 5);
  CHECK(basenamePos == 5 && basenameLen == 3);
  CHECK(extensionPos == 9 && extensionLen == 4);

  // no directory at all
  CHECK(parser.ParseFilePath("bar.html", -1, &directoryPos, &directoryLen,
                             &basenamePos, &basenameLen, &extensionPos,
                             &extensionLen) == Result::Ok);
  CHECK(directoryLen == -1);
  CHECK(basenamePos == 0 && basenameLen == 3);
  CHECK(extensionPos == 4 && extensionLen == 4);

  // empty filepath
  CHECK(parser.ParseFilePath("", 0, &directoryPos, &directoryLen, &basenamePos,
                             &basenameLen, &extensionPos,
                             &extensionLen) == Result::Ok);
  CHECK(directoryLen == -1);
  CHECK(basenameLen == 0);
  CHECK(extensionLen == -1);
}

void TestParseFileName() {
  network::url::StdUrlParser parser;

  uint32_t basenamePos = 0, extensionPos = 0;
  int32_t basenameLen = 0, extensionLen = 0;

  CHECK(parser.ParseFileName("bar.html", -1, &basenamePos, &basenameLen,
                             &extensionPos, &extensionLen) == Result::Ok);
  CHECK(basenamePos == 0 && basenameLen == 3);
  CHECK(extensionPos == 4 && extensionLen == 4);

  // a trailing dot means "no extension"
  CHECK(parser.ParseFileName("bar.", -1, &basenamePos, &basenameLen,
                             &extensionPos, &extensionLen) == Result::Ok);
  CHECK(basenamePos == 0 && basenameLen == 4);
  CHECK(extensionLen == -1);

  // no dot at all
  CHECK(parser.ParseFileName("bar", -1, &basenamePos, &basenameLen,
                             &extensionPos, &extensionLen) == Result::Ok);
  CHECK(basenamePos == 0 && basenameLen == 3);
  CHECK(extensionLen == -1);
}

//--------------------------------------------------------------------------
// netwerk/base/nsURLHelper.cpp: scheme, path and file URL helpers
//--------------------------------------------------------------------------
void TestExtractURLScheme() {
  std::string scheme;

  CHECK(network::url::ExtractURLScheme("HTTP://www.foo.com/bar", scheme) ==
        Result::Ok);
  CHECK(scheme == "http");

  // leading C0 controls and space are skipped
  CHECK(network::url::ExtractURLScheme("  http://www.foo.com/bar", scheme) ==
        Result::Ok);
  CHECK(scheme == "http");

  // \r\n\t inside the scheme are stripped from the result
  CHECK(network::url::ExtractURLScheme("ht\ttp://www.foo.com/bar", scheme) ==
        Result::Ok);
  CHECK(scheme == "http");

  CHECK(network::url::ExtractURLScheme("mailto:user@host", scheme) ==
        Result::Ok);
  CHECK(scheme == "mailto");

  // no colon -> not a scheme
  CHECK(network::url::ExtractURLScheme("http", scheme) ==
        Result::ErrorMalformedUri);
  // first char must be alpha
  CHECK(network::url::ExtractURLScheme("1http://x", scheme) ==
        Result::ErrorMalformedUri);
}

void TestIsAbsoluteURL() {
  CHECK(network::url::IsAbsoluteURL("http://www.foo.com/bar"));
  CHECK(network::url::IsAbsoluteURL("HTTP://www.foo.com/bar"));
  CHECK(network::url::IsAbsoluteURL("ftp://www.foo.com/bar"));
  // only one slash after the scheme
  CHECK(!network::url::IsAbsoluteURL("http:/www.foo.com/bar"));
  CHECK(!network::url::IsAbsoluteURL("http:www.foo.com/bar"));
  CHECK(!network::url::IsAbsoluteURL("/foo/bar"));
}

void TestFilterURIString() {
  std::string result;

  network::url::FilterURIString(" \rhttp://a\tb\n ", result);
  CHECK(result == "http://ab");

  // nothing to filter -> the string is used unchanged
  network::url::FilterURIString("http://a", result);
  CHECK(result == "http://a");

  network::url::FilterURIString("  \t ", result);
  CHECK(result.empty());
}

void TestCharacterHelpers() {
  char buf[] = "ABCDEF";
  network::url::ToLowerCase(buf, 3);
  CHECK(std::string(buf) == "abcDEF");
  network::url::ToLowerCase(buf);
  CHECK(std::string(buf) == "abcdef");

  char set[] = "abcdef";
  CHECK(network::url::FindCharInSet(set, set + 6, "cd") == set + 2);
  // not found -> returns stop
  CHECK(network::url::FindCharInSet(set, set + 6, "z") == set + 6);

  char padded[] = "  a";
  CHECK(network::url::FindCharNotInSet(padded, padded + 3, " ") == padded + 2);
  // everything is in the set -> returns stop
  CHECK(network::url::FindCharNotInSet(padded, padded + 2, " ") == padded + 2);

  // Scanning backwards from the end, the last character that is *not* in the
  // set is 'b' at index 2: the function returns the position reached, not the
  // position of the last match.
  char trailing[] = "xab  ";
  CHECK(network::url::RFindCharNotInSet(trailing + 1, trailing + 5, " ") ==
        trailing + 2);
}

void TestIsValidDNSHost() {
  CHECK(network::url::IsValidDNSHost("www.foo.com"));
  CHECK(network::url::IsValidDNSHost("foo"));
  CHECK(network::url::IsValidDNSHost("my-host_1.example.com"));
  // space is not in the whitelist
  CHECK(!network::url::IsValidDNSHost("www.foo com"));
  // IPv6 literals reach DNS through the percent-sign path
  CHECK(network::url::IsValidDNSHost("[::1]"));
  // too long
  CHECK(!network::url::IsValidDNSHost(std::string(300, 'a')));
}

void TestCoalesceDirs() {
  {
    char path[] = "/foo/./foo1";
    auto result = network::url::CoalesceDirs(path);
    CHECK(result.has_value());
    CHECK(std::string(path) == "/foo/foo1");
  }
  {
    char path[] = "/foo/foo1/..";
    auto result = network::url::CoalesceDirs(path);
    CHECK(result.has_value());
    CHECK(std::string(path) == "/foo/");
    // lastSlash is the index of the last '/' before any '?' or '#', which for
    // "/foo/" is the trailing slash itself (index 4); endOfBasename is the
    // length of the path without query/ref.
    CHECK(result->lastSlash == 4);
    CHECK(result->endOfBasename == 5);
  }
  {
    char path[] = "/foo/foo1/.";
    auto result = network::url::CoalesceDirs(path);
    CHECK(result.has_value());
    CHECK(std::string(path) == "/foo/foo1/");
  }
  {
    // %2e%2e between slashes is a ".." too
    char path[] = "/foo/%2e%2e/bar";
    auto result = network::url::CoalesceDirs(path);
    CHECK(result.has_value());
    CHECK(std::string(path) == "/bar");
  }
  {
    // the path must start with a slash
    char path[] = "foo/bar";
    CHECK(!network::url::CoalesceDirs(path).has_value());
  }
}

void TestParseFileURL() {
  std::string directory, baseName, extension;

  CHECK(network::url::ParseFileURL("file:///foo/bar.txt", directory, baseName,
                                   extension) == Result::Ok);
  CHECK(directory == "/foo/");
  CHECK(baseName == "bar");
  CHECK(extension == "txt");

  CHECK(network::url::ParseFileURL("file:///foo/bar/", directory, baseName,
                                   extension) == Result::Ok);
  CHECK(directory == "/foo/bar/");
  CHECK(baseName.empty());
  CHECK(extension.empty());

  // not a file:// url
  CHECK(network::url::ParseFileURL("http://www.foo.com/bar.txt", directory,
                                   baseName,
                                   extension) == Result::ErrorUnexpected);

  // no scheme at all
  CHECK(network::url::ParseFileURL("1foo/bar.txt", directory, baseName,
                                   extension) == Result::ErrorMalformedUri);
}

void TestParseContentType() {
  std::string type, charset;
  bool hadCharset = true;

  // plain media type
  network::url::ParseContentType("text/html", type, charset, &hadCharset);
  CHECK(type == "text/html");
  CHECK(charset.empty());
  CHECK(!hadCharset);

  // the type is lower-cased, surrounding LWS is dropped
  type.clear();
  charset.clear();
  network::url::ParseContentType("  TEXT/HTML  ", type, charset, &hadCharset);
  CHECK(type == "text/html");

  // charset parameter
  type.clear();
  charset.clear();
  network::url::ParseContentType("text/html; charset=ISO-8859-1", type, charset,
                                 &hadCharset);
  CHECK(type == "text/html");
  CHECK(charset == "ISO-8859-1");
  CHECK(hadCharset);

  // quoted-string charset: the quotes are removed
  type.clear();
  charset.clear();
  network::url::ParseContentType("text/html; charset=\"ISO-8859-1\"", type,
                                 charset, &hadCharset);
  CHECK(type == "text/html");
  CHECK(charset == "ISO-8859-1");
  CHECK(hadCharset);

  // later media types replace an earlier different one (same-type entries
  // only update the charset), so this ends up as text/plain
  type.clear();
  charset.clear();
  network::url::ParseContentType("text/html, text/plain; charset=utf-8", type,
                                 charset, &hadCharset);
  CHECK(type == "text/plain");
  CHECK(charset == "utf-8");
  CHECK(hadCharset);

  // a charset anywhere in the list still counts
  type.clear();
  charset.clear();
  network::url::ParseContentType("text/html,text/html; charset=ISO-8859-1",
                                 type, charset, &hadCharset);
  CHECK(type == "text/html");
  CHECK(charset == "ISO-8859-1");
  CHECK(hadCharset);

  // commas inside a quoted string do not split the media type
  type.clear();
  charset.clear();
  network::url::ParseContentType("text/html; charset=\"a,b\"", type, charset,
                                 &hadCharset);
  CHECK(type == "text/html");
  CHECK(charset == "a,b");

  // "*/*" is meaningless and therefore not stored
  type.clear();
  charset.clear();
  network::url::ParseContentType("*/*", type, charset, &hadCharset);
  CHECK(type.empty());

  // no slash -> not a media type
  type.clear();
  charset.clear();
  network::url::ParseContentType("text", type, charset, &hadCharset);
  CHECK(type.empty());

  // the overload carrying the charset parameter positions
  type.clear();
  charset.clear();
  int32_t charsetStart = -1, charsetEnd = -1;
  network::url::ParseContentType("text/html;charset=ISO-8859-1", type, charset,
                                 &hadCharset, &charsetStart, &charsetEnd);
  CHECK(type == "text/html");
  CHECK(charset == "ISO-8859-1");
  CHECK(charsetStart == 9);
  CHECK(charsetEnd == 29);

  // without a charset parameter both positions point at the ';' of the
  // current media type (or at its end when there is none)
  type.clear();
  charset.clear();
  network::url::ParseContentType("text/html", type, charset, &hadCharset,
                                 &charsetStart, &charsetEnd);
  CHECK(type == "text/html");
  CHECK(charsetStart == 8);
  CHECK(charsetEnd == 8);
}

void TestParseRequestContentType() {
  std::string type, charset;
  bool hadCharset = true;

  network::url::ParseRequestContentType("text/html; charset=UTF-8", type,
                                        charset, &hadCharset);
  CHECK(type == "text/html");
  CHECK(charset == "UTF-8");
  CHECK(hadCharset);

  network::url::ParseRequestContentType("application/octet-stream", type,
                                        charset, &hadCharset);
  CHECK(type == "application/octet-stream");
  CHECK(charset.empty());
  CHECK(!hadCharset);

  // a request Content-Type must hold a single media type
  type = "x";
  charset = "y";
  network::url::ParseRequestContentType("text/html, text/plain", type, charset,
                                        &hadCharset);
  CHECK(type.empty());
  CHECK(charset.empty());
  CHECK(!hadCharset);

  // strictness: junk after the media type itself rejects the whole header
  // (here there is no ';' so nothing is consumed past "text/html")
  type.clear();
  charset.clear();
  network::url::ParseRequestContentType("text/html junk", type, charset,
                                        &hadCharset);
  CHECK(type.empty());
}

}  // namespace

int main() {
  TestSchemeHelpers();
  TestIPv4Helper();
  TestIPv6Helper();
  TestStdUrlParserParseURL();
  TestAuthUrlParser();
  TestNoAuthUrlParser();
  TestParsePath();
  TestParseFilePath();
  TestParseFileName();
  TestExtractURLScheme();
  TestIsAbsoluteURL();
  TestFilterURIString();
  TestCharacterHelpers();
  TestIsValidDNSHost();
  TestCoalesceDirs();
  TestParseFileURL();
  TestParseContentType();
  TestParseRequestContentType();

  if (gFailures != 0) {
    std::fprintf(stderr, "%d check(s) failed\n", gFailures);
    return 1;
  }
  std::printf("network_url_test: all checks passed\n");
  return 0;
}
