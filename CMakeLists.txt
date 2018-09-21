cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(clex)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

enable_testing()

set(GMOCK_DIR "libs/googletest-master/googlemock")
set(GTEST_DIR "libs/googletest-master/googletest")

add_subdirectory(${GMOCK_DIR} ${GTEST_DIR})

include_directories(SYSTEM ${GMOCK_DIR}/include ${GTEST_DIR}/include)


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	#set(warnings "-Wall -Wextra -Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	#set(warnings "/W4 /WX /EHsc")
endif()

if(NOT CONFIGURED_ONCE)
	set(CMAKE_CXX_FLAGS "${warnings}"
		CACHE STRING "Compiler flags for all build types." FORCE)
	set(CMAKE_C_FLAGS "${warnings}"
		CACHE STRING "Compiler flags for all build types." FORCE)
endif()

add_subdirectory(src)
