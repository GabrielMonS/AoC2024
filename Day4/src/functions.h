#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace Day4{
    char* loadTextFromFile(const char* fileName);
    std::vector<std::vector<char>> arrayFromText(char* text);
    int countXMASinArray(std::vector<std::vector<char>> xmasarray);
    int countCrossedMASinArray(std::vector<std::vector<char>> xmasarray);
}