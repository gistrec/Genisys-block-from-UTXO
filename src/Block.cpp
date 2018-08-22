#include "Block.h"

Block::Block(FILE* filePointer) {
    // Считываем Magic number
    fread(magic, sizeof(byte), 4, filePointer);

    blockSize = 0;
}

bool Block::read(FILE *filePointer) {
    // Считываем размер блока
    byte buf[9];
    fread(buf, sizeof(byte), 4, filePointer);
    blockSize = getIntFromBytes((byte *) &buf, 4);

    // Считываем заголовок блока
    fread(header, sizeof(byte), 80, filePointer);

    // Считываем количество транзакций
    transactionCount = readVarInt(filePointer);


    // Считываем транзакции
    for (int i = 0; i < transactionCount; i++) {
        Transaction* transaction = new Transaction();
        transaction->read(filePointer);
        transactions.push_back(transaction);
    }
    // size_t transactionSize = blockSize - 4 - 80 - byteCount;
    // transactions = new byte[transactionSize];

    // fread(transactions, sizeof(byte), transactionSize, filePointer);
}

bool Block::isMagicValid() {
    return magic[0] == 0xf9 &&
           magic[1] == 0xbe &&
           magic[2] == 0xb4 &&
           magic[3] == 0xd9;
}

Block::~Block() {
    // delete [] transactions;
}