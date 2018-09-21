# Author: Connor Nolan

set(libs pda_lib fa_lib)

add_subdirectory(pda)
add_subdirectory(fa)

add_executable(clex main.cpp)

target_link_libraries(clex ${libs})

set_target_properties(clex PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
