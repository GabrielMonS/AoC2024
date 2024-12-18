#include "functions.h"
#include <iostream>
#include <thread>

using namespace Day7;

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    char *text = loadTextFromFile(argv[1]);
    std::vector<std::vector<long unsigned int>> equations = loadEquationsFromText(text);
    std::vector<std::vector<unsigned int>> shortEquations;
    for(int i = 0; i < equations.size(); i++){
        std::vector<unsigned int> equation;
        for(int j = 0; j < equations[i].size(); j++){
            equation.push_back(equations[i][j]);
        }
        shortEquations.push_back(equation);
    }

    int validEquations = 0;
    long unsigned int validSum = 0;
    for(int i = 0; i < equations.size(); i++){
        // sleep for 1 second
        //std::this_thread::sleep_for(std::chrono::seconds(20));
        printf("Checking equation %d\n", i);
        int validSolutions = checkEquation(shortEquations[i]);
        if( validSolutions > 0){
            validEquations++;
            validSum += equations[i][0];
            printf("Equation %d has %d possible solutions\n", i+1, validSolutions);
        }else{
            validSolutions = checkEquationWithConcat(equations[i]);
            if(validSolutions > 0){
                printf("At least a solution was found using concatenation. Adding to final result\n");
                validEquations++;
                validSum += equations[i][0];
            }
        }
    }
    printf("Valid equations: %d\n", validEquations);
    printf("Sum of valid equations' results: %lu\n", validSum);

    printf("Press any key to close the program\n");
    getchar();
    return 0;
}