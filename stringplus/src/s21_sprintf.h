#include "s21_string.h"

unsigned int get_unsigned_argument(va_list args, char length_modifier);
int get_int_argument(va_list args, char length_modifier);
int s21_sprintf(char *buffer, const char *format, ...);
int parse_width(const char **traverse, int *width);
int parse_precision(const char **traverse, int *precision);

char to_upper(char ch);
char process_length_modifier(const char **traverse);

void format_and_align(int left_align, int padding, int zero_padding,
                      char **buffer, int plus_sign, const char *str,
                      int *written, int i);
void parse_buffer(const char **traverse, char **buffer, int *written);
void s21_itoa(long long value, char *str, int base);
void s21_uittoa(unsigned int value, char *str, int base);
void s21_ftoa(double value, char *str, int precision);
void s21_lftoa(long double value, char *str, int precision);
void process_flags(const char **traverse, int *left_align, int *plus_sign,
                   int *space_sign, int *hash_flag, int *zero_padding);
