#include "cpp/api.h"
#include "cpp/Map.h"

#ifdef __cplusplus
extern "C" {
#endif

//Can define functions here which call C++, but must be callable from C

Map_s* createMap() {
    return reinterpret_cast<Map_s*>(new Map);
}

void deleteMap(Map_s** map) {
    reinterpret_cast<Map*>(*map)->clear();
    delete reinterpret_cast<Map*>(*map);
    *map = NULL;
}

int contains(Map_s* map, void* key) {
    return reinterpret_cast<Map*>(map)->contains(key);
}

void* get(Map_s* map, void* key) {
    return reinterpret_cast<Map*>(map)->get(key);
}

void add(Map_s* map, void* key, void* element) {
    reinterpret_cast<Map*>(map)->add(key, element);
}

void insert(Map_s* map, void* key_prev, void* element_prev, void* key_next) {
    reinterpret_cast<Map*>(map)->insert(key_prev, element_prev, key_next);
}

void erase(Map_s* map, void* key) {
    reinterpret_cast<Map*>(map)->erase(key);
}

int size(Map_s* map) {
    return reinterpret_cast<Map*>(map)->size();
}

int empty(Map_s* map) {
    return reinterpret_cast<Map*>(map)->empty();
}

void* front(Map_s* map) {
    return reinterpret_cast<Map*>(map)->front();
}

void* back(Map_s* map) {
    return reinterpret_cast<Map*>(map)->back();
}

void* next(Map_s* map, void* element) {
    return reinterpret_cast<Map*>(map)->next(element);
}

void* previous(Map_s* map, void* element) {
    return reinterpret_cast<Map*>(map)->previous(element);
}

#ifdef __cplusplus
}
#endif
