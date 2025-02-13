#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = 1;
  if (result != NULL) {
    double det = 0;
    s21_determinant(A, &det);
    code = 0;
    if (det != 0) {
      matrix_t complement_matrix;
      s21_calc_complements(A, &complement_matrix);

      matrix_t transposed_matrix;
      s21_transpose(&complement_matrix, &transposed_matrix);

      s21_mult_number(&transposed_matrix, (1 / det), result);
      s21_remove_matrix(&transposed_matrix);
      s21_remove_matrix(&complement_matrix);
    } else {
      code = 2;
    }
  }

  return code;
}