#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  void *result = s21_NULL;

  if (src && str) {
    s21_size_t str_len = s21_strlen(str);
    s21_size_t src_len = s21_strlen(src);

    if (start_index <= src_len) {
      char *new_str = (char *)malloc((str_len + src_len + 1) * sizeof(char));
      if (new_str) {
        // Копируем часть str до индекса
        for (s21_size_t i = 0; i < start_index; i++) {
          new_str[i] = src[i];
        }

        // всавлям на место указанного индекса элемент
        for (s21_size_t i = 0; i < str_len; i++) {
          new_str[start_index + i] = str[i];
        }

        // вставляем оставшуюся часть элементов
        for (s21_size_t i = start_index; i < src_len; i++) {
          new_str[str_len + i] = src[i];
        }

        new_str[src_len + str_len] = '\0';
        result = new_str;
      }
    }
  }

  return result;
}