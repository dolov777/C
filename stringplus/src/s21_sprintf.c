#include "s21_sprintf.h"

#include "s21_string.h"

int s21_sprintf(char *buffer, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *traverse;
  const char *str;
  int i;
  unsigned int u;
  double f;
  long double lf;
  char buf[100];
  const char *str_beginning = buffer;
  int written = 0;

  for (traverse = format; *traverse != '\0'; traverse++) {
    parse_buffer(&traverse, &buffer, &written);

    if (*traverse == '\0') break;

    traverse++;

    if (*traverse == '%') {
      *buffer++ = '%';
      written++;
      continue;
    }

    int width = 0;
    int precision = -1;
    int left_align = 0;
    int zero_padding = 0;
    int plus_sign = 0;
    int space_sign = 0;
    int hash_flag = 0;

    process_flags(&traverse, &left_align, &plus_sign, &space_sign, &hash_flag,
                  &zero_padding);

    width = parse_width(&traverse, &width);
    precision = parse_precision(&traverse, &precision);

    char length_modifier = process_length_modifier(&traverse);

    switch (*traverse) {
      case 'd':
      case 'i':
        i = get_int_argument(args, length_modifier);
        if (i < 0) {
          *buffer++ = '-';
          written++;
          i = -i;
        } else if (space_sign) {
          *buffer++ = ' ';
          written++;
        } else if (plus_sign) {
          *buffer++ = ' ';
          written++;
        }
        if (plus_sign) {
          *buffer-- = ' ';
        }

        if (i > 0 && plus_sign) {
          *buffer-- = ' ';
        }

        s21_itoa(i, buf, 10);
        str = buf;
        break;
      case 'u':
        u = get_unsigned_argument(args, length_modifier);
        s21_uittoa(u, buf, 10);
        str = buf;
        break;
      case 'o':
        u = get_unsigned_argument(args, length_modifier);
        if (hash_flag && u != 0) {
          *buffer++ = '0';
          written++;
        }
        s21_uittoa(u, buf, 8);
        str = buf;
        break;
      case 'x':
        u = get_unsigned_argument(args, length_modifier);
        if (hash_flag && u != 0) {
          *buffer++ = '0';
          *buffer++ = 'x';
          written += 2;
        }
        s21_uittoa(u, buf, 16);
        str = buf;
        break;
      case 'X':
        u = get_unsigned_argument(args, length_modifier);
        if (hash_flag && u != 0) {
          *buffer++ = '0';
          *buffer++ = 'X';
          written += 2;
        }
        s21_uittoa(u, buf, 16);

        for (char *p = buf; *p; p++) *p = to_upper(*p);
        str = buf;
        break;
      case 'f':
        if (length_modifier == 'L') {
          lf = va_arg(args, long double);
          if (precision == -1) {
            precision = 6;
          }
          s21_lftoa(lf, buf, precision);
        } else {
          f = va_arg(args, double);
          if (precision == -1) {
            precision = 6;
          }
          s21_ftoa(f, buf, precision);
        }
        str = buf;
        break;
      case 's':
        str = va_arg(args, char *);
        if (precision >= 0) {
          s21_strncpy(buf, str, precision);
          buf[precision] = '\0';
          str = buf;
        }
        break;
      case 'c':
        buf[0] = (char)va_arg(args, int);
        buf[1] = '\0';
        str = buf;
        break;
      case 'n':
        int *n = va_arg(args, int *);
        *n = written;
        continue;
      default:
        str = "";
        break;
    }

    int len = s21_strlen(str);
    int padding = (width > len) ? width - len : 0;
    format_and_align(left_align, padding, zero_padding, &buffer, plus_sign, str,
                     &written, i);
  }

  *buffer = '\0';
  va_end(args);
  return buffer - str_beginning;
}

void process_flags(const char **traverse, int *left_align, int *plus_sign,
                   int *space_sign, int *hash_flag, int *zero_padding) {
  while (**traverse == '-' || **traverse == '+' || **traverse == ' ' ||
         **traverse == '#' || **traverse == '0') {
    if (**traverse == '-')
      *left_align = 1;
    else if (**traverse == '+')
      *plus_sign = 1;
    else if (**traverse == ' ')
      *space_sign = 1;
    else if (**traverse == '#')
      *hash_flag = 1;
    else if (**traverse == '0')
      *zero_padding = 1;
    (*traverse)++;
  }
}

char process_length_modifier(const char **traverse) {
  char length_modifier = '\0';
  if (**traverse == 'h' || **traverse == 'l' || **traverse == 'L') {
    length_modifier = **traverse;
    (*traverse)++;
    if ((length_modifier == 'h' && **traverse == 'h') ||
        (length_modifier == 'l' && **traverse == 'l')) {
      length_modifier = length_modifier == 'h' ? 'H' : 'L';
      (*traverse)++;
    }
  }

  return length_modifier;
}

unsigned int get_unsigned_argument(va_list args, char length_modifier) {
  unsigned int u;
  if (length_modifier == 'h') {
    u = (unsigned short)va_arg(args, unsigned int);
  } else if (length_modifier == 'H') {
    u = (unsigned char)va_arg(args, unsigned int);
  } else if (length_modifier == 'l') {
    u = va_arg(args, unsigned long);
  } else {
    u = va_arg(args, unsigned int);
  }
  return u;
}

