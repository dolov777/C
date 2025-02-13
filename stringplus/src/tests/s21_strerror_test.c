#include "s21_string_test.h"

START_TEST(test_basic) {
  int error = 138;
  char *res_s21 = s21_strerror(error);
  char *res_orig = strerror(error);

  ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_negative) {
  int error = -1;
  char *res_s21 = s21_strerror(error);
  char *res_orig = strerror(error);

  ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_errors) {
  for (int i = 0; i < 150; i++) {
    char *res_s21 = s21_strerror(i);
    char *res_orig = strerror(i);

    ck_assert_str_eq(res_s21, res_orig);
  }
}
END_TEST

START_TEST(test_zero) {
  int error = 0;
  char *res_s21 = s21_strerror(error);
  char *res_orig = strerror(error);

  ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

Suite *strerror_suite(void) {
  Suite *s = suite_create("suite_strerrror");
  TCase *tc = tcase_create("tc_strerror");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_negative);
  tcase_add_test(tc, test_errors);
  tcase_add_test(tc, test_zero);

  suite_add_tcase(s, tc);

  return s;
}