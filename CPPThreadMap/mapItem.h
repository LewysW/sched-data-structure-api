#ifndef MAP_ITEM_H
#define MAP_ITEM_H
#include <stdint.h>
#include "../DoublyLinkedList/doublyLinkedListNode.h"

class MapItem {
public:
    uint16_t key;
    DoublyLinkedListNode* value;
}

#endif