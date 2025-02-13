#ifndef S21_HELPER_FUNCTIONS
#define S21_HELPER_FUNCTIONS

#include "../s21_matrix.h"

int s21_is_matrix_same_size(matrix_t *A, matrix_t *B);
int s21_validate_matrix(matrix_t *A, matrix_t *B);
void s21_multiplyMatrix(int i, int j, matrix_t *A, matrix_t *B,
                        matrix_t *result);
void s21_create_submatrix(matrix_t *A, matrix_t *submatrix, int excluding_row,
                          int excluding_col);
#endif