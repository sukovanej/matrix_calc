//
// Created by Milan Suk on 15.03.18.
//

#include "func_builtin.h"

/**
 * Save builtin functions into the environment
 * @param env
 */
void set_builtin(Environment *env) {
    memory_set_value(env, "det", &det, MEM_TYPE_FUNCTION);
    memory_set_value(env, "trans", &trans, MEM_TYPE_FUNCTION);
    memory_set_value(env, "cof", &cof, MEM_TYPE_FUNCTION);
    memory_set_value(env, "inv", &inv, MEM_TYPE_FUNCTION);
}

/**
 * Calculate determinant
 * @param matrix
 * @return
 */
Matrix* det(Matrix* matrix) {
    Matrix* result = matrix_create_new(1, 1);
    result->matrix[0][0] = determinant(matrix);

    return result;
}

Matrix *trans(Matrix *matrix) {
    return transpose(matrix);
}

Matrix *cof(Matrix *matrix) {
    return cofactor(matrix);
}

Matrix *inv(Matrix *matrix) {
    return inverse(matrix);
}
