#ifndef GENISYS_BLOCK_FROM_UTXO_BLOCK_H
#define GENISYS_BLOCK_FROM_UTXO_BLOCK_H

#include "main.h"
#include "utils/Utils.h"

class Block {
public:
    byte magic[4];
    int size;
    byte header[80];

    Block(FILE* filePointer);

    bool isMagicValid();
};


#endif //GENISYS_BLOCK_FROM_UTXO_BLOCK_H
