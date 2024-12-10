#include "functions.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <thread>

namespace Day5{
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

    std::vector<std::vector<int>> loadRulesFromText(char* text){
        std::vector<std::vector<int>> rulesPairs;
        char* ptr = text;
        char* line = text;
        int firstNumber = 0;
        int secondNumber = 0;
        while(!((*(ptr+1) == '\n') && (*ptr == '\n'))){
            // Get the next line
            line = strtok(line, "\n");
            //Separate the line into two numbers separated by a single '|' between them
            char* rule = strtok(line, "|");
            firstNumber = atoi(rule);
            //Move the pointer to the next number
            rule = strtok(NULL, "\n");
            secondNumber = atoi(rule);
            //Add the pair to the rules
            rulesPairs.push_back({firstNumber, secondNumber});
            ptr = rule + strlen(rule);
            line = ptr + 1;
            if(*ptr == NULL && *(ptr+1) == '\n'){
                break;
            }
        }
        std::cout << "Loop ended" << std::endl;
        std::cout << "Number of rules pairs: " << rulesPairs.size() << std::endl;
        std::cout << "Rules pairs: ";
        for(int i = 0; i < rulesPairs.size(); i++){
            std::cout << rulesPairs[i][0] << "|" << rulesPairs[i][1] << " ";
        }
        std::cout << std::endl;

        return rulesPairs;
    }

    std::vector<std::vector<int>> loadUpdatesFromText(char* text){
        std::vector<std::vector<int>> updates;
        std::vector<int> updateVector;
        char* ptr = text;
        char* line = text;
        int ctr = 0;
        //Updates start when two consecutive '\n' characters are found
        while(!((*(ptr+1) == '\n') && (*ptr == NULL))){
            ptr++;
            ctr++;
        }
        ptr = ptr + 2;
        // Updates are separated by a single '\n' character
        int ctrDo = 0;
        do{
            ctrDo++;
            // Get the next line
            line = strtok(ptr, "\n");
            if(line == NULL){
                std::cout << "No new lines found!" << std::endl;
                break;
            }
            //std::cout << "Line found: " << line << std::endl;
            //Separate the line into comma-separated numbers
            char* update = strtok(line, ",");
            char* prevUpdate;
            while(update != NULL){
                updateVector.push_back(atoi(update));
                prevUpdate = update;
                update = strtok(NULL, ",");
                if(update == NULL){
                    ptr = prevUpdate + 3;
                }
            }
            //Add the update to the updates
            updates.push_back(updateVector);
            updateVector.clear();
        }while(line != NULL);
        return updates;
    }

    bool checkUpdate(std::vector<std::vector<int>> rules, std::vector<int> update){
        for(int i = 0; i < update.size() - 1; i++){
            //std::cout << "Checking if number " << update[i] << " is in a valid position" << std::endl;
            for(int j = 0; j < rules.size(); j++){
                if(rules[j][0] == update[i]){
                    for(int k = 0; k < update.size(); k++){
                        if(k == i){
                            continue;
                        }
                        if(rules[j][1] == update[k]){
                            if(k > i){
                                break;
                            }else{
                                std::cout << "Faulty update!! Number " << update[i] << " must go before number " << update[k] << std::endl;
                                return false;
                            }
                            break;
                        }
                    }
                }
            }
            //std::cout << "Number " << update[i] << " is in a valid position" << std::endl;
        }
        return true;
    }

    void fixUpdate(std::vector<std::vector<int>> rules, std::vector<int> &update){
        std::vector<int> fixedUpdate;
        //Rules before fixing
        std::cout << "Update before fixing: ";
        for(int i = 0; i < update.size(); i++){
            std::cout << update[i] << " ";
        }
        std::cout << std::endl;
        while(update.size() > 1){
            for(int i = 0; i < update.size() - 1; i++){
                int next = i;
                int current = i;
                while(next !=-1){
                    current = next;
                    next = -1;
                    for(int j = 0; j < rules.size(); j++){
                        if(rules[j][0] == update[current]){
                            for(int k = 0; k < update.size(); k++){
                                if(k == current){
                                    continue;
                                }
                                if(rules[j][1] == update[k]){
                                    next = k;
                                }
                            }
                        }
                    }
                }
                fixedUpdate.push_back(update[current]);
                update.erase(update.begin() + current);
            }
        }
        //Inverse the fixed update
        std::reverse(fixedUpdate.begin(), fixedUpdate.end());
        //Rules after fixing
        std::cout << "Update after fixing: ";
        for(int i = 0; i < fixedUpdate.size(); i++){
            std::cout << fixedUpdate[i] << " ";
        }
        update = fixedUpdate;
        std::cout << std::endl;
    }
    
}