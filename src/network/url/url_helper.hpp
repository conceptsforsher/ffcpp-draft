/* MPL 2.0 - network/url
 *
 * C++ translation of:
 *   - netwerk/base/nsURLHelper.cpp
 *       net_IsValidScheme, net_IsValidIPv4Addr, net_IsValidIPv6Addr
 *   - netwerk/base/rust-helper/src/lib.rs
 *       is_valid_scheme, is_valid_scheme_char,
 *       is_valid_ipv4_addr, is_valid_ipv6_addr
 *
 * In Gecko the nsURLHelper entry points above are thin wrappers around the
 * Rust helpers shipped in netwerk/base/rust-helper.  Because this port must not
 * depend on Rust, the Rust implementations are translated here line for line,
 * so the C++ code keeps Gecko's acceptance rules for schemes and IP literals.
 */
#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>

#include "network/url/url_parser.hpp"

namespace network::url {

// translation of rust_net_is_valid_scheme_char / is_valid_scheme_char
bool IsValidSchemeChar(unsigned char aChar);

// translation of net_IsValidScheme (rust_net_is_valid_scheme)
bool IsValidScheme(std::string_view scheme);

// translation of net_IsValidIPv4Addr (rust_net_is_valid_ipv4_addr)
bool IsValidIPv4Addr(std::string_view addr);

// translation of net_IsValidIPv6Addr (rust_net_is_valid_ipv6_addr)
bool IsValidIPv6Addr(std::string_view addr);

// translation of net_ToLowerCase / net_FindCharInSet /
// net_FindCharNotInSet / net_RFindCharNotInSet
char* ToLowerCase(char* str, uint32_t length);
char* ToLowerCase(char* str);
char* FindCharInSet(const char* iter, const char* stop, const char* set);
char* FindCharNotInSet(const char* iter, const char* stop, const char* set);
char* RFindCharNotInSet(const char* stop, const char* iter, const char* set);

// translation of net_ExtractURLScheme
Result ExtractURLScheme(std::string_view inUri, std::string& scheme);

// translation of net_IsAbsoluteURL
bool IsAbsoluteURL(std::string_view uri);

// translation of net_FilterURIString
void FilterURIString(std::string_view input, std::string& result);

// translation of HostIsIPLiteral (used by net_IsValidDNSHost)
bool HostIsIPLiteral(std::string_view host);

// translation of net_IsValidDNSHost
bool IsValidDNSHost(std::string_view host);

// translation of the Maybe<CompactPair<uint32_t, uint32_t>> returned by
// net_CoalesceDirs.  The pair is (position of the last slash before the query
// or ref, end of the basename).
struct CoalescedPath {
  uint32_t lastSlash;
  uint32_t endOfBasename;
};

// translation of net_CoalesceDirs.  `path` is modified in place; it must start
// with '/'.  The optional is empty when the precondition is violated.
std::optional<CoalescedPath> CoalesceDirs(char* path);

// translation of net_ParseFileURL
Result ParseFileURL(std::string_view inUrl, std::string& outDirectory,
                    std::string& outFileBaseName,
                    std::string& outFileExtension);

}  // namespace network::url
