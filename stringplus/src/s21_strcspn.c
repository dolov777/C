#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  int found = 0;

  while (str1[result] != '\0') {
    s21_size_t index = 0;
    while (str2[index] != '\0') {
      if (str1[result] == str2[index]) {
        found = 1;
        break;
      }
      index++;
    }
    if (!found) {
      result++;
    } else {
      break;
    }
  }

  return result;
}
