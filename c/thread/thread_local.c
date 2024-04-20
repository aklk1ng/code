#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

__attribute__((constructor)) void build() {
  printf("call the constructor function brefore the main function\n");
}

__attribute__((destructor)) void cleanup() {
  printf("call the destructor function after the main function\n");
}

thread_local int counter = 0;

int increment() {
  counter++;
  return counter;
}

int thread_func(void *arg) {
  printf("Thread %ld starting...\n", (long)arg);
  for (int i = 0; i < 5; i++) {
    printf("Thread %ld: counter = %d\n", (long)arg, increment());
  }
  return 0;
}

int main(int argc, char *argv[]) {
  thrd_t threads[2];

  for (long i = 0; i < 2; i++) {
    thrd_create(&threads[i], thread_func, (void *)i);
  }
  for (long i = 0; i < 2; i++) {
    thrd_join(threads[i], NULL);
  }
  return 0;
}
