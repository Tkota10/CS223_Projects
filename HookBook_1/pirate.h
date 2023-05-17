/*
Name of File: pirate.h
Creator: Tarun Kota
Class: CS223, HookBook1
Date: 03/11/23
Purpose: This file contains the implementation of a pirate struct
that we can use to populate the pirate arraylist described in the 
other files. In this file, we have a lot of different functions that 
we can use to access and manipulate parts of the pirate struct.
*/
#ifndef __PIRATE_H__
#define __PIRATE_H__

#include <stdlib.h>

typedef struct implementation pirate;

/* 
Parameters: None
Returns: a pointer to a new pirate object
Purpose: Initializes a new pirate, with allocated memory
        for name.
*/
pirate* pirate_create();
/* 
Parameters: A Pirate object
Returns: the name of a pirate object
Purpose: Used to access name of a pirate object
*/
char *get_name(pirate *p);

/* 
Parameters: A Pirate object and new name
Returns: 0
Purpose: Used to change the name of a pirate object
*/
int change_name(pirate *p, char *name);

/* 
Parameters: A Pirate object
Returns: 0
Purpose: Free the memory associated with a pirate object
*/
void pirate_destroy(pirate *p);

#endif
