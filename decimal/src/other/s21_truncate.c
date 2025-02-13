#include "./../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_reset(result);
  int scale = s21_get_scale(value);
  while (scale > 0) {
    s21_div_ten(&value);
    scale--;
  }
  *result = value;
  s21_set_scale(result, scale);
  return 0;
}