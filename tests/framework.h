//
// Created by Milan Suk on 23.02.18.
//

#ifndef MATRIXCALC_FRAMEWORK_H
#define MATRIXCALC_FRAMEWORK_H

#include <src/matrix.h>

void test_err(char[]);
void test_success(char[]);

void assert_eq_string(char *name, char* value1, char* value2);
void assert_eq_int(char *name, int value1, int value2);
void assert_eq_double(char *name, double value1, double value2);
void assert_eq_matrix(char *name, Matrix* value1, Matrix* value2);

#endif //MATRIXCALC_FRAMEWORK_H
