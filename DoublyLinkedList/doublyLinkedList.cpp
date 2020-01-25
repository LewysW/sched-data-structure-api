#include "doublyLinkedList.h"
#include <cstdlib>

void DoublyLinkedList::insertAfter(struct thread* element, DoublyLinkedListNode* predecessor) {
    if (currentSize == 0) {
            tail = (DoublyLinkedListNode*) malloc(sizeof(DoublyLinkedListNode));
            *tail = DoublyLinkedListNode(element);
            root = tail;
        }
        else {
            DoublyLinkedListNode* new_node = (DoublyLinkedListNode*) malloc(sizeof(DoublyLinkedListNode));

            //If root node
            if (predecessor == NULL) {
                //Set previous to NULL and next to current root
                *new_node = DoublyLinkedListNode(element, root, NULL);
                //Sets root to new_node
                root = new_node;
            //Otherwise if any other node
            } else {
                *new_node = DoublyLinkedListNode(element, predecessor->next, predecessor);
                predecessor->next = new_node;

                //If next is NULL, new_node becomes tail node
                if (new_node->next == NULL) tail = new_node;
            }
        }

        currentSize++;
}

void DoublyLinkedList::emplaceBack(struct thread* element) {
    insertAfter(element, getTail());
}

void DoublyLinkedList::remove(DoublyLinkedListNode* node) {
    if (currentSize == 1)
            clear();
        else {
            if (node != root) node->previous->next = node->next;

            if (node != tail) node->next->previous = node->previous;

            if (root == node) root = node->next;

            if (tail == node) tail = node->previous;

            free(node);
            currentSize--;
        }
}

int DoublyLinkedList::size() {
    return currentSize;
}

void DoublyLinkedList::clear() {
    root = tail = NULL;
    currentSize = 0;
}

DoublyLinkedListNode* DoublyLinkedList::getRoot() {
    return root;
}

DoublyLinkedListNode* DoublyLinkedList::getTail() {
    return tail;
}