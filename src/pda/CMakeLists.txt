# Author: Connor Nolan

set(sources pda_stack.cpp pda_trans_table.cpp pda.cpp)

add_library(pda_lib ${sources})

add_subdirectory(unit_tests)
