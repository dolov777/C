#include "s21_string_test.h"

START_TEST(test_basic) {
  char dest_s21[] = "hello world";
  char dest[] = "hello world";
  char src[] = "!";
  int len = s21_strlen(src);

  s21_strncpy(dest_s21, src, len);
  strncpy(dest, src, len);

  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

START_TEST(test_dest_empty) {
  char dest_s21[20] = "";
  char dest[20] = "";
  char src[] = "!";
  int len = s21_strlen(src);

  s21_strncpy(dest_s21, src, len);
  strncpy(dest, src, len);

  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

START_TEST(test_src_empty) {
  char dest_s21[] = "hello";
  char dest[] = "hello";
  char src[] = "";
  int len = s21_strlen(src);

  s21_strncpy(dest_s21, src, len);
  strncpy(dest, src, len);

  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

START_TEST(test_both_empty) {
  char dest_s21[] = "";
  char dest[] = "";
  char src[] = "";
  int len = s21_strlen(src);

  s21_strncpy(dest_s21, src, len);
  strncpy(dest, src, len);

  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

START_TEST(test_len_zero) {
  char dest_s21[] = "hello";
  char dest[] = "hello";
  char src[] = "world";
  int len = 0;

  s21_strncpy(dest_s21, src, len);
  strncpy(dest, src, len);

  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

START_TEST(test_spaces) {
  char dest_s21[] = "     ";
  char dest[] = "     ";
  char src[] = "   !";
  int len = s21_strlen(src);

  s21_strncpy(dest_s21, src, len);
  strncpy(dest, src, len);

  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

START_TEST(test_break) {
  char dest_s21[20] = "\n\n\n\n";
  char dest[20] = "\n\n\n\n";
  char src[] = "   !\n\n\n\n";
  int len = s21_strlen(src);

  s21_strncpy(dest_s21, src, len);
  strncpy(dest, src, len);

  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

START_TEST(test_len_larger) {
  char dest_s21[20] = "hello";
  char dest[20] = "hello";
  char src[] = "world";
  int len = 20;

  s21_strncpy(dest_s21, src, len);
  strncpy(dest, src, len);

  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

START_TEST(test_line_break) {
  char dest_s21[20] = "\0\0\0\0";
  char dest[20] = "\0\0\0\0";
  char src[] = "world\0";
  int len = 20;

  s21_strncpy(dest_s21, src, len);
  strncpy(dest, src, len);

  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("tc_strncpy");

  tcase_add_test(tc, test_basic);
  tcase_add_test(tc, test_dest_empty);
  tcase_add_test(tc, test_src_empty);
  tcase_add_test(tc, test_both_empty);
  tcase_add_test(tc, test_len_zero);
  tcase_add_test(tc, test_spaces);
  tcase_add_test(tc, test_break);
  tcase_add_test(tc, test_len_larger);
  tcase_add_test(tc, test_line_break);

  suite_add_tcase(s, tc);

  return s;
}