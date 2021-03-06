//
// Created by Milan Suk on 23.02.18.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "message.h"

/**
 * Creates new matrix structure and returns pointer to it
 * @param rows
 * @param columns
 * @return Matrix*
 */
Matrix* matrix_create_new(unsigned int rows, unsigned int columns) {
    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));

    matrix->matrix = (double**) malloc(rows * sizeof(double*));
    matrix->rows = rows;
    matrix->columns = columns;

    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = (double *) malloc(columns * sizeof(double));
    }

    return matrix;
}

/**
 * Add two matrices, return the result
 * @param matrix1
 * @param matrix2
 * @return
 */
Matrix* matrix_add(Matrix* matrix1, Matrix* matrix2) {
    if (matrix1->columns != matrix2->columns || matrix1->rows != matrix2->rows) {
        err("Matrices must have same dimensions.");
    }

    Matrix* result = matrix_create_new(matrix1->rows, matrix1->columns);

    for (unsigned int i = 0; i < matrix1->rows; i++) {
        for (unsigned int j = 0; j < matrix1->columns; j++) {
            result->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
        }
    }

    return result;
}

/**
 * Multiply two matrices, return the result
 * @param matrix1
 * @param matrix2
 * @return
 */
Matrix* matrix_multiply(Matrix* matrix1, Matrix* matrix2) {
    if (matrix1->rows == 1 && matrix1->columns == 1) {
        return matrix_multiply_with_scalar(matrix2, matrix1->matrix[0][0]);
    } else if (matrix2->rows == 1 && matrix2->columns == 1) {
        return matrix_multiply_with_scalar(matrix1, matrix2->matrix[0][0]);
    }

    if (matrix1->columns != matrix2->rows) {
        err("Matrices must be of type k*l and l*m");
    }

    Matrix* result = matrix_create_new(matrix1->rows, matrix2->columns);

    for (unsigned int i = 0; i < matrix1->rows; i++) {
        for (unsigned int j = 0; j < matrix2->columns; j++) {
            result->matrix[i][j] = 0;

            for (unsigned int k = 0; k < matrix1->columns; k++) {
                result->matrix[i][j] += matrix1->matrix[i][k] * matrix2->matrix[k][j];
            }
        }
    }

    return result;
}

/**
 * Initialize matrix with values
 * @param matrix
 * @param values
 */
void matrix_initialize(Matrix *matrix, const double values[]) {
    unsigned i = 0;
    for (unsigned x = 0; x < matrix->rows; x++) {
        for (unsigned y = 0; y < matrix->columns; y++) {
            matrix->matrix[x][y] = values[i];
            i++;
        }
    }
}

/**
 * Print matrix entries
 * @param matrix
 */
char* matrix_str(Matrix *matrix) {
    char* result = malloc(sizeof(char));
    char buffer[256];

    for (unsigned x = 0; x < matrix->rows; x++) {
        for (unsigned y = 0; y < matrix->columns; y++) {
            sprintf(buffer, "%lf", matrix->matrix[x][y]);
            result = realloc(result, (3 + strlen(result) + strlen(buffer)) * sizeof(char));
            strcat(result, buffer);

            if (matrix->columns > 1 && x < matrix->rows && y < matrix->columns - 1) {
                strcat(result, ", ");
            }
        }

        if (matrix->rows > 1 && x < matrix->rows) {
            strcat(result, "\n");
        }
    }

    return result;
}

/**
 * Print matrix entries
 * @param matrix
 */
void matrix_print(Matrix *matrix) {
    printf("%s", matrix_str(matrix));
}

/**
 * Evaluate matrix1 - matrix2
 * @param matrix1
 * @param matrix2
 * @return
 */
Matrix *matrix_minus(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->columns != matrix2->columns || matrix1->rows != matrix2->rows) {
        err("Matrices must have same dimensions.");
    }

    Matrix* result = matrix_create_new(matrix1->rows, matrix1->columns);

    for (unsigned int i = 0; i < matrix1->rows; i++) {
        for (unsigned int j = 0; j < matrix1->columns; j++) {
            result->matrix[i][j] = matrix1->matrix[i][j] - matrix2->matrix[i][j];
        }
    }

    return result;
}

Matrix *matrix_multiply_with_scalar(Matrix *matrix, double scalar) {
     Matrix* result = matrix_create_new(matrix->rows, matrix->columns);

    for (unsigned int i = 0; i < result->rows; i++) {
        for (unsigned int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = matrix->matrix[i][j] * scalar;
        }
    }

    return result;
}
