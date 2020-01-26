#ifndef MAP_ITEM_H
#define MAP_ITEM_H
#include <stdint.h>

class MapItem {
public:
    uint16_t key;
    struct thread* value;
}

#endif