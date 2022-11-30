// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Airlines.h"
#include "FileRandW.h"
#include "Routes.h"
#include "FindRoute.h"
#include <iostream>
#include <sstream>

using namespace std;


unordered_map<string, vector<string>> FileReadAndWrite::cityAirportMap = *new unordered_map<string, vector<string>>;
unordered_map<string, string> FileReadAndWrite::airportCityMap = *new unordered_map<string, string>;
unordered_map<string, vector<Routes>> FileReadAndWrite::routeMap = *new unordered_map<string, vector<Routes>>;


int main()
{
    cout << "Hello World!\n";
    //Routes routeObj;

    //FileReadAndWrite::CityAirportRandW();
    //FileReadAndWrite::AirportCityRandW();
    //FileReadAndWrite::RouteRandW();

        vector<string> finalSolution = FindRoute::bfs("Accra, Ghana", "Sandane, Norway");


//    ifstream fileStream;
//    ofstream outfile;
//    fileStream.open(
//            "C:/Users/SWIFT 3/OneDrive - Ashesi University/Nadia/Academic/Year2/Year 2 Sem 2/Intermediate Computer Programming/C++ code/Final Project/accra-sandane.txt");
//    string line1;
//    string line2;
//    string line;
//
//    stringstream stream(line);
//        getline(stream, line1, ',');
//        getline(stream, line2, ',');
//
//    vector<string> finalSolution = FindRoute::bfs(line1, line2);
//     //create file writer
//     ofstream fileWrite;
//     fileWrite.open("C:/Users/SWIFT 3/OneDrive - Ashesi University/Nadia/Academic/Year2/Year 2 Sem 2/Intermediate Computer Programming/C++ code/Final Project/accra-sandane.txt");
//
//
//     for(string line : finalSolution){
//        outfile << line <<"\n";
//     }
//
//      outfile<< "Total flights: " << finalSolution.size()<<"\n";
//      outfile << "Total additional stops: 0"<<endl;
//
//
//    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
