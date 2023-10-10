#ifndef __MINI_CRT_H__
#define __MINI_CRT_H__

#ifndef NULL
#define NULL (0)
#endif

void free(void *ptr);
void *malloc(unsigned size);
static int brk(void *end_data_segment);
int mini_crt_init_heap();

char *itoa(int n, char *str, int radix);
int strcmp(const char *src, const char *dst);
char *strcpy(char *dest, const char *src);
unsigned strlen(const char *str);

#define EOF (-1)
#define stdin ((int *)0)
#define stdout ((int *)1)
#define stderr ((int *)2)

int mini_crt_init_io();
int *fopen(const char *filename, const char *mode);
int fread(void *buffer, int size, int count, int *stream);
int fwrite(const void *buffer, int size, int count, int *stream);
int fclose(int *fp);
int fseek(int *fp, int offset, int set);

int fputc(int c, int *stream);
int fputs(const char *str, int *stream);
int printf(const char *format, ...);
int vfprintf(int *stream, const char *format, ...);

void do_global_ctors();
void mini_crt_call_exit_routine();

typedef void (*atexit_func_t)(void);
int atexit(atexit_func_t func);

#endif
