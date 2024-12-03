#include "functions.h"
#include <iostream>
#include <algorithm>

namespace Day1{
    void orderList(std::vector<int> &list){
        std::sort(list.begin(), list.end());
    }
    unsigned int getTotalDistance(std::vector<int> firstList, std::vector<int> secondList){
        unsigned int totalDistance = 0;
        for(int i = 0; i < firstList.size(); i++){
            totalDistance += abs(firstList[i] - secondList[i]);
        }
        return totalDistance;
    }
    unsigned long int getSimilarity(std::vector<int> firstList, std::vector<int> secondList){
        unsigned int similarity = 0;
        for(int i = 0; i < firstList.size(); i++){
            for(int j = 0; j < secondList.size(); j++){
                if(firstList[i] == secondList[j]){
                    similarity += firstList[i];
                }
            }
        }
        return similarity;
    }
    void getListsFromFile(std::vector<int> &firstList, std::vector<int> &secondList, const char* fileName){
        FILE* file = fopen(fileName, "r");
        if(file == NULL){
            printf("Error: File not found\n");
            exit(1);
        }
        // Print file chars
        int ctr = 0;
        int num;
        while(fscanf(file, "%d", &num) != EOF){
            if(ctr % 2 == 0){
                firstList.push_back(num);
            }else{
                secondList.push_back(num);
            }
            ctr++;
        }
        fclose(file);
    }
}