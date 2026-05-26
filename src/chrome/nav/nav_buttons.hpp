/* MPL 2.0 */
#pragma once
#include "chrome/chrome.hpp"
namespace chrome {
class BackButton : public Widget { public: BackButton(); ~BackButton() override; };
class ForwardButton : public Widget { public: ForwardButton(); ~ForwardButton() override; };
class ReloadButton : public Widget { public: ReloadButton(); ~ReloadButton() override; };
class HomeButton : public Widget { public: HomeButton(); ~HomeButton() override; };
class StopButton : public Widget { public: StopButton(); ~StopButton() override; };
class ZoomControl : public Widget { public: ZoomControl(); ~ZoomControl() override; };
class ReaderButton : public Widget { public: ReaderButton(); ~ReaderButton() override; };
class BookmarkStar : public Widget { public: BookmarkStar(); ~BookmarkStar() override; };
class DownloadButton : public Widget { public: DownloadButton(); ~DownloadButton() override; };
class ExtensionsButton : public Widget { public: ExtensionsButton(); ~ExtensionsButton() override; };
class AccountButton : public Widget { public: AccountButton(); ~AccountButton() override; };
class MenuButton : public Widget { public: MenuButton(); ~MenuButton() override; };
} // namespace chrome
