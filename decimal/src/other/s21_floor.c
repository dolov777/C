#include "./../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int err_code;
  s21_decimal one = {{1, 0, 0, 0}};
  s21_reset(result);

  if (result == NULL) {
    err_code = 1;
  }

  int scale = s21_get_scale(value);
  int sign = s21_get_bit(value, 127);

  s21_truncate(value, result);

  if (scale == 0) {
    *result = value;
  } else if (scale > 0 && sign == 1) {
    s21_sub(*result, one, result);
  }

  return err_code;
}