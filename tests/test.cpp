#ifndef GENISYS_BLOCK_FROM_UTXO_TEST_H
#define GENISYS_BLOCK_FROM_UTXO_TEST_H

#include <gtest/gtest.h>
#include <math.h>

#include "../src/utils/Utils.h"

class CustomTest : public ::testing::Test {
public:
    // Инициализировать приватные переменные
    CustomTest() = default;
    // Отчищать приватные переменные
    ~CustomTest() = default;

    // Вызывается перед каждым тестом
    void SetUp() {};
    // Вызывается после каждого теста
    void TearDown() {}

protected:
    /* Еще нету */
};

TEST_F(CustomTest, getIntFromBytes) {
    byte first[1] = {0x00};
    ASSERT_EQ(0, getIntFromBytes(first, 1));

    byte second[2] = {0x00, 0x01};
    ASSERT_EQ(16 * 16, getIntFromBytes(second, 2));

    byte third[4] = {0x01, 0x01, 0x01, 0x00};
    ASSERT_EQ(pow(16, 4) + pow(16, 2) + 1, getIntFromBytes(third, 4));

    byte fourth[4] = {0x00, 0x00, 0x00, 0x10};
    ASSERT_EQ(pow(16, 7), getIntFromBytes(fourth, 4));
}

/*TEST_F(CustomTest, getVarInt) {
    byte first[4] = {0x00, 0x00, 0x00, 0x00};
    ASSERT_EQ(0, getVarInt(first));

    byte second[4] = {0x00, 0x01, 0x00, 0x00};
    ASSERT_EQ(16 * 16, getVarInt(second));

    byte third[4] = {0x01, 0x01, 0x01, 0x00};
    ASSERT_EQ(pow(16, 4) + pow(16, 2) + 1, getVarInt(third));

    byte fourth[4] = {0x00, 0x00, 0x00, 0x10};
    ASSERT_EQ(pow(16, 7), getVarInt(fourth));
}*/

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


#endif //GENISYS_BLOCK_FROM_UTXO_TEST_H
