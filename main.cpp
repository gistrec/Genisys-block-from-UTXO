#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Получаем название блока вида blk00000.dat
string getRawBlockName(size_t id) {
    size_t count = to_string(id).size();
    string result = "blk" + string(5 - count, '0') + to_string(id) + ".dat";
    return result;
}

int main() {
    string blockPath = "/home/alex/Рабочий стол/php-blockchain-parser/blocks/";
    // Для всех сырых блоков
    // Т.е. в них хранятся блоки блокчейна
    for (size_t rawBlockIndex = 0; rawBlockIndex < 271; rawBlockIndex++) {
        string rawBlockName = getRawBlockName(rawBlockIndex);
        string rawBlockPath = blockPath + rawBlockName;

        ifstream file;
        file.open(rawBlockPath, std::ifstream::in);



    }
    // cout << getRawBlockName(10) << endl;
}