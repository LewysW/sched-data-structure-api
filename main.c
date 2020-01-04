#include "API/api.h"
#include <stdio.h>
#include <stdlib.h>
struct thread {uint16_t id;};

int main() {
    struct thread *t1, *t2, *t3, *t4, *t5;
    t1 = malloc(sizeof(struct thread));
    t2 = malloc(sizeof(struct thread));
    t3 = malloc(sizeof(struct thread));
    t4 = malloc(sizeof(struct thread));
    t5 = malloc(sizeof(struct thread));
    t1->id = 10;
    t2->id = 20;
    t3->id = 30;
    t4->id = 40;
    t5->id = 50;

    ThreadMap_s* threadMap = createThreadMap();

    printf("Empty?: %d\n", empty(threadMap));

    add(threadMap, t1);
    printf("Size: %d\n", size(threadMap));
    add(threadMap, t2);
    printf("Size: %d\n", size(threadMap));
    add(threadMap, t3);
    printf("Size: %d\n", size(threadMap));
    add(threadMap, t4);
    printf("Size: %d\n", size(threadMap));
    add(threadMap, t5);
    printf("Size: %d\n", size(threadMap));

    printf("Empty?: %d\n", empty(threadMap));

    printf("Thread ID: %d\n", getThread(threadMap, 10)->id);
    printf("Thread ID: %d\n", getThread(threadMap, 20)->id);
    printf("Thread ID: %d\n", getThread(threadMap, 30)->id);
    printf("Thread ID: %d\n", getThread(threadMap, 40)->id);
    printf("Thread ID: %d\n", getThread(threadMap, 50)->id);

    for (int i = 0; i < size(threadMap); i++) {
        printf("Element at(%d): %d\n", i, at(threadMap, i)->id);
    }

    printf("Size: %d\n", size(threadMap));
    erase(threadMap, t1);
    printf("Size: %d\n", size(threadMap));
    erase(threadMap, t2);
    printf("Size: %d\n", size(threadMap));
    eraseID(threadMap, 30);
    printf("Size: %d\n", size(threadMap));
    eraseID(threadMap, 40);
    printf("Size: %d\n", size(threadMap));
    eraseID(threadMap, 50);
    printf("Size: %d\n", size(threadMap));

    printf("Empty?: %d\n", empty(threadMap));

    return 0;
}
