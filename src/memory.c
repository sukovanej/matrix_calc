//
// Created by Milan Suk on 15.03.18.
//

#include <stdlib.h>
#include <string.h>
#include "memory.h"

struct environment *env_create() {
    Environment* environment = malloc(sizeof(Environment));
    environment->node = NULL;
    environment->parent = NULL;

    return environment;
}

void memory_set(Environment *env, MemoryNode *value) {
    MemoryNode* m = memory_find(env, value->name);

    if (m == NULL) {
        value->next = env->node;
        env->node = value;
    } else {
        m->value = value->value;
        m->type = value->type;
    }
}

MemoryNode *memory_find(Environment *env, char *name) {
    MemoryNode* current = env->node;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void memory_set_value(Environment *env, char *name, void *value, MemoryNodeType type) {
    MemoryNode* node = malloc(sizeof(MemoryNode));
    node->type = type;
    node->value = value;
    node->name = name;

    memory_set(env, node);
}
