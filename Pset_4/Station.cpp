/*
 * Name of File: Station.cpp
 * Creator: Tarun Kota
 * Class: CPSC 223
 * Date: 04/05/23
 * Purpose: This is the implementation of the Station Class that we can use to 
 * store the Name and accesbility of the station. It also defines other 
 * functions for Station that we can then use for our benefit.
 */

#include "Station.h"

// Constructor
Station::Station(){
	name = "NoName";
    access = false;
}

// Parameterized Constructor
Station::Station(string input_name, bool input_access){
    name = input_name;
    access = input_access;
}

// Function: To compare if two functions are equal or not.
// Input: It takes in a Station
// Returns: True if the stations are equal, false if the station is not.
// Does: Through an if statement it checks if both components of the Stations 
// equal.
bool Station::isEqual(Station s){

    if (name == s.getName() && access == s.getAccess()) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

// Function: Print out a station in the designated format
// Input: An ostream object
// Returns: Nothing
// Does: This is used to print out the station in the designated format and is
// something we will use when we print out the LinkedList.
void Station::print(ostream &outfile){
    string available = "A";
    if (access == false)
    {
        available ="U";
    }
    outfile << name << " " << available;
}



