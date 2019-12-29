#ifndef STARDUST_EXPERIMENTAL_SCHED_API_H
#define STARDUST_EXPERIMENTAL_SCHED_API_H

typedef struct ThreadMap_s { } ThreadMap_s;

#ifdef __cplusplus
extern "C" {
#endif

ThreadMap_s* createThreadMap();

#ifdef __cplusplus
}
#endif

#endif //STARDUST_EXPERIMENTAL_SCHED_API_H
