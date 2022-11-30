#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "FileRandW.h"
#include "Airports.h"
#include "Airlines.h"
#include "Routes.h"
using namespace std;

//defining the default constructor
    FileReadAndWrite::FileReadAndWrite() = default;


    //defining the airport file reading method
    unordered_map<string, vector<string>>  FileReadAndWrite::CityAirportRandW() {
        /**This method reads from the airports csv file and splits each line at the comma,
         *appending the individual entries into an array, then creates two hashmaps,
         * with the city and country as the key and an arraylist containing specific entries from the file as the values
         */

        ifstream fileStream;
        fileStream.open("C:/Users/SWIFT 3/OneDrive - Ashesi University/Nadia/Academic/Year2/Year 2 Sem 2/Intermediate Computer Programming/airports.csv");
        string line;

        while(getline(fileStream, line)) {
            string airport_id;
            string airport_name;
            string airport_city;
            string airport_country;
            string airport_code;

            stringstream stream(line);
            getline(stream, airport_id, ',');
            getline(stream, airport_name, ',');
            getline(stream, airport_city, ',');
            getline(stream, airport_country, ',');
            getline(stream, airport_code, ',');

            //creating a key for the city airport map
            string cityAirportMapKey = airport_city + ", " + airport_country;

            //inputting airport codes as the values of the city airport map
            //adding the start city country the key if it is not
            //adding its corresponding destination code as its values
            if (cityAirportMap.find(cityAirportMapKey) == cityAirportMap.end()) {
                vector<string> theseAirportValues;
                theseAirportValues.push_back(airport_code);
                FileReadAndWrite::cityAirportMap.insert(pair<string, vector<string>>
                                                            (cityAirportMapKey, theseAirportValues));
            }
            //adding the airport code the vector if the city and country are a key
            else {
                vector<string> temp = cityAirportMap.at(cityAirportMapKey);
                temp.push_back(airport_code);
                FileReadAndWrite::cityAirportMap.erase(cityAirportMapKey);
                FileReadAndWrite::cityAirportMap.insert({cityAirportMapKey,temp});

            }

        }
//        for (auto const &pair: cityAirportMap) {
//            std::cout << "{" << pair.first << ": ";
//            for (string entry: pair.second)
//                cout << entry << " ";
//            cout << "}\n";
//        }
        return cityAirportMap;
    }

//defining the airport file reading method
unordered_map <string, string> FileReadAndWrite::AirportCityRandW() {
    /**This method reads from the airports csv file and splits each line at the comma,
     *appending the individual entries into an array, then creates two hashmaps,
     * with the city and country as the key and an arraylist containing specific entries from the file as the values
     */

    //reading from the airports file
    ifstream fileStream;
    fileStream.open(
            "C:/Users/SWIFT 3/OneDrive - Ashesi University/Nadia/Academic/Year2/Year 2 Sem 2/Intermediate Computer Programming/airports.csv");
    string line;


    while (getline(fileStream, line)) {
        string airport_id;
        string airport_name;
        string airport_city;
        string airport_country;
        string airport_code;

        stringstream stream(line);
        getline(stream, airport_id, ',');
        getline(stream, airport_name, ',');
        getline(stream, airport_city, ',');
        getline(stream, airport_country, ',');
        getline(stream, airport_code, ',');

        //creating a key for the city airport map
        string AirportCityMapValues = airport_city + ", " + airport_country;

        //populating the airportCityMap
        airportCityMap.insert(pair<string, string>
                                      (airport_code, AirportCityMapValues));


        }
//    for (auto const &pair: airportCityMap) {
//        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
//    }
    return airportCityMap;
}


unordered_map <string, vector<Routes>>  FileReadAndWrite::RouteRandW() {
    /**This method reads from the routes csv file and splits each line at the comma,
         *appending the individual entries into a string stream, then creates a hashmap,
         * with the airport code as the key and an arraylist containing specific entries from the file as the values
         */
    ifstream fileStream;
    fileStream.open(
            "C:/Users/SWIFT 3/OneDrive - Ashesi University/Nadia/Academic/Year2/Year 2 Sem 2/Intermediate Computer Programming/routes.csv");
    string line;

    while (getline(fileStream, line)) {
        string airline_code;
        string airline_ID;
        string source_airport_code;
        string source_airport_ID;
        string dest_airport_code;
        string dest_airport_ID;
        string code_share;
        string temp;
        int stops;
        string equipment;

        stringstream stream(line);
        getline(stream, airline_code, ',');
        getline(stream, airline_ID, ',');
        getline(stream, source_airport_code, ',');
        getline(stream, source_airport_ID, ',');
        getline(stream, dest_airport_code, ',');
        getline(stream, dest_airport_ID, ',');
        getline(stream, code_share, ',');
        getline(stream, temp, ',');
        stops = stoi(temp);
        getline(stream, equipment, ',');

        //creating a key for route map
        string key = source_airport_code;

        //creating a Route object
        Routes routeObj = Routes(airline_code, airline_ID, dest_airport_code, stops);

        //checking to see if the key is already in the hashmap
        //vector<Routes> newRoutesList;
        if (routeMap.count(key)<=0){
            vector<Routes> routeList;
            routeList.push_back(routeObj);
            routeMap.insert(pair<string, vector<Routes>>(
                    key, routeList));
        } else {
            routeMap.at(key).push_back(routeObj);
        }
    }


//        for (auto const &pair: routeMap) {
//            std::cout << "{" << pair.first << ": ";
//            for (Routes entry: pair.second) {
//                entry.toString();
//                cout << "}\n";
//            }
//
//        }

    return routeMap;

}