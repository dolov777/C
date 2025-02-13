#include "./../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (dst == NULL) return 1;

  int sign = (src.bits[3] & 0x80000000) ? -1 : 1;

  int exponent = (src.bits[3] >> 16) & 0xFF;

  double mantissa = (double)src.bits[0];
  mantissa += (double)src.bits[1] * 4294967296.0;
  mantissa += (double)src.bits[2] * 1.844674407370955e+19;

  double factor = pow(10.0, -exponent);

  double result = sign * mantissa * factor;

  if (result > FLT_MAX || result < -FLT_MAX) return 1;

  *dst = (float)result;

  return 0;
}
