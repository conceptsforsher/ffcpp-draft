add_library(compositor STATIC
    compositor.cpp
)
target_include_directories(compositor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_compile_features(compositor PUBLIC cxx_std_20)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(compositor PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(compositor PRIVATE -fsanitize=address,undefined)
endif()
