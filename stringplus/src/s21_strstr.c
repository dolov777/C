#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;

  if (!*needle) {
    res = (char *)haystack;
  } else {
    for (const char *h = haystack; *h; h++) {
      if (*h == *needle) {
        const char *h_sub = h;
        const char *n_sub = needle;

        while (*h_sub && *n_sub && *h_sub == *n_sub) {
          h_sub++;
          n_sub++;
        }

        if (!*n_sub) {
          res = (char *)h;
          break;
        }
      }
    }
  }

  return res;
}