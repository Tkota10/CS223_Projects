/*
Name of File: hookbook.c
Creator: Tarun Kota
Class: CS223, HookBook2
Date: 03/11/23
Purpose: This is the main file of my program and describes
the entire lifecyle of the program. It gets the pirates names
of a text file, gets the pirate_captain pairings, creates pirate profiles,
sorts the pirates profiles, prints the pirate profiles and then frees all the 
associate memory.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pirate_list.h"
#include "pirate.h"
#include "libhookbook.h"

int main(int argc, char* argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Invalid arguments\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");

    if (f == NULL) 
    {
        fprintf(stderr, "Invalid filename: %s\n", argv[1]);
        return 1;
    } 
    else if (f == NULL && f2 == NULL)
    {
        fprintf(stderr, "Invalid filename: %s\n", argv[1]);
        return 1;
    }
    else if (f2 == NULL) 
    { 
        fprintf(stderr, "Invalid filename: %s\n", argv[2]);
        return 1;
    }
    if (strcmp(argv[3], "-n") != 0 && 
        strcmp(argv[3], "-v") != 0 && 
        strcmp(argv[3], "-t") != 0) {
        fprintf(stderr, "Invalid argument: %s\n", argv[3]);
        exit(1);
    }
   
    pirate_list *pirates = list_create();
    get_pirates(pirates, f);
    get_captains(pirates, f2);
    list_sort(pirates, argv[3]);
    print_information(pirates);
    fclose(f);
    fclose (f2);
    destroy_everything(pirates);  
    return 0;
}

