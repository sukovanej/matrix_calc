//
// Created by Milan Suk on 15.03.18.
//

#include "func_scalar.h"

struct matrix *scalar_acos(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = acos(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_asin(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = asin(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_atan(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = atan(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_cos(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = cos(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_sin(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = sin(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_cosh(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = cosh(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_sinh(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = sinh(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_tanh(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = tanh(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_exp(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = exp(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_log(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = log(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_log10(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = log10(matrix->matrix[0][0]);
    return result;
}

struct matrix *scalar_sqrt(Matrix *matrix) {
    if (matrix->rows != 1 && matrix->columns != 1) {
        err("Scalar value expected.");
        exit(1);
    }

    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = sqrt(matrix->matrix[0][0]);
    return result;
}
