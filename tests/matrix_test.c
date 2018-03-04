//
// Created by Milan Suk on 23.02.18.
//

#include "matrix_test.h"
#include "framework.h"

/**
 * Call all matrix tests
 */
void all_matrix_test() {
    add_matrix_test();
    multiply_matrix_test();
    create_new_matrix_test();
}

void add_matrix_test() {
    Matrix* m1 = matrix_create_new(2, 3);
    Matrix* m2 = matrix_create_new(2, 3);
    Matrix* m3 = matrix_create_new(2, 3);

    const double values1[] = {1, 2, 3, 4, 5, 6};
    const double values2[] = {2, 3, 4, 5, 6, 7};
    const double values3[] = {3, 5, 7, 9, 11, 13};

    matrix_initialize(m1, values1);
    matrix_initialize(m2, values2);
    matrix_initialize(m3, values3);

    Matrix* result = matrix_add(m1, m2);

    assert_eq_matrix("add_matrix", result, m3);
}

void create_new_matrix_test() {
    Matrix* m1 = matrix_create_new(2, 2);

    assert_eq_double("create_matrix_columns", m1->columns, 2);
    assert_eq_double("create_matrix_rows", m1->rows, 2);

    const double values[] = {1, 2, 3, 4};
    matrix_initialize(m1, values);

    assert_eq_double("create_matrix_values_1", m1->matrix[0][0], 1);
    assert_eq_double("create_matrix_values_2", m1->matrix[0][1], 2);
    assert_eq_double("create_matrix_values_3", m1->matrix[1][0], 3);
    assert_eq_double("create_matrix_values_4", m1->matrix[1][1], 4);
}

void multiply_matrix_test() {
    Matrix* m1 = matrix_create_new(2, 3);
    Matrix* m2 = matrix_create_new(3, 2);
    Matrix* m3 = matrix_create_new(2, 2);

    /*
     * 1 2 3
     * 4 5 6
     *
     * 2 3
     * 4 5
     * 6 7
     *
     * 28 34
     * 64 79
     */

    const double values1[] = {1, 2, 3, 4, 5, 6};
    const double values2[] = {2, 3, 4, 5, 6, 7};
    const double values3[] = {28, 34, 64, 79};

    matrix_initialize(m1, values1);
    matrix_initialize(m2, values2);
    matrix_initialize(m3, values3);

    Matrix* result = matrix_multiply(m1, m2);

    assert_eq_matrix("multiply_matrix", result, m3);
}

