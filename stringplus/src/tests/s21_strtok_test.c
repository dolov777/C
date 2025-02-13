#include "s21_string_test.h"

START_TEST(test_basic) {
  char str1[] = "hello, world!";
  char str2[] = "hello, world!";
  char delim[] = ", ";

  char *res_s21 = s21_strtok(str1, delim);
  char *res_orig = strtok(str2, delim);

  while (res_s21 != s21_NULL || res_orig != NULL) {
    ck_assert_str_eq(res_s21, res_orig);

    res_s21 = s21_strtok(s21_NULL, delim);
    res_orig = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_delim_empty) {
  char str1[] = "hello, world!";
  char str2[] = "hello, world!";
  char delim[] = "";

  char *res_s21 = s21_strtok(str1, delim);
  char *res_orig = strtok(str2, delim);

  while (res_s21 != s21_NULL || res_orig != NULL) {
    ck_assert_str_eq(res_s21, res_orig);

    res_s21 = s21_strtok(s21_NULL, delim);
    res_orig = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_str_empty) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = "!";

  char *res_s21 = s21_strtok(str1, delim);
  char *res_orig = strtok(str2, delim);

  ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_both_empty) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = "";

  char *res_s21 = s21_strtok(str1, delim);
  char *res_orig = strtok(str2, delim);

  ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_space) {
  char str1[] = " ";
  char str2[] = " ";
  char delim[] = " ";

  char *res_s21 = s21_strtok(str1, delim);
  char *res_orig = strtok(str2, delim);

  ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_no_match) {
  char str1[] = "Hello World";
  char str2[] = "Hello World";
  char delim[] = ",";

  char *res_s21 = s21_strtok(str1, delim);
  char *res_orig = strtok(str2, delim);

  ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_double_space) {
  char str1[] = "Hello   World   World!";
  char str2[] = "Hello   World   World!";
  char delim[] = " ";

  char *res_s21 = s21_strtok(str1, delim);
  char *res_orig = strtok(str2, delim);

  while (res_s21 != s21_NULL || res_orig != NULL) {
    ck_assert_str_eq(res_s21, res_orig);

    res_s21 = s21_strtok(s21_NULL, delim);
    res_orig = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_break) {
  char str1[] = "\n";
  char str2[] = "\n";
  char delim[] = "\n";

  char *res_s21 = s21_strtok(str1, delim);
  char *res_orig = strtok(str2, delim);

  ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_spaces) {
  char str1[] = "             ";
  char str2[] = "             ";
  char delim[] = " ";

  char *res_s21 = s21_strtok(str1, delim);
  char *res_orig = strtok(str2, delim);

  ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("tc_strtok");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_delim_empty);
  tcase_add_test(tc, test_str_empty);
  tcase_add_test(tc, test_both_empty);
  tcase_add_test(tc, test_space);
  tcase_add_test(tc, test_no_match);
  tcase_add_test(tc, test_double_space);
  tcase_add_test(tc, test_break);
  tcase_add_test(tc, test_spaces);

  suite_add_tcase(s, tc);

  return s;
}