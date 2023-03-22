#include <stdio.h>
#include <stdlib.h>

unsigned long long memory_size = 0;
void calc() {
  /**
   * @brief a simple way to calc the memory size roughly
   */
  unsigned int arr[3] = {1024 * 1024, 1024, 1};
  int i, index;
  for (i = 0; i < 3; i++) {
    for (index = 1;; index++) {
      void *size = malloc(memory_size + (arr[i] * index));
      if (size) {
        memory_size += arr[index];
      } else {
        break;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  calc();
  //              bytes       kb      mb    gb
  printf("%f", memory_size / 1024.0 / 1024.0 / 1024.0);
  return 0;
}
