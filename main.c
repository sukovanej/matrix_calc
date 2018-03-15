#include <stdio.h>
#include <string.h>
#include <src/eval.h>

void help();

int main(int argc, char *argv[]) {
    if (argc == 0) {
        help();
    }

    FILE* input_file = NULL;
    FILE* output_file = NULL;

    for (unsigned i = 1; i < argc; i++) {
        char* val = argv[i];

        if (strcmp(val, "-h") == 0 || strcmp(val, "--help") == 0) {
            help();
        } else if (strcmp(val, "-e") == 0 || strcmp(val, "--eval") == 0) {
            val = argv[i + 1];
            input_file = fmemopen(val, strlen(val), "r");
            i++;
        } else if (strcmp(val, "-o") == 0 || strcmp(val, "--output") == 0) {
            val = argv[i + 1];
            output_file = fopen(val, "w");
            i++;
        } else {
            input_file = fopen(val, "w");
        }
    }

    if (input_file == NULL) {
        printf("Input file does not exist.");
        exit(1);
    }

    char* result = eval(input_file, env_create_top());

    if (output_file == NULL) {
        puts(result);
    } else {
        fputs(result, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void help() {
    printf("matrix_calc, 2018 (c) Milan Suk | github.com/sukovanej \n\n");
    printf("Usage: matrix_calc [input_filename| -e, --eval expr] [-o, --output output_file] \n\n");
    printf(" -h, --help    -- Show help\n");
    printf(" -o, --output  -- Output file\n");
    printf(" -e, --eval    -- Evaluate string input");
}