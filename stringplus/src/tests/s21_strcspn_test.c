#include "s21_string_test.h"

START_TEST(test_basic) {
  char str1[] = "Hello, world!\n";
  char str2[] = "hello";

  s21_size_t res_s21 = s21_strcspn(str1, str2);
  s21_size_t res_orig = strcspn(str1, str2);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_number) {
  char str1[] = "Hello, world!\n";
  char str2[] = "1";

  s21_size_t res_s21 = s21_strcspn(str1, str2);
  s21_size_t res_orig = strcspn(str1, str2);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_symbols) {
  char str1[] = "_;,-!()*&^$#";
  char str2[] = "alo";

  s21_size_t res_s21 = s21_strcspn(str1, str2);
  s21_size_t res_orig = strcspn(str1, str2);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str1_empty) {
  char str1[] = "";
  char str2[] = "alo";

  s21_size_t res_s21 = s21_strcspn(str1, str2);
  s21_size_t res_orig = strcspn(str1, str2);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str2_empty) {
  char str1[] = "hello";
  char str2[] = "";

  s21_size_t res_s21 = s21_strcspn(str1, str2);
  s21_size_t res_orig = strcspn(str1, str2);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_both_empty) {
  char str1[] = "";
  char str2[] = "";

  s21_size_t res_s21 = s21_strcspn(str1, str2);
  s21_size_t res_orig = strcspn(str1, str2);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_break) {
  char str1[] = "hello\n\n";
  char str2[] = "\n";

  s21_size_t res_s21 = s21_strcspn(str1, str2);
  s21_size_t res_orig = strcspn(str1, str2);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_symbols_two) {
  char str1[] = "hello world hello world hello world hello world.\n";
  char str2[] = "_!\t\n";

  s21_size_t res_s21 = s21_strcspn(str1, str2);
  s21_size_t res_orig = strcspn(str1, str2);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("tc_strcspn");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_number);
  tcase_add_test(tc, test_symbols);
  tcase_add_test(tc, test_str1_empty);
  tcase_add_test(tc, test_str2_empty);
  tcase_add_test(tc, test_both_empty);
  tcase_add_test(tc, test_break);
  tcase_add_test(tc, test_symbols_two);

  suite_add_tcase(s, tc);

  return s;
}