#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *result = (const unsigned char *)str;
  int status = 0;
  int x = 0;

  while (status == 0 && result && (s21_size_t)x < n) {
    if (result[x] == (unsigned char)c) {
      if (c != '\0') {
        result += x;
      }
      status = 1;
    }
    x += 1;
  }

  return status ? ((void *)result) : s21_NULL;
}
