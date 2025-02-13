#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <check.h>

#include "../s21_matrix.h"

#define TEST_EPS (1e-07)

void s21_suit_execution(Suite *suite, int *failed_count, char *suite_name);

#endif
