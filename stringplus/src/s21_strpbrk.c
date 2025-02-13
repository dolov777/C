#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  while (*str1 && !res) {
    const char *s2 = str2;
    while (*s2) {
      if (*str1 == *s2) {
        res = (char *)str1;
        break;
      }
      s2++;
    }
    str1++;
  }

  return res;
}
