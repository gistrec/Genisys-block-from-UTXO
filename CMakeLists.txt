cmake_minimum_required(VERSION 3.9)
project(Genisys_block_from_UTXO)

set(CMAKE_CXX_STANDARD 11)

add_executable(Genisys_block_from_UTXO main.cpp Block.cpp Block.h utils/Utils.cpp utils/Utils.h main.h)