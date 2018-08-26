#include "../src/utils/sha256.h"

class SHA256Test : public ::testing::Test {};

TEST_F(SHA256Test, hash) {
    vector<byte> hash(32);
    vector<byte> result(32);

    string first = "Test";
    result = {0x53, 0x2e, 0xAA, 0xBD, 0x95, 0x74, 0x88, 0x0D,
              0xBF, 0x76, 0xB9, 0xB8, 0xCC, 0x00, 0x83, 0x2C,
              0x20, 0xA6, 0xEC, 0x11, 0x3D, 0x68, 0x22, 0x99,
              0x55, 0x0D, 0x7A, 0x6E, 0x0F, 0x34, 0x5E, 0x25};
    hash256(first.begin(), first.end(), hash.begin(), hash.end());


    string hex_str = bytes_to_hex_string(hash.begin(), hash.end());

    ASSERT_EQ(hex_str, "532eaabd9574880dbf76b9b8cc00832c20a6ec113d682299550d7a6e0f345e25");
}