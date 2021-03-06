#ifndef GENISYS_BLOCK_FROM_UTXO_TEST_H
#define GENISYS_BLOCK_FROM_UTXO_TEST_H

#include <gtest/gtest.h>
#include <math.h>

#include "./utils.cpp"
#include "./sha256.cpp"
#include "./container.cpp"
#include "./transaction.cpp"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif //GENISYS_BLOCK_FROM_UTXO_TEST_H