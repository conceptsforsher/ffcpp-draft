add_executable(style_test style_test.cpp)
target_link_libraries(style_test PRIVATE style)
target_compile_features(style_test PRIVATE cxx_std_20)
add_test(NAME style_test COMMAND style_test)

add_executable(network_url_test network_url_test.cpp)
target_link_libraries(network_url_test PRIVATE network)
target_compile_features(network_url_test PRIVATE cxx_std_20)
add_test(NAME network_url_test COMMAND network_url_test)
