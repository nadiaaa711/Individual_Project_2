//
// Created by SWIFT 3 on 11/29/2022.
//

#ifndef FINAL_PROJECT_FINDROUTE_H
#define FINAL_PROJECT_FINDROUTE_H
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include "Routes.h"

using namespace std;

class FindRoute{

public:
    static vector<string> bfs (string startState, string goalState);

};
#endif //FINAL_PROJECT_FINDROUTE_H
