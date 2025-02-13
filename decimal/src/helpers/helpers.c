#include "./../s21_decimal.h"

int s21_get_bit(s21_decimal value, int bit_position) {
  int array_index = bit_position / 32;
  int bit_index = bit_position % 32;

  return (value.bits[array_index] >> bit_index) & 1;
}

int s21_get_bit_big(s21_big_decimal value, int bit_index) {
  int result = 0;

  if (bit_index >= 0 && bit_index <= 255) {
    int array_index = bit_index / 32;
    int bit_position = bit_index % 32;
    result = (value.bits[array_index] >> bit_position) & 1;
  }

  return result;
}

void s21_set_bit_big(s21_big_decimal *value, int position, int bit_value) {
  if (position >= 0 && position <= 255) {
    int index = position / 32;
    int bit_position = position % 32;

    if (bit_value) {
      value->bits[index] |= (1 << bit_position);
    } else {
      value->bits[index] &= ~(1 << bit_position);
    }
  }
}

void s21_set_bit(s21_decimal *value, int bit_position, int bit_value) {
  int array_index = bit_position / 32;
  int bit_index = bit_position % 32;
  if (bit_value == 1) {
    value->bits[array_index] |= (1 << bit_index);
  } else {
    value->bits[array_index] &= ~(1 << bit_index);
  }
}

unsigned int s21_get_bits_range(s21_decimal value, int start_bit, int end_bit) {
  unsigned int range_value = 0;
  for (int i = start_bit; i <= end_bit; i++) {
    range_value |= (s21_get_bit(value, i) << (i - start_bit));
  }
  return range_value;
}

void s21_set_bits_range(s21_decimal *value, int start_bit, int end_bit,
                        unsigned int range_value) {
  for (int i = start_bit; i <= end_bit; i++) {
    s21_set_bit(value, i, (range_value >> (i - start_bit)) & 1);
  }
}

int s21_get_scale(s21_decimal value) {
  int scale = (value.bits[3] >> 16) & 0xFF;
  return scale;
}

s21_decimal *s21_set_scale(s21_decimal *value, int scale) {
  if (scale >= 0 && scale <= 28) {
    value->bits[3] &= ~0x00FF0000;
    value->bits[3] |= (scale << 16) & 0x00FF0000;
  }

  return value;
}

s21_decimal *s21_set_sign(s21_decimal *value, int sign) {
  if (sign) {
    value->bits[3] |= (1 << 31);
  } else {
    value->bits[3] &= ~(1 << 31);
  }
  return value;
}

int s21_get_sign(s21_decimal value) {
  return (value.bits[3] & 0x80000000) ? 1 : 0;
}

void s21_div_ten(s21_decimal *value) {
  unsigned long long remainder = 0;
  for (int i = 2; i >= 0; i--) {
    unsigned long long temp = (remainder << 32) + value->bits[i];
    value->bits[i] = (unsigned int)(temp / 10);
    remainder = temp % 10;
  }
}

s21_decimal *s21_reset(s21_decimal *result) {
  for (int i = 0; i < 4; i++) {
    result->bits[i] = 0;
  }
  return result;
}

int s21_is_correct_decimal(s21_decimal decimal) {
  unsigned int result = 0;
  unsigned int scale = (decimal.bits[3] & 0x00FF0000) >> 16;
  unsigned int reserved_bits = decimal.bits[3] & 0x7FFFFF00;

  if (scale > 28) {
    result = 1;
  } else if (reserved_bits != 0) {
    result = 1;
  }

  return result;
}

int s21_shift_left(s21_decimal *value, int shift) {
  int remainder = 0;

  for (int i = 0; i < 3; i++) {
    int new_remainder = value->bits[i] >> (32 - shift);
    value->bits[i] <<= shift;
    value->bits[i] |= remainder;
    remainder = new_remainder;
  }

  return remainder ? 1 : 0;
}

int s21_minus(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int borrow = 0;
  for (int i = 0; i < 3; i++) {
    result->bits[i] = 0;
    for (int b = 0; b < 32; b++) {
      unsigned int bit1 = (value_1.bits[i] >> b) & 1;
      unsigned int bit2 = (value_2.bits[i] >> b) & 1;

      unsigned int diff = bit1 ^ bit2 ^ borrow;
      borrow = ((~bit1) & bit2) | ((bit2 ^ borrow) & (~bit1));
      result->bits[i] |= (diff << b);
    }
  }

  return borrow;
}

