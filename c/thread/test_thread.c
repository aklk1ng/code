#include "thread.h"
#include <stdio.h>
#include <unistd.h>

__thread char *base, *cur; // thread-local variables
__thread int id;

__attribute__((noinline)) void set_cur(void *ptr) { cur = ptr; }
__attribute__((noinline)) char *get_cur() { return cur; }

void stackoverflow(int n) {
  set_cur(&n);
  if (n % 1024 == 0) {
    int sz = base - get_cur();
    printf("Stack size of T%d >= %d KB\n", id, sz / 1024);
  }
  stackoverflow(n + 1);
}

void Tprobe(int tid) {
  id = tid;
  base = (void *)&tid;
  stackoverflow(0);
}

int x = 0;
void hello(int id) {
  printf("Thread id: %d\n", id);
  usleep(id * 1000);
  printf("Hello from thread #%c\n", "123456789ABCDEF"[x++]);
}

unsigned long balance = 100;
void Alipay_withdraw(int amt) {
  if (balance >= amt) {
    usleep(1);
    balance -= amt;
  }
}

void Talipay(int id) { Alipay_withdraw(100); }

int main(int argc, char *argv[]) {
  create(Talipay);
  create(Talipay);
  join();
  printf("balance = %lu\n", balance);
  // setbuf(stdout, NULL);
  // for (int i = 0; i < 4; i++) {
  //   create(Tprobe);
  // }

  return 0;
}
