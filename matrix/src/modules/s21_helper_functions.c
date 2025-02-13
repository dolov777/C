#include "s21_helper_functions.h"

int s21_is_matrix_same_size(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;

  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    status = FAILURE;
  }

  return status;
}

int s21_validate_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;

  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) {
    status = FAILURE;
  }

  if ((A->rows <= 0 || B->rows <= 0) || (A->columns <= 0 || B->columns <= 0)) {
    status = FAILURE;
  }

  return status;
}

void s21_multiplyMatrix(int i, int j, matrix_t *A, matrix_t *B,
                        matrix_t *result) {
  for (int k = 0; k < A->columns; k++) {
    result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
  }
}

void s21_create_submatrix(matrix_t *A, matrix_t *submatrix, int excluding_row,
                          int excluding_col) {
  for (int i = 0, sub_i = 0; i < A->rows; i++) {
    if (i != excluding_row) {
      for (int j = 0, sub_j = 0; j < A->columns; j++) {
        if (j != excluding_col) {
          submatrix->matrix[sub_i][sub_j] = A->matrix[i][j];
          sub_j++;
        }
      }
      sub_i++;
    }
  }
}