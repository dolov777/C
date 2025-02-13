#include "s21_string_test.h"

START_TEST(test_basic) {
  char src[] = "** *Hello, world!\n*  *";
  char trim_chars[] = "* ";

  char *res_s21 = s21_trim(src, trim_chars);
  char *res_orig = "Hello, world!\n";

  ck_assert_str_eq(res_s21, res_orig);
  if (res_s21) free(res_s21);
}
END_TEST

START_TEST(test_not_found) {
  char src[] = "Hello, world!";
  char trim_chars[] = "*";

  char *res_s21 = s21_trim(src, trim_chars);
  char *res_orig = "Hello, world!";

  ck_assert_str_eq(res_s21, res_orig);
  if (res_s21) free(res_s21);
}
END_TEST

START_TEST(test_break) {
  char src[] = "\nHello, world!\n\n";
  char trim_chars[] = "\n";

  char *res_s21 = s21_trim(src, trim_chars);
  char *res_orig = "Hello, world!";

  ck_assert_str_eq(res_s21, res_orig);
  if (res_s21) free(res_s21);
}
END_TEST

START_TEST(test_src_null) {
  char *src = s21_NULL;
  char trim_chars[] = "*";

  char *res_s21 = s21_trim(src, trim_chars);

  ck_assert_ptr_eq(res_s21, s21_NULL);
  if (res_s21) free(res_s21);
}
END_TEST

START_TEST(test_trim_chars_null) {
  char src[] = "hello world";
  char *trim_chars = s21_NULL;

  char *res_s21 = s21_trim(src, trim_chars);

  ck_assert_ptr_eq(res_s21, s21_NULL);
  if (res_s21) free(res_s21);
}
END_TEST

START_TEST(test_line_break) {
  char src[] = "hello world\0";
  char trim_chars[] = "\0";

  char *res_s21 = s21_trim(src, trim_chars);
  char *res_orig = "hello world";

  ck_assert_str_eq(res_s21, res_orig);
  if (res_s21) free(res_s21);
}
END_TEST

START_TEST(test_spaces) {
  char src[] = "                     ";
  char trim_chars[] = " ";

  char *res_s21 = s21_trim(src, trim_chars);
  char *res_orig = "";

  ck_assert_str_eq(res_s21, res_orig);
  if (res_s21) free(res_s21);
}
END_TEST

Suite *trim_suite(void) {
  Suite *s = suite_create("suite_trim");
  TCase *tc = tcase_create("tc_trim");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_not_found);
  tcase_add_test(tc, test_break);
  tcase_add_test(tc, test_src_null);
  tcase_add_test(tc, test_trim_chars_null);
  tcase_add_test(tc, test_line_break);
  tcase_add_test(tc, test_spaces);

  suite_add_tcase(s, tc);

  return s;
}