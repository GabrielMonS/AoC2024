#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace Day1{
    void orderList(std::vector<int> &list);
    unsigned int getTotalDistance(std::vector<int> firstList, std::vector<int> secondList);
    unsigned long int getSimilarity(std::vector<int> firstList, std::vector<int> secondList);    
    void getListsFromFile(std::vector<int> &firstList, std::vector<int> &secondList, const char* fileName);
}