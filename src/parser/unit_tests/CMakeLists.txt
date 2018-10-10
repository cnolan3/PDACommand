# Author: Connor Nolan

set(tsources grammar_test.cpp parse_table_test.cpp)

add_executable(parser_test ${tsources})
target_link_libraries(parser_test parser_lib gmock_main)

add_test(parser_test parser_test)
