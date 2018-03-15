//
// Created by Milan Suk on 15.03.18.
//

#include "func_builtin.h"

void set_builtin(Environment *env) {
    memory_set_value(env, "det", &det, MEM_TYPE_FUNCTION);
}

Matrix* det(Matrix* matrix) {
    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = determinant(matrix);

    return result;
}
