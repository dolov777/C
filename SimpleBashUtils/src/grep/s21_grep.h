#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arguments {
  int e, i, c, v, l, n, h, s, o, f;
  int len_pattern;
  char pattern[1024];
} arguments;

void pattern_add(arguments *arg, char *pattern);
void add_reg_from_file(arguments *arg, char *filepath);
arguments argument_parser(int argc, char **argv);
void output_line(char *line, int n);
void print_math(regex_t *re, char *line);
void processLine(arguments arg, char *path, regex_t *reg);
void output(arguments arg, int argc, char **argv);

#endif
