#include "cpp/Map.h"

/**
 * Clears all entries in the map (including deallocation of memory)
**/
void Map::clear() {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    while (elements.size() > 0) {
        elements.remove(elements.getRoot());
    }
    data.clear();
}

/**
 * Checks whether an entry is contained within the map
**/
bool Map::contains(void* key) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    return data.find(key) != data.end();
}
/**
Gets a thread by id
**/
void* Map::get(void* key) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    auto object = data.find(key);
    return (object != data.end()) ? object->second->element : NULL;
}

/**
Adds a thread to the end of the linked list and then to the map
**/
void Map::add(void* key, void* element) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    elements.insertAfter(element, elements.getTail());
    data[key] = elements.getTail();
    //data.insert(std::pair<void*, DoublyLinkedListNode*>(key, elements.getTail()));
}

void Map::insert(void* key_prev, void* element_prev, void* key_next) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    elements.insertBefore(element_prev, data[key_next]);
    data[key_prev] = data[key_next]->previous;
    //data.insert(std::pair<void*, DoublyLinkedListNode*>(key_prev, data[key_next]->previous));
}

/**
Given a thread, deletes its id from the linked list and thread map if it exists
**/
void Map::erase(void* key) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    //If item is in map, then
    //deletes from map
    auto object = data.find(key);

    if (object != data.end()) {
        elements.remove(object->second);
        data.erase(object);
    }
}

/**
Gets the size of the thread map
**/
int Map::size() {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    return elements.size();
}

/**
Gets whether the thread map is empty
**/
bool Map::empty() {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);
    return elements.size() == 0;
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

    DoublyLinkedListNode* node;
    auto object = data.find(key);

    node = (object != data.end()) ? object->second->next : NULL;
    return (node) ? node->element : NULL;
}

/**
Gets the previous thread in the linked list before the current thread
**/
void* Map::previous(void* key) {
    std::lock_guard<std::recursive_mutex> data_guard(data_mutex);

    DoublyLinkedListNode* node;
    auto object = data.find(key);

    node = (object != data.end()) ? object->second->previous : NULL;
    return (node) ? node->element : NULL;
}