void s21_mul_ten(s21_decimal *value) {
  s21_decimal result = {0};
  s21_decimal value2 = *value;

  s21_shift_left(value, 2);
  s21_plus(*value, value2, &result);
  s21_shift_left(&result, 1);

  *value = result;
}

int s21_plus(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int carry = 0;
  for (int i = 0; i < 3; i++) {
    result->bits[i] = 0;
    for (int b = 0; b < 32; b++) {
      unsigned int bit1 = (value_1.bits[i] >> b) & 1;
      unsigned int bit2 = (value_2.bits[i] >> b) & 1;

      unsigned int sum = bit1 ^ bit2 ^ carry;
      carry = (bit1 & bit2) | ((bit1 ^ bit2) & carry);
      result->bits[i] |= (sum << b);
    }
  }

  return carry != 0;
}

s21_big_decimal s21_to_big_decimal(s21_decimal value) {
  s21_big_decimal big_value = {0};

  for (int i = 0; i < 3; i++) {
    big_value.bits[i] = value.bits[i];
  }

  big_value.bits[7] = value.bits[3];
  return big_value;
}

void s21_set_big_scale(s21_big_decimal *value, int scale) {
  if (scale >= 0 && scale <= 28) {
    value->bits[7] = value->bits[7] & 0x80000000;
    value->bits[7] |= (scale << 16);
  }
}

void s21_mul_ten_big(s21_big_decimal *value) {
  s21_big_decimal result = {0};
  s21_big_decimal value2 = *value;

  s21_shift_left_big(value, 2);
  s21_big_plus(*value, value2, &result);
  s21_shift_left_big(&result, 1);

  *value = result;
}

int s21_shift_left_big(s21_big_decimal *value, int shift) {
  int bit_carry = 0;
  if (shift != 0) {
    for (int i = 0; i < 7; i++) {
      int new_bit_carry = value->bits[i] >> (32 - shift);
      value->bits[i] <<= shift;
      value->bits[i] |= bit_carry;
      bit_carry = new_bit_carry;
    }
  }
  return bit_carry ? 1 : 0;
}

void s21_normalize_mantissa_big(s21_big_decimal *value,
                                s21_big_decimal *value2) {
  int scale1 = s21_get_big_scale(*value);
  int scale2 = s21_get_big_scale(*value2);

  if (scale1 != scale2) {
    if (scale1 < scale2) {
      s21_normalize_mantissa_big(value2, value);
    } else {
      int diff = scale1 - scale2;

      for (; diff > 0; diff--) {
        s21_mul_ten_big(value2);
        scale2++;
      }

      s21_set_big_scale(value, scale1);
      s21_set_big_scale(value2, scale1);
    }
  }
}

int s21_is_greater_or_equal_big(s21_big_decimal value_1,
                                s21_big_decimal value_2) {
  int result = 1;
  int should_continue = 1;

  for (int i = 6; i >= 0 && should_continue; i--) {
    if (value_1.bits[i] > value_2.bits[i]) {
      result = 1;
      should_continue = 0;
    } else if (value_1.bits[i] < value_2.bits[i]) {
      result = 0;
      should_continue = 0;
    }
  }

  return result;
}

int s21_big_plus(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  int carry = 0;
  for (int i = 0; i < 7; i++) {
    result->bits[i] = 0;
    for (int b = 0; b < 32; b++) {
      unsigned int bit1 = (value_1.bits[i] >> b) & 1;
      unsigned int bit2 = (value_2.bits[i] >> b) & 1;

      unsigned int sum = bit1 ^ bit2 ^ carry;
      carry = (bit1 & bit2) | ((bit1 ^ bit2) & carry);
      result->bits[i] |= (sum << b);
    }
  }
  return carry;
}
int s21_big_minus(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result) {
  int borrow = 0;
  for (int i = 0; i < 7; i++) {
    result->bits[i] = 0;
    for (int b = 0; b < 32; b++) {
      unsigned int bit1 = (value_1.bits[i] >> b) & 1;
      unsigned int bit2 = (value_2.bits[i] >> b) & 1;

      unsigned int diff = bit1 ^ bit2 ^ borrow;
      result->bits[i] |= (diff << b);

      borrow = (bit2 + borrow > bit1);
    }
  }
  return borrow;
}

int s21_overflow_check_big(s21_big_decimal value) {
  int overflow = 0;
  for (int i = 96; i < 224 && !overflow; i++) {
    if (s21_get_bit_big(value, i) == 1) {
      overflow = 1;
    }
  }

  return overflow;
}

