#include <stdio.h>
#include <string.h>
#include <src/eval.h>

void help();

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            help();
        } else {
            char* input_file = argv[1];
            FILE* file = fopen(input_file, "r");

            if (file == NULL) {
                printf("File %s does not exist.", input_file);
                exit(1);
            }

            char* result = eval(file, env_create_top());
            puts(result);
        }
    } else if (argc == 4) {
        if (strcmp(argv[2], "-o") == 0 || strcmp(argv[2], "--output") == 0) {

        } else {
            char* input_file = argv[1];
            FILE* file = fopen(input_file, "r");

            char* result = eval(file, env_create_top());
            printf("%s", result);
        }
    } else {
        help();
    }
}

void help() {
    printf("matrix_calc, 2018 (c) Milan Suk | github.com/sukovanej \n\n");
    printf("Usage: matrix_calc input_filename [-o|--output output_file] \n\n");
    printf(" -h, --help    -- Show help\n");
    printf(" -o, --output  -- Output file");
}