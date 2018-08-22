#ifndef GENISYS_BLOCK_FROM_UTXO_TRANSACTIONINPUT_H
#define GENISYS_BLOCK_FROM_UTXO_TRANSACTIONINPUT_H

#include "../main.h"

// Формат входа:
// 32  байта  - хеш предыдущей транзакции
// 4   байта  - номер выхода у предыдущей транзакции
// 1-9 байта  - длина скрипта
// много байт - скрипт
// 4 байта    - sequence number
class TransactionInput {
public:
    byte hashPreviousTrans[32];
    size_t indexPreviousTrans;

    size_t scriptSize;

    explicit TransactionInput(FILE* filePointer);
};


#endif //GENISYS_BLOCK_FROM_UTXO_TRANSACTIONINPUT_H
