#include <cstdlib>

#include "cpp/api.h"
#include "cpp/Map.h"

#ifdef __cplusplus
extern "C" {
#endif

//Can define functions here which call C++, but must be callable from C

Map_s* createMap() {
    return (Map_s*) new Map;
}

int contains(Map_s* map, void* key) {
    return ((Map*)(map))->contains(key);
}

void* get(Map_s* map, void* key) {
    return ((Map*)(map))->get(key);
}

void add(Map_s* map, void* key, void* element) {
    ((Map*)(map))->add(key, element); 
}

void insert(Map_s* map, void* key_prev, void* element_prev, void* key_next) {
    ((Map*)(map))->insert(key_prev, element_prev, key_next);
}

void erase(Map_s* map, void* key) {
    ((Map*)(map))->erase(key);
}

int size(Map_s* map) {
    return ((Map*)(map))->size();
}

int empty(Map_s* map) {
    return ((Map*)(map))->empty();
}

void* front(Map_s* map) {
    return ((Map*)(map))->front();
}

void* back(Map_s* map) {
    return ((Map*)(map))->back();
}

void* next(Map_s* threadMap, void* element) {
    return ((Map*)(threadMap))->next(element);
}

void* previous(Map_s* threadMap, void* element) {
    return ((Map*)(threadMap))->previous(element);
}

void lock_map(Map_s* threadMap) {
    return ((Map*)(threadMap))->lock();
}

void unlock_map(Map_s* threadMap) {
    return ((Map*)(threadMap))->unlock();
}

#ifdef __cplusplus
}
#endif

