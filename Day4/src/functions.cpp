#include "functions.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <thread>

namespace Day4{
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

    std::vector<std::vector<char>> arrayFromText(char* text){
        std::vector<std::vector<char>> array;
        while(*text != '\0'){
            std::vector<char> row;
            while(*text != '\n'){
                row.push_back(*text);
                text++;
            }
            array.push_back(row);
            text++;
        }
        //delete last row
        array.pop_back();
        return array;
    }

    int countXMASinArray(std::vector<std::vector<char>> xmasarray){
        int count = 0;
        std::cout << "Checking array for XMAS" << std::endl;
        for(int i = 0; i < xmasarray.size(); i++){
            for(int j = 0; j < xmasarray[i].size(); j++){
                std::cout << "Checking vertical(positive)" << std::endl;
                if(xmasarray[i][j] == 'X'){
                    if(i+1 < xmasarray.size()){
                        if(xmasarray[i+1][j] == 'M'){
                            if(i+2 < xmasarray.size()){
                                if(xmasarray[i+2][j] == 'A'){
                                    if(i+3 < xmasarray.size()){
                                        if(xmasarray[i+3][j] == 'S'){
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    std::cout << "Checking horizontal(positive)" << std::endl;
                    if(j+1 < xmasarray[i].size()){
                        if(xmasarray[i][j+1] == 'M'){
                            if(j+2 < xmasarray[i].size()){
                                if(xmasarray[i][j+2] == 'A'){
                                    if(j+3 < xmasarray[i].size()){
                                        if(xmasarray[i][j+3] == 'S'){
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    std::cout << "Checking vertical(negative)" << std::endl;
                    if(i-1 >= 0){
                        if(xmasarray[i-1][j] == 'M'){
                            if(i-2 >= 0){
                                if(xmasarray[i-2][j] == 'A'){
                                    if(i-3 >= 0){
                                        if(xmasarray[i-3][j] == 'S'){
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    std::cout << "Checking horizontal(negative)" << std::endl;
                    if(j-1 >= 0){
                        if(xmasarray[i][j-1] == 'M'){
                            if(j-2 >= 0){
                                if(xmasarray[i][j-2] == 'A'){
                                    if(j-3 >= 0){
                                        if(xmasarray[i][j-3] == 'S'){
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    // Now check the diagonals
                    std::cout << "Checking diagonals" << std::endl;
                    std::cout << "Checking diagonal 1" << std::endl;
                    if(i+1 < xmasarray.size() && j+1 < xmasarray[i].size()){
                        if(xmasarray[i+1][j+1] == 'M'){
                            if(i+2 < xmasarray.size() && j+2 < xmasarray[i].size()){
                                if(xmasarray[i+2][j+2] == 'A'){
                                    if(i+3 < xmasarray.size() && j+3 < xmasarray[i].size()){
                                        std::cout << "i+3: " << i+3 << " j+3: " << j+3 << std::endl;
                                        if(xmasarray[i+3][j+3] == 'S'){
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    std::cout << "Checking diagonal 2" << std::endl;
                    if(i-1 >= 0 && j-1 >= 0){
                        if(xmasarray[i-1][j-1] == 'M'){
                            if(i-2 >= 0 && j-2 >= 0){
                                if(xmasarray[i-2][j-2] == 'A'){
                                    if(i-3 >= 0 && j-3 >= 0){
                                        if(xmasarray[i-3][j-3] == 'S'){
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    std::cout << "Checking diagonal 3" << std::endl;
                    if(i+1 < xmasarray.size() && j-1 >= 0){
                        if(xmasarray[i+1][j-1] == 'M'){
                            if(i+2 < xmasarray.size() && j-2 >= 0){
                                if(xmasarray[i+2][j-2] == 'A'){
                                    if(i+3 < xmasarray.size() && j-3 >= 0){
                                        if(xmasarray[i+3][j-3] == 'S'){
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    std::cout << "Checking diagonal 4" << std::endl;
                    if(i-1 >= 0 && j+1 < xmasarray[i].size()){
                        if(xmasarray[i-1][j+1] == 'M'){
                            if(i-2 >= 0 && j+2 < xmasarray[i].size()){
                                if(xmasarray[i-2][j+2] == 'A'){
                                    if(i-3 >= 0 && j+3 < xmasarray[i].size()){
                                        if(xmasarray[i-3][j+3] == 'S'){
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
            }
        }
        return count;
    }

    int countCrossedMASinArray(std::vector<std::vector<char>> xmasarray){
        int count = 0;
        std::cout << "Checking array for CrossedMAS" << std::endl;
        for(int i = 0; i < xmasarray.size(); i++){
            for(int j = 0; j < xmasarray[i].size(); j++){
                if(xmasarray[i][j] == 'A'){
                    //Check if the corners are M and S
                    if(i-1 >= 0 && j-1 >= 0 && i+1 < xmasarray.size() && j+1 < xmasarray[i].size()){
                        char corner1 = xmasarray[i-1][j-1];
                        char corner2 = xmasarray[i-1][j+1];
                        char corner3 = xmasarray[i+1][j-1];
                        char corner4 = xmasarray[i+1][j+1];
                        if((corner1 == 'M' && corner4 == 'S') || (corner1 == 'S' && corner4 == 'M')){
                            if((corner2 == 'M' && corner3 == 'S') || (corner2 == 'S' && corner3 == 'M')){
                                count++;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
}