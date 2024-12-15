#include "functions.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <thread>

namespace Day6{

    Map::Map(std::vector<std::vector<char>> map){
        bool guardFound = false;
        this->height = map.size();
        this->width = map[0].size();
        this->map = map;
        for(int i = 0; i < map.size(); i++){
            for(int j = 0; j < map[i].size(); j++){
                if(map[i][j] == '^'){
                    printf("Guard found! Position: [%d][%d]\n", j, i);
                    Point gPoint(j,i);
                    SavePoint gSPoint(gPoint, 0);
                    this->guardPosition = gSPoint;
                    break;
                }
            }
            if(guardFound){
                printf("Guard found!");
                break;
            }
        }
        this->pointsOfInterest.clear();
        printf("Guard starting postion is: [%d][%d]\n", this->guardPosition.point.x, this->guardPosition.point.y);
    }

    int Map::guardAdvance(){
        int ret = 0;
        int ctr = 1;
        //printf("Advance guard\n");

        switch(this->guardPosition.direction.currentDirection){
            case 0:
            {   
                int gYNewPosition = this->guardPosition.point.y - ctr;
                while(true){
                    gYNewPosition = this->guardPosition.point.y - ctr;
                    //printf("Counter: %d\n", ctr);
                    if(gYNewPosition < 0){
                        //printf("Guard moved out of bounds!!\n");
                        ret = 1;
                        break;
                    } else if(this->map[gYNewPosition][this->guardPosition.point.x] == '#'){
                        //printf("Guard encountered an obstacle! Turning...\n");
                        Point newPos = Point(this->guardPosition.point.x, gYNewPosition + 1);
                        this->guardPosition.direction.turnRight();
                        SavePoint newSPoint = SavePoint(newPos, this->guardPosition.direction);  
                        this->guardPosition = newSPoint;
                        //printf("New save Point reached! Point: [%d][%d] , Direction: Right\n", newSPoint.point.x, newSPoint.point.y);
                        for(int i = 0; i < this->pointsOfInterest.size(); i ++){
                            if(this->guardPosition == this->pointsOfInterest[i]){
                                printf("I remember this place. WE ARE IN A FUCKING LOOP!!");
                                ret = 2;
                                return ret;
                            }
                        }
                        this->pointsOfInterest.push_back(newSPoint);
                        ret = 0;
                        break;   
                    }
                    map[gYNewPosition][this->guardPosition.point.x] = 'X';
                    ctr++;
                }
            }
            break;
            case 1:
            {
                int gXNewPosition = this->guardPosition.point.x + ctr;
                while(true){
                    gXNewPosition = this->guardPosition.point.x + ctr;
                    if(gXNewPosition >= this->width){
                        //printf("Guard moved out of bounds!!\n");
                        ret = 1;
                        break;
                    } else if(this->map[this->guardPosition.point.y][gXNewPosition] == '#'){
                        //printf("Guard encountered an obstacle! Turning...\n");
                        Point newPos = Point(gXNewPosition - 1, this->guardPosition.point.y);
                        this->guardPosition.direction.turnRight();
                        SavePoint newSPoint = SavePoint(newPos, this->guardPosition.direction);  
                        this->guardPosition = newSPoint;
                        //printf("New ssave Point reached! Point: [%d][%d] , Direction: Down\n", newSPoint.point.x, newSPoint.point.y);
                        for(int i = 0; i < this->pointsOfInterest.size(); i ++){
                            if(this->guardPosition == this->pointsOfInterest[i]){
                                printf("I remember this place. WE ARE IN A FUCKING LOOP!!\n");
                                ret = 2;
                                return ret;
                            }
                        }
                        this->pointsOfInterest.push_back(newSPoint);
                        ret = 0;
                        break;   
                    }
                    map[this->guardPosition.point.y][gXNewPosition] = 'X';
                    ctr++;
                }
            }
            break;
            case 2:
            {
                int gYNewPosition = this->guardPosition.point.y + ctr;
                while(true){
                    gYNewPosition = this->guardPosition.point.y + ctr;
                    if(gYNewPosition >= this->height){
                        //printf("Guard moved out of bounds!!");
                        ret = 1;
                        break;
                    } else if(this->map[gYNewPosition][this->guardPosition.point.x] == '#'){
                        //printf("Guard encountered an obstacle! Turning...\n");
                        Point newPos = Point(this->guardPosition.point.x, gYNewPosition - 1);
                        this->guardPosition.direction.turnRight();
                        SavePoint newSPoint = SavePoint(newPos, this->guardPosition.direction);  
                        this->guardPosition = newSPoint;
                        //printf("New ssave Point reached! Point: [%d][%d] , Direction: Left\n", newSPoint.point.x, newSPoint.point.y);
                        for(int i = 0; i < this->pointsOfInterest.size(); i ++){
                            if(this->guardPosition == this->pointsOfInterest[i]){
                                printf("I remember this place. WE ARE IN A FUCKING LOOP!!\n");
                                ret = 2;
                                return ret;
                            }
                        }
                        this->pointsOfInterest.push_back(newSPoint);
                        ret = 0;
                        break;   
                    }
                    map[gYNewPosition][this->guardPosition.point.x] = 'X';
                    ctr++;
                }
            }
            break;
            case 3:
            {
                int gXNewPosition = this->guardPosition.point.x - ctr;
                while(true){
                    gXNewPosition = this->guardPosition.point.x - ctr;
                    if(gXNewPosition < 0){
                        //printf("Guard moved out of bounds!!\n");
                        ret = 1;
                        break;
                    } else if(this->map[this->guardPosition.point.y][gXNewPosition] == '#'){
                        //printf("Guard encountered an obstacle! Turning...\n");
                        Point newPos = Point(gXNewPosition + 1, this->guardPosition.point.y);
                        this->guardPosition.direction.turnRight();
                        SavePoint newSPoint = SavePoint(newPos, this->guardPosition.direction);  
                        this->guardPosition = newSPoint;
                        printf("New ssave Point reached! Point: [%d][%d] , Direction: Up\n", newSPoint.point.x, newSPoint.point.y);
                        for(int i = 0; i < this->pointsOfInterest.size(); i ++){
                            if(this->guardPosition == this->pointsOfInterest[i]){
                                printf("I remember this place. WE ARE IN A FUCKING LOOP!!\n");
                                ret = 2;
                                return ret;
                            }
                        }
                        this->pointsOfInterest.push_back(newSPoint);
                        ret = 0;
                        break;   
                    }
                    map[this->guardPosition.point.y][gXNewPosition] = 'X';
                    ctr++;
                }
            }
            break;
            default:
                printf("Congratulations!! You have broken the program...");
            break;
        }
        return ret;
    }

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

    std::vector<std::vector<char>> loadMapFromText(char* text){
        std::vector<std::vector<char>> map;
        char* ptr = text;
        while(*ptr != '\0'){
            std::vector<char> row;
            while(*ptr != '\n'){
                row.push_back(*ptr);
                ptr++;
            }
            map.push_back(row);
            ptr++;
        }
        printf("Map size: %d\n", map.size());
        return map;
    }


}