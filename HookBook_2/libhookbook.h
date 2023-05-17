/*
Name of File: libhookbook.h
Creator: Tarun Kota
Class: CS223, HookBook2
Date: 03/11/23
Purpose: This file contains all the helper functions
referenced in hookbook (main), ranging from 
reading in the pirates, reading and assigning pirate captain pairings  and 
eventually  printing out the pirates.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pirate_list.h"
#include "pirate.h"

/*
 Parameters: Pirate_list pointer and file pointer
 Returns: None
 Purpose: It reads in a profiles text file and populates a pirate list array
 with pirates and the associated information that completes their information
 */
void get_pirates(pirate_list* p, FILE *f);

/*
 Parameters: Pirate_list pointer and file pointer
 Returns: None
 Purpose: It reads in a pirate/captains pairing text file and assigns captains
 to pirates!
 */
void get_captains (pirate_list* p, FILE *f);

/*
 Parameters: Pirate_list pointer and index
 Returns: None
 Purpose: It prints all the skills in the correct order and format. 
 */
void print_skills(pirate_list *pirates, int idx);

/*
 Parameters: Pirate_list pointer and index
 Returns: None
 Purpose: Building on the print skills function it prints out the asteriks's on 
 the side of all the names. It does this by searching for duplicates and adding 
 as asterik everytime a duplicate is found.
 */
void order_skills(pirate_list *pirates, int idx);

/*
 Parameters: Pirate_list pointer 
 Returns: None
 Purpose: Prints out all the profile information of a pirate list based on the 
 format given by the specification.
 */
int print_information(pirate_list *pirates);

/*
 Parameters: Pirate_list pointer 
 Returns: None
 Purpose: This frees all the memory allocated during the entire runtime of this
 program ensuring that all heap blocks were freed and memory was effectively
 managed.
 */
int destroy_everything(pirate_list *pirates);


