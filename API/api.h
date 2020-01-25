#ifndef STARDUST_EXPERIMENTAL_SCHED_API_H
#define STARDUST_EXPERIMENTAL_SCHED_API_H
#include <stdint.h>
#include <stdbool.h>

typedef struct ThreadMap_s { } ThreadMap_s;

#ifdef __cplusplus
extern "C" {
#endif

ThreadMap_s* createThreadMap();

struct thread* getThread(ThreadMap_s* threadMap, uint16_t id);

void add(ThreadMap_s* threadMap, struct thread* thread);

void erase(ThreadMap_s* threadMap, struct thread* thread);

int size(ThreadMap_s* threadMap);

bool empty(ThreadMap_s* threadMap);

struct thread* front(ThreadMap_s* threadMap);

struct thread* back(ThreadMap_s* threadMap);

struct thread* next(ThreadMap_s* threadMap, struct thread* element);

struct thread* previous(ThreadMap_s* threadMap, struct thread* element);

#ifdef __cplusplus
}
#endif

#endif //STARDUST_EXPERIMENTAL_SCHED_API_H
