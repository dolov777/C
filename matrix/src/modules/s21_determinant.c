#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int code = 1;
  if (result != NULL) {
    if (A->columns != A->rows) {
      code = 2;
    } else {
      double det = 0;

      if (A->rows == 1) {
        det = A->matrix[0][0];
      } else if (A->rows == 2) {
        det = A->matrix[0][0] * A->matrix[1][1] -
              A->matrix[0][1] * A->matrix[1][0];
      } else {
        for (int j = 0; j < A->columns; j++) {
          matrix_t submatrix;
          s21_create_matrix(A->rows - 1, A->columns - 1, &submatrix);
          s21_create_submatrix(A, &submatrix, 0, j);
          double subdet = 0;
          s21_determinant(&submatrix, &subdet);
          det += (j % 2 == 0 ? 1 : -1) * A->matrix[0][j] * subdet;
          s21_remove_matrix(&submatrix);
        }
      }

      *result = det;
      code = 0;
    }
  }
  return code;
}
