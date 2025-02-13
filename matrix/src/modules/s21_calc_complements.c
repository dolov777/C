#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = s21_create_matrix(A->rows, A->columns, result);
  if (code == 0) {
    if (A->rows != A->columns) {
      code = 2;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t submatrix;
          s21_create_matrix(A->rows - 1, A->columns - 1, &submatrix);
          s21_create_submatrix(A, &submatrix, i, j);

          double subdet = 0;
          s21_determinant(&submatrix, &subdet);

          result->matrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * subdet;
          s21_remove_matrix(&submatrix);
        }
      }
    }
  }

  return code;
}