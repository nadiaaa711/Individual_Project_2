//
// Created by SWIFT 3 on 11/28/2022.
//
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "FileRandW.h"
#include "Airports.h"
#include "Airlines.h"
#include "Routes.h"
#include "Node.h"
using namespace std;

Node::Node(Node* parent, string airportCode, string airlineCode, int stops){
    this->airportCode = airportCode;
    this->parent = parent;
    this->airlineCode = airlineCode;
    this->stops = stops;
}

Node::Node(string airportCode) {
// set parent to nullptr
    this->airportCode =airportCode;
}


string Node::getAirportCode(){
    return this->airportCode;
};

string Node::getAirlineCode(){
    return this->airlineCode;
};

double Node::getStops(){
    return this->stops;
};

vector<string> Node::solutionPath(){
    /**This method reads creates a solution path that shows the
     * start and destination airport codes and the airline ID for that flight
     *as well as the number of stops
     */

    //declaring three vectors for the instance variables
    vector<string> airportCodesList;
    vector<string> airlineCodesList;
    vector<int> stopsList;
    vector<string> pathList;

    Node* changingNode = this;

    // adding the values to the lists
    while (changingNode != NULL)
    {
        airportCodesList.push_back(changingNode->getAirportCode());
        airlineCodesList.push_back(changingNode->getAirlineCode());
        stopsList.push_back(changingNode->getStops());
        changingNode = changingNode->parent;
    }

    // reversing the order of the list
    reverse(airlineCodesList.begin(), airlineCodesList.end());
    reverse(airportCodesList.begin(), airportCodesList.end());
    reverse(stopsList.begin(), stopsList.end());

// creating the solution print statement
    for (int i = 0; i < airlineCodesList.size() - 1; i++)
    {
        string solutionStatement = to_string(i + 1) + ". " + airlineCodesList[i + 1] + " from " + airportCodesList[i] + " to " + airportCodesList[i + 1] + " " + to_string(stopsList[i]) + " stops.";
        //            String numberOfFlights = "Total number of flights: " + solutionPath().size();
        pathList.push_back(solutionStatement);
    }
    return pathList;
};

void Node::toString(){
    cout << "Node{ airportCode= " << airportCode
           << ", parent=" << parent
           << "airlineCode='" << airlineCode <<
           ", stops=" << stops <<
           "}";
}


bool Node::operator==(const Node &rhs) const {
    return airportCode == rhs.airportCode &&
           parent == rhs.parent &&
           airlineCode == rhs.airlineCode &&
           stops == rhs.stops;
};