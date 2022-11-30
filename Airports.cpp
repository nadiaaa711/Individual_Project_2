#include <iostream>
#include "Airports.h"
#include <string>
using namespace std;



Airports::Airports(string airportID,string name, string country,
        string city,string IATACode) {
        this->airportID = airportID;
        this->name = name;
        this->city = city;
        this->country = country;
        this->IATACode = IATACode;
    }


    //accessor method

    string Airports::getAirportID() {
        return airportID;
    }

    void Airports::setAirportID(string airportID) {
        airportID = airportID;
    }

    string Airports::getName() {
        return name;
    }

    void Airports::setName(string name) {
        name = name;
    }

    string Airports::getCity() {
        return city;
    }

    void Airports::setCity(string city) {
        city = city;
    }

    string Airports::getCountry() {
        return country;
        }
    
    void Airports::setCountry(string country) {
        country = country;
    }

    string Airports::getIATACode() {
        return IATACode;
    }

    void Airports::setIATACode(string IATACode) {
        IATACode = IATACode;
    }

    bool Airports::operator == (Airports rhs) {
        return airportID==rhs.airportID;
   }

    void Airports::toString() {
        cout<< "Airport{airportID=" <<
        airportID  << ", name='" <<
        name <<  ", city='" << city
        << ", country='" <<
        country  << ", IATACode='"
        << IATACode <<  "}";
    }