int get_int_argument(va_list args, char length_modifier) {
  int i;
  if (length_modifier == 'h') {
    i = (short)va_arg(args, int);
  } else if (length_modifier == 'H') {
    i = (char)va_arg(args, int);
  } else if (length_modifier == 'l') {
    i = va_arg(args, long);
  } else {
    i = va_arg(args, int);
  }
  return i;
}

char to_upper(char ch) {
  char res = ch;
  if (ch >= 'a' && ch <= 'z') {
    res = ch - 'a' + 'A';
  }
  return res;
}

void s21_itoa(long long value, char *str, int base) {
  if (base < 2 || base > 16) {
    *str = '\0';
    return;
  }

  char *ptr = str;
  char *ptr1 = str;
  int is_negative = 0;

  if (value < 0 && base == 10) {
    is_negative = 1;
    value = -value;
  }

  do {
    int tmp_value;
    tmp_value = value % base;
    value /= base;
    *ptr++ = "0123456789abcdef"[tmp_value];
  } while (value);

  if (is_negative) {
    *ptr++ = '-';
  }

  *ptr-- = '\0';

  while (ptr1 < ptr) {
    char tmp_char;
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }
}

void s21_uittoa(unsigned int value, char *str, int base) {
  if (base < 2 || base > 16) {
    *str = '\0';
    return;
  }

  char *ptr = str;
  char *start = str;

  do {
    int tmp_value;
    tmp_value = value % base;
    value /= base;
    *ptr++ = "0123456789abcdef"[tmp_value];
  } while (value);

  *ptr-- = '\0';

  while (start < ptr) {
    char tmp_char;
    tmp_char = *start;
    *start++ = *ptr;
    *ptr-- = tmp_char;
  }
}

void s21_ftoa(double value, char *str, int precision) {
  if (precision < 0) precision = 0;

  int int_part = (int)value;
  double fraction_part = fabs(value - int_part);
  char *ptr = str;

  if (value < 0) {
    *ptr++ = '-';
    int_part = -int_part;
  }

  s21_itoa(int_part, ptr, 10);
  while (*ptr != '\0') ptr++;

  *ptr++ = '.';

  for (int i = 0; i < precision; i++) {
    fraction_part *= 10;
    int digit = (int)fraction_part;
    *ptr++ = '0' + digit;
    fraction_part -= digit;
  }

  fraction_part *= 10;
  if ((int)fraction_part >= 5) {
    char *round_ptr = ptr - 1;
    while (round_ptr >= str && *round_ptr == '9') {
      *round_ptr = '0';
      round_ptr--;
    }
    if (round_ptr >= str && *round_ptr != '.') {
      (*round_ptr)++;
    } else if (round_ptr < str) {
      for (char *shift_ptr = ptr; shift_ptr > str; shift_ptr--) {
        *shift_ptr = *(shift_ptr - 1);
      }
      *str = '1';
      ptr++;
    }
  }

  *ptr = '\0';
}

void s21_lftoa(long double value, char *str, int precision) {
  if (precision < 0) precision = 0;

  long long int_part = (long long)value;
  long double fraction_part = fabsl(value - int_part);
  char *ptr = str;

  if (value < 0) {
    *ptr++ = '-';
    int_part = -int_part;
  }

  s21_itoa(int_part, ptr, 10);
  while (*ptr != '\0') ptr++;

  *ptr++ = '.';

  for (int i = 0; i < precision; i++) {
    fraction_part *= 10;
    int digit = (int)fraction_part;
    *ptr++ = '0' + digit;
    fraction_part -= digit;
  }

  fraction_part *= 10;
  if ((int)fraction_part >= 5) {
    char *round_ptr = ptr - 1;
    while (round_ptr >= str && *round_ptr == '9') {
      *round_ptr = '0';
      round_ptr--;
    }
    if (round_ptr >= str && *round_ptr != '.') {
      (*round_ptr)++;
    } else if (round_ptr < str) {
      for (char *shift_ptr = ptr; shift_ptr > str; shift_ptr--) {
        *shift_ptr = *(shift_ptr - 1);
      }
      *str = '1';
      ptr++;
    }
  }

  *ptr = '\0';
}

int parse_width(const char **traverse, int *width) {
  while (**traverse >= '0' && **traverse <= '9') {
    *width = *width * 10 + (**traverse - '0');
    (*traverse)++;
  }
  return *width;
}

int parse_precision(const char **traverse, int *precision) {
  if (**traverse == '.') {
    (*traverse)++;
    *precision = 0;
    while (**traverse >= '0' && **traverse <= '9') {
      *precision = *precision * 10 + (**traverse - '0');
      (*traverse)++;
    }
  }

  return *precision;
}

void parse_buffer(const char **traverse, char **buffer, int *written) {
  while (**traverse != '%' && **traverse != '\0') {
    *(*buffer)++ = *(*traverse)++;
    (*written)++;
  }
}

void format_and_align(int left_align, int padding, int zero_padding,
                      char **buffer, int plus_sign, const char *str,
                      int *written, int i) {
  if (!left_align) {
    while (padding-- > 0) {
      *(*buffer)++ = zero_padding ? '0' : ' ';
      (*written)++;
    }
  }

  if (i > 0 && plus_sign) {
    *(*buffer)++ = '+';
    (*written)++;
  }

  while (*str) {
    *(*buffer)++ = *str++;
    (*written)++;
  }

  if (left_align) {
    while (padding-- > 0) {
      *(*buffer)++ = ' ';
      (*written)++;
    }
  }
}