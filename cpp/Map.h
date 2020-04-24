#ifndef STARDUST_EXPERIMENTAL_THREAD_MAP_H
#define STARDUST_EXPERIMENTAL_THREAD_MAP_H
#include "doublyLinkedList.h"
#include <iostream>
#include <unordered_map>
//#include <map>
#include <mutex>
#include <algorithm>

class Map {
private:
    std::unordered_map<void*, DoublyLinkedListNode*> data;
    //std::map<void*, DoublyLinkedListNode*> data;
    DoublyLinkedList elements;
    std::recursive_mutex data_mutex;
public:
    Map() = default;

    void clear();

    bool contains(void* key);

    void* get(void* key);

    void add(void* key, void* element);

    void insert(void* key_prev, void* element_prev, void* key_next);

    void erase(void* key);

    int size();

    bool empty();

    void* front();

    void* back();

    void* next(void* key);

    void* previous(void* key);
};


#endif //STARDUST_EXPERIMENTAL_THREAD_MAP_H
