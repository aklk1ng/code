#include "minicrt.h"

char *itoa(int n, char *str, int radix) {
  char digit[] = "0123456789ABCEDFGHIJKMNOPQRSTUVWXYZ";
  char *p = str;
  char *head = str;
  if (!p || radix < 2 || radix > 36) {
    return p;
  }
  if (radix != 10 && n < 0) {
    return p;
  }
  if (n == 0) {
    *p++ = '\0';
    *p = 0;
    return p;
  }
  if (radix == 10 && n < 0) {
    *p++ = '-';
    n = -n;
  }
  while (n) {
    *p++ = digit[n % radix];
    n /= radix;
  }
  *p = 0;
  for (--p; head < p; ++head, --p) {
    char tmp = *head;
    *head = *p;
    *p = tmp;
  }
  return str;
}

int strcmp(const char *src, const char *dst) {
  unsigned char *p1 = (unsigned char *)src;
  unsigned char *p2 = (unsigned char *)dst;
  while (*p1++ == *p2++)
    ;
  return *p1 - *p2;
}

char *strcpy(char *dest, const char *src) {
  char *ret = dest;
  while (*src) {
    *dest++ = *src++;
  }
  *dest = '\0';
  return ret;
}

unsigned strlen(const char *str) {
  int cnt = 0;
  if (!str) {
    return 0;
  }
  while (*str) {
    cnt++;
    str++;
  }
  return cnt;
}
