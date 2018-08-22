cmake_minimum_required(VERSION 3.9)
project(Genisys_block_from_UTXO)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(ADDITIONAL_FILES
        src/Block.cpp
        src/utils/Utils.cpp
        src/transactions/Transaction.cpp
        src/transactions/TransactionInput.cpp
        src/transactions/TransactionOutput.cpp)

add_executable(genisys_creator src/main.cpp ${ADDITIONAL_FILES})


add_executable(run_tests tests/test.cpp ${ADDITIONAL_FILES})
target_link_libraries(run_tests ${GTEST_LIBRARIES} Threads::Threads)
enable_testing()
add_test(run_tests "tests/test.cpp")