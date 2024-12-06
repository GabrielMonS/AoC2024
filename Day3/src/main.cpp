#include "functions.h"
#include <iostream>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    char *text = Day3::loadTextFromFile(argv[1]);
    long unsigned int totalMul = Day3::findTotalMul(text);
    printf("Total mul: %lu\n", totalMul);
    free(text);
    printf("Press any key to close the program\n");
    getchar();
    return 0;
}