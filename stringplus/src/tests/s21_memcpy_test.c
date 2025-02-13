#include "s21_string_test.h"

START_TEST(test_basic) {
  char dest_s21[] = "hello world";
  char dest[] = "hello world";
  char src[] = "!";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_memcpy(dest_s21, src, len);
  char *res_orig = memcpy(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_dest_empty) {
  char dest_s21[20] = "";
  char dest[20] = "";
  char src[] = "!";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_memcpy(dest_s21, src, len);
  char *res_orig = memcpy(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_src_empty) {
  char dest_s21[] = "hello";
  char dest[] = "hello";
  char src[] = "";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_memcpy(dest_s21, src, len);
  char *res_orig = memcpy(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_both_empty) {
  char dest_s21[] = "";
  char dest[] = "";
  char src[] = "";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_memcpy(dest_s21, src, len);
  char *res_orig = memcpy(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_len_zero) {
  char dest_s21[] = "hello";
  char dest[] = "hello";
  char src[] = "world";
  s21_size_t len = 0;

  char *res_s21 = s21_memcpy(dest_s21, src, len);
  char *res_orig = memcpy(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_spaces) {
  char dest_s21[] = "     ";
  char dest[] = "     ";
  char src[] = "   !";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_memcpy(dest_s21, src, len);
  char *res_orig = memcpy(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_break) {
  char dest_s21[20] = "\n\n\n\n";
  char dest[20] = "\n\n\n\n";
  char src[] = "   !\n\n\n\n";
  s21_size_t len = s21_strlen(src);

  char *res_s21 = s21_memcpy(dest_s21, src, len);
  char *res_orig = memcpy(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_len_larger) {
  char dest_s21[20] = "hello";
  char dest[20] = "hello";
  char src[20] = "world";
  s21_size_t len = 20;

  char *res_s21 = s21_memcpy(dest_s21, src, len);
  char *res_orig = memcpy(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

START_TEST(test_line_break) {
  char dest_s21[20] = "\0\0\0\0";
  char dest[20] = "\0\0\0\0";
  char src[20] = "world\0";
  s21_size_t len = 20;

  char *res_s21 = s21_memcpy(dest_s21, src, len);
  char *res_orig = memcpy(dest, src, len);

  ck_assert_mem_eq(res_s21, res_orig, len);
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("tc_memcpy");

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