set(STYLE_SOURCES
    stylist.cpp properties/properties.cpp properties/properties_serialize.cpp
    matching/matching.cpp color/convert.cpp rule_tree/rule_tree.cpp
    custom_properties.cpp sharing/sharing.cpp driver/driver.cpp
    invalidation/invalidation.cpp
    style_adjuster.cpp
    traversal/traversal.cpp
)
add_library(style STATIC ${STYLE_SOURCES})
target_include_directories(style PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_compile_features(style PUBLIC cxx_std_20)
target_compile_options(style PRIVATE -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(style PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(style PRIVATE -fsanitize=address,undefined)
endif()
