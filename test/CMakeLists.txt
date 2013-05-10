
include_directories(${yuzu_SOURCE_DIR})
include_directories(${gc_SOURCE_DIR}/include)
include_directories(${gtest_SOURCE_DIR}/include)

add_definitions(
  -g -std=c++11 -pedantic -Werror -Wall -Wextra -Weffc++ -Wno-unused-parameter
)

add_executable(test_yuzu main)
target_link_libraries(test_yuzu gc-lib)
target_link_libraries(test_yuzu gtest)

add_custom_target(test COMMAND test_yuzu --gtest_color=yes DEPENDS test_yuzu)
