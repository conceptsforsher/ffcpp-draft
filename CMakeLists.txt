cmake_minimum_required(VERSION 3.22)
project(firefox-cpp VERSION 130.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

option(BUILD_HEADLESS "Build headless browser" OFF)
option(BUILD_FULL_BROWSER "Build full GUI browser" ON)
option(BUILD_TESTS "Build test suite" OFF)
option(USE_SANITIZERS "Enable AddressSanitizer and UBSan" ON)

find_package(PkgConfig)
if(PkgConfig_FOUND)
    pkg_check_modules(GLIB glib-2.0)
endif()

# Core rendering engines
add_subdirectory(src/style)
add_subdirectory(src/webrender)
add_subdirectory(src/dom)
add_subdirectory(src/js)

# Full browser components
add_subdirectory(src/widget)
add_subdirectory(src/chrome)
add_subdirectory(src/network)
add_subdirectory(src/compositor)
add_subdirectory(src/ipc)
add_subdirectory(src/platform)
add_subdirectory(src/browser)

if(USE_SANITIZERS AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()
