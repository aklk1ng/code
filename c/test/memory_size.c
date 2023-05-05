#include <stdio.h>
#include <stdlib.h>

unsigned long long memory_size = 0;
void calc() {
  /**
   * @brief a simple way to calc the memory size roughly
   */
  unsigned int arr[3] = {1024 * 1024, 1024, 1};
  int i, count;
  for (i = 0; i < 3; i++) {
    for (count = 1;; count++) {
      void *block = malloc(memory_size + (arr[i] * count));
      if (block) {
        memory_size += arr[i] * count;
        free(block);
      } else {
        break;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  calc();
  //              bytes       kb      mb    gb
  printf("%f\n", memory_size / 1024.0 / 1024.0 / 1024.0);
  printf("%llu bytes", memory_size);
  return 0;
}
