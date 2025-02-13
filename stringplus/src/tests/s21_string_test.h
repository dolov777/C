#ifndef STRING_TEST_H
#define STRING_TEST_H

#include <check.h>
#include <stddef.h>
#include <string.h>

#include "../s21_string.h"

Suite *strchr_suite(void);
Suite *strstr_suite(void);
Suite *strrchr_suite(void);
Suite *strlen_suite(void);
Suite *strerror_suite(void);
Suite *memcmp_suite(void);
Suite *strncmp_suite(void);
Suite *strpbrk_suite(void);
Suite *strtok_suite(void);
Suite *memset_suite(void);
Suite *memchr_suite(void);
Suite *strcspn_suite(void);
Suite *strncat_suite(void);
Suite *strncpy_suite(void);
Suite *memcpy_suite(void);
Suite *sprintf_suite(void);

Suite *trim_suite(void);
Suite *insert_suite(void);
Suite *to_lower_suite(void);
Suite *to_upper_suite(void);

#endif