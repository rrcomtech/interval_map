cmake_minimum_required(VERSION 3.0)

project(ThinkCellHomework)

set(
	CMAKE_CXX_STANDARD 17
	CMAKE_CXX_STANDARD_REQUIRED ON
)

enable_testing()

add_executable(homework
	src/main.cpp
	src/data-structure.hpp
	src/data-structure.cpp
)

add_executable(homework-tests
	src/test.cpp
	src/data-structure.hpp
	src/data-structure.cpp
)

target_link_libraries(homework-tests
	GTest::gtest_main
)

include(GoogleTest)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/9ff2450a56aed4f7f124f5104d9e3088bf791ee9.zip
)

FetchContent_MakeAvailable(googletest)
