//
// Created by Milan Suk on 15.03.18.
//

#include <src/functions/func_matrix.h>
#include "eval_test.h"

void eval_test_1() {
    FILE* input1 = fopen("../tests/functions/test1.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    char* result = eval(input1, env_create_top());
}

void all_eval_tests() {
    eval_test_1();
    eval_test_determinant();
    eval_test_minor();
}

void eval_test_determinant() {
    Matrix* m = matrix_create_new(2, 2);
    m->matrix[0][0] = 1;
    m->matrix[0][1] = 2;
    m->matrix[1][0] = 3;
    m->matrix[1][1] = 4;

    /*
     * 1 2
     * 3 4
     */

    double det = determinant(m);
    assert_eq_double("det1", det, -2);
}

void eval_test_minor() {
    Matrix* m = matrix_create_new(2, 2);
    m->matrix[0][0] = 1;
    m->matrix[0][1] = 2;
    m->matrix[1][0] = 3;
    m->matrix[1][1] = 4;

    Matrix* m1 = minor(m, 0, 0);
    Matrix* m2 = minor(m, 1, 0);
    assert_eq_double("minor1", m1->matrix[0][0], 4);
    assert_eq_double("minor1", m2->matrix[0][0], 2);

    m = matrix_create_new(3, 3);
    m->matrix[0][0] = 1;
    m->matrix[0][1] = 2;
    m->matrix[0][2] = 3;
    m->matrix[1][0] = 4;
    m->matrix[1][1] = 5;
    m->matrix[1][2] = 6;
    m->matrix[2][0] = 7;
    m->matrix[2][1] = 8;
    m->matrix[2][2] = 9;

    /*
     * 1 2 3
     * 4 5 6
     * 7 8 9
     */

    m1 = minor(m, 0, 0);

    m2 = matrix_create_new(2, 2);
    m2->matrix[0][0] = 5;
    m2->matrix[0][1] = 6;
    m2->matrix[1][0] = 8;
    m2->matrix[1][1] = 9;

    assert_eq_matrix("minor 3x3", m1, m2);
}

