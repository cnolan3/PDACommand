# Author: Connor Nolan

set(sources fa.cpp fa_trans_table.cpp)

add_library(fa_lib ${sources})

add_subdirectory(unit_tests)
