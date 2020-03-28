#ifndef DOUBLY_LINKED_LIST_NODE_H
#define DOUBLY_LINKED_LIST_NODE_H
#include <stdint.h>
#include <stddef.h>

class DoublyLinkedListNode {
public:
    void* key;
    void* element;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* previous;

    DoublyLinkedListNode(void* key, void* element) : key(key),
                                                    element(element),
                                                    next(NULL),
                                                    previous(NULL)
    {
    }

    DoublyLinkedListNode(void* key, void* element, DoublyLinkedListNode* next, DoublyLinkedListNode* previous) :
        key(key),
        element(element),
        next(next),
        previous(previous)
    {
    }
};
#endif

