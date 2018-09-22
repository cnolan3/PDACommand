# Author: Connor Nolan

set(tsources pda_stack_test.cpp pda_trans_table_test.cpp pda_test.cpp)

add_executable(pda_test ${tsources})
target_link_libraries(pda_test pda_lib gmock_main)

add_test(pda_test pda_test)
