#include "threadMap.h"

/**
Gets a thread by id
**/
struct thread* ThreadMap::getThread(uint16_t id) {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    std::lock_guard<std::mutex> element_guard(element_mutex);
    return data.at(id)->element;
}

/**
Adds a thread to the end of the linked list and then to the map
**/
void ThreadMap::add(struct thread* thread) {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    std::lock_guard<std::mutex> element_guard(element_mutex);

    uint16_t id = thread->id;
    elements.emplaceBack(thread);
    data.insert(std::pair<uint16_t, DoublyLinkedListNode*>(id, elements.getTail()));
}

/**
Given a thread, deletes its id from the linked list and thread map if it exists
**/
void ThreadMap::erase(struct thread* thread) {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    std::lock_guard<std::mutex> element_guard(element_mutex);

    //Checks if item is in map
    std::map<uint16_t, DoublyLinkedListNode*>::iterator it = data.find(thread->id);

    //If item is in map, then finds location in vector and deletes, then
    //deletes from map
    if (it != data.end()) {
        elements.remove(it->second);
        data.erase(it->first);
    }
}

/**
Gets the size of the thread map
**/
int ThreadMap::size() {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    return data.size();
}

/**
Gets whether the thread map is empty
**/
bool ThreadMap::empty() {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    return data.empty();
}

/**
Gets the thread at the front of the linked list
**/
struct thread* ThreadMap::front() {
    std::lock_guard<std::mutex> element_guard(element_mutex);
    return elements.getRoot()->element;
}

/**
Gets the thread at the back of the linked list
**/
struct thread* ThreadMap::back() {
    std::lock_guard<std::mutex> element_guard(element_mutex);
    return elements.getTail()->element;
}

/**
Gets the next thread in the linked list after the current thread
**/
struct thread* ThreadMap::next(struct thread* element) {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    std::lock_guard<std::mutex> element_guard(element_mutex);

    DoublyLinkedListNode* node = data.at(element->id)->next;

    return (node == NULL) ? NULL : data.at(element->id)->next->element;
}

/**
Gets the previous thread in the linked list before the current thread
**/
struct thread* ThreadMap::previous(struct thread* element) {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    std::lock_guard<std::mutex> element_guard(element_mutex);

    DoublyLinkedListNode* node = data.at(element->id)->previous;

    return (node == NULL) ? NULL : data.at(element->id)->previous->element;
}

