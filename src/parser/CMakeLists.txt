# Author: Connor Nolan

set(sources parse_table.cpp parse_funcs.cpp grammar.cpp)

add_library(parser_lib ${sources})

add_subdirectory(unit_tests)
