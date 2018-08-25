#include "main.h"

// Получаем название блока вида blk00000.dat
string getRawBlockName(size_t id) {
    size_t count = to_string(id).size();
    string result = "blk" + string(5 - count, '0') + to_string(id) + ".dat";
    return result;
}

int main(int argc, char** argv) {
    string blockPath = "/home/alex/Рабочий стол/php-blockchain-parser/blocks/";
    // Для всех сырых блоков
    // Т.е. в них хранятся блоки блокчейна
    int i = 0;
    for (size_t rawBlockIndex = 0; rawBlockIndex < 271; rawBlockIndex++) {
        string rawBlockName = getRawBlockName(rawBlockIndex);
        string rawBlockPath = blockPath + rawBlockName;

        FILE* file = fopen(rawBlockPath.c_str(), "r");
        // TODO: проверка на то, что файл есть

        Block* block;
        // Перебираем блоки в файле
        while (block = new Block(file), block->isMagicValid()) {
            block->read(file);
            // TODO
            delete block;
            cout << rawBlockName << "   " << i++ << endl;
        }
    }
    // cout << getRawBlockName(10) << endl;
}