#include "./test.cpp"
#include "../src/Container.h"

class ContainerTest : public ::testing::Test{};

TEST_F(ContainerTest, a) {
    ASSERT_EQ(0, 0);
    Container container;
    Transaction* transaction = (Transaction *) 1;

    ustring key(32, '0');
    container.add(key, transaction);
    ASSERT_EQ(container[key], (Transaction *) 1);
}