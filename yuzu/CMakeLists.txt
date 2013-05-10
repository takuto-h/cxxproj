
include_directories(${yuzu_SOURCE_DIR})
include_directories(${gc_SOURCE_DIR}/include)

add_definitions(
  -g -std=c++11 -pedantic -Werror -Wall -Wextra -Weffc++ -Wno-unused-parameter
)

add_executable(yuzu main)
target_link_libraries(yuzu gc-lib)
