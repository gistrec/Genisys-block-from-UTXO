#ifndef GENISYS_BLOCK_FROM_UTXO_BLOCK_H
#define GENISYS_BLOCK_FROM_UTXO_BLOCK_H

#include "main.h"
#include "utils/Utils.h"

class Block {
public:
    byte magic[4];

    size_t blockSize;

    byte* blockData;

    // В конструкторе считываем Magic Number
    explicit Block(FILE* filePointer);

    // Считываем размер блока
    // И потом весь блок
    bool read(FILE* filePointer);

    bool isMagicValid();

    ~Block();
};


#endif //GENISYS_BLOCK_FROM_UTXO_BLOCK_H
