#include "cpp/api.h"
#include <stdio.h>
#include <stdlib.h>
struct thread {uint16_t id;};

int main() {
    Map_s* map = createMap();
	printf("Got past map creation!\n");
	struct thread* t1 = (struct thread*) malloc(sizeof(struct thread));
	t1->id = 45;
	struct thread* t2 = (struct thread*) malloc(sizeof(struct thread));
	t2->id = 102;
	struct thread* t3 = (struct thread*) malloc(sizeof(struct thread));
	t3->id = 96;
	struct thread* t4 = (struct thread*) malloc(sizeof(struct thread));
	t4->id = 13;

	printf("Size of map: %d\n", size(map));
	add(map, (void*) t1->id, t1);
	printf("Size of map: %d\n", size(map));
	add(map, (void*) t2->id, t2);
	printf("Size of map: %d\n", size(map));
	add(map, (void*) t3->id, t3);
	printf("Size of map: %d\n", size(map));
	add(map, (void*) t4->id, t4);
	printf("Size of map: %d\n", size(map));

  printf("id: %d\n", id);
  printf("pid: %p\n", pid);
	struct thread* currentThread = (struct thread*) front(map);

	while (currentThread != NULL) {
		printf("Thread in loop: %d\n", currentThread->id);
		currentThread = (struct thread*) next(map, (void*) currentThread->id);
	}

    struct thread* t5 = (struct thread*) malloc(sizeof(struct thread));
    t5->id = 99;

    printf("Inserting thread with id %d before thread with id %d\n", t5->id, t1->id);
    insert(map, (void*) t5->id, t5, (void*) t1->id);

    currentThread = (struct thread*) front(map);

	while (currentThread != NULL) {
		printf("Thread in loop: %d\n", currentThread->id);
		currentThread = (struct thread*) next(map, (void*) currentThread->id);
	}


	printf("Size of map: %d\n", size(map));
    erase(map, (void*) t1->id);
    printf("Size of map: %d\n", size(map));
    erase(map, (void*) t2->id);
    printf("Size of map: %d\n", size(map));
    erase(map, (void*) t3->id);
    printf("Size of map: %d\n", size(map));
    erase(map, (void*) t4->id);
    printf("Size of map: %d\n", size(map));

    return 0;
}
