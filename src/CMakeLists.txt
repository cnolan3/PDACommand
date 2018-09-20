# Author: Connor Nolan

set(libs pda_lib fa_lib)

add_subdirectory(pda)
add_subdirectory(fa)

add_executable(pda main.cpp)

target_link_libraries(pda ${libs})

set_target_properties(pda PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
