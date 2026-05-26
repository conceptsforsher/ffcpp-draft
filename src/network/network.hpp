/* MPL 2.0 */
#pragma once
#include <string>
#include <vector>
#include <map>
namespace network {
class HTTP1Client { public: HTTP1Client(); ~HTTP1Client(); bool connect(const std::string& host, int port); bool send(const std::string& data); std::string recv(); void close(); bool connected() const { return connected_; } private: bool connected_=false; std::string host_; int port_=80; };
class HTTP2Client { public: HTTP2Client(); ~HTTP2Client(); bool connect(const std::string& host, int port); bool send(const std::string& data); std::string recv(); void close(); private: bool connected_=false; };
class HTTP3Client { public: HTTP3Client(); ~HTTP3Client(); bool connect(const std::string& host, int port); bool send(const std::string& data); std::string recv(); void close(); private: bool connected_=false; };
class WebSocketClient { public: WebSocketClient(); ~WebSocketClient(); bool connect(const std::string& host, int port); bool send(const std::string& data); std::string recv(); void close(); private: bool connected_=false; };
class TLSConnection { public: TLSConnection(); ~TLSConnection(); bool connect(const std::string& host, int port); bool send(const std::string& data); std::string recv(); void close(); private: bool connected_=false; };
class CookieJar { public: CookieJar(); ~CookieJar(); bool init(); bool shutdown(); private: int state_=0; };
class DNSCache { public: DNSCache(); ~DNSCache(); bool init(); bool shutdown(); private: int state_=0; };
class ProxyResolver { public: ProxyResolver(); ~ProxyResolver(); private: int state_=0; };
class CacheManager { public: CacheManager(); ~CacheManager(); bool init(); bool shutdown(); private: int state_=0; };
class URLParser { public: URLParser(); ~URLParser(); private: int state_=0; };
class HeaderParser { public: HeaderParser(); ~HeaderParser(); private: int state_=0; };
class ChunkedDecoder { public: ChunkedDecoder(); ~ChunkedDecoder(); private: int state_=0; };
class GZipDecompressor { public: GZipDecompressor(); ~GZipDecompressor(); private: int state_=0; };
class BrotliDecompressor { public: BrotliDecompressor(); ~BrotliDecompressor(); private: int state_=0; };
class SSLSessionCache { public: SSLSessionCache(); ~SSLSessionCache(); private: int state_=0; };
class CertVerifier { public: CertVerifier(); ~CertVerifier(); private: int state_=0; };
} // namespace network
