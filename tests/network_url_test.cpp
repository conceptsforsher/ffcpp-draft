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

  if (gFailures != 0) {
    std::fprintf(stderr, "%d check(s) failed\n", gFailures);
    return 1;
  }
  std::printf("network_url_test: all checks passed\n");
  return 0;
}
