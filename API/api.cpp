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

struct thread* at(ThreadMap_s* threadMap, int index);

void add(ThreadMap_s* threadMap, struct thread* thread);

void deleteThread(ThreadMap_s* threadMap, struct thread* thread);

void deleteID(ThreadMap_s* threadMap, uint16_t id);

int size(ThreadMap_s* threadMap);

bool empty(ThreadMap_s* threadMap);

#ifdef __cplusplus
}
#endif
