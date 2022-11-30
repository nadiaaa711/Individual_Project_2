//
// Created by SWIFT 3 on 11/28/2022.
//
#include <iostream>
#include <string>
using namespace std;

#ifndef FINAL_PROJECT_ROUTES_H
#define FINAL_PROJECT_ROUTES_H

class Routes {
private:
    string airlineCode;
    string airlineID;
    string destinationAirportCode;
    int stops;


public:
    Routes(string airlineCode, string airlineID,
           string destinationAirportCode, int stops);


    //accessor method

    string getAirlineCode();

    void setAirlineCode(string airlineCode);

    string getAirlineID();

    void setAirlineID(string airlineID);

    string getDestinationAirportCode();

    void setDestinationAirportCode(string destinationAirportCode);

    int getStops();

    void setStops(int stops);


    bool operator==(Routes rhs);

    void toString();

};
#endif //FINAL_PROJECT_ROUTES_H
