#include "./../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = 0;

  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }

  int sign = (src < 0) ? 1 : 0;

  if (src == INT_MIN) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0x80000000;
  } else {
    if (sign) {
      src = -src;
    }

    dst->bits[0] = (unsigned int)src;
    dst->bits[3] = sign << 31;
  }

  return result;
}