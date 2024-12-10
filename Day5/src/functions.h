#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace Day5{
    char* loadTextFromFile(const char* fileName);
    std::vector<std::vector<int>> loadRulesFromText(char* text);
    std::vector<std::vector<int>> loadUpdatesFromText(char* text);
    bool checkUpdate(std::vector<std::vector<int>> rules, std::vector<int> update);
    void fixUpdate(std::vector<std::vector<int>> rules, std::vector<int> &update);
}