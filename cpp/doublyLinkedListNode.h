#ifndef DOUBLY_LINKED_LIST_NODE_H
#define DOUBLY_LINKED_LIST_NODE_H
#include <stdint.h>
#include <stddef.h>

class DoublyLinkedListNode {
public:
    void* element;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* previous;

    DoublyLinkedListNode(void* element) : element(element),
                                        next(NULL),
                                        previous(NULL)
    {
    }

    DoublyLinkedListNode(void* element, DoublyLinkedListNode* next,
                                        DoublyLinkedListNode* previous) :
        element(element),
        next(next),
        previous(previous)
    {
    }
};
#endif
