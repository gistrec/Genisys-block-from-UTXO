cmake_minimum_required(VERSION 3.9)
project(Genisys_block_from_UTXO)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/Block.cpp
        src/utils/Utils.cpp)

add_executable(Genisys_block_from_UTXO ${SOURCE_FILES})