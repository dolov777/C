#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *to_lower = s21_NULL;

  if (str != s21_NULL) {
    int len = 0;
    while (str[len] != '\0') {
      len++;
    }

    to_lower = (char *)malloc((len + 1) * sizeof(char));

    if (to_lower != s21_NULL) {
      for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          to_lower[i] = str[i] - 'A' + 'a';
        } else {
          to_lower[i] = str[i];
        }
      }
      to_lower[len] = '\0';
    }
  }

  return (void *)to_lower;
}
