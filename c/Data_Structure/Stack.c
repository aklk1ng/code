// 数组栈
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int StackDataType;
typedef struct Stack {
  StackDataType *a;
  int top;
  int capacity;
} ST;

void StackInit(ST *ps) {
  assert(ps);
  ps->a = NULL;
  ps->top = 0;
  ps->capacity = 0;
}

void StackDestroy(ST *ps) {
  assert(ps);
  free(ps->a);
  ps->top = 0;
  ps->capacity = 0;
}

void StackPush(ST *ps, StackDataType x) {
  assert(ps);
  if (ps->top == ps->capacity) {
    int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
    StackDataType *tmp =
        (StackDataType *)realloc(ps->a, sizeof(StackDataType) * newcapacity);
    if (tmp == NULL) {
      printf("realloc failed!\n");
      exit(-1);
    }
    ps->a = tmp;
    ps->capacity = newcapacity;
  }
  ps->a[ps->top] = x;
  ps->top++;
}

void StackPop(ST *ps) {
  assert(ps);
  assert(ps->top > 0);
  ps->top--;
}

int StackSize(ST *ps) {
  assert(ps);
  return ps->top;
}

bool StackEmpty(ST *ps) {
  assert(ps);
  return ps->top == 0;
}

StackDataType StackTop(ST *ps) {
  assert(ps);
  assert(ps->top > 0);
  return ps->a[ps->top - 1];
}

void Print(ST *ps) {
  for (int i = 0; i < ps->top; i++) {
    printf("%d ", ps->a[i]);
  }
  printf("\n");
}

void test() {
  ST ps;
  StackInit(&ps);
  StackPush(&ps, 0);
  StackPush(&ps, 1);
  StackPush(&ps, 2);
  StackPush(&ps, 3);
  StackPush(&ps, 4);
  StackPush(&ps, 5);
  StackPop(&ps);
  printf("%d\n", StackTop(&ps));
  Print(&ps);
  StackDestroy(&ps);
}

int main() {
  test();
  return 0;
}
