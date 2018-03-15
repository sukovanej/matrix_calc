//
// Created by Milan Suk on 15.03.18.
//

#ifndef MATRIXCALC_FUNC_MATRIX_H
#define MATRIXCALC_FUNC_MATRIX_H

#include <src/matrix.h>
#include <stdlib.h>

Matrix* minor(Matrix* matrix, unsigned row, unsigned column);
double determinant(Matrix* matrix);
Matrix* transpose(Matrix* matrix);
Matrix* cofactor(Matrix* matrix);
Matrix* inverse(Matrix* matrix);
int sign_factor(unsigned i, unsigned j);

#endif //MATRIXCALC_FUNC_MATRIX_H
