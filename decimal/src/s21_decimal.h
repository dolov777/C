#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>

#define OK 0

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct s21_big_decimal {
  unsigned int bits[8];
} s21_big_decimal;

#include "./HEADERS/s21_arithmetics.h"
#include "./HEADERS/s21_comparison.h"
#include "./HEADERS/s21_convertors.h"
#include "./HEADERS/s21_helpers.h"
#include "./HEADERS/s21_other.h"

#endif
