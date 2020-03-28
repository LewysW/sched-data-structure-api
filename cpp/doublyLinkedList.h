#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include "doublyLinkedListNode.h"

class DoublyLinkedList {
private:
    DoublyLinkedListNode* root = NULL;
    DoublyLinkedListNode* tail = NULL;
    int currentSize = 0;

public:
    void insertBefore(void* key, void* element, DoublyLinkedListNode* successor);

    void insertAfter(void* key, void* element, DoublyLinkedListNode* predecessor);

    void push(void* key, void* element);

    void emplaceBack(void* key, void* element);

    void remove(DoublyLinkedListNode* node);
    
    int size();
    
    void clear();

    DoublyLinkedListNode* getRoot();

    DoublyLinkedListNode* getTail();
};

#endif
