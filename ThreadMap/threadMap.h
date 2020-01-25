#ifndef STARDUST_EXPERIMENTAL_THREAD_MAP_H
#define STARDUST_EXPERIMENTAL_THREAD_MAP_H
#include "../DoublyLinkedList/doublyLinkedList.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <mutex>

//TODO - integrate with code in sched.c
//TODO - cancel Huel subscription

class ThreadMap {
private:
    std::map<uint16_t, DoublyLinkedListNode*> data;
    DoublyLinkedList elements;
    std::mutex data_mutex;
    std::mutex element_mutex;
public:
    ThreadMap() {std::cout << "Creating new ThreadMap!" << std::endl;}

    struct thread* getThread(uint16_t id);

    void add(struct thread* thread);

    void erase(struct thread* thread);

    void erase(uint16_t id);

    int size();

    bool empty();

    struct thread* front();

    struct thread* back();

    struct thread* next(struct thread* element);

    struct thread* previous(struct thread* element);
};


#endif //STARDUST_EXPERIMENTAL_THREAD_MAP_H
