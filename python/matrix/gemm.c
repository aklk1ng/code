#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define N 4096
float A[N][N];
float B[N][N];
float C[N][N];

__int64_t nanos() {
  struct timespec start;
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  return (uint64_t)start.tv_sec * 1000000000 + (uint64_t)start.tv_nsec;
}

int main(int argc, char *argv[]) {
  uint64_t start = nanos();
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      float acc = 0;
      for (int k = 0; k < N; k++) {
        acc += A[y][k] * B[k][x];
      }
      C[y][x] = acc;
    }
  }
  uint64_t end = nanos();
  double tflop = (N * N * 2.0 * N) * 1e-12;
  double s = (end - start) * 1e-9;
  printf("%f TFLOP/S\n", tflop / s);
  return 0;
}
