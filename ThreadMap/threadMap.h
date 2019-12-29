#ifndef STARDUST_EXPERIMENTAL_THREAD_MAP_H
#define STARDUST_EXPERIMENTAL_THREAD_MAP_H
#include <iostream>

//TODO - define data structure in terms of thread structs used scheduler
//TODO - define iterator for data structure
//TODO - add each function required by scheduler
//TODO - Make each function thread safe using std::lock_guard and std::mutex


class ThreadMap {
public:
    ThreadMap() {std::cout << "Creating new ThreadMap!" << std::endl;}
};


#endif //STARDUST_EXPERIMENTAL_THREAD_MAP_H
