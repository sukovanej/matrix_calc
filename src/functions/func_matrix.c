//
// Created by Milan Suk on 15.03.18.
//

#include "func_matrix.h"

Matrix *minor(Matrix *matrix, unsigned row, unsigned column) {
    Matrix* result = matrix_create_new(matrix->rows - 1, matrix->columns - 1);

    unsigned I = 0, J = 0;
    for (unsigned i = 0; i < matrix->rows; i++) {
        if (i == row) {
            continue;
        }

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

