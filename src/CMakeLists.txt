# Author: Connor Nolan

set(libs fa_lib utils_lib parser_lib)

add_subdirectory(fa)
add_subdirectory(util)
add_subdirectory(parser)

add_executable(clex main.cpp)

target_link_libraries(clex ${libs})

set_target_properties(clex PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)
