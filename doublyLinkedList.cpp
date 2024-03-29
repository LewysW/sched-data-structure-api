#include "cpp/doublyLinkedList.h"
#include <stdlib.h>

void DoublyLinkedList::insertBefore(void* element, DoublyLinkedListNode* successor) {
    if (currentSize == 0) {
            tail = new DoublyLinkedListNode(element);
            root = tail;
        }
        else {
            DoublyLinkedListNode* new_node;

            //If tail node
            if (successor == NULL) {
                //Set next to NULL and previous to current tail
                new_node = new DoublyLinkedListNode(element, NULL, tail);
                tail->next = new_node;
                //Sets tail to new_node
                tail = new_node;
            //Otherwise if any other node
            } else {
                //Sets next to successor and previous to successor previous
                new_node = new DoublyLinkedListNode(element, successor, successor->previous);

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

void DoublyLinkedList::insertAfter(void* element, DoublyLinkedListNode* predecessor) {
    if (currentSize == 0) {
            tail = new DoublyLinkedListNode(element);
            root = tail;
        }
        else {
            DoublyLinkedListNode* new_node;

            //If root node
            if (predecessor == NULL) {
                //Set previous to NULL and next to current root
                new_node = new DoublyLinkedListNode(element, root, NULL);
                //Sets root previous to new_node
                root->previous = new_node;
                //Sets root to new_node
                root = new_node;
            //Otherwise if any other node
            } else {
                new_node = new DoublyLinkedListNode(element, predecessor->next, predecessor);

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

void DoublyLinkedList::remove(DoublyLinkedListNode* node) {
    //If final node is being deleted, reset root and tail
    if (currentSize == 1) {
        root = tail = NULL;
    } else {
        //Update pointers
        //Check to avoid NULL dereference
        if (node != root) {
            node->previous->next = node->next;
        } else {
            root = node->next;
        }

        //Update pointers
        //Check to avoid NULL dereference
        if (node != tail) {
            node->next->previous = node->previous;
        } else {
            tail = node->previous;
        }
    }

    //Decrement current size and free node
    currentSize--;
    delete(node);
}

int DoublyLinkedList::size() {
    return currentSize;
}

DoublyLinkedListNode* DoublyLinkedList::getRoot() {
    return root;
}

DoublyLinkedListNode* DoublyLinkedList::getTail() {
    return tail;
}
