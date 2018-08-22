#ifndef GENISYS_BLOCK_FROM_UTXO_TRANSACTIONOUTPUT_H
#define GENISYS_BLOCK_FROM_UTXO_TRANSACTIONOUTPUT_H

#include "../main.h"

// Формат выхода:
// 8 байт     - количество сатоши для перевода
// 1-9 байт   - длина скрипта
// много байт - скрипт
class TransactionOutput {
public:
    size_t scriptSize;

    explicit TransactionOutput(FILE* filePointer);
};


#endif //GENISYS_BLOCK_FROM_UTXO_TRANSACTIONOUTPUT_H
