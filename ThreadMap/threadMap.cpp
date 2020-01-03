#include "threadMap.h"

/**
Gets a thread by id
**/
struct thread* ThreadMap::getThread(uint16_t id) {
    return data.at(id);
}

/**
Gets the thread corresponding to the id at the given vector index
**/
struct thread* ThreadMap::at(int index) {
    uint16_t id = elements.at(index);
    return data.at(id);
}

/**
Adds a thread to the vector and map using its id
**/
void ThreadMap::add(struct thread* thread) {
    uint16_t id = thread->id;
    elements.push_back(id);
    threadMap.insert(std::pair<uint16_t, struct thread*>(id, thread));
}

/**
Given a thread, deletes its id from the element vector and thread map if it exists
**/
void ThreadMap::delete(struct thread* thread) {
    uint16_t id = thread->id;

    this->delete(id);
}

/**
Given an id, deletes the corresponding thread if it is in the map/vector
**/
void ThreadMap::delete(uint16_t id) {
    //Code to find id in vector using iterator:
    //https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
    std::vector<int>::iterator position = std::find(elements.begin(), elements.end(), id);

    //If item is found in vector, delete from vector and map
    if (position != elements.end()) {
        elements.erase(position);
        data.erase(id);
    }
}

/**
Gets the size of the thread map
**/
int ThreadMap::size() {
    return data.size();
}

/**
Gets whether the thread map is empty
**/
bool ThreadMap::empty() {
    return data.empty();
}
