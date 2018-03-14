#include <stdlib.h>
#include "syntax.h"

//
// Created by Milan Suk on 14.03.18.
//

/**
 * Create AST with all values
 * @param token
 * @param left
 * @param right
 * @return
 */
AbstractSyntaxTreeNode *ast(Token token, AbstractSyntaxTreeNode *left, AbstractSyntaxTreeNode *right) {
    AbstractSyntaxTreeNode* node = ast_create();
    node->token = token;
    node->left = left;
    node->right = right;

    return node;
}

/**
 * Creates new empty AST
 * @return
 */
AbstractSyntaxTreeNode *ast_create() {
    AbstractSyntaxTreeNode* ast = (AbstractSyntaxTreeNode*) malloc(sizeof(AbstractSyntaxTreeNode));
    ast->left = NULL;
    ast->right = NULL;
    ast->token = token_create();

    return ast;
}

/**
 * Creates new AST with defined token value
 * @param token
 * @return
 */
AbstractSyntaxTreeNode *ast_create_valued(Token token) {
    AbstractSyntaxTreeNode* ast = ast_create();
    ast->token = token;

    return ast;
}

/**
 * Parse input and produces an AST
 * @param file
 * @return
 */
AbstractSyntaxTreeNode *ast_parse(FILE *file) {
    ParserState* parser_state = (ParserState*) malloc(sizeof(ParserState));
    parser_state->file = file;
    parser_state->token = get_token(file, STATE_INIT);

    return expr(parser_state);
}

/**
 * Evaluate R + R -> R | R - R -> R
 * @param parser_state
 * @return
 */
AbstractSyntaxTreeNode *expr(ParserState *parser_state) {
    AbstractSyntaxTreeNode* node = term(parser_state);

    while (parser_state->token.state == STATE_PLUS ||
           parser_state->token.state == STATE_MINUS) {
        Token token = parser_state->token;

        switch (token.state) {
            case STATE_PLUS:
                get_next_token(parser_state, STATE_PLUS);
                break;
            case STATE_MINUS:
                get_next_token(parser_state, STATE_MINUS);
                break;
            default:
                printf("expr error");
                exit(1);
        }

        node = ast(token, node, term(parser_state));
    }

    return node;
}

/**
 * Evaluate (R) -> R, or R -> R
 * @param parser_state
 * @return
 */
AbstractSyntaxTreeNode *factor(ParserState *parser_state) {
    Token token = parser_state->token;
    switch (token.state) {
        case STATE_NUMBER:
            get_next_token(parser_state, STATE_NUMBER);
            return ast_create_valued(token);
        case STATE_CHAR:
            get_next_token(parser_state, STATE_CHAR);
            return ast_create_valued(token);
        case STATE_LEFT_PAR:
            get_next_token(parser_state, STATE_LEFT_PAR);
            AbstractSyntaxTreeNode* node = expr(parser_state);
            get_next_token(parser_state, STATE_RIGHT_PAR);
            return node;
        default:
            printf("factor error");
            exit(1);
    }
}

/**
 * Evaluate R * R -> R | R / R -> R
 * @param parser_state
 * @return
 */
AbstractSyntaxTreeNode *term(ParserState *parser_state) {
    AbstractSyntaxTreeNode* node = factor(parser_state);

    // Setting a new variable
    if (node->token.state == STATE_CHAR && parser_state->token.state == STATE_EQUAL) {
        Token token = parser_state->token;

        get_next_token(parser_state, STATE_EQUAL);
        node = ast(token, node, expr(parser_state));
        return node;
    }

    while (parser_state->token.state == STATE_MULTIPLY ||
            parser_state->token.state == STATE_DIVIDE) {
        Token token = parser_state->token;

        switch (token.state) {
            case STATE_MULTIPLY:
                get_next_token(parser_state, STATE_MULTIPLY);
                break;
            case STATE_DIVIDE:
                get_next_token(parser_state, STATE_DIVIDE);
                break;
            default:
                printf("term error");
                exit(1);
        }

        node = ast(token, node, factor(parser_state));
    }

    return node;
}

/**
 * Get new token and check token type
 * @param parser_state
 * @param token_state
 */
void get_next_token(ParserState *parser_state, State token_state) {
    if (parser_state->token.state == token_state) {
        parser_state->token = get_token(parser_state->file, parser_state->token.state);
    } else {
        printf("get_next_token error");
        exit(1);
    }
}

