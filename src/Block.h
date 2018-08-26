#ifndef GENISYS_BLOCK_FROM_UTXO_BLOCK_H
#define GENISYS_BLOCK_FROM_UTXO_BLOCK_H

#include "main.h"
#include "utils/Utils.h"
#include "transactions/Transaction.h"

class Transaction;

class Block {
private:
    /*
     * Первые четыре байта блока
     * Служат идентификатором начала блока
     */
    byte magic[4];

    /*
     * Размер блока в байтах без учета Magic Number
     */
    size_t blockSize;

    /*
     * Заголовок блока
     */
    byte header[80] = {};

    /*
     * Количество транзакций
     */
    size_t transactionCount;

    /*
     * Список транзакций
     */
    std::vector<Transaction*> transactions;

public:
    // В конструкторе считываем Magic Number
    explicit Block(FILE* filePointer);

    // Считываем размер блока
    // И потом весь блок
    bool read(FILE* filePointer);

    bool isMagicValid();

    /**
     * Получаем все транзакции
     */
    std::vector<Transaction*> getTransactions();

    ~Block();
};


#endif //GENISYS_BLOCK_FROM_UTXO_BLOCK_H
