//
// Created by Milan Suk on 15.03.18.
//

#ifndef MATRIXCALC_EVAL_H
#define MATRIXCALC_EVAL_H

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "syntax.h"
#include "matrix.h"

char* eval(FILE* file, Environment* env);
char* eval_ast(AbstractSyntaxTreeNode* file, Environment* env);

void eval_set_variable(char* name, AbstractSyntaxTreeNode* value, Environment* env);

Matrix* eval_ops(AbstractSyntaxTreeNode* node, Environment* env);
Matrix* eval_matrix(AbstractSyntaxTreeNode* value, Environment* env);
Matrix* eval_function(AbstractSyntaxTreeNode* value, Environment* env);

#endif //MATRIXCALC_EVAL_H
