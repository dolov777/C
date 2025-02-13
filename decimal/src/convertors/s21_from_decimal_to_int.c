#include "./../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int result = 0;
  *dst = 0;

  int sign = s21_get_bit(src, 127);

  s21_truncate(src, &src);

  if (src.bits[1] != 0 || src.bits[2] != 0) {
    result = 1;
  } else if (sign == 0 && src.bits[0] > INT_MAX) {
    result = 1;
  } else if (sign == 1 && src.bits[0] > (unsigned int)INT_MAX + 1) {
    result = 1;
  } else if (sign == 1 && src.bits[0] == (unsigned int)INT_MAX + 1) {
    *dst = INT_MIN;
  } else {
    *dst = src.bits[0];
    if (sign == 1) {
      *dst = -*dst;
    }
  }

  return result;
}