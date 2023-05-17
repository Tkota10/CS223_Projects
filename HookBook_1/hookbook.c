/*
Name of File: hookbook.c
Creator: Tarun Kota
Class: CS223, HookBook1
Date: 03/11/23
Purpose: This is the main file of my program and describes
the entire lifecyle of the program. It gets the pirates names
of a text file, sorts the pirates names, prints the pirate
names and then frees all the associate memory.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pirate_list.h"
#include "pirate.h"
#include "libhookbook.h"

int main(int argc, char* argv[])
{
    if(argc != 2) 
    {
        exit(1);
    }

    FILE *f = fopen(argv[1], "r");
    if(f == 0) 
    {
        exit(2);
    }
    pirate_list *pirates = list_create();

    get_names(pirates, f);

    list_sort(pirates);

    print_list(pirates);

    fclose(f);
    list_destroy(pirates);
    return 0;
}
