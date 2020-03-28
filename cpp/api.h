#ifndef STARDUST_EXPERIMENTAL_SCHED_API_H
#define STARDUST_EXPERIMENTAL_SCHED_API_H
#include <stdint.h>

typedef struct Map_s { } Map_s;

#ifdef __cplusplus
extern "C" {
#endif

Map_s* createMap();

void* get(Map_s* map, void* key);

void add(Map_s* map, void* key, void* element);

void insert(Map_s* map, void* key_prev, void* element_prev, void* key_next);

void erase(Map_s* map, void* key);

int size(Map_s* map);

int empty(Map_s* map);

void* front(Map_s* map);

void* back(Map_s* map);

void* next(Map_s* map, void* element);

void* previous(Map_s* map, void* element);

void lock_map(Map_s* map);

void unlock_map(Map_s* map);

#ifdef __cplusplus
}
#endif

#endif //STARDUST_EXPERIMENTAL_SCHED_API_H

