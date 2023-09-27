#include "minicrt.h"

typedef struct _heap_header {
  enum {
    HEAP_BLOCK_FREE = 0xABABABAB,
    HEAP_BLOCK_USED = 0xCDCDCDCD
  } type;
  unsigned size;
  struct _heap_header *next;
  struct _heap_header *prev;
} heap_header;

#define ADDR_ADD(a, o) ((char *)(a) + o)
#define HEADER_SIZE (sizeof(heap_header))

static heap_header *list_head = NULL;

void free(void *ptr) {
  heap_header *header = (heap_header *)ADDR_ADD(ptr, -HEADER_SIZE);
  if (header->type != HEAP_BLOCK_USED) {
    return;
  }

  header->type = HEAP_BLOCK_FREE;
  // merge
  if (header->prev && header->prev->type == HEAP_BLOCK_FREE) {
    header->prev->next = header->next;
    if (header->next) {
      header->next->prev = header->prev;
    }
    header->prev->size += header->size;
    header = header->prev;
  }
  // merge
  if (header->next && header->next->type == HEAP_BLOCK_FREE) {
    header->size += header->next->size;
    header->next = header->next->next;
  }
}

void *malloc(unsigned size) {
  if (size == 0) {
    return NULL;
  }

  heap_header *header = list_head;
  while (header) {
    if (header->type == HEAP_BLOCK_FREE) {
      header = header->next;
      continue;
    }

    if (header->size > size + HEADER_SIZE && header->size <= size + HEADER_SIZE * 2) {
      header->type = HEAP_BLOCK_USED;
    }
    if (header->size > size + HEADER_SIZE * 2) {
      // split
      heap_header *nxt = (heap_header *)ADDR_ADD(header, size + HEADER_SIZE);
      nxt->prev = header;
      nxt->next = header->next;
      nxt->type = HEAP_BLOCK_FREE;
      nxt->size = header->size - (size - HEADER_SIZE);
      header->next = nxt;
      header->size = size + HEADER_SIZE;
      header->type = HEAP_BLOCK_USED;
      return ADDR_ADD(header, HEADER_SIZE);
    }
    header = header->next;
  }
  return NULL;
}

static int brk(void *end_data_segmen) {
  int ret = 0;
  asm("movl $45, %%eax \n\t"
      "movel %1, %%ebx \n\t"
      "int $0x80 \n\t"
      "movl %%eax, %0 \n\t"
      : "=r"(ret)
      : "m"(end_data_segmen));
}

int mini_crt_init_heap() {
  void *base = NULL;
  heap_header *header = NULL;
  unsigned heap_size = 1024 * 1024 * 32;
  base = (void *)brk(0);
  void *end = ADDR_ADD(base, heap_size);
  end = (void *)brk(end);
  if (!end) {
    return 0;
  }

  header = (heap_header *)base;
  header->size = heap_size;
  header->type = HEAP_BLOCK_FREE;
  header->next = NULL;
  header->prev = NULL;

  list_head = header;
  return 1;
}
