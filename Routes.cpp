#include <iostream>
#include <string>
#include "Routes.h"
using namespace std;



Routes::Routes(string airlineCode, string airlineID,
            string destinationAirportCode, int stops) {
        this->airlineCode = airlineCode;
        this->airlineID = airlineID;
        this->destinationAirportCode = destinationAirportCode;
        this->stops = stops;
    }


    //accessor method

    string Routes::getAirlineCode() {
        return airlineCode;
    }

    void Routes::setAirlineCode(string airlineCOde) {
        airlineCode = airlineCode;
    }

    string Routes::getAirlineID() {
        return airlineID;
    }

    void Routes::setAirlineID(string airlineID) {
        airlineID = airlineID;
    }

    string Routes::getDestinationAirportCode() {
        return destinationAirportCode;
    }

    void Routes::setDestinationAirportCode(string destinationAirportCode) {
        destinationAirportCode = destinationAirportCode;
    }

    int Routes::getStops() {
        return stops;
    }

    void Routes::setStops(int stops) {
        stops = stops;
    }

    
    bool Routes::operator == (Routes rhs) {
        return stops == rhs.stops;
    }

    void Routes::toString() {
        cout << "Routes{ airlineCode=" <<
        getAirlineCode() <<
        ", airlineID = " << airlineID <<
         ", destinationAirportCode = " <<
        destinationAirportCode << ", stops=" <<
       stops << "}";
    }
