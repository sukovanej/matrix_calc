//
// Created by Milan Suk on 04.03.18.
//

#include <src/lexer.h>
#include "lexer_test.h"
#include "framework.h"

void all_lexer_test() {
    lexer_test();
    lexer_init_test();
    arith_test_1();
    arith_test_2();
    arith_test_3();
}

void lexer_init_test() {
    FILE* input1 = fopen("../tests/lexer/lexer2.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    Token token = get_token(input1, STATE_INIT);
    assert_eq_int("token1", token.state, STATE_CHAR);
    assert_eq_string("token1", token.value, "A");
    token = get_token(input1, token.state);
    assert_eq_int("token2", token.state, STATE_EQUAL);
    token = get_token(input1, token.state);
    assert_eq_string("token3", token.value, "1.2");
    assert_eq_int("token3", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token4", token.state, STATE_DELIMITER);
    token = get_token(input1, token.state);
    assert_eq_string("token5", token.value, "2");
    assert_eq_int("token5", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token6", token.state, STATE_DELIMITER);
    token = get_token(input1, token.state);
    assert_eq_string("token7", token.value, "3.14");
    assert_eq_int("token7", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token8", token.state, STATE_DELIMITER);
    token = get_token(input1, token.state);
    assert_eq_string("token9", token.value, "4");
    assert_eq_int("token9", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token10", token.state, STATE_NEWLINE);

    token = get_token(input1, STATE_INIT);
    assert_eq_int("token11", token.state, STATE_CHAR);
    assert_eq_string("token11", token.value, "B");
    token = get_token(input1, token.state);
    assert_eq_int("token12", token.state, STATE_EQUAL);
    token = get_token(input1, token.state);
    assert_eq_string("token13", token.value, "2.1");
    assert_eq_int("token13", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token14", token.state, STATE_DELIMITER);
    token = get_token(input1, token.state);
    assert_eq_string("token15", token.value, "2");
    assert_eq_int("token15", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token16", token.state, STATE_NEWLINE_DELIMITER);

    token = get_token(input1, token.state);
    assert_eq_string("token17", token.value, "2");
    assert_eq_int("token17", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token18", token.state, STATE_DELIMITER);
    token = get_token(input1, token.state);
    assert_eq_string("token19", token.value, "1.2");
    assert_eq_int("token19", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token20", token.state, STATE_NEWLINE);

    token = get_token(input1, token.state);
    assert_eq_int("token21", token.state, STATE_CHAR);
    assert_eq_string("token21", token.value, "C");
    token = get_token(input1, token.state);
    assert_eq_int("token22", token.state, STATE_EQUAL);
    token = get_token(input1, token.state);
    assert_eq_int("token23", token.state, STATE_NUMBER);
    assert_eq_string("token23", token.value, "1");
    token = get_token(input1, token.state);
    assert_eq_int("token24", token.state, STATE_END);
}

void lexer_test() {
    FILE* input1 = fopen("../tests/lexer/lexer1.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    Token token = get_token(input1, STATE_INIT);
    assert_eq_int("token1", token.state, STATE_LEFT_PAR);
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_CHAR);
    assert_eq_string("token1", token.value, "A");
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_PLUS);
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_CHAR);
    assert_eq_string("token1", token.value, "B");
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_RIGHT_PAR);
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_MULTIPLY);
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_CHAR);
    assert_eq_string("token1", token.value, "D");
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_PLUS);
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_LEFT_PAR);
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_CHAR);
    assert_eq_string("token1", token.value, "D");
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_PLUS);
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_CHAR);
    assert_eq_string("token1", token.value, "AB");
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_RIGHT_PAR);
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_END);
}

void arith_test_1() {
    FILE* input1 = fopen("../tests/ast/test1.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    Token token = get_token(input1, STATE_INIT);
    assert_eq_string("token1", token.value, "1");
    assert_eq_int("token1", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token2", token.state, STATE_PLUS);
    token = get_token(input1, token.state);
    assert_eq_string("token3", token.value, "2");
    assert_eq_int("token3", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token4", token.state, STATE_END);
}

void arith_test_2() {
    FILE* input1 = fopen("../tests/ast/test2.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    Token token = get_token(input1, STATE_INIT);
    assert_eq_int("token1", token.state, STATE_LEFT_PAR);
    token = get_token(input1, token.state);
    assert_eq_string("token1", token.value, "1");
    assert_eq_int("token1", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token2", token.state, STATE_PLUS);
    token = get_token(input1, token.state);
    assert_eq_string("token3", token.value, "2");
    assert_eq_int("token3", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_RIGHT_PAR);
    token = get_token(input1, token.state);
    assert_eq_int("token1", token.state, STATE_MULTIPLY);
    token = get_token(input1, token.state);
    assert_eq_string("token3", token.value, "3");
    assert_eq_int("token3", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token4", token.state, STATE_END);
}

void arith_test_3() {
    FILE* input1 = fopen("../tests/ast/test3.txt", "r");

    if (input1 == NULL) {
        test_err("test file does not exists");
        return;
    }

    Token token = get_token(input1, STATE_INIT);
    assert_eq_int("token1", token.state, STATE_CHAR);
    assert_eq_string("token1", token.value, "x");
    token = get_token(input1, token.state);
    assert_eq_int("token2", token.state, STATE_EQUAL);
    token = get_token(input1, token.state);
    assert_eq_string("token3", token.value, "y");
    assert_eq_int("token3", token.state, STATE_CHAR);
    token = get_token(input1, token.state);
    assert_eq_int("token4", token.state, STATE_PLUS);
    token = get_token(input1, token.state);
    assert_eq_string("token5", token.value, "1");
    assert_eq_int("token5", token.state, STATE_NUMBER);
    token = get_token(input1, token.state);
    assert_eq_int("token6", token.state, STATE_END);
}
