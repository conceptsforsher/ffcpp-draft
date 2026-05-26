/* MPL 2.0 */
#pragma once
#include <string>
#include <vector>
#include <map>
#include <cstdint>
namespace ipc {
class IPCMessage { public: IPCMessage(); ~IPCMessage(); bool init(); void shutdown(); private: int state_=0; std::string name_; };
class IPCChannel { public: IPCChannel(); ~IPCChannel(); bool init(); void shutdown(); private: int state_=0; std::string name_; };
class SharedMemory { public: SharedMemory(); ~SharedMemory(); bool create(size_t size); void destroy(); uint8_t* data(); size_t size() const; private: uint8_t* data_=nullptr; size_t size_=0; int state_=0; };
class ProcessManager { public: ProcessManager(); ~ProcessManager(); bool init(); void shutdown(); int spawn(const std::string& type, const std::vector<std::string>& args={}); bool kill(int pid); private: int next_pid_=1; std::map<int,std::string> processes_; int state_=0; };
class SandboxEngine { public: SandboxEngine(); ~SandboxEngine(); bool init(); void shutdown(); bool enable_seccomp(); private: int state_=0; std::string name_; };
class SeccompFilter { public: SeccompFilter(); ~SeccompFilter(); void allow_syscall(const std::string&) {} void deny_syscall(const std::string&) {} bool apply() { return true; } private: int state_=0; };
class NamespaceIsolator { public: NamespaceIsolator(); ~NamespaceIsolator(); bool init(); void shutdown(); private: int state_=0; };
class CapabilityManager { public: CapabilityManager(); ~CapabilityManager(); bool init(); void shutdown(); private: int state_=0; };
class ProcessPool { public: ProcessPool(); ~ProcessPool(); bool init(); void shutdown(); private: int state_=0; };
class ContentProcess { public: ContentProcess(); ~ContentProcess(); bool init(); void shutdown(); private: int state_=0; };
class GPUProcess { public: GPUProcess(); ~GPUProcess(); bool init(); void shutdown(); private: int state_=0; };
class NetworkProcess { public: NetworkProcess(); ~NetworkProcess(); bool init(); void shutdown(); private: int state_=0; };
class PluginProcess { public: PluginProcess(); ~PluginProcess(); bool init(); void shutdown(); private: int state_=0; };
class ExtensionProcess { public: ExtensionProcess(); ~ExtensionProcess(); bool init(); void shutdown(); private: int state_=0; };
class MessageRouter { public: MessageRouter(); ~MessageRouter(); bool init(); void shutdown(); private: int state_=0; };
class SerializationEngine { public: SerializationEngine(); ~SerializationEngine(); bool init(); void shutdown(); private: int state_=0; };
class FileDescriptor { public: FileDescriptor(); ~FileDescriptor(); bool init(); void shutdown(); private: int state_=0; };
class EventFD { public: EventFD(); ~EventFD(); bool init(); void shutdown(); private: int state_=0; };
class MemFD { public: MemFD(); ~MemFD(); bool init(); void shutdown(); private: int state_=0; };
} // namespace ipc
