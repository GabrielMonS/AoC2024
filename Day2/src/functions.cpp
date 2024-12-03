#include "functions.h"
#include <iostream>
#include <algorithm>
#include <cstring>

namespace Day1{
    void loadReports(const char* fileName, std::vector<std::vector<int>> &list){
        FILE* file = fopen(fileName, "r");
        if(file == NULL){
            printf("Error: File not found\n");
            exit(1);
        }
        std::vector<std::vector<int>> reportList;
        std::vector<int> report;
        int num;
        // Put all numbers before a new line into a vector
        char line[1000000];
        while (fgets(line, sizeof(line), file)) {
            report.clear();
            char* token = strtok(line, " ");
            while (token != NULL) {
            report.push_back(atoi(token));
            token = strtok(NULL, " ");
            }
            reportList.push_back(report);
        }
        // Delete last item if it is empty
        if(reportList[reportList.size() - 1].size() == 1){
            reportList.pop_back();
        }
        list = reportList;
        fclose(file);
    }

    bool checkSafety(const std::vector<int> &report){
        bool ascending = true;
        int dampener = 1;
        if( report[0] > report[1]){
            ascending = false;
        }
        for(int i = 0; i < report.size() - 1; i++){
            if(ascending){
                if( report[i] >= report[i + 1]){
                    dampener--;
                }
                if( report[i+1] > report[i] + 3){
                    dampener--;
                }
            }else{
                if( report[i] <= report[i + 1]){
                    dampener--;
                }
                if( report[i] > report[i + 1] + 3){
                    dampener--;
                }
            }
            if(dampener < 0){
                return false;
            }
        }
        return true;
    }
}