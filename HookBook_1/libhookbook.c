/*
Name of File: libhookbook.c
Creator: Tarun Kota
Class: CS223, HookBook1
Date: 03/11/23
Purpose: This file contains all the helper functions
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
void get_names(pirate_list* p, FILE *f)
{
    char* name = (char *) malloc (65); 
    size_t name_len = 65;
    while (fgets(name, name_len, f) != NULL) 
    {
        name[strcspn(name, "\n")] = '\0';
        char *tempname = malloc(65);
        strcpy(tempname, name);
        pirate *new_pirate = pirate_create();
        change_name(new_pirate, tempname);
        pirate *tofree = list_insert(p, new_pirate, list_length(p));
        if (tofree != NULL)
        {
            pirate_destroy(tofree);
        }
        free(tempname);
    }
    free(name); 
}

/*
Parameters: Pirate_list pointer
Returns: None
Purpose: Prints out all the pirates from a pirate list.
 */
void print_list(pirate_list* p){
    for (int i = 0; i < list_length(p); i++)
    {          
        printf("%s\n", get_name(list_access(p, i)));
        //free each pirate after we print it!
        pirate_destroy(list_access(p, i));
    }
}