void s21_to_decimal(s21_big_decimal big_value, s21_decimal *value) {
  for (int i = 0; i < 3; i++) {
    value->bits[i] = big_value.bits[i];
  }
}

int s21_get_big_scale(s21_big_decimal value) {
  return (value.bits[7] >> 16) & 0xFF;
}

int s21_is_last_overflow(s21_big_decimal value) {
  int res = 0;

  if (value.bits[4] == 0 && value.bits[5] == 0 && value.bits[6] == 0 &&
      value.bits[3] < 10) {
    res = 1;
  }

  return res;
}

int s21_fixOverflow(s21_big_decimal *value, int *scale) {
  int overflow = 0;
  while ((*scale > 0 && (overflow = s21_overflow_check_big(*value)) != 0) ||
         *scale > 28) {
    if (*scale == 1 || s21_is_last_overflow(*value)) {
      s21_big_rounding(value);
    } else {
      s21_divide_ten_big(value);
    }
    (*scale)--;
  }

  overflow = s21_overflow_check_big(*value);

  return overflow;
}

void s21_big_multiply_by_10(s21_big_decimal *value) {
  s21_big_multiply_by_2(value);
  s21_big_multiply_by_5(value);
}

void s21_big_multiply_by_2(s21_big_decimal *value) {
  unsigned int carry = 0;
  for (int i = 0; i < 8; i++) {
    unsigned long long temp = ((unsigned long long)value->bits[i]) * 2 + carry;
    value->bits[i] = (unsigned int)(temp & 0xFFFFFFFF);
    carry = (unsigned int)(temp >> 32);
  }
}

void s21_big_rounding(s21_big_decimal *value) {
  s21_big_decimal remainder = {0};
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};

  s21_big_decimal tmp = *value;
  s21_divide_ten_big(value);
  int is_odd = (value->bits[0] & 1);
  s21_mul_ten_big(value);
  s21_big_minus(tmp, *value, &remainder);
  s21_divide_ten_big(value);

  if (remainder.bits[0] > 5 || (remainder.bits[0] == 5 && is_odd)) {
    s21_big_plus(*value, one, value);
  }
}

void s21_divide_ten_big(s21_big_decimal *value) {
  unsigned long long carry = 0;
  for (int i = 6; i >= 0; --i) {
    unsigned long long temp = (carry << 32) + value->bits[i];
    value->bits[i] = (unsigned int)(temp / 10);
    carry = temp % 10;
  }
}

void s21_big_multiply_by_5(s21_big_decimal *value) {
  unsigned int carry = 0;
  for (int i = 0; i < 8; i++) {
    unsigned long long temp = ((unsigned long long)value->bits[i]) * 5 + carry;
    value->bits[i] = (unsigned int)(temp & 0xFFFFFFFF);
    carry = (unsigned int)(temp >> 32);
  }
}

void s21_big_divide_by_10(s21_big_decimal *value) {
  s21_big_divide_by_5(value);
  s21_big_divide_by_2(value);
}

void s21_big_divide_by_5(s21_big_decimal *value) {
  unsigned long long temp = 0;
  for (int i = 7; i >= 0; i--) {
    temp = (temp << 32) + value->bits[i];
    value->bits[i] = (unsigned int)(temp / 5);
    temp %= 5;
  }
}

void s21_big_divide_by_2(s21_big_decimal *value) {
  unsigned int carry = 0;
  for (int i = 7; i >= 0; i--) {
    unsigned long long temp =
        ((unsigned long long)carry << 32) | value->bits[i];
    value->bits[i] = (unsigned int)(temp / 2);
    carry = temp % 2;
  }
}

void add_values(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  uint64_t carry = 0;
  for (int i = 0; i < 3; i++) {
    uint64_t temp =
        (uint64_t)value_1.bits[i] + (uint64_t)value_2.bits[i] + carry;
    result->bits[i] = (uint32_t)(temp & 0xFFFFFFFF);
    carry = temp >> 32;
  }
}

void subtract_values(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result) {
  uint64_t borrow = 0;
  for (int i = 0; i < 3; i++) {
    uint64_t temp =
        (uint64_t)value_1.bits[i] - (uint64_t)value_2.bits[i] - borrow;
    result->bits[i] = (uint32_t)(temp & 0xFFFFFFFF);
    borrow = (temp >> 32) & 1;
  }
}

void s21_divide_ten(s21_decimal *value) {
  unsigned long long carry = 0;
  for (int i = 2; i >= 0; --i) {
    unsigned long long temp = (carry << 32) + value->bits[i];
    value->bits[i] = (unsigned int)(temp / 10);
    carry = temp % 10;
  }
}

