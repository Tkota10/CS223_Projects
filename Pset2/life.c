/*
Life.c
Author: Tarun kota
CS223, Pset 2
February, 10th, 2023
Purpose: This file contains important function 
that are referenced in the main file that helps 
dertimine things such as whether a cell will die
or not.
*/

#include <stdbool.h>
#include <stdio.h>

//Parameters: Game of life array, index of interested cell, size of array
//Returns: True if alive/True if dead
//Purpose: Dertimine if a cell is alive or dead at a certain time.
bool isAlive(int array[], size_t index, size_t size){
    if (array[index]== 1) {
        return true;
    } else {
        return false;
    }
    return 0;
}

//Parameters: Game of life array, index of interested cell, size of array
//Returns: True if will die/True if will not die during next timestep
//Purpose: Dertimine if a cell will die during the next timestep
bool shouldDie(int array[], size_t index, size_t size) {
    if (index == 0) {
        if (isAlive(array,index, size)) {
            return false;
        } else if (isAlive(array,(index + 1), size)) {
            return false;
        } else {
            return true;
        }
    }
    if (index == (size - 1) ) {
        if (isAlive(array,index, size)) {
            return false;
        } else if (isAlive(array, (index - 1), size)) {
            return false;
        } else {
            return true;
        }
    }
    if (isAlive(array,index, size)) {
        if (isAlive(array, (index - 1), size) && isAlive(array, (index + 1), size )) {
            return true;
        } else {
            return false;
        }
    } else if (isAlive(array, (index - 1), size) || isAlive(array, (index + 1), size)) {
        return false;
    } else {
        return true;
    }
    return 0;

}

//Parameters: Game of life array, index of interested cell, size of array
//Returns: No return, but will change inputted array to be one step ahead
//Purpose: Advance a Game of Life Array by one timestep!
void (advanceTime(int array[], size_t index, size_t size)) {
    int copy[size];
    for (int i = 0; i < size; i++) {
        if (shouldDie(array,i,size)) {
            copy[i]=0;
        } else {
            copy[i]=1;
        }

    }
    for (int i = 0; i < size; i++) {     
        array[i] = copy[i];     
    }
     
}