//
// Created by Milan Suk on 23.02.18.
//

#include <stdio.h>
#include <string.h>
#include "matrix_test.h"

/**
 * Print error message
 * @param input
 */
void test_err(char *input) {
    printf("[TEST] \x1B[31merror:\x1B[0m %s\n", input);
}

/**
 * Print success message
 * @param input
 */
void test_success(char *input) {
    printf("[TEST] \x1B[32mpassed:\x1B[0m %s\n", input);
}

/**
 * Assert two double values
 * @param name
 * @param value1
 * @param value2
 */
void assert_eq_double(char *name, double value1, double value2) {
    if (value1 == value2) {
        test_success(name);
    } else {
        test_err(name);
        printf("> (value1 != value2) %lf != %lf\n", value1, value2);
    }
}

/**
 * Assert two matrices to be equal
 * @param name
 * @param matrix1
 * @param matrix2
 */
void assert_eq_matrix(char *name, Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows) {
        test_err(name);
        printf("> (m1->rows != m2->rows) %d != %d\n", matrix1->rows, matrix2->rows);
        return;
    } else if (matrix1->columns != matrix2->columns) {
        test_err(name);
        printf("> (m1->columns != m2->columns) %d != %d\n", matrix1->columns, matrix2->columns);
        return;
    }

    for (unsigned int i = 0; i < matrix1->rows; i++) {
        for (unsigned int j = 0; j < matrix1->columns; j++) {
            if (matrix1->matrix[i][j] != matrix2->matrix[i][j]) {
                test_err(name);
                printf("> %f != %f\n", matrix1->matrix[i][j], matrix2->matrix[i][j]);
                return;
            }
        }
    }

    test_success(name);
}

void assert_eq_int(char *name, int value1, int value2) {
    if (value1 == value2) {
        test_success(name);
    } else {
        test_err(name);
        printf(" > %d != %d\n", value1, value2);
    }
}

void assert_eq_string(char *name, char *value1, char *value2) {
    if (strcmp(value1, value2) == 0) {
        test_success(name);
    } else {
        test_err(name);
        printf(" > %s [%zu] != %s [%zu]\n", value1, strlen(value1), value2, strlen(value2));
    }
}

void assert_eq_char(char *name, char value1, char value2) {
    if (value1 == value2) {
        test_success(name);
    } else {
        test_err(name);
        printf(" > %c != %c\n", value1, value2);
    }
}
