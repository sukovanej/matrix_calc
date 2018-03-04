//
// Created by Milan Suk on 23.02.18.
//

#include "message.cpp"
#include <stdio.h>
#include <stdlib.h>

/**
 * Print error message
 * @param input
 */
void err(char input[]) {
    printf("\x1B[31merror:\x1B[0m %s", input);
    exit(1);
}

/**
 * Print success message
 * @param input
 */
void success(char input[]) {
    printf("\x1B[32msuccess:\x1B[0m %s", input);
}
