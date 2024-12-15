#include "functions.h"
#include <iostream>

using namespace Day6;

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    printf("Loading map from file: %s\n", argv[1]);
    char *text = loadTextFromFile(argv[1]);
    std::vector<std::vector<char>> mapArray = loadMapFromText(text);
    Map originalMap(mapArray);
    printf("Map created Map size: %dx%d\n", originalMap.width, originalMap.height);
    int advanceRes = 0;
    printf("Starting guard advance\n");
    while(true){
        advanceRes = originalMap.guardAdvance();
        if(advanceRes != 0){
            break;
        }
    }
    //Print new map
    for(int i = 0; i < originalMap.height; i++){
        for(int j = 0; j < originalMap.width; j++){
            printf("%c", originalMap.map[i][j]);
        }
        printf("\n");
    }

    // Count the number of X in the map
    int xCount = 0;
    for(int i = 0; i < originalMap.height; i++){
        for(int j = 0; j < originalMap.width; j++){
            if(originalMap.map[i][j] == 'X'){
                xCount++;
            }
        }
    }
    printf("Number of X in the map: %d\n", xCount);


    // Seccond part of the exercise
    printf("Starting second part of the exercise\n");
    Map newMap(mapArray);
    std::vector<std::vector<char>> newMapArray;
    int loopCounter = 0;
    for(int i = 0; i < mapArray.size(); i++){
        for(int j = 0; j < mapArray[i].size(); j++){
            printf("Checking if putting a new obstacle at [%d][%d] will create a loop\n", j, i);
            newMapArray = mapArray;
            if(mapArray[i][j] == '^'){
                continue;
            }
            else if(mapArray[i][j] == '#'){
                continue;
            }else{
                newMapArray[i][j] = '#';
            }
            newMap = Map(newMapArray);

            int advanceRes = 0;
            while(true){
                advanceRes = newMap.guardAdvance();
                if(advanceRes != 0){
                    break;
                }
            }
            if(advanceRes == 2){
                loopCounter++;
                printf("Found a loop! Loop counter: %d\n", loopCounter);
            }
        }
    }

    printf("Number of loops found: %d\n", loopCounter);

    printf("Press any key to close the program\n");
    getchar();
    return 0;
}