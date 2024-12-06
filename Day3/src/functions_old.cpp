#include "functions.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <thread>

namespace Day3{
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

    int checkMul(char *text, int &ptrCtrOut){
        //Find position of the words "mul" in the text
        char *ptr = text;
        int ptrCtr = 4;
        int totalMul = -1;
        int firstnumber = -1;
        int secondnumber = -1;
        //sleep for 1 second
        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
        //Check if the next three characters are digits  one by one
        if(isdigit(*(ptr + ptrCtr))){
            std::cout << "First digit is a number: " << *(ptr + ptrCtr) << std::endl;
            ptrCtr++;
            // If it is, check if the next one is a number as well
            if(isdigit(*(ptr + ptrCtr))){
                std::cout << "Second digit is a number: " << *(ptr + ptrCtr) << std::endl;
                ptrCtr++;
                //If it is, check if the next one is a number as well
                if(isdigit(*(ptr + ptrCtr))){
                    std::cout << "Third digit is a number: " << *(ptr + ptrCtr) << std::endl;
                    ptrCtr++;
                    // If it is, compose the number
                    firstnumber = (*(ptr + ptrCtr - 3) - '0') * 100 + (*(ptr + ptrCtr - 2) - '0') * 10 + (*(ptr + ptrCtr - 1) - '0');
                }else{
                    //If it is not, compose the number
                    firstnumber = (*(ptr + ptrCtr - 2) - '0') * 10 + (*(ptr + ptrCtr - 1) - '0');
                }
            }else{
                //If it is not, compose the number
                firstnumber = *(ptr + ptrCtr - 1) - '0';
            }
            //Check if the next character is a comma
            if(*(ptr + ptrCtr) == ','){
                std::cout << "Comma found!" << std::endl;
                ptrCtr++;
                //Check if the next character is a digit
                if(isdigit(*(ptr + ptrCtr))){
                    std::cout << "First digit is a number(2): " << *(ptr + ptrCtr) << std::endl;
                    ptrCtr++;
                    //Check if the next character is a digit
                    if(isdigit(*(ptr + ptrCtr))){
                        std::cout << "Second digit is a number(2): " << *(ptr + ptrCtr) << std::endl;
                        ptrCtr++;
                        //Check if the next character is a digit
                        if(isdigit(*(ptr + ptrCtr))){
                            std::cout << "Third digit is a number(2): " << *(ptr + ptrCtr) << std::endl;
                            ptrCtr++;
                            //If it is, compose the number
                            secondnumber = (*(ptr + ptrCtr - 3) - '0') * 100 + (*(ptr + ptrCtr - 2) - '0') * 10 + (*(ptr + ptrCtr - 1) - '0');
                        }else{
                            //If it is not, compose the number
                            secondnumber = (*(ptr + ptrCtr - 2) - '0') * 10 + (*(ptr + ptrCtr - 1) - '0');
                        }
                    }else{
                        //If it is not, compose the number
                        secondnumber = (*(ptr + ptrCtr - 1) - '0');
                    }
                    // Check if the next character is a closing parenthesis
                    if(*(ptr + ptrCtr) == ')'){
                        //If it is, multiply the numbers
                        totalMul += firstnumber * secondnumber;
                        //Remove all text before the closing parenthesis
                        std::cout << "Mul successful! Result: " << totalMul << std::endl;
                        //ptrCtr++;
                        //ptr = ptr + ptrCtr;
                        ptrCtrOut = ptrCtr;
                        return totalMul;
                    }else{
                        std::cout << "Mul failed since closing parenthesis is missing: " << *(ptr + ptrCtr) << std::endl;
                        //ptrCtr++;
                        //ptr = ptr + ptrCtr;
                        ptrCtrOut = ptrCtr;
                        return -1;
                    }
                }else{
                    std::cout << "Mul failed since second digit is actually a char: " << *(ptr + ptrCtr) << std::endl;
                    //ptrCtr++;
                    //ptr = ptr + ptrCtr;
                    ptrCtrOut = ptrCtr;
                    return -1;
                }
            }else{
                std::cout << "Mul failed since comma is missing: " << *(ptr + ptrCtr) << std::endl;
                //ptrCtr++;
                //ptr = ptr + ptrCtr;
                ptrCtrOut = ptrCtr;
                return -1;
            }
        }else{
            std::cout << "Mul failed since first digit is actually a char: " << *(ptr + ptrCtr) << std::endl;
            //ptrCtr++;
            //ptr = ptr + ptrCtr;
            ptrCtrOut = ptrCtr;
            return -1;
        }
    }

    long unsigned int findTotalMul(char *text){
        //Find position of the words "mul" in the text
        char *ptr = text;
        int ptrCtr = 0;
        long unsigned int totalMul = 0;
        while((ptr = strstr(ptr, "mul(")) != NULL){
            //std::this_thread::sleep_for(std::chrono::milliseconds(100));
            int mul = checkMul(ptr, ptrCtr);
            if(mul != -1){
                totalMul += mul;
                std::cout << "Current total mul: " << totalMul << std::endl;
            }
            ptr = ptr + 1;
        }
        return totalMul;
    }

    bool checkControl(char *textControl, char* limit){
        // Find "do()" and "don't()" in the text until we reach the limit indicated in the limit parameter
        char *ptrcontrol = textControl;
        char* ptrDo;
        char* ptrDont;
        bool controlEnabled = true;
        while(ptrcontrol < limit){
            ptrDo = strstr(ptrcontrol, "do()");
            ptrDont = strstr(ptrcontrol, "don't()");
            if(ptrDo != NULL && ptrDont != NULL){
                if(ptrDo < ptrDont){
                    ptrcontrol = ptrDo + 4;
                }else{
                    ptrcontrol = ptrDont + 7;
                }
            }else if(ptrDo != NULL){
                ptrcontrol = ptrDo + 4;
                controlEnabled = true;
                break;
            }else if(ptrDont != NULL){
                ptrcontrol = ptrDont + 7;
                controlEnabled = false;
                break;
            }else{
                std::cout << "Control not found!" << std::endl;
                ptrcontrol = limit;
                break;
            }
        }
        return controlEnabled;
    }

    long unsigned int findTotalMulWithControl(char *text){
        //Find position of the words "mul" in the text
        char *ptr = text;
        int ptrCtr = 0;
        char *ptrcontrol = text;
        long unsigned int totalMul = 0;
        bool mulEnabled = true;
        while((ptr = strstr(ptr, "mul(")) != NULL){
            if(checkControl(ptrcontrol, ptr)){
                std::cout << "Control enabled!" << std::endl;
                int mul = checkMul(ptr, ptrCtr);
                if(mul != -1){
                    totalMul += mul;
                }
                ptr = ptr + ptrCtr;
            }else{
                std::cout << "Control disabled!" << std::endl;
            }
        }
        return totalMul;
    }
}