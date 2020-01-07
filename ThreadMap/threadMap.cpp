#include "threadMap.h"

/**
Gets a thread by id
**/
struct thread* ThreadMap::getThread(uint16_t id) {
    std::lock_guard<std::mutex> guard(data_mutex);
    return data.at(id);
}

/**
Gets the thread corresponding to the id at the given vector index
**/
struct thread* ThreadMap::at(int index) {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    std::lock_guard<std::mutex> element_guard(element_mutex);

    uint16_t id = elements.at(index);
    return data.at(id);
}

/**
Adds a thread to the vector and map using its id
**/
void ThreadMap::add(struct thread* thread) {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    std::lock_guard<std::mutex> element_guard(element_mutex);

    uint16_t id = thread->id;
    elements.push_back(id);
    data.insert(std::pair<uint16_t, struct thread*>(id, thread));
}

/**
Given a thread, deletes its id from the element vector and thread map if it exists
**/
void ThreadMap::erase(struct thread* thread) {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    std::lock_guard<std::mutex> element_guard(element_mutex);

    //Checks if item is in map
    std::map<uint16_t, struct thread*>::iterator it = data.find(thread->id);

    //If item is in map, then finds location in vector and deletes, then
    //deletes from map
    if (it != data.end()) {
        std::vector<uint16_t>::iterator position;
        position = std::find(elements.begin(), elements.end(), thread->id);
        elements.erase(position);
        data.erase(thread->id);
    }
}

/**
Gets the size of the thread map
**/
int ThreadMap::size() {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    return data.size();
}

/**
Gets whether the thread map is empty
**/
bool ThreadMap::empty() {
    std::lock_guard<std::mutex> data_guard(data_mutex);
    return data.empty();
}
