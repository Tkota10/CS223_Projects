/*
 * Name of File: LinkedList.h
 * Creator: Tarun Kota
 * Class: CPSC 223
 * Date: 04/05/23
 * Purpose: This is the implementation for Linked List of Green Line Extension 
 * Stations. It defines different functions to achieve this such as constructor,
 * destructor, inserting and removing stations and finally printing out the 
 * linked list.
 */

#include "NodeType.h"
#include "Station.h"
#include <fstream>

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

class LinkedList
{
public:
    LinkedList();                                   // Default constructor
    ~LinkedList();                                  // Default constructor
    LinkedList & operator = (const LinkedList &);   // Assignment Operator
    LinkedList(const LinkedList &);                 // copy constructor. 
                                            // It creates a new list that is 
                                            // identical to the one given


    void insertStation(Station);           // Inserts a station into the list
    void removeStation(Station);           // Removes a station from the list
    void makeEmpty();                      // Empties the list
    void resetCurrPos();
    Station getNextStation();             // Gives a new station

    bool isCurrPosNull() const;
    int getLength() const;                 // Returns the length of the list
    void print(ostream &);                  // Print the list of stations 


private:
    int length;
    NodeType *head;
    NodeType *currPos;
};

#endif
