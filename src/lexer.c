//
// Created by Milan Suk on 04.03.18.
//

#include <string.h>
#include <stdlib.h>
#include "lexer.h"

Token get_token(FILE *file, State state) {
    Token old_token = token_create();
    old_token.state = state;

    Token new_token = old_token;
    unsigned counter = 0;

    while (1) {
        char new_val = (char) getc(file);

        if (is_gap(new_val)) {
            continue;
        }

        switch (old_token.state) {
            case STATE_INIT:
                if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (is_num(new_val)) {
                    new_token.state = STATE_NUMBER;
                } else if (new_val == '\n') {
                    continue;
                } else if (new_val == EOF) {
                    new_token.state = STATE_END;
                } else if (new_val == '(') {
                    new_token.state = STATE_LEFT_PAR;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_CHAR:
                if (is_char(new_val) || is_num(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (new_val == ')') {
                    new_token.state = STATE_RIGHT_PAR;
                } else if (new_val == '*') {
                    new_token.state = STATE_MULTIPLY;
                } else if (new_val == '+') {
                    new_token.state = STATE_PLUS;
                } else if (new_val == '-') {
                    new_token.state = STATE_MINUS;
                } else if (new_val == '/') {
                    new_token.state = STATE_DIVIDE;
                } else if (new_val == '=') {
                    new_token.state = STATE_EQUAL;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_EQUAL:
                if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (new_val == '(') {
                    new_token.state = STATE_LEFT_PAR;
                } else if (is_num(new_val)) {
                    new_token.state = STATE_NUMBER;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_NUMBER:
                if (is_num(new_val)) {
                    new_token.state = STATE_NUMBER;
                } else if (new_val == ')') {
                    new_token.state = STATE_RIGHT_PAR;
                } else if (new_val == ',') {
                    new_token.state = STATE_DELIMITER;
                } else if (new_val == '.') {
                    new_token.state = STATE_NUMBER_POINT;
                } else if (new_val == '*') {
                    new_token.state = STATE_MULTIPLY;
                } else if (new_val == '+') {
                    new_token.state = STATE_PLUS;
                } else if (new_val == '-') {
                    new_token.state = STATE_MINUS;
                } else if (new_val == '/') {
                    new_token.state = STATE_DIVIDE;
                } else if (new_val == '\n') {
                    new_token.state = STATE_NEWLINE;
                } else if (new_val == EOF) {
                    new_token.state = STATE_END;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_NEWLINE_DELIMITER:
            case STATE_NEWLINE:
                if (is_num(new_val)) {
                    new_token.state = STATE_NUMBER;
                } else if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (new_val == '\n') {
                    new_token.state = STATE_NEWLINE;
                } else if (new_val == EOF) {
                    new_token.state = STATE_END;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_DELIMITER:
                if (is_num(new_val)) {
                    new_token.state = STATE_NUMBER;
                } else if (new_val == '\n') {
                    new_token.state = STATE_NEWLINE;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_NUMBER_POINT:
                if (is_num(new_val)) {
                    new_token.state = STATE_NUMBER;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_LEFT_PAR:
                if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (is_num(new_val)) {
                    new_token.state = STATE_NUMBER;
                } else if (new_val == '(') {
                    new_token.state = STATE_LEFT_PAR;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_RIGHT_PAR:
                if (new_val == '*') {
                    new_token.state = STATE_MULTIPLY;
                } else if (new_val == '+') {
                    new_token.state = STATE_PLUS;
                } else if (new_val == ')') {
                    new_token.state = STATE_RIGHT_PAR;
                } else if (new_val == EOF) {
                    new_token.state = STATE_END;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_PLUS:
            case STATE_MINUS:
                if (is_num(new_val)) {
                    new_token.state = STATE_NUMBER;
                } else if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (new_val == '(') {
                    new_token.state = STATE_LEFT_PAR;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_MULTIPLY:
            case STATE_DIVIDE:
                if (is_num(new_val)) {
                    new_token.state = STATE_NUMBER;
                } else if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (new_val == '(') {
                    new_token.state = STATE_LEFT_PAR;
                } else {
                    new_token.state = STATE_ERROR;
                }

                break;
            case STATE_ERROR:
                return old_token;
            case STATE_END:
                return old_token;
        }

        if (new_token.state == STATE_CHAR || new_token.state == STATE_NUMBER ||
                (new_token.state == STATE_NUMBER_POINT && old_token.state == STATE_NUMBER)) {
            if (!new_token.value) {
                new_token.value = malloc(sizeof(char));
            }

            strncat(new_token.value, &new_val, 1);
        } else if (((old_token.state == STATE_CHAR && new_token.state != STATE_CHAR) ||
                (old_token.state == STATE_NUMBER && new_token.state != STATE_NUMBER)) && counter > 0) {
            if (new_val != EOF) {
                fseek(file, ftell(file) - 1, SEEK_SET);
            }

            return old_token;
        } else {
            if (new_token.state == STATE_DELIMITER) {
                if (getc(file) == '\n') {
                    new_token.state = STATE_NEWLINE_DELIMITER;
                } else {
                    fseek(file, ftell(file) - 1, SEEK_SET);
                }
            }

            return new_token;
        }

        old_token.state = new_token.state;
        counter++;
    }
}

int is_gap(char val) {
    return (val == ' ' || val == '\t');
}

int is_char(char val) {
    return ((val >= 65 && val <= 90) || (val >= 97 && val <= 122));
}

Token token_create() {
    Token result;
    result.value = malloc(sizeof(char));

    return result;
}

int is_num(char val) {
    return (val >= 48 && val <= 57);
}
