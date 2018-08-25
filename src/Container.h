#ifndef GENISYS_BLOCK_FROM_UTXO_CONTAINER_H
#define GENISYS_BLOCK_FROM_UTXO_CONTAINER_H

#include "main.h"
#include "transactions/Transaction.h"

class Container {
public:
    /**
     * ustring == char[32] - хэш транзакции
     * Transaction* - указатель на транзакцию
     */
    std::map <ustring, Transaction*> container;

    /**
     * Получаем указатель на транзакцию
     * Если её нет в контейнере, то nullptr
     * @param hash - хэш транзакции
     * @return Transaction* или nullptr
     */
    Transaction* operator [] (byte* hash);

    /**
     * Добавить транзакцию в контейнер
     * @param hash - хэш транзакции
     * @param transaction - указатель на транзакцию
     */
    void add(ustring hash, Transaction* transaction);

    /**
     * Удалить транзакцию из контейнера
     * @param hash - хэш транзакции
     */
    void remove(ustring hash);

    /**
     * Проверка на наличие транзакции в контейнере
     * @param hash - хэш транзакции
     * @return bool
     */
    bool isset(ustring hash);
};


#endif //GENISYS_BLOCK_FROM_UTXO_CONTAINER_H
