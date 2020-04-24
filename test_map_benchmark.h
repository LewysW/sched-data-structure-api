#ifndef STARDUST_TEST_MAP_BENCHMARK_H_
#define STARDUST_TEST_MAP_BENCHMARK_H_

#include <stdio.h>
#include <stdlib.h>
#include "cpp/api.h"

#define MAX_NUM_THREADS 10000
#define INCREMENT 1000
#define NUM_JOINEES 10
#define NUM_READINGS 5

struct map_test_thread {
    //ID of this thread
    int id;
    //IDs of threads to join
    int joinee_ids[NUM_JOINEES];
};

void test_map_benchmark();
void map_init_threads(int num_threads);
void map_lookup_threads();
void map_clear_threads();
struct map_test_thread* map_sched_get_thread(int id);
void map_sched_add_thread(struct map_test_thread *thread);
void map_sched_del_thread(struct map_test_thread *thread);


#endif
