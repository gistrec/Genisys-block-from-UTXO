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

add_executable(GenisysCreator ${SOURCE_FILES})


add_executable(tests tests/test.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} Threads::Threads)
enable_testing()
add_test(test "tests/test.cpp")