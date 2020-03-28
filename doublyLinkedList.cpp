#include "cpp/doublyLinkedList.h"
#include <stdlib.h>

void DoublyLinkedList::insertBefore(void* key, void* element, DoublyLinkedListNode* successor) {
    if (currentSize == 0) {
            tail = (DoublyLinkedListNode*) malloc(sizeof(DoublyLinkedListNode));
            *tail = DoublyLinkedListNode(key, element);
            root = tail;
        }
        else {
            DoublyLinkedListNode* new_node = (DoublyLinkedListNode*) malloc(sizeof(DoublyLinkedListNode));

            //If tail node
            if (successor == NULL) {
                //Set next to NULL and previous to current tail
                *new_node = DoublyLinkedListNode(key, element, NULL, tail);
                tail->next = new_node;
                //Sets tail to new_node
                tail = new_node;
            //Otherwise if any other node
            } else {
                //Sets next to successor and previous to successor previous
                *new_node = DoublyLinkedListNode(key, element, successor, successor->previous);

                if (successor->previous != NULL) {
                    //Updates successor->previous->next to new_node
                    successor->previous->next = new_node;
                }
                
                //Updates successor previous to new_node
                successor->previous = new_node;

                //If previous is NULL, new_node becomes root node
                if (new_node->previous == NULL) root = new_node;
            }
        }

        currentSize++;
}

void DoublyLinkedList::insertAfter(void* key, void* element, DoublyLinkedListNode* predecessor) {
    if (currentSize == 0) {
            tail = (DoublyLinkedListNode*) malloc(sizeof(DoublyLinkedListNode));
            *tail = DoublyLinkedListNode(key, element);
            root = tail;
        }
        else {
            DoublyLinkedListNode* new_node = (DoublyLinkedListNode*) malloc(sizeof(DoublyLinkedListNode));

            //If root node
            if (predecessor == NULL) {
                //Set previous to NULL and next to current root
                *new_node = DoublyLinkedListNode(key, element, root, NULL);
                //Sets root previous to new_node
                root->previous = new_node;
                //Sets root to new_node
                root = new_node;
            //Otherwise if any other node
            } else {
                *new_node = DoublyLinkedListNode(key, element, predecessor->next, predecessor);

                if (predecessor->next != NULL) {
                    predecessor->next->previous = new_node;
                }
                
                predecessor->next = new_node;

                //If next is NULL, new_node becomes tail node
                if (new_node->next == NULL) tail = new_node;
            }
        }

        currentSize++;
}

//Insert the element at the front of the list
void DoublyLinkedList::push(void* key, void* element) {
    insertBefore(key, element, getRoot());
}

//Insert the element at the back of the list
void DoublyLinkedList::emplaceBack(void* key, void* element) {
    insertAfter(key, element, getTail());
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
