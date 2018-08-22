#ifndef GENISYS_BLOCK_FROM_UTXO_UTILS_H
#define GENISYS_BLOCK_FROM_UTXO_UTILS_H

#include "../main.h"

/**
 * Функция нужна для получения int из little-endian числа
 * @param buffer буффер с little-endian числом
 * @param count  количество байт
 * @return int
 */
size_t getIntFromBytes(byte* buffer, int count);

/**
 * Функция нужна для получения int из VarInt little-endian числа
 * @param buffer буффер с little-endian числом
 * @return 1. uint16_t - число (8 байт)
 *         2. int - кол-во байт, которое занимает это число
 */
std::tuple<size_t, int> getVarInt(byte* buffer);

#endif //GENISYS_BLOCK_FROM_UTXO_UTILS_H
