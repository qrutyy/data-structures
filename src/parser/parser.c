#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"


int8_t cl_args_check(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Too much command-line arguments.\n For available arguments please visit: https://github.com/qrutyy/data-structures. \n");
        exit(1);
    }
    else if (argc == 1){
        return 0;
    }
    else if (strcmp(argv[1], "--help")) {
        return -1;
    }
    else if (strcmp(argv[1], "-queue")) {
        // get queue request in main
    }
    else if (strcmp(argv[1], "-dll")) {

    }
    else if (strcmp(argv[1], "-sll")) {

    }
    else if (strcmp(argv[1], "-tree")) {

    }
    else if (strcmp(argv[1], "-stack")) {

    }
    return 10;
}


int8_t error_handling(int8_t ERROR_STATE) {
    
}