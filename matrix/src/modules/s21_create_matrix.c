#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int matrix_Status = OK;

  if (rows < 1 || columns < 1 || result == NULL) {
    matrix_Status = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(result->rows, sizeof(double *));
    for (int i = 0; i < rows && matrix_Status == OK; i++) {
      result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
    }
  }
  return matrix_Status;
}
