//
// Created by Milan Suk on 04.03.18.
//

#ifndef MATRIXCALC_LEXER_H
#define MATRIXCALC_LEXER_H

#include <stdio.h>

typedef enum state {
    STATE_INIT = 1,     // 1
    STATE_CHAR,         // 2
    STATE_LEFT_PAR,     // 3
    STATE_RIGHT_PAR,    // 4
    STATE_PLUS,         // 5
    STATE_MINUS,        // 6
    STATE_MULTIPLY,     // 7
    STATE_DIVIDE,       // 8
    STATE_EQUAL,        // 9
    STATE_NUMBER,       // 10
    STATE_NUMBER_POINT, // 11
    STATE_DELIMITER,    // 12
    STATE_NEWLINE,      // 13
    STATE_ERROR,        // 14
    STATE_END           // 15
} State;

typedef struct token {
    State state;
    char* value;
} Token;

Token token_create();
Token get_token(FILE*, State);
int is_gap(char);
int is_char(char);
int is_num(char);

#endif //MATRIXCALC_LEXER_H
