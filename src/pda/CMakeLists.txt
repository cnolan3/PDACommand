# Author: Connor Nolan

set(sources pda.cpp pda_stack.cpp trans_func.cpp)

add_library(pda_lib ${sources})

add_subdirectory(unit_tests)
