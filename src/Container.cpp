#include "Container.h"

Transaction* Container::operator[] (ustring hash) {
    if (isset(hash)) {
        return container[hash];
    }else {
        return nullptr;
    }
}

void Container::add(ustring hash, Transaction *transaction) {
    container[hash] = transaction;
}

void Container::remove(ustring hash) {
    auto iter = container.find(hash);
    if (iter != container.end()) {
        container.erase(iter);
    }
}

bool Container::isset(ustring hash) {
    return container.count(hash) > 0;
}

