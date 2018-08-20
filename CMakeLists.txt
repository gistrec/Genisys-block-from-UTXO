cmake_minimum_required(VERSION 3.9)
project(Genisys_block_from_UTXO)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(SOURCE_FILES
        src/main.cpp
        src/Block.cpp
        src/utils/Utils.cpp)

add_executable(genisys_creator ${SOURCE_FILES})


add_executable(run_tests tests/test.cpp)
target_link_libraries(run_tests ${GTEST_LIBRARIES} Threads::Threads)
enable_testing()
add_test(run_tests "tests/test.cpp")