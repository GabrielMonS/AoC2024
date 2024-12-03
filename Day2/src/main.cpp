#include "functions.h"
#include <iostream>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    std::vector<std::vector<int>> reports;
    std::cout << "Reading reports from file: " << argv[1] << std::endl;
    Day2::loadReports(argv[1], reports);
    for(int i = 0; i < reports.size(); i++){
        printf("Report %d: ", i);
        for(int j = 0; j < reports[i].size(); j++){
            printf("%d ", reports[i][j]);
        }
        printf("\n");
    }
    std::cout << "Checking reports" << std::endl;
    int safeReports = 0;
    for(int i = 0; i < reports.size(); i++){
        if(Day2::checkSafety(reports[i])){
            safeReports++;
        }
    }
    printf("Safe reports: %d\n", safeReports);
    // Way for keypress to close the program
    printf("Press any key to close the program\n");
    getchar();
    return 0;
}