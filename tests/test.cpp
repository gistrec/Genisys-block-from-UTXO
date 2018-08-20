#ifndef GENISYS_BLOCK_FROM_UTXO_TEST_H
#define GENISYS_BLOCK_FROM_UTXO_TEST_H

#include <gtest/gtest.h>

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

TEST_F(CustomTest, FirstTest) {
    ASSERT_EQ(true, true);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


#endif //GENISYS_BLOCK_FROM_UTXO_TEST_H
