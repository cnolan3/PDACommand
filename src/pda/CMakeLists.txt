# Author: Connor Nolan

set(sources pda.cpp pda_stack.cpp)

add_library(pda_lib ${sources})

add_subdirectory(unit_tests)
