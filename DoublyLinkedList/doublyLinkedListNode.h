#ifndef DOUBLY_LINKED_LIST_NODE_H
#define DOUBLY_LINKED_LIST_NODE_H
#include <stdint.h>
#include <stddef.h>
struct thread {uint16_t id;};


class DoublyLinkedListNode {
public:
    struct thread* element;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* previous;

    DoublyLinkedListNode(struct thread* element) : element(element), 
                                                    next(NULL), 
                                                    previous(NULL) 
    {
    }

    DoublyLinkedListNode(struct thread* element, DoublyLinkedListNode* next, DoublyLinkedListNode* previous) :
        element(element),
        next(next),
        previous(previous)
    {
    }
};
#endif