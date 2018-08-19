#include "Block.h"

Block::Block(FILE* filePointer) {
    // Считываем Magic number
    fread(magic, sizeof(byte), 4, filePointer);
}

bool Block::read(FILE *filePointer) {
    // Считываем размер блока
    byte buf[4];
    fread(buf, sizeof(byte), 4, filePointer);
    blockSize = (size_t) getIntFromBytes((byte*) &buf);

    // Считываем весь блок
    blockData = new byte[blockSize];
    fread(blockData, sizeof(byte), (size_t) blockSize, filePointer);
}

bool Block::isMagicValid() {
    return magic[0] == 0xf9 &&
           magic[1] == 0xbe &&
           magic[2] == 0xb4 &&
           magic[3] == 0xd9;
}

Block::~Block() {
    delete [] blockData;
}