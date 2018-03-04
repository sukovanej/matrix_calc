//
// Created by Milan Suk on 04.03.18.
//

#include <string.h>
#include <stdlib.h>
#include "lexer.h"

Token get_token(FILE *file, State state) {
    Token old_token;
    old_token.state = state;

    Token new_token = old_token;
    unsigned counter = 0;

    while (1) {
        char new_val = (char) getc(file);

        if (new_val == EOF) {
            new_token.state = STATE_END;
            return new_token;
        }

        switch (old_token.state) {
            case STATE_INIT:
                if (is_gap(new_val)) {
                    new_token.state = STATE_GAP;
                } else if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (new_val == '(') {
                    new_token.state = STATE_LEFT_PAR;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_CHAR:
                if (is_gap(new_val)) {
                    new_token.state = STATE_GAP;
                } else if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (new_val == ')') {
                    new_token.state = STATE_RIGHT_PAR;
                } else if (new_val == '*') {
                    new_token.state = STATE_MULTIPLY;
                } else if (new_val == '+') {
                    new_token.state = STATE_PLUS;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_GAP:
                if (is_gap(new_val)) {
                    new_token.state = STATE_GAP;
                } else if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (new_val == '(') {
                    new_token.state = STATE_LEFT_PAR;
                } else if (new_val == ')') {
                    new_token.state = STATE_RIGHT_PAR;
                } else if (new_val == '*') {
                    new_token.state = STATE_MULTIPLY;
                } else if (new_val == '+') {
                    new_token.state = STATE_PLUS;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_LEFT_PAR:
                if (is_gap(new_val)) {
                    new_token.state = STATE_GAP;
                } else if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (new_val == '(') {
                    new_token.state = STATE_LEFT_PAR;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_RIGHT_PAR:
                if (is_gap(new_val)) {
                    new_token.state = STATE_GAP;
                } else if (new_val == '*') {
                    new_token.state = STATE_MULTIPLY;
                } else if (new_val == '+') {
                    new_token.state = STATE_PLUS;
                } else if (new_val == ')') {
                    new_token.state = STATE_RIGHT_PAR;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_PLUS:
                if (is_gap(new_val)) {
                    new_token.state = STATE_GAP;
                } else if (is_char(new_val)) {
                    new_token.state = STATE_CHAR;
                } else if (new_val == '(') {
                    new_token.state = STATE_LEFT_PAR;
                } else {
                    new_token.state = STATE_ERROR;
                }
                break;
            case STATE_MULTIPLY:
                if (is_gap(new_val)) {
                    new_token.state = STATE_GAP;
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

        if (old_token.state == STATE_CHAR && new_token.state == STATE_CHAR) {
            if (!old_token.value) {
                old_token.value = malloc(sizeof(char) * 2);
                *old_token.value = strcat(new_val, "\0");
            } else {
                realloc(old_token.value, strlen(old_token.value) + 1);
                old_token.value[strlen(old_token.value) - 1] = new_val;
            }

            new_token.value = old_token.value;
        } else if (old_token.state == STATE_CHAR && new_token.state != STATE_CHAR && counter > 0) {
            fseek(file, ftell(file) - 1, SEEK_SET);
            return old_token;
        } else if (new_token.state == STATE_GAP) {
            continue;
        } else {
            return new_token;
        }

        counter++;
    }
}

int is_gap(char val) {
    return (val == ' ' || val == '\t' || val == '\n');
}

int is_char(char val) {
    return (val >= 65 && val <= 90);
}