int s21_is_zero(s21_decimal value) {
  return (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0);
}

int s21_is_zero_decimal(s21_decimal value) {
  int code = 1;

  for (int i = 0; i < 3 && code; i++) {
    if (value.bits[i] != 0) code = 0;
  }

  return code;
}

int s21_is_less_big(s21_big_decimal value_1, s21_big_decimal value_2) {
  int result = 0;

  for (int i = 6; i >= 0 && result == 0; i--) {
    if (value_1.bits[i] < value_2.bits[i]) {
      result = 1;
    } else if (value_1.bits[i] > value_2.bits[i]) {
      result = 0;
    }
  }

  return result;
}

int s21_big_div(s21_big_decimal big_value_1, s21_big_decimal big_value_2,
                s21_big_decimal *result, int *scale) {
  s21_big_decimal quotient = {0};
  s21_big_decimal remainder = {0};

  while (s21_is_less_big(big_value_1, big_value_2) && *scale < 28) {
    (*scale)++;
    s21_mul_ten_big(&big_value_1);
    s21_mul_ten_big(result);
  }

  if (s21_is_greater_or_equal_big(big_value_1, big_value_2)) {
    int shift = s21_get_highest_big_bit(big_value_1) -
                s21_get_highest_big_bit(big_value_2);
    s21_big_decimal shifted_divisor = big_value_2;
    s21_shift_left_big(&shifted_divisor, shift);

    while (shift >= 0) {
      if (s21_is_greater_or_equal_big(big_value_1, shifted_divisor)) {
        s21_big_minus(big_value_1, shifted_divisor, &remainder);
        big_value_1 = remainder;
        s21_shift_left_big(&quotient, 1);
        s21_set_bit_big(&quotient, 0, 1);
      } else {
        s21_shift_left_big(&quotient, 1);
      }

      s21_shift_right_big(&shifted_divisor, 1);
      shift--;
    }

    s21_big_plus(*result, quotient, result);

    if (!s21_is_zero_big_decimal(remainder) && *scale < 28 &&
        !overflow_check_big(*result)) {
      (*scale)++;
      s21_mul_ten_big(result);
      s21_mul_ten_big(&remainder);

      s21_big_div(remainder, big_value_2, result, scale);
    }
  }

  return 0;
}

void s21_set_result_sign_and_scale(s21_decimal *result, int sign1, int sign2,
                                   int scale) {
  int final_sign = (sign1 == sign2) ? 0 : 1;
  s21_set_bit(result, 127, final_sign);
  s21_set_scale(result, scale);
}

int overflow_check_big(s21_big_decimal value) {
  int overflow = 0;
  for (int i = 96; i < 224 && !overflow; i++) {
    if (s21_get_bit_big(value, i) == 1) {
      overflow = 1;
    }
  }

  return overflow;
}

int s21_get_highest_big_bit(s21_big_decimal value) {
  int idx_bit = -1;

  for (int i = 224; i >= 0 && idx_bit == -1; i--) {
    int index = i / 32;
    int bit_position = i % 32;

    if ((value.bits[index] >> bit_position) & 1) {
      idx_bit = i;
    }
  }

  return idx_bit;
}

int s21_shift_right_big(s21_big_decimal *value, int shift) {
  int bit_carry = 0;

  for (int i = 6; i >= 0; i--) {
    int new_bit_carry = value->bits[i] << (32 - shift);
    value->bits[i] >>= shift;
    value->bits[i] |= bit_carry;
    bit_carry = new_bit_carry;
  }

  return bit_carry ? 1 : 0;
}

int s21_is_zero_big_decimal(s21_big_decimal value) {
  int code = 1;

  for (int i = 0; i < 7 && code; i++) {
    if (value.bits[i] != 0) code = 0;
  }

  return code;
}

int s21_big_mul(s21_big_decimal big_val_1, s21_big_decimal big_val_2,
                s21_big_decimal *big_res) {
  int overflow = 0;
  for (int i = 0; i < 8; i++) {
    for (int b = 0; b < 32; b++) {
      unsigned int bit2 = (big_val_2.bits[i] >> b) & 1;

      if (bit2 == 1) {
        if (s21_big_plus(big_val_1, *big_res, big_res) != 0) {
          overflow = 1;
        }
      }

      s21_shift_left_big(&big_val_1, 1);
    }
  }
  return overflow;
}