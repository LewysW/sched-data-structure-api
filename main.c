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

    struct thread* current = front(threadMap);

    while (current != NULL) {
         printf("Thread in loop: %d\n", current->id);
         current = next(threadMap, current);
    }

    current = back(threadMap);

    while (current != NULL) {
         printf("Thread in loop: %d\n", current->id);
         current = previous(threadMap, current);
    }
    printf("Thread ID: %d\n", getThread(threadMap, 10)->id);
    printf("Thread ID: %d\n", getThread(threadMap, 20)->id);
    printf("Thread ID: %d\n", getThread(threadMap, 30)->id);
    printf("Thread ID: %d\n", getThread(threadMap, 40)->id);
    printf("Thread ID: %d\n", getThread(threadMap, 50)->id);

    printf("Size: %d\n", size(threadMap));
    erase(threadMap, t1);
    printf("Size: %d\n", size(threadMap));
    erase(threadMap, t2);
    printf("Size: %d\n", size(threadMap));
    erase(threadMap, t3);
    printf("Size: %d\n", size(threadMap));
    erase(threadMap, t4);
    printf("Size: %d\n", size(threadMap));
    erase(threadMap, t5);
    printf("Size: %d\n", size(threadMap));

    printf("Empty?: %d\n", empty(threadMap));

    return 0;
}
