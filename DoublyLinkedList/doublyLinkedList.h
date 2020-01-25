#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include "doublyLinkedListNode.h"

class DoublyLinkedList {
private:
    DoublyLinkedListNode* root = NULL;
    DoublyLinkedListNode* tail = NULL;
    int currentSize = 0;

public:
    void insertAfter(struct thread* element, DoublyLinkedListNode* predecessor);

    void emplaceBack(struct thread* element);

    void remove(DoublyLinkedListNode* node);
    
    int size();
    
    void clear();

    DoublyLinkedListNode* getRoot();

    DoublyLinkedListNode* getTail();
};

#endif