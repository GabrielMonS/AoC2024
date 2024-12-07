#include "functions.h"
#include <iostream>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    char *text = Day4::loadTextFromFile(argv[1]);
    std::vector<std::vector<char>> xmasarray = Day4::arrayFromText(text);
    std::cout << "Array loaded. Sizes are: " << xmasarray.size() << "x" << xmasarray[0].size() << std::endl;
    std::cout << "Last element: " << xmasarray[xmasarray.size()-1][xmasarray[0].size()-1] << std::endl;
    int count = Day4::countXMASinArray(xmasarray);
    printf("XMAS Count: %d\n", count);
    printf("Press any key to close the program\n");
    getchar();
    return 0;
}