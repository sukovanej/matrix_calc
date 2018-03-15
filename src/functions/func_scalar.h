//
// Created by Milan Suk on 15.03.18.
//

#ifndef MATRIXCALC_FUNC_SCALAR_H
#define MATRIXCALC_FUNC_SCALAR_H

#include <src/matrix.h>
#include <src/message.h>
#include <stdlib.h>
#include <math.h>

Matrix* scalar_acos(Matrix* matrix);
Matrix* scalar_asin(Matrix* matrix);
Matrix* scalar_atan(Matrix* matrix);
Matrix* scalar_cos(Matrix* matrix);
Matrix* scalar_sin(Matrix* matrix);
Matrix* scalar_cosh(Matrix* matrix);
Matrix* scalar_tanh(Matrix* matrix);
Matrix* scalar_exp(Matrix* matrix);
Matrix* scalar_log(Matrix* matrix);
Matrix* scalar_log10(Matrix* matrix);
Matrix* scalar_sqrt(Matrix* matrix);

#endif //MATRIXCALC_FUNC_SCALAR_H
