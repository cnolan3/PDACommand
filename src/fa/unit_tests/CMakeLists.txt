# Author: Connor Nolan

set(tsources fa_test.cpp)

add_executable(fa_test ${tsources})
target_link_libraries(fa_test fa_lib gmock_main)

add_test(fa_test fa_test)
