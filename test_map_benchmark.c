#include "test_map_benchmark.h"
#include <stdlib.h>
#include <time.h>

static Map_s* test_thread_map;

void test_map_benchmark() {
  test_thread_map = createMap();

	for (int test_run = 0; test_run < NUM_READINGS; test_run++) {
    for (int num_test_threads = INCREMENT; num_test_threads <= MAX_NUM_THREADS; num_test_threads += INCREMENT) {
      //Populate map with threads
      map_init_threads(num_test_threads);

      clock_t begin = clock();
      //Lookup threads by ID (simluates work done by join_thread lookup)
      map_lookup_threads();
      clock_t end = clock();

      double duration = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
      printf("%d, %lf\n", num_test_threads, duration);

      //Removes threads from list
      map_clear_threads();
    }
}

  deleteMap(&test_thread_map);
}

void map_init_threads(int num_threads) {
	struct map_test_thread* thread;
	int joinee;
    long flags;
	//Initialise each thread
	for (int i = 0; i < num_threads; i++) {

		//Create and initialise attributes of current thread
		thread = (struct map_test_thread*) malloc(sizeof(struct map_test_thread));
		thread->id = i;

		joinee = 0;
		//Choose 10 threads for the current thread to "join"
		for (float j = 0.0; j < 1.0; j += 0.1) {
			//Pick an ID a certain percentage through the list of threads
			int joinee_id = j * num_threads;
			//Make sure the ID is not itself
			joinee_id = joinee_id + i + 1;
			//Make sure ID is not out of range
			joinee_id = joinee_id % num_threads;
			thread->joinee_ids[joinee++] = joinee_id;
		}

    map_sched_add_thread(thread);
	}
}

void map_lookup_threads() {
    struct map_test_thread* thread = front(test_thread_map);
    int iteration = 0;

    while (thread != NULL) {
        //printk("\nMap: Thread->id: %d\n", thread->id);
        for (int i = 0; i < NUM_JOINEES; i++) {
            //printk("Map: Joinee->id: %d\n", thread->joinee_ids[i]);
            map_sched_get_thread(thread->joinee_ids[i]);
        }
        thread = next(test_thread_map, (void*) thread->id);
    }
}

void map_clear_threads() {
    long flags;
    struct map_test_thread* thread = front(test_thread_map);
    struct map_test_thread* nextThread;
    while (thread != NULL) {
        nextThread = next(test_thread_map, (void*) thread->id);
        map_sched_del_thread(thread);
        free(thread);
        thread = nextThread;
    }
}

struct map_test_thread *
map_sched_get_thread(int id)
{
	return get(test_thread_map, (void*) id);
}

void map_sched_add_thread(struct map_test_thread *thread)
{
	add(test_thread_map, (void*) thread->id, thread);
}

void map_sched_del_thread(struct map_test_thread *thread)
{
	erase(test_thread_map, (void*) thread->id);
}
