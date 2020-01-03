#ifndef STARDUST_EXPERIMENTAL_THREAD_MAP_H
#define STARDUST_EXPERIMENTAL_THREAD_MAP_H
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

//TODO - define data structure in terms of thread structs used scheduler
//TODO - define iterator for data structure
//TODO - add each function required by scheduler
//TODO - Make each function thread safe using std::lock_guard and std::mutex
//TODO - integrate with code in sched.c

class ThreadMap {
private:
    std::map<uint16_t, struct thread*> data;
    std::vector<unint16_t> elements;
public:
    ThreadMap() {std::cout << "Creating new ThreadMap!" << std::endl;}

    struct thread* getThread(unint16_t id);

    struct thread* at(int index);

    void add(struct thread* thread);

    void delete(struct thread* thread);

    void delete(uint16_t id);

    int size();

    bool empty();
    //TODO NEXT - define iterator for thread map,
    //list of IDs in map, mutex/lock in map, and iterator

};


#endif //STARDUST_EXPERIMENTAL_THREAD_MAP_H
