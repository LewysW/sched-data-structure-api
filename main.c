#include "cpp/api.h"
#include <stdio.h>
#include <stdlib.h>
struct thread {uint64_t id;};

int main() {
  Map_s* map = createMap();

  for (int i = 0; i < 1000; i++) {
    struct thread* thread = (struct thread*) malloc(sizeof(struct thread));
    thread->id = i;
    add(map, (void*) thread->id, thread);
    printf("Size of map: %d\n", size(map));
  }

  Map_s* map2 = createMap();

  for (int i = 0; i < 1000; i++) {
    struct thread* thread = get(map, (void*) i);
    if (i % 5 == 0 && i > 0) {
      printf("Insert is called!\n");
      insert(map2, (void*) thread->id, thread, (void*) i - 1);
    } else {
      add(map2, (void*) thread->id, thread);
    }

    erase(map, (void*) i);
    printf("Size of map: %d\n", size(map));
  }

  printf("Size of map2: %d\n", size(map2));

  struct thread* current = front(map2);

  while (current != NULL) {
    printf("current->id: %lu\n", current->id);
    current = next(map2, (void*) current->id);
  }

  if (contains(map2, (void*) 999)) {
    printf("map2 contains key %d\n", 999);
  }

  if (!contains(map2, (void*) 1000)) {
    printf("map2 does not contain key %d\n", 1000);
  }
  return 0;
}
