#include "functions.h"
#include <iostream>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    char *text = Day5::loadTextFromFile(argv[1]);
    std::vector<std::vector<int>> rulesPairs = Day5::loadRulesFromText(text);
    printf("Rules loaded. Number of rules: %d\n", rulesPairs.size());
    std::vector<std::vector<int>> updates = Day5::loadUpdatesFromText(text);
    printf("Updates loaded. Number of updates: %d\n", updates.size());
    //Print the updates
    std::cout << "Updates: " << std::endl;
    for(int i = 0; i < updates.size(); i++){
        for(int j = 0; j < updates[i].size(); j++){
            std::cout << updates[i][j] << " ";
        }
        std::cout << std::endl;
    }
    int middleSum = 0;
    int middleSumBad = 0;
    int halfPage = 0;
    
    std::cout << "Valid updates: " << std::endl;
    for(int i = 0; i < updates.size(); i++){
        if(Day5::checkUpdate(rulesPairs, updates[i])){
            std::cout << "Update " << i << " is valid. adding middle page to count." << std::endl;
            halfPage = (updates[i].size() - 1) / 2;
            middleSum = middleSum + updates[i][halfPage];
        }else{
            std::cout << "Update " << i << " is invalid. Rearranging it." << std::endl;
            Day5::fixUpdate(rulesPairs, updates[i]);
            halfPage = (updates[i].size() - 1) / 2;
            middleSumBad = middleSumBad + updates[i][halfPage];
        }
    }
    std::cout << "Final half-page sum is: " << middleSum << std::endl;
    std::cout << "Final half-page sum of bad updates is: " << middleSumBad << std::endl;
    std::cout << "Total sum is: " << middleSum + middleSumBad << std::endl;

    free(text);
    printf("Press any key to close the program\n");
    getchar();
    return 0;
}