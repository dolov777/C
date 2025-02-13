#include "s21_string_test.h"

START_TEST(test_basic) {
  char src[] = "hello world";
  char str[] = "my ";
  int index = 6;

  char *res_s21 = s21_insert(src, str, index);
  char *res = "hello my world";

  ck_assert_str_eq(res_s21, res);
  free(res_s21);
}
END_TEST

START_TEST(test_str_empty) {
  char src[] = "hello world";
  char str[] = "";
  int index = 2;

  char *res_s21 = s21_insert(src, str, index);
  char *res = "hello world";

  ck_assert_str_eq(res_s21, res);
  free(res_s21);
}
END_TEST

START_TEST(test_src_empty) {
  char src[] = "";
  char str[] = "abd";
  int index = 0;

  char *res_s21 = s21_insert(src, str, index);
  char *res = "abd";

  ck_assert_str_eq(res_s21, res);
  free(res_s21);
}
END_TEST

START_TEST(test_both_empty) {
  char src[] = "";
  char str[] = "";
  int index = 0;

  char *res_s21 = s21_insert(src, str, index);
  char *res = "";

  ck_assert_str_eq(res_s21, res);
  free(res_s21);
}
END_TEST

START_TEST(test_index_larger) {
  char src[] = "abcde";
  char str[] = "e";
  int index = 8;

  char *res_s21 = s21_insert(src, str, index);

  ck_assert_ptr_null(res_s21);
  free(res_s21);
}
END_TEST

START_TEST(test_src_null) {
  char *src = s21_NULL;
  char *str = "e";
  int index = 8;

  char *res_s21 = s21_insert(src, str, index);

  ck_assert_ptr_null(res_s21);
  free(res_s21);
}
END_TEST

START_TEST(test_str_null) {
  char *src = "hello world";
  char *str = s21_NULL;
  int index = 8;

  char *res_s21 = s21_insert(src, str, index);

  ck_assert_ptr_null(res_s21);
  free(res_s21);
}
END_TEST

Suite *insert_suite(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("tc_insert");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_str_empty);
  tcase_add_test(tc, test_src_empty);
  tcase_add_test(tc, test_both_empty);
  tcase_add_test(tc, test_index_larger);
  tcase_add_test(tc, test_src_null);
  tcase_add_test(tc, test_str_null);

  suite_add_tcase(s, tc);

  return s;
}