#ifndef MAP_H
#define MAP_H
#include "mapItem.h"
#include <stdbool.h>

#define MAX_SIZE 10000

class Map {
private:
    int size;
    MapItem* table[MAX_SIZE];

public:
    MapItem* at(int key);

    void insert(int key, DoublyLinkedListNode* value);

    void erase(MapItem* item);

    int getSize();

    bool empty();

};

#endif