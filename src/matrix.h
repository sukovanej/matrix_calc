//
// Created by Milan Suk on 23.02.18.
//

#ifndef MATRIXCALC_MATRIX_H
#define MATRIXCALC_MATRIX_H

typedef struct matrix {
    double** matrix;
    unsigned int rows;
    unsigned int columns;
} Matrix;

Matrix* matrix_create_new(unsigned int, unsigned int);
Matrix* matrix_add(Matrix*, Matrix*);
Matrix* matrix_multiply(Matrix*, Matrix*);

void matrix_initialize(Matrix*, const double[]);
void matrix_print(Matrix*);

#endif //MATRIXCALC_MATRIX_H
