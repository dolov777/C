#include "s21_string.h"

char *s21_strncpy(char *str1, const char *str2, s21_size_t n) {
  s21_size_t i;

  // Копируем символы из str2 в str1 до n символов или пока не достигнем конца
  // str2
  for (i = 0; i < n && str2[i] != '\0'; i++) {
    str1[i] = str2[i];
  }

  // Заполняем оставшиеся символы в str1 символом '\0', если str2 закончилась
  // раньше n
  for (; i < n; i++) {
    str1[i] = '\0';
  }

  return str1;
}