/*
Name of File: pirate.c
Creator: Tarun Kota
Class: CS223, HookBook1
Date: 03/11/23
Purpose: This file contains the implementation of a pirate struct
that we can use to populate the pirate arraylist described in the 
other files. In this file, we have a lot of different functions that 
we can use to access and manipulate parts of the pirate struct.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pirate.h"

struct implementation
{ 
    char *vessel;
    struct pirate *captain;
    size_t treasures;
    char *favoriteport;
    char *name;
};

/* 
Parameters: None
Returns: a pointer to a newpirate object
Purpose: Initializes a new pirate, with allocated memory
        for name.
*/
pirate* pirate_create()
{
    pirate *new_pirate = malloc(sizeof(pirate));
    new_pirate->name = malloc(65 * sizeof(char));
    return new_pirate;
}

/* 
Parameters: A Pirate object
Returns: the name of a pirate object
Purpose: Used to access name of a pirate object
*/
char *get_name(pirate *p){
    if (p == NULL){
        return NULL;
    }
    char *name = p->name;
    return name;
}

/* 
Parameters: A Pirate object and new name
Returns: 0
Purpose: Used to change the name of a pirate object
*/
int change_name(pirate *p, char *name) {
    strcpy (p->name, name);
    return 0;
}

/* 
Parameters: A Pirate object
Returns: 0
Purpose: Free the memory associated with a pirate object
*/
void pirate_destroy(pirate *p){
    free (p->name);
    free (p);
}
