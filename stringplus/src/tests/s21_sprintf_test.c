#include "s21_string_test.h"

START_TEST(test_s21_sprintf_1) {  // c
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, my name is %c...";

  char symbol = 'A';
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, symbol);
  res_orig = sprintf(dest_orig, pattern, symbol);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_2) {  // d
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, my age is %d...";

  int age = 17;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, age);
  res_orig = sprintf(dest_orig, pattern, age);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_3) {  // i
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, my age is %i...";

  int age = -17;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, age);
  res_orig = sprintf(dest_orig, pattern, age);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_4) {  // f
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %f...";

  float number = 27.777;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_5) {  // s
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %-10.2s...";

  char str[5] = "123";
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, str);
  res_orig = sprintf(dest_orig, pattern, str);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_6) {  // s
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %s...";

  char str[4] = "123";
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, str);
  res_orig = sprintf(dest_orig, pattern, str);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_7) {  // u
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %u...";

  unsigned int number = 123;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_8) {  // u
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %u...";

  unsigned int number = -123;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_9) {  // x
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %x...";

  unsigned int number = 0xFF;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_10) {  // X
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %X...";

  unsigned int number = 0xFF;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_11) {  // n
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, count symbols is %n...";

  int result_symbols;
  int expected_symbols;

  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, &result_symbols);
  res_orig = sprintf(dest_orig, pattern, &expected_symbols);

  ck_assert_int_eq(result_symbols, expected_symbols);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_12) {  // n
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "%n...";

  int result_symbols;
  int expected_symbols;

  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, &result_symbols);
  res_orig = sprintf(dest_orig, pattern, &expected_symbols);

  ck_assert_int_eq(result_symbols, expected_symbols);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_13) {  // n
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "%n";

  int result_symbols;
  int expected_symbols;

  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, &result_symbols);
  res_orig = sprintf(dest_orig, pattern, &expected_symbols);

  ck_assert_int_eq(result_symbols, expected_symbols);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_14) {  // %
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, percent is %d%%...";

  int number = 100;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_15) {  // -
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, percent is %-10d%%...";

  int number = 100;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_16) {  // +
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, percent is %+10d%%...";

  int number = 100;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_17) {  // +
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, percent is %+20d%%...";

  int number = 100;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_18) {  // +
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, percent is %d%%...";

  int number = 100;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_19) {  // +
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, percent is %%d%%...";

  int number = 10;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_20) {  // #o
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %#o...";

  int number = 7;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_21) {  // +
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, percent is %1d%%...";

  int number = 100;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_22) {  // #X
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %#X...";

  int number = 0xFF;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_23) {  // #x
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %#x...";

  int number = 0xFF;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_24) {  // #f
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %#f...";

  float number = 10;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_25) {  // 0
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %010d...";

  int number = 10;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_26) {  // 0
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %01d...";

  int number = 10;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_27) {  // (num)
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %2d...";

  int number = 10;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_28) {  // (num)
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %10d...";

  int number = 10;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_29) {  // hd
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %hd...";

  short int number = 32769;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_30) {  // ld
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %ld...";

  long int number = 922337247;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_31) {  // Lf
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %Lf...";

  long double number = 113132.12315149;
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, number);
  res_orig = sprintf(dest_orig, pattern, number);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_32) {  // s
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, number is %5.2s...";

  char str[5] = "123";
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, str);
  res_orig = sprintf(dest_orig, pattern, str);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_s21_sprintf_33) {  // c
  char dest_s21[124];
  char dest_orig[124];
  const char *pattern = "Hello, my name is %-3c...";

  char symbol = 'F';
  int res_s21 = 0;
  int res_orig = 0;

  res_s21 = s21_sprintf(dest_s21, pattern, symbol);
  res_orig = sprintf(dest_orig, pattern, symbol);

  ck_assert_str_eq(dest_s21, dest_orig);
  ck_assert_int_eq(res_s21, res_orig);
}
END_TEST

Suite *sprintf_suite(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tcase = tcase_create("tc_sprintf");

  tcase_add_test(tcase, test_s21_sprintf_1);
  tcase_add_test(tcase, test_s21_sprintf_2);
  tcase_add_test(tcase, test_s21_sprintf_3);
  tcase_add_test(tcase, test_s21_sprintf_4);
  tcase_add_test(tcase, test_s21_sprintf_5);
  tcase_add_test(tcase, test_s21_sprintf_6);
  tcase_add_test(tcase, test_s21_sprintf_7);
  tcase_add_test(tcase, test_s21_sprintf_8);
  tcase_add_test(tcase, test_s21_sprintf_9);
  tcase_add_test(tcase, test_s21_sprintf_10);
  tcase_add_test(tcase, test_s21_sprintf_11);
  tcase_add_test(tcase, test_s21_sprintf_12);
  tcase_add_test(tcase, test_s21_sprintf_13);
  tcase_add_test(tcase, test_s21_sprintf_14);
  tcase_add_test(tcase, test_s21_sprintf_15);
  tcase_add_test(tcase, test_s21_sprintf_16);
  tcase_add_test(tcase, test_s21_sprintf_17);
  tcase_add_test(tcase, test_s21_sprintf_18);
  tcase_add_test(tcase, test_s21_sprintf_19);
  tcase_add_test(tcase, test_s21_sprintf_20);
  tcase_add_test(tcase, test_s21_sprintf_21);
  tcase_add_test(tcase, test_s21_sprintf_22);
  tcase_add_test(tcase, test_s21_sprintf_23);
  tcase_add_test(tcase, test_s21_sprintf_24);
  tcase_add_test(tcase, test_s21_sprintf_25);
  tcase_add_test(tcase, test_s21_sprintf_26);
  tcase_add_test(tcase, test_s21_sprintf_27);
  tcase_add_test(tcase, test_s21_sprintf_28);
  tcase_add_test(tcase, test_s21_sprintf_29);
  tcase_add_test(tcase, test_s21_sprintf_30);
  tcase_add_test(tcase, test_s21_sprintf_31);
  tcase_add_test(tcase, test_s21_sprintf_32);
  tcase_add_test(tcase, test_s21_sprintf_33);

  suite_add_tcase(s, tcase);

  return s;
}