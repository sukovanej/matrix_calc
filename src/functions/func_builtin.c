//
// Created by Milan Suk on 15.03.18.
//

#include "func_builtin.h"
#include "func_scalar.h"

/**
 * Save builtin functions into the environment
 * @param env
 */
void set_builtin(Environment *env) {
    // matrix functions
    memory_set_value(env, "det", &det, MEM_TYPE_FUNCTION);
    memory_set_value(env, "trans", &trans, MEM_TYPE_FUNCTION);
    memory_set_value(env, "cof", &cof, MEM_TYPE_FUNCTION);
    memory_set_value(env, "inv", &inv, MEM_TYPE_FUNCTION);

    // scalar functions
    memory_set_value(env, "acos", &scalar_acos, MEM_TYPE_FUNCTION);
    memory_set_value(env, "asin", &scalar_asin, MEM_TYPE_FUNCTION);
    memory_set_value(env, "atan", &scalar_atan, MEM_TYPE_FUNCTION);
    memory_set_value(env, "cos", &scalar_cos, MEM_TYPE_FUNCTION);
    memory_set_value(env, "sin", &scalar_sin, MEM_TYPE_FUNCTION);
    memory_set_value(env, "cosh", &scalar_cosh, MEM_TYPE_FUNCTION);
    memory_set_value(env, "tanh", &scalar_tanh, MEM_TYPE_FUNCTION);
    memory_set_value(env, "exp", &scalar_exp, MEM_TYPE_FUNCTION);
    memory_set_value(env, "log", &scalar_log, MEM_TYPE_FUNCTION);
    memory_set_value(env, "log10", &scalar_log10, MEM_TYPE_FUNCTION);
    memory_set_value(env, "sqrt", &scalar_sqrt, MEM_TYPE_FUNCTION);
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