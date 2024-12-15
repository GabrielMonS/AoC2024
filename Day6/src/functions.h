#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace Day6{

    struct Direction{
        int currentDirection; // 0 - up, 1 - right, 2 - down, 3 - left

        Direction(){};

        Direction(const int startDirection) : currentDirection(startDirection){};

        void turnRight(){
            currentDirection = (currentDirection + 1) % 4;
        }
        void turnLeft(){
            currentDirection = (currentDirection + 3) % 4;
        }

        bool operator == (const Direction &d){
            return currentDirection == d.currentDirection;
        }
    };

    struct Point{
        int x;
        int y;

        Point(){};

        Point(int x, int y): x(x), y(y) {}

        Point(const Point &point){
            this->x = point.x;
            this->y = point.y;
        }

        bool operator == (const Point& p){
            return x == p.x && y == p.y;
        }
    };

    struct SavePoint{
        Point point;
        Direction direction;

        SavePoint(){};

        SavePoint(Point point, Direction direction) : point(point), direction(direction) {};

        bool operator == (const SavePoint &sP){
            return (point == sP.point) && (direction == sP.direction);
        }

    };

    struct Map{
        std::vector<std::vector<char>> map;
        int width;
        int height;
        SavePoint guardPosition;
        std::vector<SavePoint> pointsOfInterest;

        Map();

        Map(int width, int height): width(width), height(height){};

        Map(std::vector<std::vector<char>> map);

        bool isPointValid(Point p){
            return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height;
        }
        int guardAdvance(); // Returns 0 if noting happens, 1 if guard moves out of bounds, 2 if guard reaches a point of interest
        bool mapUpdate();
    };

    char* loadTextFromFile(const char* fileName);
    std::vector<std::vector<char>> loadMapFromText(char* text);
}