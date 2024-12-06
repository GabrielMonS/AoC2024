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

    int checkMul(char *text){
        //Find position of the words "mul" in the text
        char *ptr = text;
        int ptrCtr = 4;
        int totalMul = 0;
        int firstnumber = -1;
        int secondnumber = -1;
        //sleep for 1 second
        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
        ptrCtr = 4;
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
                        ptrCtr++;
                        ptr = ptr + ptrCtr;
                    }else{
                        std::cout << "Mul failed since closing parenthesis is missing: " << *(ptr + ptrCtr) << std::endl;
                        ptrCtr++;
                        ptr = ptr + ptrCtr;
                        return 0;
                    }
                }else{
                    ptrCtr++;
                    ptr = ptr + ptrCtr;
                    return 0;
                }
            }else{
                ptrCtr++;
                return 0;
            }
        }else{
            std::cout << "Mul failed since first digit is actually a char: " << *(ptr + ptrCtr) << std::endl;
            ptrCtr++;
            ptr = ptr + ptrCtr;
            return 0;
        }
        return totalMul;
    }

    long unsigned int findTotalMul(char *text){
        //Find position of the words "mul" in the text
        char *ptr = text;
        char *ptrmul = text;
        char *ptrcontrol = text;
        char *ptrDo = text;
        char *ptrDont = text;
        bool controlEnabled = true;
        int ptrCtr = 4;
        long unsigned int totalMul = 0;
        int firstnumber = -1;
        int secondnumber = -1;
        std::cout << "Finding mul() instances in the text" << std::endl;
        while((ptrmul = strstr(ptr, "mul(")) != NULL){
            while(ptrcontrol < ptrmul){
                ptrDo = strstr(ptrcontrol, "do()");
                ptrDont = strstr(ptrcontrol, "don't()");
                if(ptrDo > ptrmul){
                    ptrDo = NULL;
                }
                if(ptrDont > ptrmul){
                    ptrDont = NULL;
                }
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
                    ptrcontrol = ptrmul;
                    break;
                }
            }
            std::cout << "Found mul() at position " << ptr - text << std::endl;
            //sleep for 1 second
            //std::this_thread::sleep_for(std::chrono::milliseconds(10));
            ptrCtr = 4;
            //Check if the next three characters are digits  one by one
            if(isdigit(*(ptrmul + ptrCtr))){
                std::cout << "First digit is a number: " << *(ptrmul + ptrCtr) << std::endl;
                ptrCtr++;
               // If it is, check if the next one is a number as well
                if(isdigit(*(ptrmul + ptrCtr))){
                    std::cout << "Second digit is a number: " << *(ptrmul + ptrCtr) << std::endl;
                    ptrCtr++;
                    //If it is, check if the next one is a number as well
                    if(isdigit(*(ptrmul + ptrCtr))){
                        std::cout << "Third digit is a number: " << *(ptrmul + ptrCtr) << std::endl;
                        ptrCtr++;
                        // If it is, compose the number
                        firstnumber = (*(ptrmul + ptrCtr - 3) - '0') * 100 + (*(ptrmul + ptrCtr - 2) - '0') * 10 + (*(ptrmul + ptrCtr - 1) - '0');
                    }else{
                        //If it is not, compose the number
                        firstnumber = (*(ptrmul + ptrCtr - 2) - '0') * 10 + (*(ptrmul + ptrCtr - 1) - '0');
                    }
                }else{
                    //If it is not, compose the number
                    firstnumber = *(ptrmul + ptrCtr - 1) - '0';
                }
                //Check if the next character is a comma
                if(*(ptrmul + ptrCtr) == ','){
                    std::cout << "Comma found!" << std::endl;
                    ptrCtr++;
                    //Check if the next character is a digit
                    if(isdigit(*(ptrmul + ptrCtr))){
                        std::cout << "First digit is a number(2): " << *(ptrmul + ptrCtr) << std::endl;
                        ptrCtr++;
                        //Check if the next character is a digit
                        if(isdigit(*(ptrmul + ptrCtr))){
                            std::cout << "Second digit is a number(2): " << *(ptrmul + ptrCtr) << std::endl;
                            ptrCtr++;
                            //Check if the next character is a digit
                            if(isdigit(*(ptrmul + ptrCtr))){
                                std::cout << "Third digit is a number(2): " << *(ptrmul + ptrCtr) << std::endl;
                                ptrCtr++;
                                //If it is, compose the number
                                secondnumber = (*(ptrmul + ptrCtr - 3) - '0') * 100 + (*(ptrmul + ptrCtr - 2) - '0') * 10 + (*(ptrmul + ptrCtr - 1) - '0');
                            }else{
                                //If it is not, compose the number
                                secondnumber = (*(ptrmul + ptrCtr - 2) - '0') * 10 + (*(ptrmul + ptrCtr - 1) - '0');
                            }
                        }else{
                            //If it is not, compose the number
                            secondnumber = (*(ptrmul + ptrCtr - 1) - '0');
                        }
                        // Check if the next character is a closing parenthesis
                        if(*(ptrmul + ptrCtr) == ')'){
                            //If it is, multiply the numbers
                            if(controlEnabled){
                                totalMul += firstnumber * secondnumber;
                                //Remove all text before the closing parenthesis
                                std::cout << "Mul successful! Total mul: " << totalMul << std::endl;
                                ptrCtr++;
                                ptr = ptrmul + ptrCtr;
                            }else{
                                std::cout << "Control is disabled, skipping mul()" << std::endl;
                                ptrCtr++;
                                ptr = ptrmul + ptrCtr;
                                continue;
                            }
                        }else{
                            std::cout << "Mul failed since closing parenthesis is missing: " << *(ptrmul + ptrCtr) << std::endl;
                            ptrCtr++;
                            ptr = ptrmul + ptrCtr;
                            continue;
                        }
                    }else{
                        ptrCtr++;
                        ptr = ptrmul + ptrCtr;
                        continue;
                    }
                }else{
                    ptrCtr++;
                    ptr = ptrmul + ptrCtr;
                    continue;
                }
            }else{
                std::cout << "Mul failed since first digit is actually a char: " << *(ptr + ptrCtr) << std::endl;
                ptrCtr++;
                ptr = ptrmul + ptrCtr;
                continue;
            }
        }
        return totalMul;
    }
}