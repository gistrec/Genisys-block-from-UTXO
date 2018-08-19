#include "Block.h"

Block::Block(FILE* filePointer) {
    // Считываем Magic number
    fread(magic, sizeof(byte), 4, filePointer);

    if (isMagicValid()) {
        // Считываем размер блока
        byte buf[4];
        fread(buf, sizeof(byte), 4, filePointer);
        size = getIntFromBytes((byte*) &buf);

        // Считываем заголовок
        fread(header, sizeof(byte), 80, filePointer);

    }

}

bool Block::isMagicValid() {
    return magic[0] == 0xf9 && magic[1] == 0xbe &&
           magic[2] == 0xb4 && magic[3] == 0xd9;
}
