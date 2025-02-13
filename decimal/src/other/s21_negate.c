#include "./../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) {
    return 1;
  }

  for (int i = 0; i < 4; i++) {
    result->bits[i] = value.bits[i];
  }

  int current_sign = s21_get_bit(value, 127);
  s21_set_sign(result, !current_sign);

  return OK;
}
