add_library(widget STATIC
    widget_base.cpp
    primitives/primitives.cpp
    containers/containers.cpp
    layouts/layouts.cpp
    themes/themes.cpp
    dialogs/dialogs.cpp
    text/text.cpp
    scrolling/scrolling.cpp
    events/events.cpp
)
target_include_directories(widget PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_compile_features(widget PUBLIC cxx_std_20)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(widget PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(widget PRIVATE -fsanitize=address,undefined)
endif()
