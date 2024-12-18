#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace Day7{
    char* loadTextFromFile(const char* fileName);
    std::vector<std::vector<long unsigned int>> loadEquationsFromText(char* text);
    int checkEquation(const std::vector<unsigned int> &equation);
    int checkEquationWithConcat(const std::vector<long unsigned int> &equation);
}