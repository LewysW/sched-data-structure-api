#ifndef MAP_H
#define MAP_H
#include "mapItem.h"
#include <stdbool.h>

#define MAX_SIZE 10000

class Map {
private:
    int size;
    MapItem* table[MAX_SIZE];

private:
    MapItem* at(int key);
    void insert(int key, DoublyLinkedListNode* value);
    void erase(MapItem* item);
    int size();
    bool empty();

}

#endif