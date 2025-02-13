#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *elem = s21_NULL;
  const char *count = str;

  while (*count != '\0') {
    if (*count == (char)c) {
      elem = count;
    }
    count++;
  }
  if (*count == (char)c) {
    elem = count;
  }

  return (char *)elem;
}
