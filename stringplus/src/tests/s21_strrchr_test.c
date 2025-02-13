#include "s21_string_test.h"

START_TEST(test_basic) {
  char *str = "hello world";
  char c = 'o';

  char *res_s21 = s21_strrchr(str, c);
  char *res_orig = strrchr(str, c);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_char_equals) {
  char *str = "o";
  char c = 'o';

  char *res_s21 = s21_strrchr(str, c);
  char *res_orig = strrchr(str, c);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_not_found) {
  char *str = "hello world";
  char c = 'r';

  char *res_s21 = s21_strrchr(str, c);
  char *res_orig = strrchr(str, c);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str_empty) {
  char *str = "";
  char c = 'o';

  char *res_s21 = s21_strrchr(str, c);
  char *res_orig = strrchr(str, c);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_line_break) {
  char *str = "\0\0\0";
  char c = '\0';

  char *res_s21 = s21_strrchr(str, c);
  char *res_orig = strrchr(str, c);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_c_break) {
  char *str = "hello";
  char c = '\0';

  char *res_s21 = s21_strrchr(str, c);
  char *res_orig = strrchr(str, c);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_c_space) {
  char *str = "hello world ";
  char c = ' ';

  char *res_s21 = s21_strrchr(str, c);
  char *res_orig = strrchr(str, c);

  ck_assert_pstr_eq(res_s21, res_orig);
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("tc_strrchr");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_char_equals);
  tcase_add_test(tc, test_not_found);
  tcase_add_test(tc, test_str_empty);
  tcase_add_test(tc, test_line_break);
  tcase_add_test(tc, test_c_break);
  tcase_add_test(tc, test_c_space);

  suite_add_tcase(s, tc);

  return s;
}