#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (!s21_validate_matrix(A, B) || result == NULL) {
    status = INCORRECT_MATRIX;
  }
  if (A->columns != B->rows) {
    status = CALCULATION_ERROR;
  }

  if (status == OK) {
    status = s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        s21_multiplyMatrix(i, j, A, B, result);
      }
    }
  }

  return status;
}