#ifndef STARDUST_EXPERIMENTAL_SCHED_API_H
#define STARDUST_EXPERIMENTAL_SCHED_API_H

typedef struct ThreadMap_s { } ThreadMap_s;

#ifdef __cplusplus
extern "C" {
#endif

ThreadMap_s* createThreadMap();

struct thread* getThread(ThreadMap_s* threadMap, uint16_t id);

struct thread* at(ThreadMap_s* threadMap, int index);

void add(ThreadMap_s* threadMap, struct thread* thread);

void deleteThread(ThreadMap_s* threadMap, struct thread* thread);

void deleteID(ThreadMap_s* threadMap, uint16_t id);

int size(ThreadMap_s* threadMap);

bool empty(ThreadMap_s* threadMap);

#ifdef __cplusplus
}
#endif

#endif //STARDUST_EXPERIMENTAL_SCHED_API_H
