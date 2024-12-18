#include "functions.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <thread>

namespace Day7{
    char* loadTextFromFile(const char* fileName){
        FILE* file = fopen(fileName, "r");
        if(file == NULL){
            printf("Error: File not found\n");
            exit(1);
        }
        char* text = (char*)malloc(1000000);
        char line[1000000];
        while (fgets(line, sizeof(line), file)) {
            strcat(text, line);
        }
        fclose(file);
        return text;
    }

    std::vector<std::vector<long unsigned int>> loadEquationsFromText(char* text){
        std::vector<std::vector<long unsigned int>> equations;
        char* ptr = text;
        char* line = text;
        while(*ptr != '\0'){
            // Parse the equation; first number is separated by : and the rest by spaces
            std::vector<long unsigned int> equation;
            long unsigned int number;
            while(*ptr != '\n'){
                if(*ptr == ':'){
                    //WE parse a number from the start of the line to the :
                    number = strtol(line, &ptr, 10);
                    if(number == 0){
                        break;
                    }
                    equation.push_back(number);
                    printf("Found result. Result: %lu\n", number);
                }
                if(*ptr == ' '){
                    //We parse a number from the space to the next space
                    number = strtol(ptr, &ptr, 10);
                    if(number == 0){
                        break;
                    }
                    equation.push_back(number);
                    printf("Found number. Number: %lu\n", number);
                }else{
                    ptr++;
                }
            }
            if(equation.size() == 0){
                break;
            }
            equations.push_back(equation);
            ptr++;
            line = ptr;
        }
        printf("Equations size: %d\n", equations.size());
        return equations;
    }

    int checkEquation(const std::vector<unsigned int> &equation){
        printf("Result: %lu , Number of factors: %d\n", equation[0], equation.size()-1);
        unsigned int result = equation[0];
        int validCombinations = 0;
        std::vector<unsigned int> currentResults;
        bool impossible = false;
        bool mulExceeds = false;
        bool sumExceeds = false;
        currentResults.push_back(equation[1]);
        for(int i = 2; i < equation.size(); i++){
            unsigned int number = equation[i];
            int currentResultsSize = currentResults.size();
            for(int j = 0; j < currentResultsSize; j++){
                unsigned int currentResult = currentResults[j];
                unsigned int mulNewResult = 0;
                if(!mulExceeds) mulNewResult = currentResult * number;
                if(mulNewResult > result){
                    // printf("Multiplication already exceeds since it is %lu, no more multiplications for you sir.\n", mulNewResult);
                    // printf("We are in factor %d by the way\n", i);
                    // mulExceeds = true;
                }
                unsigned int addNewResult = 0;
                if(!sumExceeds) addNewResult = currentResult + number;
                if(addNewResult > result){
                    // printf("Addition already exceeds, no more additions for you sir.\n");
                    // printf("We are in factor %d by the way\n", i);
                    // sumExceeds = true;
                }
                if(mulExceeds && sumExceeds){
                    impossible = true;
                    return 0;
                }
                if(!mulExceeds){
                    currentResults.push_back(mulNewResult);
                }
                if(!sumExceeds){
                    currentResults.push_back(addNewResult);
                }
            }
            // Remove the first currentResultSize elements from the vector.
            currentResults.erase(currentResults.begin(), currentResults.begin() + currentResultsSize);
        }
        printf("Total number of combinations: %d\n", currentResults.size());
        for(int i = 0; i < currentResults.size(); i++){
            if(currentResults[i] == result){
                validCombinations++;
            }
        }
        return validCombinations;
    }

    int checkEquationWithConcat(const std::vector<unsigned long int> &equation){
        printf("Result: %lu , Number of factors: %d\n", equation[0], equation.size()-1);
        long unsigned int result = equation[0];
        int validCombinations = 0;
        std::vector<unsigned long int> currentResults;
        currentResults.push_back(equation[1]);
        for(int i = 2; i < equation.size(); i++){
            unsigned int number = equation[i];
            int currentResultsSize = currentResults.size();
            for(int j = 0; j < currentResultsSize; j++){
                unsigned long int currentResult = currentResults[j];
                unsigned long int mulNewResult = currentResult * number;
                unsigned long int addNewResult = currentResult + number;
                std::string concatResultStr = std::to_string(currentResult) + std::to_string(number);
                unsigned long int concatResult = std::atol(concatResultStr.c_str());
                //printf("Concatenation result: %lu\n", concatResult);
                if(mulNewResult <= result){
                    currentResults.push_back(mulNewResult);
                }
                if(addNewResult <= result){
                    currentResults.push_back(addNewResult);
                }
                if(concatResult <= result){
                    currentResults.push_back(concatResult);
                }
            }
            // Remove the first currentResultSize elements from the vector.
            currentResults.erase(currentResults.begin(), currentResults.begin() + currentResultsSize);
        }
        printf("Total number of combinations: %d\n", currentResults.size());
        //Print the results
        for(int i = 0; i < currentResults.size(); i++){
            if(currentResults[i] == result){
                validCombinations++;
            }
        }
        return validCombinations;
    }
}