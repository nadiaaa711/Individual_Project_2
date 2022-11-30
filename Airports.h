//
// Created by SWIFT 3 on 11/28/2022.
//
#include <iostream>
#include <string>
using namespace std;

#ifndef FINAL_PROJECT_AIRPORTS_H
#define FINAL_PROJECT_AIRPORTS_H

class Airports
{
private:
    string airportID;
    string name;
    string country;
    string city;
    string IATACode;


public:
    Airports(string airportID,string name, string country,
             string city,string IATACode);


    //accessor method

    string getAirportID();

    void setAirportID(string airportID);

    string getName();

    void setName(string name);

    string getCity();

    void setCity(string city);

    string getCountry();

    void setCountry(string country);

    string getIATACode();

    void setIATACode(string IATACode);

    string getICAOCode();

    void setICAOCode(string ICAOCode);

    bool operator == (Airports rhs);

    void toString();
};
#endif //FINAL_PROJECT_AIRPORTS_H
