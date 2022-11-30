//
// Created by SWIFT 3 on 11/28/2022.
//

#ifndef FINAL_PROJECT_NODE_H
#define FINAL_PROJECT_NODE_H

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Routes.h"

using namespace std;

class Node{
private:
    //instance variables
    string airportCode;
    Node* parent;
    string airlineCode;
    double stops;


public:
    //constructor
    Node(Node* parent, string airportCode, string airlineCode, int stops);

    // add a default constructor
    Node(string parent);

    string getAirportCode();

    string getAirlineCode();

    double getStops();

    vector<string> solutionPath();

    void toString();

    bool operator==(const Node &rhs) const;
};


#endif //FINAL_PROJECT_NODE_H
