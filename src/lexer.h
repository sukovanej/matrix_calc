//
// Created by Milan Suk on 04.03.18.
//

#ifndef MATRIXCALC_LEXER_H
#define MATRIXCALC_LEXER_H

#include <stdio.h>

typedef enum state {
    STATE_INIT = 1,
    STATE_CHAR = 2,
    STATE_GAP = 3,
    STATE_LEFT_PAR = 4,
    STATE_RIGHT_PAR = 5,
    STATE_PLUS = 6,
    STATE_MULTIPLY = 7,
    STATE_ERROR = 8,
    STATE_END = 9
} State;

typedef struct token {
    State state;
    char* value;
} Token;

Token get_token(FILE*, State);
int is_gap(char);
int is_char(char);

#endif //MATRIXCALC_LEXER_H
