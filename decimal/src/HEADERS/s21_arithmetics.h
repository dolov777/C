#ifndef HEADERS_S21_ARITHMETICS_H_
#define HEADERS_S21_ARITHMETICS_H_
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

int s21_sub(s21_decimal value1, s21_decimal value2, s21_decimal* result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

#endif