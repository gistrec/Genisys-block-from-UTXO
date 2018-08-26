#include "../src/transactions/TransactionInput.h"

class TransactionTest : public ::testing::Test {
public:
    Block *block;
    FILE *file;

    TransactionTest() : block(nullptr), file(nullptr) {};

    void SetUp() override {
        file = fopen("./tests/blocks/first.dat", "r");

        if (file == NULL) {
            cout << "Не найден файл first.dat" << endl;
            ASSERT_EQ(0, 1);
        }

        block = new Block(file);

        ASSERT_EQ(true, block->isMagicValid());
        // Читаем весь блок
        block->read(file);
    }

    void TearDown() override {
        delete block;
        fclose(file);
    }
};

// Тестируем сборку транзакции
TEST_F(TransactionTest, getSourceBytes) {
    // Получаем первую транзакцию
    Transaction* transaction = block->getTransactions()[0];

    TransactionInput* input = transaction->getInputs()[0];
    ASSERT_EQ(input->getHashPreviousTrans(), vector<byte>(32, 0x00));

    vector<byte> bytes = input->getSourceBytes();
    // Не стоило пихать сюда ~100 байтов, но что поделать
    vector<byte> need = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x4D, 0x04, 0xFF, 0xFF, 0x00, 0x1D, 0x01, 0x04, 0x45, 0x54, 0x68, 0x65, 0x20, 0x54, 0x69, 0x6D, 0x65, 0x73, 0x20, 0x30, 0x33, 0x2F, 0x4A, 0x61, 0x6E, 0x2F, 0x32, 0x30, 0x30, 0x39, 0x20, 0x43, 0x68, 0x61, 0x6E, 0x63, 0x65, 0x6C, 0x6C, 0x6F, 0x72, 0x20, 0x6F, 0x6E, 0x20, 0x62, 0x72, 0x69, 0x6E, 0x6B, 0x20, 0x6F, 0x66, 0x20, 0x73, 0x65, 0x63, 0x6F, 0x6E, 0x64, 0x20, 0x62, 0x61, 0x69, 0x6C, 0x6F, 0x75, 0x74, 0x20, 0x66, 0x6F, 0x72, 0x20, 0x62, 0x61, 0x6E, 0x6B, 0x73, 0xFF, 0xFF, 0xFF, 0xFF};
    ASSERT_EQ(bytes, need);
}