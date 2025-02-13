#include "s21_string_test.h"

START_TEST(test_basic) {
  char dest_s21[128] = "hello";
  char dest[128] = "hello";
  char src[] = " world";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_strncat(dest_s21, src, len);
  char *res_orig = strncat(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_dest_empty) {
  char dest_s21[128] = "";
  char dest[128] = "";
  char src[] = " world";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_strncat(dest_s21, src, len);
  char *res_orig = strncat(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_src_empty) {
  char dest_s21[128] = "hello";
  char dest[128] = "hello";
  char src[] = "";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_strncat(dest_s21, src, len);
  char *res_orig = strncat(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_both_empty) {
  char dest_s21[128] = "";
  char dest[128] = "";
  char src[] = "";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_strncat(dest_s21, src, len);
  char *res_orig = strncat(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_spaces) {
  char dest_s21[128] = "hello";
  char dest[128] = "hello";
  char src[] = "           ";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_strncat(dest_s21, src, len);
  char *res_orig = strncat(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_len_larger) {
  char dest_s21[128] = "hello";
  char dest[128] = "hello";
  char src[] = "world";
  int len = 6;

  char *res_s21 = s21_strncat(dest_s21, src, len);
  char *res_orig = strncat(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_break) {
  char dest_s21[128] = "hello\n\n";
  char dest[128] = "hello\n\n";
  char src[] = "\n\n";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_strncat(dest_s21, src, len);
  char *res_orig = strncat(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_line_break) {
  char dest_s21[128] = "\0\0";
  char dest[128] = "\0\0";
  char src[] = "~";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_strncat(dest_s21, src, len);
  char *res_orig = strncat(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s = suite_create("suite_strncat");
  TCase *tc = tcase_create("tc_strncat");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_dest_empty);
  tcase_add_test(tc, test_src_empty);
  tcase_add_test(tc, test_both_empty);
  tcase_add_test(tc, test_spaces);
  tcase_add_test(tc, test_len_larger);
  tcase_add_test(tc, test_break);
  tcase_add_test(tc, test_line_break);

  suite_add_tcase(s, tc);

  return s;
}