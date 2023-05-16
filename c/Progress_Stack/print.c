#include <elf.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
  int *p = (int *)argv;
  int i = 0;
  Elf32_auxv_t *aux;
  printf("Argument count: %d\n", *(p - 1));

  for (; i < *(p - 1); i++) {
    printf("Argument%d: %s\n", i, *(p + i));
  }
  p += i;
  // skip the 0
  p++;

  printf("Environment:\n");
  while (*p) {
    printf("%s\n", *p);
    p++;
  }
  // skip the 0
  p++;

  printf("Auxiliary Vectors:\n");
  aux = (Elf32_auxv_t *)p;
  while (aux->a_type != AT_NULL) {
    printf("Type: %02d Value: %x\n", aux->a_type, aux->a_un.a_val);
    aux++;
  }
}
