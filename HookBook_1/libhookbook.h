/*
Name of File: libhookbook.h
Creator: Tarun Kota
Class: CS223, HookBook1
Date: 03/11/23
Purpose: This header file contains all the helper functions
referenced in hookbook (main), ranging from 
reading in the pirates and eventually printing out
the pirates.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pirate_list.h"
#include "pirate.h"

/*
Parameters: Pirate_list pointer, File pointer
Returns: None
Purpose: Reads in all of the pirate names from a txt file and 
        stores it into a pirate array list.
 */
void get_names(pirate_list* p, FILE *f);

/*
Parameters: Pirate_list pointer
Returns: None
Purpose: Prints out all the pirates from a pirate list.
 */
void print_list(pirate_list* p);
