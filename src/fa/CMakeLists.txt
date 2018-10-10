# Author: Connor Nolan

set(sources fa.cpp fa_trans_table.cpp fa_alpha.cpp)

add_library(fa_lib ${sources})

add_subdirectory(unit_tests)
