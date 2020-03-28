#include "cpp/Map.h"

/**
Gets a thread by id
**/
void* Map::get(void* key) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    return data[key]->element;
}

/**
Adds a thread to the end of the linked list and then to the map
**/
void Map::add(void* key, void* element) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    elements.emplaceBack(key, element);
    data.insert(std::pair<void*, DoublyLinkedListNode*>(key, elements.getTail()));
}

void Map::insert(void* key_prev, void* element_prev, void* key_next) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    elements.insertBefore(key_prev, element_prev, data[key_next]);
    data.insert(std::pair<void*, DoublyLinkedListNode*>(key_prev, data[key_next]->previous));
}

/**
Given a thread, deletes its id from the linked list and thread map if it exists
**/
void Map::erase(void* key) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    //Checks if item is in map
    std::map<void*, DoublyLinkedListNode*>::iterator it = data.find(key);

    //If item is in map, then finds location in vector and deletes, then
    //deletes from map
    if (it != data.end()) {
        elements.remove(it->second);
        data.erase(key);
    }
}

/**
Gets the size of the thread map
**/
int Map::size() {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    return data.size();
}

/**
Gets whether the thread map is empty
**/
bool Map::empty() {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    return data.empty();
}

/**
Gets the thread at the front of the linked list
**/
void* Map::front() {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    return (elements.getRoot()) ? elements.getRoot()->element : NULL;
}

/**
Gets the thread at the back of the linked list
**/
void* Map::back() {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    return (elements.getTail()) ? elements.getTail()->element : NULL;
}

/**
Gets the next thread in the linked list after the current thread
**/
void* Map::next(void* key) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);

    DoublyLinkedListNode* node = data[key]->next;

    return (node) ? data[key]->next->element : NULL;
}

/**
Gets the previous thread in the linked list before the current thread
**/
void* Map::previous(void* key) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);

    DoublyLinkedListNode* node = data[key]->previous;
    
    return (node) ? data[key]->previous->element : NULL; 
}

void Map::lock() {
    data_mutex.lock();
}

void Map::unlock() {
    data_mutex.unlock();
}

