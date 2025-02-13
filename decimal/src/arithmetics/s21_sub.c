#include <stdio.h>

#include "./../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  s21_reset(result);

  s21_big_decimal big_value_1 = s21_to_big_decimal(value_1);
  s21_big_decimal big_value_2 = s21_to_big_decimal(value_2);
  s21_normalize_mantissa_big(&big_value_1, &big_value_2);
  s21_big_decimal big_result = {0};

  int sign1 = s21_get_bit(value_1, 127);
  int sign2 = s21_get_bit(value_2, 127);
  int scale = s21_get_big_scale(big_value_1);
  int final_sign = 0;

  if (sign1 && sign2) {
    if (s21_is_greater_or_equal_big(big_value_2, big_value_1)) {
      s21_big_minus(big_value_2, big_value_1, &big_result);
    } else {
      s21_big_minus(big_value_1, big_value_2, &big_result);
      final_sign = 1;
    }
  } else if (!sign1 && sign2) {
    s21_big_plus(big_value_1, big_value_2, &big_result);
  } else if (sign1 && !sign2) {
    s21_big_plus(big_value_1, big_value_2, &big_result);
    final_sign = 1;
  } else {
    if (s21_is_greater_or_equal_big(big_value_2, big_value_1)) {
      s21_big_minus(big_value_2, big_value_1, &big_result);
      final_sign = 1;
    } else {
      s21_big_minus(big_value_1, big_value_2, &big_result);
    }
  }

  if (s21_overflow_check_big(big_result)) {
    if (s21_fixOverflow(&big_result, &scale)) {
      code = sign1 == sign2 ? 1 : 2;
    } else {
      s21_to_decimal(big_result, result);
      s21_set_bit(result, 127, final_sign);
      s21_set_scale(result, scale);
    }
  } else {
    s21_to_decimal(big_result, result);
    s21_set_bit(result, 127, final_sign);
    s21_set_scale(result, scale);
  }
  return code;
}
