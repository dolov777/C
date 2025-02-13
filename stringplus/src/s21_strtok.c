#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last = s21_NULL;
  char *token = s21_NULL;

  if (str != s21_NULL) {
    last = str;
  }

  int end_of_string = 0;

  if (last == s21_NULL) {
    end_of_string = 1;
  } else {
    while (*last && s21_strchr(delim, *last)) {
      last++;
    }

    if (*last == '\0') {
      end_of_string = 1;
    } else {
      token = last;
      while (*last && !s21_strchr(delim, *last)) {
        last++;
      }

      if (*last) {
        *last = '\0';
        last++;
      } else {
        last = s21_NULL;
      }
    }
  }

  return end_of_string ? s21_NULL : token;
}