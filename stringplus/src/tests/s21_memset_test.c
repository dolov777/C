#include "s21_string_test.h"

START_TEST(test_basic) {
  char str1[] = "abcdef";
  char str2[] = "abcdef";
  char c = 'A';
  int n = 4;

  char* res_s21 = s21_memset(str1, c, n);
  char* res_orig = memset(str2, c, n);

  ck_assert_mem_eq(res_s21, res_orig, n);
}
END_TEST

START_TEST(test_full) {
  char str1[] = "abcdef";
  char str2[] = "abcdef";
  char c = 'A';
  s21_size_t n = s21_strlen(str2);

  char* res_s21 = s21_memset(str1, c, n);
  char* res_orig = memset(str2, c, n);

  ck_assert_mem_eq(res_s21, res_orig, n);
}
END_TEST

START_TEST(test_str_empty) {
  char str1[10] = "";
  char str2[10] = "";
  char c = 'A';
  int n = 1;

  char* res_s21 = s21_memset(str1, c, n);
  char* res_orig = memset(str2, c, n);

  ck_assert_mem_eq(res_s21, res_orig, n);
}
END_TEST

START_TEST(test_space) {
  char str1[] = "   ";
  char str2[] = "   ";
  char c = ' ';
  s21_size_t n = s21_strlen(str2);

  char* res_s21 = s21_memset(str1, c, n);
  char* res_orig = memset(str2, c, n);

  ck_assert_mem_eq(res_s21, res_orig, n);
}
END_TEST

START_TEST(test_break) {
  char str1[] = "\n\n\n\n";
  char str2[] = "\n\n\n\n";
  char c = '\n';
  s21_size_t n = s21_strlen(str2);

  char* res_s21 = s21_memset(str1, c, n);
  char* res_orig = memset(str2, c, n);

  ck_assert_mem_eq(res_s21, res_orig, n);
}
END_TEST

START_TEST(test_line_break) {
  char str1[] = "\0\0\0\0";
  char str2[] = "\0\0\0\0";
  char c = '\0';
  s21_size_t n = s21_strlen(str2);

  char* res_s21 = s21_memset(str1, c, n);
  char* res_orig = memset(str2, c, n);

  ck_assert_mem_eq(res_s21, res_orig, n);
}
END_TEST

START_TEST(test_c_symbol) {
  char str1[] = "hello world";
  char str2[] = "hello world";
  char c = '^';
  int n = 5;

  char* res_s21 = s21_memset(str1, c, n);
  char* res_orig = memset(str2, c, n);

  ck_assert_mem_eq(res_s21, res_orig, n);
}
END_TEST

START_TEST(test_n_larger) {
  char str1[100] = "hello world";
  char str2[100] = "hello world";
  char c = '^';
  int n = 20;

  char* res_s21 = s21_memset(str1, c, n);
  char* res_orig = memset(str2, c, n);

  ck_assert_mem_eq(res_s21, res_orig, n);
}
END_TEST

Suite* memset_suite(void) {
  Suite* s = suite_create("suite_memset");
  TCase* tc = tcase_create("tc_memset");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_full);
  tcase_add_test(tc, test_str_empty);
  tcase_add_test(tc, test_space);
  tcase_add_test(tc, test_break);
  tcase_add_test(tc, test_line_break);
  tcase_add_test(tc, test_c_symbol);
  tcase_add_test(tc, test_n_larger);

  suite_add_tcase(s, tc);

  return s;
}
