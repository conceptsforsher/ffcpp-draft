# QuickJS integration — C wrapper + C++ engine
#
# The pre-compiled QuickJS checkout this module was developed against lives
# outside of this repository, so its location is configurable and every piece
# that needs it is skipped when it is absent.  That keeps configuring (and
# building the modules that do not use QuickJS) working on a clean machine,
# which is what CI does.
set(QUICKJS_DIR "" CACHE PATH "Path to a QuickJS checkout (quickjs.h + libquickjs.a)")
if(QUICKJS_DIR STREQUAL "")
    set(QUICKJS_DIR /home/bym/ff/quickjs)
endif()

# C++ JS engine
add_library(js STATIC js_engine.cpp)
target_include_directories(js PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_compile_features(js PUBLIC cxx_std_20)

if(EXISTS ${QUICKJS_DIR}/quickjs.h)
    # C wrapper (avoids C++/C incompatibilities with QuickJS struct mode)
    add_library(quickjs_wrapper STATIC quickjs_c_wrapper.c)
    target_include_directories(quickjs_wrapper PUBLIC ${QUICKJS_DIR})
    target_compile_options(quickjs_wrapper PRIVATE -O2 -D_GNU_SOURCE -DCONFIG_VERSION="2025-09-13")

    # Pre-compiled QuickJS static library
    add_library(quickjs STATIC IMPORTED)
    set_target_properties(quickjs PROPERTIES
        IMPORTED_LOCATION ${QUICKJS_DIR}/build_obj/libquickjs.a
        INTERFACE_INCLUDE_DIRECTORIES ${QUICKJS_DIR}
    )

    target_link_libraries(js PUBLIC quickjs_wrapper quickjs)
else()
    message(STATUS
        "QuickJS not found at ${QUICKJS_DIR} - building src/js without the "
        "QuickJS backend. Set -DQUICKJS_DIR=<path> to enable it.")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(js PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_compile_options(quickjs_wrapper PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(js PRIVATE -fsanitize=address,undefined)
endif()
