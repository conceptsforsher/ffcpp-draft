add_library(network STATIC
    network.cpp
    url/url_helper.cpp
    url/url_parser.cpp
)
target_include_directories(network PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_compile_features(network PUBLIC cxx_std_20)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(network PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(network PRIVATE -fsanitize=address,undefined)
endif()
