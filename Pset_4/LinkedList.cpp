/*
 * Name of File: LinkedList.cpp
 * Creator: Tarun Kota
 * Class: CPSC 223
 * Date: 04/05/23
 * Purpose: This is the implementation for Linked List of Green Line Extension 
 * Stations. It defines different functions to achieve this such as constructor,
 * destructor, inserting and removing stations and finally printing out the 
 * linked list.
 */

#include "LinkedList.h"
#include "Station.h"
#include <iostream>
using namespace std;

// Default constructor
LinkedList::LinkedList(){
    length = 0;
    head = NULL;
    currPos = NULL;
}

// Destructor
LinkedList::~LinkedList() {
   makeEmpty(); 
}

// Assignment operator overloading
// Don't change anything here. This is needed for copying objects.
LinkedList & LinkedList::operator = (const LinkedList &l){
    NodeType *temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    length = l.length;
    currPos = NULL;
    if (l.head == NULL)
        head = NULL;
    else{
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL){
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return *this;
}

// Input: nothing
// Returns: the length
// Does: returns the length of the LL
int LinkedList::getLength() const{
    return length;
}

// Input: nothing
// Returns: true if currPos is NULL
// Does: determines if currPos is NULL or not
bool LinkedList::isCurrPosNull() const{
    return currPos == NULL;    
}

// Input: Station object
// Returns: void
// Does: It inserts a station at the head of the linked List
void LinkedList::insertStation(Station s){

    NodeType* newNode = new NodeType;
    newNode->info = s;
    newNode->next = NULL;

    newNode->next = head;
    head = newNode;

    length++;
}

// Input: Station object
// Returns: void
// Does: Removes the station in the Linked list that matches the inputted 
//station.
void LinkedList::removeStation(Station s){
    NodeType* curr = head;
    NodeType* prev = NULL;

    while (curr != NULL) 
    {
        if (curr->info.isEqual(s)) 
        {
            if (curr == head) 
            {
                head = curr->next;
            } else 
            {
                prev->next = curr->next;
            }

            if (curr == currPos) 
            {
                resetCurrPos();
            }

            delete curr;
            length --;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
    return;
    
}


// Input: Nothing
// Returns: Returns the next Station
// Does: Everytime it's called it returns the next station in the Linked List.
Station LinkedList::getNextStation(){
    if (isCurrPosNull())
    {
        if (head == NULL)
        {
            return Station();
        }
        else
        {
        currPos = head->next;
        return head->info;
        }
    }
    else if (currPos->next != NULL)
    {
        NodeType *tmp = currPos;
        currPos = currPos->next;
        return tmp->info;
    }
    else
    {
        NodeType *tmp = currPos;
        currPos = NULL;
        return tmp->info;
    }

}

// Input: Nothing
// Returns: Void
// Does: Sets the currPos variable to NULL
void LinkedList::resetCurrPos()
{
   currPos = NULL;
}

// Input: Nothing
// Returns: Void
// Does: The function should delete all the elements in the Linked List and 
//deallocate any memory. 
void LinkedList::makeEmpty()
{
    NodeType* curr = head;
    if (curr == NULL)
    {
        length = 0;
        resetCurrPos(); //Is this chill?
        delete curr; //What does this do?
        return;
    }
    while (curr->next != NULL)
    {
        NodeType* tmp=curr->next;
        delete curr;
        curr = tmp;
    }
    
    delete curr;
    length = 0;
    head = NULL;
    resetCurrPos(); //Is this chill?
}



// Input: ostream Object
// Returns: void
// Does: It prints out all the stations of the Linked List according to the 
// Pset 4 spec.
void LinkedList::print(ostream &out)
{
    NodeType *tmp = head;
   int distance = length - 1;
   while (distance != 0)
   {
        tmp->info.print(out);
        out << " " << distance << " == ";
        tmp = tmp->next;
        distance --;
   }

   tmp->info.print(out);
   out << " " << distance << "\n";
}



