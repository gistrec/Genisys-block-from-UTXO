#include "./test.cpp"
#include "../src/utils/Utils.h"

class UtilsTest : public ::testing::Test {};

TEST_F(UtilsTest, getIntFromBytes) {
    byte first[1] = {0x00};
    ASSERT_EQ(0, getIntFromBytes(first, 1));

    byte second[2] = {0x00, 0x01};
    ASSERT_EQ(16 * 16, getIntFromBytes(second, 2));

    byte third[4] = {0x01, 0x01, 0x01, 0x00};
    ASSERT_EQ(pow(16, 4) + pow(16, 2) + 1, getIntFromBytes(third, 4));

    byte fourth[4] = {0x00, 0x00, 0x00, 0x10};
    ASSERT_EQ(pow(16, 7), getIntFromBytes(fourth, 4));
}

TEST_F(UtilsTest, getVarInt) {
    // Value < 0xFD
    // No prefix
    byte first[1] = {0x00};
    ASSERT_EQ(make_tuple(0, 1), getVarInt(first));

    byte second[1] = {0x08};
    ASSERT_EQ(make_tuple(8, 1), getVarInt(second));

    byte third[1] = {0xfc};
    ASSERT_EQ(make_tuple(252, 1), getVarInt(third));

    // Value <= 0xFFFF
    // 0xFD prefix
    byte fourth[3] = {0xfd, 0x00, 0x00};
    ASSERT_EQ(make_tuple(0, 3), getVarInt(fourth));

    byte fifth[3] = {0xfd, 0xff, 0xff};
    ASSERT_EQ(make_tuple(65535, 3), getVarInt(fifth));

    // Value <= 0xFFFF FFFF
    // 0xFE prefix
    byte sixth[5] = {0xfe, 0x00, 0x00, 0x00, 0x00};
    ASSERT_EQ(make_tuple(0, 5), getVarInt(sixth));

    byte seventh[5] = {0xfe, 0xff, 0xff, 0xff, 0xff};
    ASSERT_EQ(make_tuple(4294967295, 5), getVarInt(seventh));

    // Value -
    // 0xFF prefix seventh
    byte eighth[9] = {0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    ASSERT_EQ(make_tuple(0, 9), getVarInt(eighth));

    byte ninth[9] = {0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00};
    ASSERT_EQ(make_tuple(16777215, 9), getVarInt(ninth));

    byte tenth[9] = {0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff};
    ASSERT_EQ(make_tuple(18446744069414649856U, 9), getVarInt(tenth));
}