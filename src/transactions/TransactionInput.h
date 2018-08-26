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
private:
    byte hashPreviousTrans[32];
    size_t indexPreviousTrans;

    size_t scriptSize;
    byte* script;

    size_t sequence_number;

public:
    explicit TransactionInput(FILE* filePointer);

    /**
     * Получить хэш предыдущей транзакции
     * @return vector<byte> длинной 32 байта
     */
    std::vector<byte> getHashPreviousTrans();
    size_t getIndexPreviousTrans();

    /**
     * Получить изначальную последовательность байт,
     * которые соответствуют этому выходу
     */
    std::vector<byte> getSourceBytes();
};


#endif //GENISYS_BLOCK_FROM_UTXO_TRANSACTIONINPUT_H
