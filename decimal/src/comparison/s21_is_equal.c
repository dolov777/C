#include "./../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 1;

  if (s21_is_zero(value_1) && s21_is_zero(value_2)) {
    result = 1;
  } else if (s21_get_bit(value_1, 127) != s21_get_bit(value_2, 127)) {
    result = 0;
  } else {
    s21_big_decimal big_value_1 = s21_to_big_decimal(value_1);
    s21_big_decimal big_value_2 = s21_to_big_decimal(value_2);
    s21_normalize_mantissa_big(&big_value_1, &big_value_2);

    for (int i = 0; i < 7 && result; ++i) {
      if (big_value_1.bits[i] != big_value_2.bits[i]) {
        result = 0;
      }
    }
  }

  return result;
}
