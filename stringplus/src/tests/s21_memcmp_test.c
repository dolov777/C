#include "s21_string_test.h"

START_TEST(test_basic) {
  char str1[] = "hello world";
  char str2[] = "hello world";
  s21_size_t len = s21_strlen(str2);

  int res_s21 = s21_memcmp(str1, str2, len);
  int res_orig = memcmp(str1, str2, len);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str2_upper) {
  char str1[] = "hello world";
  char str2[] = "helLo world";
  s21_size_t len = s21_strlen(str2);

  int res_s21 = s21_memcmp(str1, str2, len);
  int res_orig = memcmp(str1, str2, len);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str1_upper) {
  char str1[] = "hellO world";
  char str2[] = "helLo world";
  s21_size_t len = s21_strlen(str2);

  int res_s21 = s21_memcmp(str1, str2, len);
  int res_orig = memcmp(str1, str2, len);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_numbers) {
  char str1[] = "0123456789";
  char str2[] = "0123456789";
  s21_size_t len = s21_strlen(str2);

  int res_s21 = s21_memcmp(str1, str2, len);
  int res_orig = memcmp(str1, str2, len);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str1_empty) {
  char str1[] = "";
  char str2[] = "0123456789";
  s21_size_t len = s21_strlen(str2);

  int res_s21 = s21_memcmp(str1, str2, len);
  int res_orig = memcmp(str1, str2, len);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str2_empty) {
  char str1[] = "0123456789";
  char str2[] = "";
  s21_size_t len = s21_strlen(str2);

  int res_s21 = s21_memcmp(str1, str2, len);
  int res_orig = memcmp(str1, str2, len);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_both_empty) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t len = s21_strlen(str2);

  int res_s21 = s21_memcmp(str1, str2, len);
  int res_orig = memcmp(str1, str2, len);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_len_zero) {
  char str1[] = "hello world";
  char str2[] = "hello world";
  s21_size_t len = 0;

  int res_s21 = s21_memcmp(str1, str2, len);
  int res_orig = memcmp(str1, str2, len);

  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s = suite_create("suite_memcmp");
  TCase *tc = tcase_create("tc_memcmp");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_str2_upper);
  tcase_add_test(tc, test_str1_upper);
  tcase_add_test(tc, test_numbers);
  tcase_add_test(tc, test_str1_empty);
  tcase_add_test(tc, test_str2_empty);
  tcase_add_test(tc, test_both_empty);
  tcase_add_test(tc, test_len_zero);

  suite_add_tcase(s, tc);

  return s;
}