//
// Created by Milan Suk on 04.03.18.
//

#include <src/lexer.h>
#include "lexer_test.h"
#include "framework.h"

void all_lexer_test() {
    lexer_test();
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
