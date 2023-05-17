/*
 * Name of File: Station.h
 * Creator: Tarun Kota
 * Class: CPSC 223
 * Date: 04/05/23
 * Purpose: This is the implementation of the Station Class that we can use to 
 * store the Name and accesbility of the station. It also defines other 
 * functions for Station that we can then use for our benefit.
 */

#include <fstream>
#include <string>
using namespace std;

#ifndef STATION_H_
#define STATION_H_

class Station
{
public:
    Station();                      //Constructor 
                                    //Creates a station with name "NoName" 
                                    //and accessibility "False"
    Station(string, bool);          //constructor that also sets the station 
                                    //name and accessibility

    void print(ostream &);          //Prints the information on the station
    bool isEqual(Station);//Returns true if both stations have the 
                                    //same name and accessibility
    bool getAccess() {              //Getter for access
        return access;
    };
    string getName(){               //Getter for name
        return name;
    }


private:
    string name;
    bool access;
};

#endif
