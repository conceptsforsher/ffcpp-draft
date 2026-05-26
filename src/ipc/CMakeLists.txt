add_library(ipc STATIC
    ipc.cpp
)
target_include_directories(ipc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_compile_features(ipc PUBLIC cxx_std_20)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(ipc PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(ipc PRIVATE -fsanitize=address,undefined)
endif()
