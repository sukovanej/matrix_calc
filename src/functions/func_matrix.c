//
// Created by Milan Suk on 15.03.18.
//

#include <src/message.h>
#include "func_matrix.h"

/**
 * Calculate minor from a matrix
 * @param matrix
 * @param row
 * @param column
 * @return
 */
Matrix *minor(Matrix *matrix, unsigned row, unsigned column) {
    Matrix* result = matrix_create_new(matrix->rows - 1, matrix->columns - 1);

    unsigned I = 0;
    for (unsigned i = 0; i < matrix->rows; i++) {
        if (i == row) {
            continue;
        }

        unsigned J = 0;
        for (unsigned j = 0; j < matrix->columns; j++) {
            if (j == column) {
                continue;
            }

            result->matrix[I][J] = matrix->matrix[i][j];
            J++;
        }

        I++;
    }

    return result;
}

/**
 * Get determinant
 * @param matrix
 * @return
 */
double determinant(Matrix *matrix) {
    double result = 0;

    if (matrix->rows != matrix->columns) {
        exit(1);
    }

    if (matrix->rows == 1) {
        return matrix->matrix[0][0];
    }

    char factor = 1;
    for (unsigned i = 0; i < matrix->columns; i++) {
        result += factor * matrix->matrix[0][i] * determinant(minor(matrix, 0, i));
        factor *= -1;
    }

    return result;
}

/**
 * Transpose a matrix
 * @param matrix
 * @return
 */
Matrix *transpose(Matrix *matrix) {
    Matrix* result = matrix_create_new(matrix->columns, matrix->rows);

    for (unsigned i = 0; i < matrix->rows; i ++) {
        for (unsigned j = 0; j < matrix->columns; j ++) {
            result->matrix[j][i] = matrix->matrix[i][j];
        }
    }

    return result;
}

/**
 * Get matrix inverse
 * @param matrix
 * @return
 */
Matrix *inverse(Matrix *matrix) {
    if (matrix->rows != matrix->columns) {
        err("Square matrix expected.");
        exit(1);
    }

    double det = determinant(matrix);

    if (det == 0) {
        err("det(matrix) = 0 -> ZERO matrix returned.");
        return matrix_create_new(matrix->rows, matrix->columns);
    }

    return matrix_multiply_with_scalar(transpose(cofactor(matrix)), 1 / det);
}

/**
 * Get cofactor matrix
 * @param matrix
 * @return
 */
Matrix *cofactor(Matrix *matrix) {
    Matrix* result = matrix_create_new(matrix->rows, matrix->columns);

    for (unsigned i = 0; i < matrix->rows; i++) {
        for (unsigned j = 0; j < matrix->columns; j++) {
            double det = determinant(minor(matrix, i, j));
            result->matrix[i][j] = sign_factor(i, j) * det;
        }
    }

    return result;
}

int sign_factor(unsigned i, unsigned j) {
    if ((i + j) % 2 == 0) {
        return 1;
    } else {
        return -1;
    }
}
