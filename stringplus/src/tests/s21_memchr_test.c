#include "s21_string_test.h"

START_TEST(test_basic) {
  char str[] = "hello world";
  s21_size_t len = s21_strlen(str);

  char *res_s21 = s21_memchr(str, 'l', len);
  char *res_orig = memchr(str, 'l', len);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str_empty) {
  char str[] = "";
  s21_size_t len = s21_strlen(str);

  char *res_s21 = s21_memchr(str, 'l', len);
  char *res_orig = memchr(str, 'l', len);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_first_match) {
  char str[] = "hello world";
  s21_size_t len = s21_strlen(str);

  char *res_s21 = s21_memchr(str, 'h', len);
  char *res_orig = memchr(str, 'h', len);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_end_match) {
  char str[] = "hello world";
  s21_size_t len = s21_strlen(str);

  char *res_s21 = s21_memchr(str, 'd', len);
  char *res_orig = memchr(str, 'd', len);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_spaces) {
  char str[] = "             ";
  s21_size_t len = s21_strlen(str);

  char *res_s21 = s21_memchr(str, ' ', len);
  char *res_orig = memchr(str, ' ', len);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_space) {
  char str[] = "hello world";
  s21_size_t len = s21_strlen(str);

  char *res_s21 = s21_memchr(str, ' ', len);
  char *res_orig = memchr(str, ' ', len);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_break) {
  char str[] = "hello world\n";
  s21_size_t len = s21_strlen(str);

  char *res_s21 = s21_memchr(str, '\n', len);
  char *res_orig = memchr(str, '\n', len);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_line_break) {
  char str[] = "hello world\0";
  s21_size_t len = s21_strlen(str);

  char *res_s21 = s21_memchr(str, '\0', len);
  char *res_orig = memchr(str, '\0', len);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_not_found) {
  char str[] = "hello world\0";
  s21_size_t len = s21_strlen(str);

  char *res_s21 = s21_memchr(str, '1', len);
  char *res_orig = memchr(str, '1', len);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_c_numbers) {
  char str[] = "hello world";
  s21_size_t len = s21_strlen(str);

  char *res_s21 = s21_memchr(str, -2, len);
  char *res_orig = memchr(str, -2, len);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

Suite *memchr_suite(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("tc_memchr");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_str_empty);
  tcase_add_test(tc, test_first_match);
  tcase_add_test(tc, test_end_match);
  tcase_add_test(tc, test_spaces);
  tcase_add_test(tc, test_space);
  tcase_add_test(tc, test_break);
  tcase_add_test(tc, test_line_break);
  tcase_add_test(tc, test_not_found);
  tcase_add_test(tc, test_c_numbers);

  suite_add_tcase(s, tc);

  return s;
}