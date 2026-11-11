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
#include <string_view>

namespace network::url {

// translation of rust_net_is_valid_scheme_char / is_valid_scheme_char
bool IsValidSchemeChar(unsigned char aChar);

// translation of net_IsValidScheme (rust_net_is_valid_scheme)
bool IsValidScheme(std::string_view scheme);

// translation of net_IsValidIPv4Addr (rust_net_is_valid_ipv4_addr)
bool IsValidIPv4Addr(std::string_view addr);

// translation of net_IsValidIPv6Addr (rust_net_is_valid_ipv6_addr)
bool IsValidIPv6Addr(std::string_view addr);

}  // namespace network::url
