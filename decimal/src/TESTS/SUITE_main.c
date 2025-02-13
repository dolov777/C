#include <check.h>
#include <stdio.h>

#include "./../s21_decimal.h"

START_TEST(is_less_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 127, 1);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 11);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_7) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 1);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_8) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 1);
  s21_set_bit(&val1, 83, 1);
  s21_set_scale(&val1, 12);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_9) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 1);
  s21_set_bit(&val1, 83, 1);
  s21_set_bit(&val2, 83, 1);
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_10) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 1);
  s21_set_bit(&val1, 83, 1);
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_11) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 0);
  s21_set_bit(&val1, 83, 1);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_12) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 0);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_greater_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 127, 1);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 11);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_7) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 1);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_8) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 0);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 127, 1);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 11);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_7) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 1);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 127, 1);
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 11);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_7) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 1);
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_0) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_set_sign(&val2, 1);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val2, 3, 1);
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val2, 127, 1);
  s21_set_bit(&val1, 33, 1);
  s21_set_bit(&val2, 33, 1);
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 3, 1);
  s21_set_bit(&val2, 3, 1);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 3, 1);
  s21_set_bit(&val2, 4, 1);
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 3);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 3, 1);
  s21_set_bit(&val2, 4, 1);
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 3);
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_7) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 2);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_8) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 0);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val2, 3, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val2, 127, 1);
  s21_set_bit(&val1, 33, 1);
  s21_set_bit(&val2, 33, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 3, 1);
  s21_set_bit(&val2, 3, 1);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 3, 1);
  s21_set_bit(&val2, 4, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 3);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_bit(&val1, 3, 1);
  s21_set_bit(&val2, 4, 1);
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 3);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_7) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_set_scale(&val1, 3);
  s21_set_scale(&val2, 2);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_8) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(sub_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_8) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_9) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_10) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_12) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_13) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_14) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_15) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_16) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_17) {
  int true_res = 0;
  s21_decimal val1 = {{890373317, 1664736595, 2742755499U, 2148204544U}};
  s21_decimal val2 = {{3230206353U, 3918853780U, 4043671449U, 2147483648U}};
  s21_decimal val3 = {{189631616, 3801053329U, 4043671449U, 0x00000000}};
  s21_decimal output;
  int s21_res = s21_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(sub_18) {
  int true_res = 0;
  s21_decimal val1 = {{900961119, 2623149003U, 2341027622U, 2148597760U}};
  s21_decimal val2 = {{2096648231, 1368807658, 3501119840U, 1179648}};
  s21_decimal result = {{251632483, 2760029769U, 2691139606U, 2148597760U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(sub_19) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_20) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = -99899;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(sub_21) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  s21_decimal res1;
  int res = 99899;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_0) {
  s21_decimal val1 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_1) {
  s21_decimal val1 = {{15, 0, 0, 0}};
  s21_decimal val2 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_2) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_9) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_10) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_13) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_14) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_15) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_17) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_set_scale(&val1, 5);
  s21_set_scale(&val2, 3);
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_18) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_set_scale(&val1, 5);
  s21_set_scale(&val2, 3);
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(mul_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_8) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_9) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_10) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_12) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  s21_set_scale(&val1, 1);
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_13) {
  int true_res = 0;
  s21_decimal val1 = {{100, 0, 0, 0}};
  s21_decimal val2 = {{10, 0, 0, 0}};
  s21_decimal output;
  s21_decimal result = {{1000, 0, 0, 0}};
  int s21_res = s21_mul(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(mul_14) {
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val1 = {{20, 0, 0, 0}};
  s21_decimal res = {{0}};
  s21_set_scale(&val2, 1);
  s21_set_scale(&val2, 2);
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(div_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_3) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_4) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(truncate_zero) {
  s21_decimal val = {{0, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_small_int) {
  s21_decimal val = {{12345678, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 12345678.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_large_negative) {
  s21_decimal val = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -79228162514264337593543950335.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_negative_with_scale) {
  s21_decimal val = {{987654321, 0, 0, 0x80090000}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_with_scale) {
  s21_decimal val = {{987654321, 0, 0, 0x00090000}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_fraction_large_scale) {
  s21_decimal val = {{123456789, 0, 0, 0x00180000}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_positive_fraction) {
  s21_decimal val = {{987654321, 0, 0, 0x00050000}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 9876.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_min_positive_fraction) {
  s21_decimal val = {{1, 0, 0, 0x001C0000}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(negate_positive_integer) {
  s21_decimal val = {{12345, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
  ck_assert_int_eq(12345, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(0x80000000, res.bits[3]);
}
END_TEST

START_TEST(negate_negative_integer) {
  s21_decimal val = {{12345, 0, 0, 0x80000000}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
  ck_assert_int_eq(12345, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(negate_large_positive_integer) {
  s21_decimal val = {{2147483647, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
  ck_assert_int_eq(2147483647, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(0x80000000, res.bits[3]);
}
END_TEST

START_TEST(negate_large_negative_integer) {
  s21_decimal val = {{2147483647, 0, 0, 0x80000000}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
  ck_assert_int_eq(2147483647, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(negate_min_value) {
  s21_decimal val = {{0, 0, 0, 0x80000000}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
  ck_assert_int_eq(0, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(negate_max_value) {
  s21_decimal val = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
  ck_assert_int_eq(0xFFFFFFFF, res.bits[0]);
  ck_assert_int_eq(0xFFFFFFFF, res.bits[1]);
  ck_assert_int_eq(0xFFFFFFFF, res.bits[2]);
  ck_assert_int_eq(0x80000000, res.bits[3]);
}
END_TEST

START_TEST(floor_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_floor(val, &res));
}
END_TEST

START_TEST(floor_1) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-2, fres);
}
END_TEST

START_TEST(floor_2) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  s21_set_scale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-1, fres);
}
END_TEST

START_TEST(floor_3) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(0, fres);
}
END_TEST

START_TEST(floor_4) {
  s21_decimal val = {{15, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 1);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(1, fres);
}
END_TEST

START_TEST(floor_5) {
  s21_decimal val = {{157, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 2);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(1, fres);
}
END_TEST

START_TEST(floor_6) {
  s21_decimal val = {{35, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 1);
  s21_set_sign(&val, 1);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-4, fres);
}
END_TEST

START_TEST(floor_7) {
  s21_decimal val = {{823, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 2);
  s21_set_sign(&val, 1);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-9, fres);
}
END_TEST

START_TEST(floor_8) {
  s21_decimal val = {{100, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 0);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(100, fres);
}
END_TEST

START_TEST(floor_9) {
  s21_decimal val = {{100, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 0);
  s21_set_sign(&val, 1);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-100, fres);
}
END_TEST

START_TEST(round_positive_fraction_less_than_half) {
  s21_decimal val = {{123, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 2);
  ck_assert_int_eq(0, s21_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_positive_half) {
  s21_decimal val = {{500, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 3);
  ck_assert_int_eq(0, s21_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_negative_less_than_half) {
  s21_decimal val = {{500, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 3);
  ck_assert_int_eq(0, s21_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_positive_fraction_greater_than_half) {
  s21_decimal val = {{750, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 3);
  ck_assert_int_eq(0, s21_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_negative_greater_than_half) {
  s21_decimal val = {{999999999, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 9);
  ck_assert_int_eq(0, s21_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_integer) {
  s21_decimal val = {{12345, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 0);
  ck_assert_int_eq(0, s21_round(val, &res));
  ck_assert_int_eq(12345, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_zero_fraction) {
  s21_decimal val = {{1000, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 3);
  ck_assert_int_eq(0, s21_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_large_fraction) {
  s21_decimal val = {{999999999, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 9);
  ck_assert_int_eq(0, s21_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_small_fraction_to_zero) {
  s21_decimal val = {{1, 0, 0, 0}};
  s21_decimal res = {0};
  s21_set_scale(&val, 2);
  ck_assert_int_eq(0, s21_round(val, &res));
  ck_assert_int_eq(0, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(from_decimal_to_float_0) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  s21_set_scale(&val, 5);
  float res = 1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  s21_from_decimal_to_float(val, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_float_1) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  s21_set_bit(&val, 127, 1);
  s21_set_scale(&val, 5);
  float res = -1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  s21_from_decimal_to_float(val, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_float_2) {
  s21_decimal inp = {{432152, 320, 133, 655360}};
  float out;
  float res = 2.453417E+11;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_decimal_to_float_3) {
  s21_decimal inp = {{432152, 320, 344, 65536}};
  float out;
  float res = 634567996273047572277.6;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_decimal_to_float_4) {
  s21_decimal inp = {{432152, 320, 133, 655360}};
  float out;
  float res = 2.453417E+11;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_decimal_to_float_5) {
  s21_decimal inp = {{0, 0, 0, 0}};
  float out;
  float res = 0.0;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_decimal_to_float_6) {
  s21_decimal inp = {{1, 0, 0, 0}};
  float out;
  float res = 1.0;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_decimal_to_float_7) {
  s21_decimal inp = {{1, 0, 0, 0}};
  s21_set_scale(&inp, 3);
  float out;
  float res = 0.001;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_decimal_to_float_8) {
  s21_decimal inp = {{1, 0, 0, 0}};
  s21_set_scale(&inp, 3);
  s21_set_bit(&inp, 127, 1);
  float out;
  float res = -0.001;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_decimal_to_float_9) {
  s21_decimal inp = {{1, 0, 0, 0}};
  s21_set_scale(&inp, 4);
  float out;
  float res = 0.0001;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_0) {
  float inp = 1. / 0.;
  s21_decimal out;
  int error = s21_from_float_to_decimal(inp, &out);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], 0);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_float_to_decimal_1) {
  float inp = 0.004;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000004, 0, 0, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_2) {
  float inp = 0.004;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000004, 0, 0, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}

START_TEST(from_float_to_decimal_3) {
  float inp = 0.00000000000000000000000000013929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{1, 0, 0, 1835008}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_4) {
  float inp = 79215000000000000000000000000.365656;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{3472883712U, 2886053469U, 4294253754U, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_5) {
  float inp = 79215000000000000000000000000.365656;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{3472883712U, 2886053469U, 4294253754U, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_6) {
  float inp = 79215000000000000000000000000.365656;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{3472883712U, 2886053469U, 4294253754U, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_7) {
  float inp = -79215000000000000000000000000.365656;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{3472883712U, 2886053469U, 4294253754U, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_8) {
  float inp = INFINITY;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_float_to_decimal_9) {
  float inp = -INFINITY;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_float_to_decimal_10) {
  float inp = NAN;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_decimal_to_int_0) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  s21_set_scale(&val, 5);
  int res = 1234;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_1) {
  int true_res = 1;
  s21_decimal val1 = {{336139824, 2147037051, 1049562280, 2148007936}};
  int result = 0;
  int output;
  int s21_res = s21_from_decimal_to_int(val1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(from_decimal_to_int_2) {
  int true_res = 0;
  s21_decimal val1 = {{3800457492U, 746078660, 44358857, 2149187584U}};
  int result = -8;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(val1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(from_decimal_to_int_3) {
  int true_res = 0;
  s21_decimal val1 = {{4146582168U, 737655971, 3179105752U, 1507328}};
  int result = 586441;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(val1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(from_decimal_to_int_4) {
  int true_res = 0;
  s21_decimal val1 = {{1989396232, 480664185, 3293331971U, 2148990976U}};
  int result = -607512;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(val1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(from_decimal_to_int_5) {
  int true_res = 1;
  s21_decimal val1 = {{1395180557, 3885759711U, 2862126795U, 393216}};
  int result = 0;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(val1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(from_decimal_to_int_6) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_7) {
  s21_decimal val = {{INT_MAX, 0, 0, 0}};
  int res = INT_MAX;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_8) {
  s21_decimal val = {{0, 0, 0, 0x80000000}};
  int res = 0;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_9) {
  s21_decimal val = {{123456789, 0, 0, 0x80000000}};
  int res = -123456789;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(from_int_to_decimal_0) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_1) {
  int inp = INT_MAX;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{2147483647, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  int inp = 1027557455;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{1027557455, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_int_to_decimal_3) {
  int inp = -1056545713;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{1056545713, 0x00000000, 0x00000000, 2147483648U}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_int_to_decimal_4) {
  int inp = 99999;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{99999, 0x00000000, 0x00000000, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_int_to_decimal_5) {
  int inp = 0;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0, 0x00000000, 0x00000000, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_int_to_decimal_6) {
  int inp = 1;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{1, 0x00000000, 0x00000000, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_int_to_decimal_7) {
  int inp = -1;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{1, 0x00000000, 0x00000000, 2147483648U}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_int_to_decimal_8) {
  int inp = 2147483647;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{2147483647, 0x00000000, 0x00000000, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, is_less_0);
  tcase_add_test(tc1_1, is_less_1);
  tcase_add_test(tc1_1, is_less_2);
  tcase_add_test(tc1_1, is_less_3);
  tcase_add_test(tc1_1, is_less_4);
  tcase_add_test(tc1_1, is_less_5);
  tcase_add_test(tc1_1, is_less_6);
  tcase_add_test(tc1_1, is_less_7);
  tcase_add_test(tc1_1, is_less_8);
  tcase_add_test(tc1_1, is_less_9);
  tcase_add_test(tc1_1, is_less_10);
  tcase_add_test(tc1_1, is_less_11);
  tcase_add_test(tc1_1, is_less_12);

  tcase_add_test(tc1_1, is_greater_0);
  tcase_add_test(tc1_1, is_greater_1);
  tcase_add_test(tc1_1, is_greater_2);
  tcase_add_test(tc1_1, is_greater_3);
  tcase_add_test(tc1_1, is_greater_4);
  tcase_add_test(tc1_1, is_greater_5);
  tcase_add_test(tc1_1, is_greater_6);
  tcase_add_test(tc1_1, is_greater_7);
  tcase_add_test(tc1_1, is_greater_8);

  tcase_add_test(tc1_1, is_greater_or_equal_0);
  tcase_add_test(tc1_1, is_greater_or_equal_1);
  tcase_add_test(tc1_1, is_greater_or_equal_2);
  tcase_add_test(tc1_1, is_greater_or_equal_3);
  tcase_add_test(tc1_1, is_greater_or_equal_4);
  tcase_add_test(tc1_1, is_greater_or_equal_5);
  tcase_add_test(tc1_1, is_greater_or_equal_6);
  tcase_add_test(tc1_1, is_greater_or_equal_7);

  tcase_add_test(tc1_1, is_less_or_equal_0);
  tcase_add_test(tc1_1, is_less_or_equal_1);
  tcase_add_test(tc1_1, is_less_or_equal_2);
  tcase_add_test(tc1_1, is_less_or_equal_3);
  tcase_add_test(tc1_1, is_less_or_equal_4);
  tcase_add_test(tc1_1, is_less_or_equal_5);
  tcase_add_test(tc1_1, is_less_or_equal_6);
  tcase_add_test(tc1_1, is_less_or_equal_7);

  tcase_add_test(tc1_1, is_equal_0);
  tcase_add_test(tc1_1, is_equal_1);
  tcase_add_test(tc1_1, is_equal_2);
  tcase_add_test(tc1_1, is_equal_3);
  tcase_add_test(tc1_1, is_equal_4);
  tcase_add_test(tc1_1, is_equal_5);
  tcase_add_test(tc1_1, is_equal_6);
  tcase_add_test(tc1_1, is_equal_7);
  tcase_add_test(tc1_1, is_equal_8);

  tcase_add_test(tc1_1, is_not_equal_0);
  tcase_add_test(tc1_1, is_not_equal_1);
  tcase_add_test(tc1_1, is_not_equal_2);
  tcase_add_test(tc1_1, is_not_equal_3);
  tcase_add_test(tc1_1, is_not_equal_4);
  tcase_add_test(tc1_1, is_not_equal_5);
  tcase_add_test(tc1_1, is_not_equal_6);
  tcase_add_test(tc1_1, is_not_equal_7);
  tcase_add_test(tc1_1, is_not_equal_8);

  tcase_add_test(tc1_1, sub_0);
  tcase_add_test(tc1_1, sub_1);
  tcase_add_test(tc1_1, sub_2);
  tcase_add_test(tc1_1, sub_3);
  tcase_add_test(tc1_1, sub_4);
  tcase_add_test(tc1_1, sub_5);
  tcase_add_test(tc1_1, sub_6);
  tcase_add_test(tc1_1, sub_7);
  tcase_add_test(tc1_1, sub_8);
  tcase_add_test(tc1_1, sub_9);
  tcase_add_test(tc1_1, sub_10);
  tcase_add_test(tc1_1, sub_11);
  tcase_add_test(tc1_1, sub_12);
  tcase_add_test(tc1_1, sub_13);
  tcase_add_test(tc1_1, sub_14);
  tcase_add_test(tc1_1, sub_15);
  tcase_add_test(tc1_1, sub_16);
  tcase_add_test(tc1_1, sub_17);
  tcase_add_test(tc1_1, sub_18);
  tcase_add_test(tc1_1, sub_19);
  tcase_add_test(tc1_1, sub_20);
  tcase_add_test(tc1_1, sub_21);

  tcase_add_test(tc1_1, add_0);
  tcase_add_test(tc1_1, add_1);
  tcase_add_test(tc1_1, add_2);
  tcase_add_test(tc1_1, add_4);
  tcase_add_test(tc1_1, add_5);
  tcase_add_test(tc1_1, add_6);
  tcase_add_test(tc1_1, add_7);
  tcase_add_test(tc1_1, add_8);
  tcase_add_test(tc1_1, add_9);
  tcase_add_test(tc1_1, add_10);
  tcase_add_test(tc1_1, add_11);
  tcase_add_test(tc1_1, add_13);
  tcase_add_test(tc1_1, add_14);
  tcase_add_test(tc1_1, add_15);
  tcase_add_test(tc1_1, add_17);
  tcase_add_test(tc1_1, add_18);

  tcase_add_test(tc1_1, mul_0);
  tcase_add_test(tc1_1, mul_1);
  tcase_add_test(tc1_1, mul_2);
  tcase_add_test(tc1_1, mul_3);
  tcase_add_test(tc1_1, mul_4);
  tcase_add_test(tc1_1, mul_5);
  tcase_add_test(tc1_1, mul_6);
  tcase_add_test(tc1_1, mul_7);
  tcase_add_test(tc1_1, mul_8);
  tcase_add_test(tc1_1, mul_9);
  tcase_add_test(tc1_1, mul_10);
  tcase_add_test(tc1_1, mul_11);
  tcase_add_test(tc1_1, mul_12);
  tcase_add_test(tc1_1, mul_13);
  tcase_add_test(tc1_1, mul_14);

  tcase_add_test(tc1_1, div_0);
  tcase_add_test(tc1_1, div_1);
  tcase_add_test(tc1_1, div_2);
  tcase_add_test(tc1_1, div_3);
  tcase_add_test(tc1_1, div_4);

  tcase_add_test(tc1_1, negate_positive_integer);
  tcase_add_test(tc1_1, negate_negative_integer);
  tcase_add_test(tc1_1, negate_large_positive_integer);
  tcase_add_test(tc1_1, negate_large_negative_integer);
  tcase_add_test(tc1_1, negate_min_value);
  tcase_add_test(tc1_1, negate_max_value);

  tcase_add_test(tc1_1, round_positive_fraction_less_than_half);
  tcase_add_test(tc1_1, round_positive_half);
  tcase_add_test(tc1_1, round_negative_less_than_half);
  tcase_add_test(tc1_1, round_positive_fraction_greater_than_half);
  tcase_add_test(tc1_1, round_negative_greater_than_half);
  tcase_add_test(tc1_1, round_integer);
  tcase_add_test(tc1_1, round_zero_fraction);
  tcase_add_test(tc1_1, round_large_fraction);
  tcase_add_test(tc1_1, round_small_fraction_to_zero);

  tcase_add_test(tc1_1, truncate_zero);
  tcase_add_test(tc1_1, truncate_small_int);
  tcase_add_test(tc1_1, truncate_large_negative);
  tcase_add_test(tc1_1, truncate_negative_with_scale);
  tcase_add_test(tc1_1, truncate_with_scale);
  tcase_add_test(tc1_1, truncate_fraction_large_scale);
  tcase_add_test(tc1_1, truncate_positive_fraction);
  tcase_add_test(tc1_1, truncate_min_positive_fraction);

  tcase_add_test(tc1_1, floor_0);
  tcase_add_test(tc1_1, floor_1);
  tcase_add_test(tc1_1, floor_2);
  tcase_add_test(tc1_1, floor_3);
  tcase_add_test(tc1_1, floor_4);
  tcase_add_test(tc1_1, floor_5);
  tcase_add_test(tc1_1, floor_6);
  tcase_add_test(tc1_1, floor_7);
  tcase_add_test(tc1_1, floor_8);
  tcase_add_test(tc1_1, floor_9);

  tcase_add_test(tc1_1, from_decimal_to_float_0);
  tcase_add_test(tc1_1, from_decimal_to_float_1);
  tcase_add_test(tc1_1, from_decimal_to_float_2);
  tcase_add_test(tc1_1, from_decimal_to_float_3);
  tcase_add_test(tc1_1, from_decimal_to_float_4);
  tcase_add_test(tc1_1, from_decimal_to_float_5);
  tcase_add_test(tc1_1, from_decimal_to_float_6);
  tcase_add_test(tc1_1, from_decimal_to_float_7);
  tcase_add_test(tc1_1, from_decimal_to_float_8);
  tcase_add_test(tc1_1, from_decimal_to_float_9);

  tcase_add_test(tc1_1, from_float_to_decimal_0);
  tcase_add_test(tc1_1, from_float_to_decimal_1);
  tcase_add_test(tc1_1, from_float_to_decimal_2);
  tcase_add_test(tc1_1, from_float_to_decimal_3);
  tcase_add_test(tc1_1, from_float_to_decimal_4);
  tcase_add_test(tc1_1, from_float_to_decimal_5);
  tcase_add_test(tc1_1, from_float_to_decimal_6);
  tcase_add_test(tc1_1, from_float_to_decimal_7);
  tcase_add_test(tc1_1, from_float_to_decimal_8);
  tcase_add_test(tc1_1, from_float_to_decimal_9);
  tcase_add_test(tc1_1, from_float_to_decimal_10);

  tcase_add_test(tc1_1, from_decimal_to_int_0);
  tcase_add_test(tc1_1, from_decimal_to_int_1);
  tcase_add_test(tc1_1, from_decimal_to_int_2);
  tcase_add_test(tc1_1, from_decimal_to_int_3);
  tcase_add_test(tc1_1, from_decimal_to_int_4);
  tcase_add_test(tc1_1, from_decimal_to_int_5);
  tcase_add_test(tc1_1, from_decimal_to_int_6);
  tcase_add_test(tc1_1, from_decimal_to_int_7);
  tcase_add_test(tc1_1, from_decimal_to_int_8);
  tcase_add_test(tc1_1, from_decimal_to_int_9);

  tcase_add_test(tc1_1, from_int_to_decimal_0);
  tcase_add_test(tc1_1, from_int_to_decimal_1);
  tcase_add_test(tc1_1, from_int_to_decimal_2);
  tcase_add_test(tc1_1, from_int_to_decimal_3);
  tcase_add_test(tc1_1, from_int_to_decimal_4);
  tcase_add_test(tc1_1, from_int_to_decimal_5);
  tcase_add_test(tc1_1, from_int_to_decimal_6);
  tcase_add_test(tc1_1, from_int_to_decimal_7);
  tcase_add_test(tc1_1, from_int_to_decimal_8);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
