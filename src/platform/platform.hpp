/* MPL 2.0 */
#pragma once
#include "widget/widget_base.hpp"
#include <vector>
#include <string>
#include <functional>
namespace platform {
class FileIO { public: FileIO(); ~FileIO(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class FontManager { public: FontManager(); ~FontManager(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class ClipboardManager { public: ClipboardManager(); ~ClipboardManager(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class DragDropManager { public: DragDropManager(); ~DragDropManager(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class ScreenManager { public: ScreenManager(); ~ScreenManager(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class DisplayInfo { public: DisplayInfo(); ~DisplayInfo(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class CursorManager { public: CursorManager(); ~CursorManager(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class ThemeProvider { public: ThemeProvider(); ~ThemeProvider(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class MimeTypeRegistry { public: MimeTypeRegistry(); ~MimeTypeRegistry(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class DesktopIntegration { public: DesktopIntegration(); ~DesktopIntegration(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class NotificationManager { public: NotificationManager(); ~NotificationManager(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class PowerManager { public: PowerManager(); ~PowerManager(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class SessionManager { public: SessionManager(); ~SessionManager(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class LocaleManager { public: LocaleManager(); ~LocaleManager(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
class PathResolver { public: PathResolver(); ~PathResolver(); bool init(); bool shutdown(); private: std::string data_; int handle_=-1; };
} // namespace platform
