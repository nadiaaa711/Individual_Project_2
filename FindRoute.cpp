#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <iterator>
#include <list>
#include <bits/stdc++.h>
#include <algorithm>
#include "Routes.h"
#include "FindRoute.h"
#include "Node.h"
#include "FileRandW.h"

vector<string> FindRoute::bfs (string startState, string goalState){
    /**This method implements the breadth first search algorithm
       */
       cout << "Performing a Breadth First Search";

       //creating a queue for the frontier and a set for the explored
       list<Node> frontierList;
       unordered_set<string> exploredSet;

    //creating return values of the methods in the file read and write class
    unordered_map<string, vector<string>> cityAirportMap = FileReadAndWrite::CityAirportRandW();
    unordered_map<string, string> airportCityMap = FileReadAndWrite::AirportCityRandW();
    unordered_map<string, vector<Routes>> routeMap = FileReadAndWrite::RouteRandW();

    //crating a list containing values from the city airport map (airport codes)
    if (cityAirportMap.count(startState)<=0) {
        cout << "Not a key in the map";
        exit(-1);
    }

    vector<string> airportCodesList = cityAirportMap.at(startState);

        //adding nodes to the frontier
        for (string airportCodes: airportCodesList) {
            Node node = Node(airportCodes);
            frontierList.push_back(node);
        }

    //implementing the breadth first search
    while(frontierList.size() != 0){
        Node nodeObj = frontierList.front();
        frontierList.pop_front();
        exploredSet.insert(nodeObj.getAirportCode());
        //checking if the key is in the map
        if (routeMap.find(nodeObj.getAirportCode()) == routeMap.end())
            continue;

        vector<Routes> routes = routeMap.at(nodeObj.getAirportCode());
        if (!routes.empty()) {
            for (Routes route : routes){
                Node childNodeObj = Node(&nodeObj,route.getDestinationAirportCode(),route.getAirlineCode(),route.getStops());
                string cityCountry = airportCityMap.at(childNodeObj.getAirportCode());
                bool inFrontier = (find(frontierList.begin(), frontierList.end(), childNodeObj)!=frontierList.end());
                if (! inFrontier&& !exploredSet.count(childNodeObj.getAirportCode())==0){
                    if (!cityCountry.empty()){
                        if(cityCountry.compare(goalState)== true) {
                            return childNodeObj.solutionPath();
                        }
                        frontierList.push_back(childNodeObj);
                    }
                }
            }
        }
}

vector<string> dummy;
    return dummy;
}

//    return 0;
//};
