//
// Created by Milan Suk on 14.03.18.
//

#include <stdio.h>
#include <src/syntax.h>
#include "syntax_test.h"
#include "framework.h"

void all_syntax_tests() {
    syntax_test_1();
    syntax_test_2();
}

void syntax_test_1() {
    FILE* input1 = fopen("../tests/ast/test1.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    AbstractSyntaxTreeNode* result = ast_parse(input1);

    assert_eq_int("token1", result->token.state, STATE_PLUS);
    assert_eq_int("left->state1", result->left->token.state, STATE_NUMBER);
    assert_eq_string("left->value1", result->left->token.value, "1");
    assert_eq_int("right->state1", result->right->token.state, STATE_NUMBER);
    assert_eq_string("left->value1", result->right->token.value, "2");
}

void syntax_test_2() {
    FILE* input1 = fopen("../tests/ast/test2.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    AbstractSyntaxTreeNode* result = ast_parse(input1);

    assert_eq_int("token1", result->token.state, STATE_MULTIPLY);
    assert_eq_string("right->value", result->right->token.value, "3");
    assert_eq_string("left->left->value", result->left->left->token.value, "1");
    assert_eq_string("left->right->value", result->left->right->token.value, "2");
    assert_eq_int("left->token->state", result->left->token.state, STATE_PLUS);
}