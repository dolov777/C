#include "unit_tests.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 0, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(-5, 5, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, -5, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), OK);
  ck_assert_int_eq(A.rows, 1);
  ck_assert_int_eq(A.columns, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(1000, 1000, &A), OK);
  ck_assert_int_eq(A.rows, 1000);
  ck_assert_int_eq(A.columns, 1000);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  ck_assert_ptr_nonnull(A.matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_9) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = i + j;
    }
  }
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_10) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(2, 3, &A), OK);
  ck_assert_int_eq(A.rows, 2);
  ck_assert_int_eq(A.columns, 3);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_11) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(3, 2, &A), OK);
  ck_assert_int_eq(A.rows, 3);
  ck_assert_int_eq(A.columns, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_12) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(10, 10, &A), OK);
  ck_assert_ptr_nonnull(A.matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_13) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(0, 5, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_14) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 0, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_remove_matrix_1) {
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_remove_matrix_3) {
  matrix_t A = {};
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

// s21_eq_matrix

START_TEST(s21_eq_matrix_1) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  int expected = SUCCESS;
  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 9;
  A.matrix[0][1] = 8;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  int expected = FAILURE;
  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

  int expected = FAILURE;
  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1.123456789;
  A.matrix[0][1] = 2.123456789;
  A.matrix[0][2] = 3.123456789;
  A.matrix[1][0] = 4.123456789;
  A.matrix[1][1] = 5.123456789;
  A.matrix[1][2] = 6.123456789;
  A.matrix[2][0] = 7.123456789;
  A.matrix[2][1] = 8.123456789;
  A.matrix[2][2] = 9.123456789;

  B.matrix[0][0] = 1.123456798;
  B.matrix[0][1] = 2.123456798;
  B.matrix[0][2] = 3.123456798;
  B.matrix[1][0] = 4.123456798;
  B.matrix[1][1] = 5.123456798;
  B.matrix[1][2] = 6.123456798;
  B.matrix[2][0] = 7.123456798;
  B.matrix[2][1] = 8.123456798;
  B.matrix[2][2] = 9.123456798;

  int expected = SUCCESS;
  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1.123556789;
  A.matrix[0][1] = 2.123556789;
  A.matrix[0][2] = 3.123556789;
  A.matrix[1][0] = 4.123556789;
  A.matrix[1][1] = 5.123556789;
  A.matrix[1][2] = 6.123556789;
  A.matrix[2][0] = 7.123556789;
  A.matrix[2][1] = 8.123556789;
  A.matrix[2][2] = 9.123556789;

  B.matrix[0][0] = 1.123456798;
  B.matrix[0][1] = 2.123456798;
  B.matrix[0][2] = 3.123456798;
  B.matrix[1][0] = 4.123456798;
  B.matrix[1][1] = 5.123456798;
  B.matrix[1][2] = 6.123456798;
  B.matrix[2][0] = 7.123456798;
  B.matrix[2][1] = 8.123456798;
  B.matrix[2][2] = 9.123456798;

  int expected = FAILURE;
  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// s21_sum_matrix

START_TEST(s21_sum_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &B);
  matrix_t result = {NULL, 0, 0};
  int state = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(state, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  double value_1 = 10;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &B);
  double value_2 = 10;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      B.matrix[i][j] = value_2;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], (value_1 + value_2),
                              TEST_EPS);
    }
  }
  ck_assert_int_eq(state, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  double value_1 = -1e30;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &B);
  double value_2 = -1e7;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      B.matrix[i][j] = value_2;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], (value_1 + value_2),
                              TEST_EPS);
    }
  }
  ck_assert_int_eq(state, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(17, 9, &A);
  double value_1 = 0.000001;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(17, 9, &B);
  double value_2 = 0.000001;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      B.matrix[i][j] = value_2;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], (value_1 + value_2),
                              TEST_EPS);
    }
  }
  ck_assert_int_eq(state, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t A;
  matrix_t B;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  int expected = 1;
  int res = s21_sum_matrix(&A, &B, NULL);

  ck_assert_int_eq(expected, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i * j;
    }
  }

  int state = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(state, OK);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(result.matrix[i][j], A.matrix[i][j] + B.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  int state = s21_sum_matrix(&A, &B, NULL);
  ck_assert_int_eq(state, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  expected_matrix.matrix[0][0] = 0;
  expected_matrix.matrix[0][1] = 0;
  expected_matrix.matrix[0][2] = 0;
  expected_matrix.matrix[1][0] = 0;
  expected_matrix.matrix[1][1] = 0;
  expected_matrix.matrix[1][2] = 0;
  expected_matrix.matrix[2][0] = 0;
  expected_matrix.matrix[2][1] = 0;
  expected_matrix.matrix[2][2] = 0;

  int expected = 0;
  int res = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  matrix_t A;
  matrix_t B;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  int expected = 1;
  int res = s21_sub_matrix(&A, &B, NULL);

  ck_assert_int_eq(expected, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  int res = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(result.matrix[0][0], 0);
  ck_assert_int_eq(result.matrix[1][0], 0);
  ck_assert_int_eq(result.matrix[2][0], 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  matrix_t A;
  matrix_t B;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  int res = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(res, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  int res = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(res, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i;
    }
  }

  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], A.matrix[i][j] - B.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

// s21_mult_number

START_TEST(s21_mult_number_1) {
  matrix_t A;
  double number = 2.0;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  expected_matrix.matrix[0][0] = 2;
  expected_matrix.matrix[0][1] = 4;
  expected_matrix.matrix[0][2] = 6;
  expected_matrix.matrix[1][0] = 8;
  expected_matrix.matrix[1][1] = 10;
  expected_matrix.matrix[1][2] = 12;
  expected_matrix.matrix[2][0] = 14;
  expected_matrix.matrix[2][1] = 16;
  expected_matrix.matrix[2][2] = 18;

  int expected = 0;
  int res = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}
END_TEST

START_TEST(s21_mult_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  double value_1 = 10;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &B);
  double value_2 = 10;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      B.matrix[i][j] = value_2;
    }
  }

  matrix_t result = {NULL, 0, 0};
  int state = s21_mult_matrix(&A, &B, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], 300.0, TEST_EPS);
    }
  }
  ck_assert_int_eq(state, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 1, &A);
  double value_1 = 10;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 2, &B);
  double value_2 = 10;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 2; j++) {
      B.matrix[i][j] = value_2;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_mult_matrix(&A, &B, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], 100.0, TEST_EPS);
    }
  }
  ck_assert_int_eq(state, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

// s21_transpose

START_TEST(s21_transpose_1) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  expected_matrix.matrix[0][0] = 1;
  expected_matrix.matrix[0][1] = 4;
  expected_matrix.matrix[1][0] = 2;
  expected_matrix.matrix[1][1] = 5;
  expected_matrix.matrix[2][0] = 3;
  expected_matrix.matrix[2][1] = 6;

  int expected = 0;
  int res = s21_transpose(&A, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(s21_transpose_2) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  expected_matrix.matrix[0][0] = 1;
  expected_matrix.matrix[0][1] = 4;
  expected_matrix.matrix[0][2] = 7;
  expected_matrix.matrix[1][0] = 2;
  expected_matrix.matrix[1][1] = 5;
  expected_matrix.matrix[1][2] = 8;
  expected_matrix.matrix[2][0] = 3;
  expected_matrix.matrix[2][1] = 6;
  expected_matrix.matrix[2][2] = 9;

  int expected = 0;
  int res = s21_transpose(&A, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(s21_transpose_3) {
  matrix_t A;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int expected = 1;
  int res = s21_transpose(&A, NULL);

  ck_assert_int_eq(expected, res);

  s21_remove_matrix(&A);
}

// s21_determinant

START_TEST(s21_determinant_1) {
  matrix_t A;
  double det;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int expected = 0;
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(expected, res);
  ck_assert_double_eq(0, det);
  s21_remove_matrix(&A);
}

// s21_calc_complements

START_TEST(s21_calc_complements_1) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  expected_matrix.matrix[0][0] = 0;
  expected_matrix.matrix[0][1] = 10;
  expected_matrix.matrix[0][2] = -20;
  expected_matrix.matrix[1][0] = 4;
  expected_matrix.matrix[1][1] = -14;
  expected_matrix.matrix[1][2] = 8;
  expected_matrix.matrix[2][0] = -8;
  expected_matrix.matrix[2][1] = -2;
  expected_matrix.matrix[2][2] = 4;
  int expected = 0;
  int res = s21_calc_complements(&A, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

// s21_inverse_matrix

START_TEST(s21_inverse_matrix_1) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  expected_matrix.matrix[0][0] = 1;
  expected_matrix.matrix[0][1] = -1;
  expected_matrix.matrix[0][2] = 1;
  expected_matrix.matrix[1][0] = -38;
  expected_matrix.matrix[1][1] = 41;
  expected_matrix.matrix[1][2] = -34;
  expected_matrix.matrix[2][0] = 27;
  expected_matrix.matrix[2][1] = -29;
  expected_matrix.matrix[2][2] = 24;
  int expected = 0;
  int res = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(s21_inverse_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  expected_matrix.matrix[0][0] = 2;
  expected_matrix.matrix[0][1] = 4;
  expected_matrix.matrix[0][2] = 6;
  expected_matrix.matrix[1][0] = 8;
  expected_matrix.matrix[1][1] = 10;
  expected_matrix.matrix[1][2] = 12;
  expected_matrix.matrix[2][0] = 14;
  expected_matrix.matrix[2][1] = 16;
  expected_matrix.matrix[2][2] = 18;

  int expected = 0;
  int res = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(s21_inverse_matrix_3) {
  matrix_t A;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int expected = 1;
  int res = s21_inverse_matrix(&A, NULL);

  ck_assert_int_eq(expected, res);

  s21_remove_matrix(&A);
}

Suite *s21_create_matrix_suite(void) {
  Suite *suite = suite_create("s21_create_matrix");
  TCase *tc_core = tcase_create("core_of_create_matrix");
  tcase_add_test(tc_core, s21_create_matrix_1);
  tcase_add_test(tc_core, s21_create_matrix_2);
  tcase_add_test(tc_core, s21_create_matrix_3);
  tcase_add_test(tc_core, s21_create_matrix_4);
  tcase_add_test(tc_core, s21_create_matrix_5);
  tcase_add_test(tc_core, s21_create_matrix_6);
  tcase_add_test(tc_core, s21_create_matrix_7);
  tcase_add_test(tc_core, s21_create_matrix_8);
  tcase_add_test(tc_core, s21_create_matrix_9);
  tcase_add_test(tc_core, s21_create_matrix_10);
  tcase_add_test(tc_core, s21_create_matrix_11);
  tcase_add_test(tc_core, s21_create_matrix_12);
  tcase_add_test(tc_core, s21_create_matrix_13);
  tcase_add_test(tc_core, s21_create_matrix_14);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *s21_remove_matrix_suite(void) {
  Suite *suite = suite_create("s21_remove_matrix");
  TCase *tc_core = tcase_create("core_of_remove_matrix");
  tcase_add_test(tc_core, s21_remove_matrix_1);
  tcase_add_test(tc_core, s21_remove_matrix_2);
  tcase_add_test(tc_core, s21_remove_matrix_3);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *s21_eq_matrix_suite(void) {
  Suite *suite = suite_create("s21_eq_matrix");
  TCase *tc_core = tcase_create("core_of_eq_matrix");
  tcase_add_test(tc_core, s21_eq_matrix_1);
  tcase_add_test(tc_core, s21_eq_matrix_2);
  tcase_add_test(tc_core, s21_eq_matrix_3);
  tcase_add_test(tc_core, s21_eq_matrix_4);
  tcase_add_test(tc_core, s21_eq_matrix_5);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *s21_sum_matrix_suite(void) {
  Suite *suite = suite_create("s21_sum_matrix");
  TCase *tc_core = tcase_create("core_of_sum_matrix");
  tcase_add_test(tc_core, s21_sum_matrix_1);
  tcase_add_test(tc_core, s21_sum_matrix_2);
  tcase_add_test(tc_core, s21_sum_matrix_3);
  tcase_add_test(tc_core, s21_sum_matrix_4);
  tcase_add_test(tc_core, s21_sum_matrix_5);
  tcase_add_test(tc_core, s21_sum_matrix_6);
  tcase_add_test(tc_core, s21_sum_matrix_7);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *s21_sub_matrix_suite(void) {
  Suite *suite = suite_create("s21_sub_matrix");
  TCase *tc_core = tcase_create("core_of_sub_matrix");
  tcase_add_test(tc_core, s21_sub_matrix_1);
  tcase_add_test(tc_core, s21_sub_matrix_2);
  tcase_add_test(tc_core, s21_sub_matrix_3);
  tcase_add_test(tc_core, s21_sub_matrix_4);
  tcase_add_test(tc_core, s21_sub_matrix_5);
  tcase_add_test(tc_core, s21_sub_matrix_6);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *s21_mult_number_suite(void) {
  Suite *suite = suite_create("s21_mult_number");
  TCase *tc_core = tcase_create("core_of_mult_number");
  tcase_add_test(tc_core, s21_mult_number_1);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *s21_mult_matrix_suite(void) {
  Suite *suite = suite_create("s21_mult_matrix");
  TCase *tc_core = tcase_create("core_of_mult_matrix");
  tcase_add_test(tc_core, s21_mult_matrix_1);
  tcase_add_test(tc_core, s21_mult_matrix_2);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *s21_transpose_suite(void) {
  Suite *suite = suite_create("s21_transpose");
  TCase *tc_core = tcase_create("core_of_transpose");
  tcase_add_test(tc_core, s21_transpose_1);
  tcase_add_test(tc_core, s21_transpose_2);
  tcase_add_test(tc_core, s21_transpose_3);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *s21_calc_complements_suite(void) {
  Suite *suite = suite_create("s21_calc_complements");
  TCase *tc_core = tcase_create("core_of_calc_complements");
  tcase_add_test(tc_core, s21_calc_complements_1);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *s21_determinant_suite(void) {
  Suite *suite = suite_create("s21_determinant");
  TCase *tc_core = tcase_create("core_of_determinant");
  tcase_add_test(tc_core, s21_determinant_1);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *s21_inverse_matrix_suite(void) {
  Suite *suite = suite_create("s21_inverse_matrix");
  TCase *tc_core = tcase_create("core_of_inverse_matrix");
  tcase_add_test(tc_core, s21_inverse_matrix_1);
  tcase_add_test(tc_core, s21_inverse_matrix_2);
  tcase_add_test(tc_core, s21_inverse_matrix_3);
  suite_add_tcase(suite, tc_core);

  return suite;
}

void s21_suit_execution(Suite *suite, int *failed_count, char *suite_name) {
  SRunner *suite_runner = srunner_create(suite);
  srunner_set_log(suite_runner, suite_name);
  srunner_run_all(suite_runner, CK_NORMAL);
  *failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
}

int main(void) {
  int failed_count = 0;

  s21_suit_execution(s21_create_matrix_suite(), &failed_count,
                     "tests/create_matrix.log");
  s21_suit_execution(s21_remove_matrix_suite(), &failed_count,
                     "tests/remove_matrix.log");
  s21_suit_execution(s21_eq_matrix_suite(), &failed_count,
                     "tests/eq_matrix.log");
  s21_suit_execution(s21_sum_matrix_suite(), &failed_count,
                     "tests/sum_matrix.log");
  s21_suit_execution(s21_sub_matrix_suite(), &failed_count,
                     "tests/sub_matrix.log");
  s21_suit_execution(s21_mult_number_suite(), &failed_count,
                     "tests/mult_number.log");
  s21_suit_execution(s21_mult_matrix_suite(), &failed_count,
                     "tests/mult_matrix.log");
  s21_suit_execution(s21_transpose_suite(), &failed_count,
                     "tests/transpose.log");
  s21_suit_execution(s21_calc_complements_suite(), &failed_count,
                     "tests/calc_complements.log");
  s21_suit_execution(s21_determinant_suite(), &failed_count,
                     "tests/determinant.log");
  s21_suit_execution(s21_inverse_matrix_suite(), &failed_count,
                     "tests/inverse_matrix.log");

  return failed_count == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
