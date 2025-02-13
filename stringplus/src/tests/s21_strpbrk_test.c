#include "s21_string_test.h"

START_TEST(test_basic) {
  char str1[] = "hello world";
  char str2[] = "hello world";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_no_match) {
  char str1[] = "hello world";
  char str2[] = "ab";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str1_empty) {
  char str1[] = "";
  char str2[] = "hello world";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str2_empty) {
  char str1[] = "hello world";
  char str2[] = "";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_both_empty) {
  char str1[] = "";
  char str2[] = "";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_break) {
  char str1[] = "\n";
  char str2[] = "\n";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_space) {
  char str1[] = " ";
  char str2[] = " ";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_line_break) {
  char str1[] = "\0";
  char str2[] = "\0";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_chars) {
  char str1[] = "!@#$$^&*()_";
  char str2[] = "!@#$$";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_start_match) {
  char str1[] = "hello world";
  char str2[] = "h";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_end_match) {
  char str1[] = "hello world";
  char str2[] = "d";

  char *res_s21 = s21_strpbrk(str1, str2);
  char *res_orig = strpbrk(str1, str2);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("tc_strpbrk");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_no_match);
  tcase_add_test(tc, test_str1_empty);
  tcase_add_test(tc, test_str2_empty);
  tcase_add_test(tc, test_both_empty);
  tcase_add_test(tc, test_break);
  tcase_add_test(tc, test_space);
  tcase_add_test(tc, test_line_break);
  tcase_add_test(tc, test_chars);
  tcase_add_test(tc, test_start_match);
  tcase_add_test(tc, test_end_match);

  suite_add_tcase(s, tc);

  return s;
}