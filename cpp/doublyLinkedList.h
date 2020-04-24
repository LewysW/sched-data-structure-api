#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include "doublyLinkedListNode.h"

class DoublyLinkedList {
private:
    DoublyLinkedListNode* root = NULL;
    DoublyLinkedListNode* tail = NULL;
    int currentSize = 0;

public:
    void insertBefore(void* element, DoublyLinkedListNode* successor);

    void insertAfter(void* element, DoublyLinkedListNode* predecessor);

    void remove(DoublyLinkedListNode* node);

    int size();

    DoublyLinkedListNode* getRoot();

    DoublyLinkedListNode* getTail();
};

#endif
