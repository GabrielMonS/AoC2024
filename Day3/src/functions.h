#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace Day3{
    char* loadTextFromFile(const char* fileName);
    int checkMul(char *text, int &ptrCtrOut);
    bool checkControl(char *textControl, char* limit);
    long unsigned int findTotalMul(char* text);   
    long unsigned int findTotalMulWithControl(char* text);
}