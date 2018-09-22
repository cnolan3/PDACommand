# Author: Connor Nolan

set(sources pda.cpp pda_stack.cpp pda_trans_table.cpp)

add_library(pda_lib ${sources})

add_subdirectory(unit_tests)
