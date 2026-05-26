add_library(chrome STATIC
    chrome.cpp
    nav/nav_buttons.cpp
    bookmarks/bookmarks.cpp
)
target_include_directories(chrome PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_compile_features(chrome PUBLIC cxx_std_20)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(chrome PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(chrome PRIVATE -fsanitize=address,undefined)
endif()
