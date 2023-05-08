#ifdef RUNTIME
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

void *malloc(size_t size) {
  void *(*mallocp)(size_t size);
  char *err;
  mallocp = dlsym(RTLD_NEXT, "malloc");
  if ((err = dlerror()) != NULL) {
    fputs(err, stderr);
    exit(0);
  }

  char *ptr = mallocp(size);
  printf("malloc(%d)=%p\n", (int)size, ptr);
  return ptr;
}

void free(void *ptr) {
  void (*freep)(void *) = NULL;
  char *err;
  if (!ptr)
    return;

  freep = dlsym(RTLD_NEXT, "free");
  if ((err = dlerror()) != NULL) {
    fputs(err, stderr);
    exit(0);
  }
  freep(ptr);
  printf("free(%p)\n", ptr);
}

#endif
