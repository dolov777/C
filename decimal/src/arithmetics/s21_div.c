#include "./../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  for (int i = 0; i < 4; i++) result->bits[i] = 0;
  int code = 0;
  if (s21_is_zero_decimal(value_2)) {
    code = 3;
  } else {
    int sign1 = s21_get_bit(value_1, 127);
    int sign2 = s21_get_bit(value_2, 127);

    s21_big_decimal big_value_1 = s21_to_big_decimal(value_1);
    s21_big_decimal big_value_2 = s21_to_big_decimal(value_2);
    s21_normalize_mantissa_big(&big_value_1, &big_value_2);
    s21_big_decimal big_result = {0};
    int scale = 0;

    s21_big_div(big_value_1, big_value_2, &big_result, &scale);

    if (overflow_check_big(big_result)) {
      if (s21_fixOverflow(&big_result, &scale)) {
        code = sign1 == sign2 ? 1 : 2;
      } else {
        s21_to_decimal(big_result, result);
        s21_set_result_sign_and_scale(result, sign1, sign2, scale);
      }
    } else {
      s21_to_decimal(big_result, result);
      s21_set_result_sign_and_scale(result, sign1, sign2, scale);
    }
  }
  return code;
}
