#include "compiletime.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int *p = malloc(10);
  free(p);
  return 0;
}
