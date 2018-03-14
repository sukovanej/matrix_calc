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
    syntax_test_3();
    syntax_test_4();
    syntax_test_5();
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

void syntax_test_3() {
    FILE* input1 = fopen("../tests/ast/test3.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    AbstractSyntaxTreeNode* result = ast_parse(input1);

    /*
        =
      /   \
     x     +
          / \
         y   1
     */

    assert_eq_int("token", result->token.state, STATE_EQUAL);
    assert_eq_string("left->token->value", result->left->token.value, "x");
    assert_eq_int("right->token->state", result->right->token.state, STATE_PLUS);
    assert_eq_string("right->left->value", result->right->left->token.value, "y");
    assert_eq_string("right->right->value", result->right->right->token.value, "1");
}

void syntax_test_4() {
    FILE* input1 = fopen("../tests/ast/test4.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    AbstractSyntaxTreeNode* result = ast_parse(input1);

    /*
           ,
         /   \
        1     ,
            /   \
           +     4
          / \
         2   3
     */

    assert_eq_int("state", result->token.state, STATE_DELIMITER);
    assert_eq_string("left->value", result->left->token.value, "1");
    assert_eq_int("right->state", result->right->token.state, STATE_DELIMITER);
    assert_eq_int("right->left->state", result->right->left->token.state, STATE_PLUS);
    assert_eq_string("right->left->left->value", result->right->left->left->token.value, "2");
    assert_eq_string("right->left->right->value", result->right->left->right->token.value, "3");
    assert_eq_int("right->right->state", result->right->token.state, STATE_DELIMITER);
    assert_eq_string("right->right->left->value", result->right->right->token.value, "4");
}

void syntax_test_5() {
    FILE* input1 = fopen("../tests/ast/test5.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    AbstractSyntaxTreeNode* result = ast_parse(input1);

    /*
           \n
         /    \
        ,      ,
       / \    / \
      1   0  0   1
     */

    assert_eq_int("state", result->token.state, STATE_NEWLINE_DELIMITER);
    assert_eq_int("left->state", result->left->token.state, STATE_DELIMITER);
    assert_eq_int("right->state", result->right->token.state, STATE_DELIMITER);
    assert_eq_string("right->left->value", result->right->left->token.value, "0");
    assert_eq_string("right->right->value", result->right->right->token.value, "1");
    assert_eq_string("left->left->value", result->left->left->token.value, "1");
    assert_eq_string("left->right->value", result->left->right->token.value, "0");
}
