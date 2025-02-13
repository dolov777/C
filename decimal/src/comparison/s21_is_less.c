#include "./../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  int sign1 = s21_get_bit(value_1, 127);
  int sign2 = s21_get_bit(value_2, 127);

  if (s21_is_zero(value_1) && s21_is_zero(value_2)) {
    result = 0;
  } else if (sign1 != sign2) {
    result = sign1 ? 1 : 0;
  } else {
    s21_big_decimal big_value_1 = s21_to_big_decimal(value_1);
    s21_big_decimal big_value_2 = s21_to_big_decimal(value_2);
    s21_normalize_mantissa_big(&big_value_1, &big_value_2);

    for (int i = 6; i >= 0; i--) {
      if (big_value_1.bits[i] < big_value_2.bits[i]) {
        result = !sign1;
        break;
      } else if (big_value_1.bits[i] > big_value_2.bits[i]) {
        result = sign1;
        break;
      }
    }
  }

  return result;
}
