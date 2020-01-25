#include <cstdlib>

#include "api.h"
#include "../ThreadMap/threadMap.h"

#ifdef __cplusplus
extern "C" {
#endif

//Can define functions here which call C++, but must be callable from C

ThreadMap_s* createThreadMap() {
    return (ThreadMap_s*) new ThreadMap;
}

struct thread* getThread(ThreadMap_s* threadMap, uint16_t id) {
    return ((ThreadMap*)(threadMap))->getThread(id);
}

void add(ThreadMap_s* threadMap, struct thread* thread) {
    ((ThreadMap*)(threadMap))->add(thread);
}

void erase(ThreadMap_s* threadMap, struct thread* thread) {
    ((ThreadMap*)(threadMap))->erase(thread);
}

int size(ThreadMap_s* threadMap) {
    return ((ThreadMap*)(threadMap))->size();
}

bool empty(ThreadMap_s* threadMap) {
    return ((ThreadMap*)(threadMap))->empty();
}

struct thread* front(ThreadMap_s* threadMap) {
    return ((ThreadMap*)(threadMap))->front();
}

struct thread* back(ThreadMap_s* threadMap) {
    return ((ThreadMap*)(threadMap))->back();
}

struct thread* next(ThreadMap_s* threadMap, struct thread* element) {
    return ((ThreadMap*)(threadMap))->next(element);
}

struct thread* previous(ThreadMap_s* threadMap, struct thread* element) {
    return ((ThreadMap*)(threadMap))->previous(element);
}

#ifdef __cplusplus
}
#endif
