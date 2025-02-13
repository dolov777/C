#ifndef HEADERS_S21_HELPERS_H_
#define HEADERS_S21_HELPERS_H_

s21_decimal *s21_set_scale(s21_decimal *value, int scale);
s21_decimal *s21_set_sign(s21_decimal *value, int sign);
s21_decimal *s21_reset(s21_decimal *result);
s21_big_decimal s21_to_big_decimal(s21_decimal value);

int s21_get_bit(s21_decimal value, int bit_position);
int s21_get_scale(s21_decimal value);
int s21_get_sign(s21_decimal value);
int s21_shift_left(s21_decimal *value, int shift);
int s21_minus(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_is_zero_decimal(s21_decimal value);
int s21_is_zero(s21_decimal value);
int overflow_check_big(s21_big_decimal value);
int s21_is_less_big(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_shift_right_big(s21_big_decimal *value, int shift);
int s21_is_zero_big_decimal(s21_big_decimal value);
int s21_shift_left_big(s21_big_decimal *value, int shift);
int s21_get_bit_big(s21_big_decimal value, int bit_index);
int s21_plus(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_get_highest_big_bit(s21_big_decimal value);
int s21_get_big_scale(s21_big_decimal value);
int s21_fixOverflow(s21_big_decimal *value, int *scale);
int s21_overflow_check_big(s21_big_decimal value);
int s21_is_greater_or_equal_big(s21_big_decimal value_1,
                                s21_big_decimal value_2);
int s21_big_plus(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
int s21_big_minus(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result);
int s21_big_div(s21_big_decimal big_value_1, s21_big_decimal big_value_2,
                s21_big_decimal *result, int *scale);
int s21_big_mul(s21_big_decimal big_val_1, s21_big_decimal big_val_2,
                s21_big_decimal *big_res);

void s21_big_multiply_by_10(s21_big_decimal *value);
void s21_big_multiply_by_2(s21_big_decimal *value);
void s21_big_multiply_by_5(s21_big_decimal *value);
void s21_big_divide_by_10(s21_big_decimal *value);
void s21_big_divide_by_5(s21_big_decimal *value);
void s21_big_divide_by_2(s21_big_decimal *value);
void s21_to_decimal(s21_big_decimal big_value, s21_decimal *value);
void s21_set_big_scale(s21_big_decimal *value, int scale);
void s21_mul_ten_big(s21_big_decimal *value);
void s21_big_rounding(s21_big_decimal *value);
void s21_divide_ten_big(s21_big_decimal *value);
void s21_set_bit_big(s21_big_decimal *value, int position, int bit_value);
void s21_divide_ten(s21_decimal *value);
void s21_div_ten(s21_decimal *value);
void s21_mul_ten(s21_decimal *value);
void s21_set_bit(s21_decimal *value, int bit_position, int bit_value);
void s21_set_bits_range(s21_decimal *value, int start_bit, int end_bit,
                        unsigned int range_value);
void s21_normalize_mantissa_big(s21_big_decimal *value_1,
                                s21_big_decimal *value_2);
void s21_set_result_sign_and_scale(s21_decimal *result, int sign1, int sign2,
                                   int scale);

unsigned int s21_get_bits_range(s21_decimal value, int start_bit, int end_bit);
#endif
