//
// Created by Milan Suk on 15.03.18.
//

#ifndef MATRIXCALC_MEMORY_H
#define MATRIXCALC_MEMORY_H

typedef enum memory_node_type {
    MEM_TYPE_MATRIX
} MemoryNodeType;

typedef struct memory_node {
    char* name;
    struct memory_node* next;
    void* value;
    MemoryNodeType type;
} MemoryNode;

typedef struct environment {
    struct environment* parent;
    MemoryNode* node;
} Environment;

Environment* env_create();

void memory_set(Environment* env, MemoryNode* value);
void memory_set_value(Environment* env, char* name, void* value, MemoryNodeType type);
MemoryNode* memory_find(Environment* env, char* name);

#endif //MATRIXCALC_MEMORY_H
