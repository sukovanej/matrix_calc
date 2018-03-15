//
// Created by Milan Suk on 15.03.18.
//

#include "eval_test.h"

void eval_test_1() {
    FILE* input1 = fopen("../tests/ast/test8.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    eval(input1, env_create());
}

void all_eval_tests() {
    eval_test_1();
}

