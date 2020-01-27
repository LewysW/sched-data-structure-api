#include "map.h"
#include <stdlib.h>

MapItem* Map::at(int key) {
    return NULL;
}

void Map::insert(int key, DoublyLinkedListNode* value) {
    if (key < MAX_SIZE) {
        MapItem* item = (MapItem*) malloc(sizeof(MapItem));
        item->key = key;
        item->value = value;
        table[key] = item;
    } //TODO - else allocate additional space for additional ids
}

void Map::erase(MapItem* item) {
    
}

int Map::getSize() {
    return size;
}

bool Map::empty() {
    return getSize() == 0;
}