//
// Created by Milan Suk on 15.03.18.
//

#ifndef MATRIXCALC_FUNC_BUILTIN_H
#define MATRIXCALC_FUNC_BUILTIN_H

#include <src/memory.h>
#include <src/matrix.h>
#include "func_matrix.h"

void set_builtin(Environment* env);

Matrix* det(Matrix* matrix);
Matrix* trans(Matrix* matrix);
Matrix* cof(Matrix* matrix);
Matrix* inv(Matrix* matrix);

#endif //MATRIXCALC_FUNC_BUILTIN_H
