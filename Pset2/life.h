/*
life.h
Author: Tarun kota
CS223, Pset 2
February, 10th, 2023
Purpose: Header file to make it easier to reference these functions
in the main.c file.
*/

#include <stdbool.h>

bool isAlive(int array[], size_t index, size_t size);

bool shouldDie(int array[], size_t index, size_t size);

void advanceTime(int array[], size_t index, size_t size);