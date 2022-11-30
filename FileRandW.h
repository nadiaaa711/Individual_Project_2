//
// Created by SWIFT 3 on 11/28/2022.
//

#ifndef FINAL_PROJECT_FILERANDW_H
#define FINAL_PROJECT_FILERANDW_H
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Routes.h"

using namespace std;

class FileReadAndWrite {

    FileReadAndWrite();
    // declaring a map and a vector for the airline reading method
//    static unordered_map<string, vector<string>> airlineMap;
//    static vector<string> airlineValues;
//
//    // declaring two maps for the airport reading method
//    static unordered_map<string, vector<string>> cityAirportMap;
//    static unordered_map<string, string> airportCityMap;
//
//
//    //declaring a map for the route reading method
//    static unordered_map<string, vector<Routes>> routeMap;


public:
    //declaring the airline file reading method
    static unordered_map <string, vector<string>>  AirlineRandW();
    //declaring the airport file reading method
    static unordered_map<string, vector<string>>  CityAirportRandW();
    //declaring the airport file reading method
    static unordered_map <string, string>  AirportCityRandW();
    //declaring the airport file reading method
    static unordered_map <string, vector<Routes>>  RouteRandW();

    static unordered_map<string, vector<string>> airlineMap;
    static vector<string> airlineValues;

    // declaring two maps for the airport reading method
    static unordered_map<string, vector<string>> cityAirportMap;
    static unordered_map<string, string> airportCityMap;


    //declaring a map for the route reading method
    static unordered_map<string, vector<Routes>> routeMap;



};
#endif //FINAL_PROJECT_FILERANDW_H
