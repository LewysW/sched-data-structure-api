#ifndef STARDUST_EXPERIMENTAL_THREAD_MAP_H
#define STARDUST_EXPERIMENTAL_THREAD_MAP_H
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <mutex>

struct thread {uint16_t id;}; //TODO - replace with import of sched.h

//TODO - Make each function thread safe using std::lock_guard and std::mutex
//TODO - integrate with code in sched.c
//TODO - cancel Huel subscription

class ThreadMap {
private:
    std::map<uint16_t, struct thread*> data;
    std::vector<uint16_t> elements;
    std::mutex data_mutex;
    std::mutex element_mutex;
public:
    ThreadMap() {std::cout << "Creating new ThreadMap!" << std::endl;}

    struct thread* getThread(uint16_t id);

    struct thread* at(int index);

    void add(struct thread* thread);

    void erase(struct thread* thread);

    void erase(uint16_t id);

    int size();

    bool empty();
};


#endif //STARDUST_EXPERIMENTAL_THREAD_MAP_H
