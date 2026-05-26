# Firefox-CPP: Complete C++ Translation of Mozilla Firefox

## Architecture

This project translates Firefox/Gecko into a pure C++ codebase.
Strategy:
- SpiderMonkey (JS engine): Keep existing C++ (already C++)
- DOM, Layout, Networking: Keep existing C++ code
- Stylo (CSS): Translate from servo/components/style Rust → C++
- WebRender: Translate from gfx/wr Rust → C++
- encoding_rs: Translate from Rust → C++
- neqo (HTTP/3): Translate from Rust → C++
- Browser UI (browser/, toolkit/): Translate from JS/HTML → C++
- Build system: Convert moz.build/Python → CMake

## Target
- Headless mode: Full browser functionality without GUI
- Modern JS support (ES2024+)
- Passes browser functionality tests
- No memory leaks (ASan/UBSan clean)

## Reference
- gecko-dev (Mozilla Firefox source)
