#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (!s21_validate_matrix(A, B) || result == NULL) {
    status = INCORRECT_MATRIX;
  }
  if (s21_is_matrix_same_size(A, B) == FAILURE) {
    status = CALCULATION_ERROR;
  }

  if (status == OK) {
    status = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return status;
}
