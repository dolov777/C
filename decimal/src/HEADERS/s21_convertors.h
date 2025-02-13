#ifndef HEADERS_S21_CONVERTORS_H_
#define HEADERS_S21_CONVERTORS_H_
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#define DEC_MAX 7.9228162514264337593543950335e+28

int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);

#endif