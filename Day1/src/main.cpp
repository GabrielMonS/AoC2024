#include "functions.h"
#include <iostream>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    std::vector<int> firstList;
    std::vector<int> secondList;
    std::cout << "Reading lists from file: " << argv[1] << std::endl;
    Day1::getListsFromFile(firstList, secondList, argv[1]);
    std::cout << "First list: ";
    for(int i = 0; i < firstList.size(); i++){
        std::cout << firstList[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Second list: ";
    for(int i = 0; i < secondList.size(); i++){
        std::cout << secondList[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Ordering lists" << std::endl;
    Day1::orderList(firstList);
    Day1::orderList(secondList);
    std::cout << "First list(Ordered): ";
    for(int i = 0; i < firstList.size(); i++){
        std::cout << firstList[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Second list(Ordered): ";
    for(int i = 0; i < secondList.size(); i++){
        std::cout << secondList[i] << " ";
    }
    std::cout << std::endl;
    printf("Total distance: %d\n", Day1::getTotalDistance(firstList, secondList));
    printf("Similarity: %lu\n", Day1::getSimilarity(firstList, secondList));
    // Way for keypress to close the program
    printf("Press any key to close the program\n");
    getchar();
    return 0;
}