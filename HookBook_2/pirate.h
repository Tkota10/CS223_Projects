/*Name of File: pirate.h
Creator: Tarun Kota
Class: CS223, HookBook2
Date: 03/11/23
Purpose: This file contains the implementation of a pirate struct
that we can use to populate the pirate arraylist described in the 
other files. In this file, we have a lot of different functions that 
we can use to access and manipulate parts of the pirate struct.
*/

#ifndef __PIRATE_H__
#define __PIRATE_H__

#include <stdlib.h>

typedef struct list_implementation skills_list;

typedef struct human pirate;

/* 
Parameters: None
Returns: a pointer to a skills_list object
Purpose: Initializes a new skills_list, and sets all the fields to 
their base state.
*/
skills_list *create_skills_list(); 

/* 
Parameters: None
Returns: a pointer to a newpirate object
Purpose: Initializes a new pirate, and sets all the fields to their base state.
*/
pirate* pirate_create();

/* 
Parameters: A Pirate object
Returns: the name of a pirate object
Purpose: Used to access name of a pirate object.
*/
char *get_name(pirate *p);

/* 
Parameters: A Pirate object
Returns: the title of a pirate object
Purpose: Used to access title of a pirate object.
*/
char *get_title(pirate *pirate);

/* 
Parameters: A Pirate object
Returns: the vessel of a pirate object
Purpose: Used to access vessel of a pirate object.
*/
char *get_vessel(pirate *pirate);

/* 
Parameters: A Pirate object
Returns: the port of a pirate object
Purpose: Used to access port of a pirate object.
*/
char *get_port(pirate *pirate);

/*
Parameters: Pirate pointer
Returns: Treasure field of a pirate
Purpose: allows access to the treasure field of a pirate
*/
int get_treasures(pirate *pirate);

/* 
Parameters: A Pirate object and new name
Returns: 0
Purpose: Used to change the name of a pirate object
*/
int change_name(pirate *pirate, char *name);

/* 
Parameters: A Pirate object and new title
Returns: 0
Purpose: Used to change the title of a pirate object
*/
int change_title(pirate *pirate, char *title);

/* 
Parameters: A Pirate object and new vessel
Returns: 0
Purpose: Used to change the vessel of a pirate object
*/
int change_vessel(pirate *pirate, char *vessel);

/* 
Parameters: A Pirate object and new port
Returns: 0
Purpose: Used to change the port of a pirate object
*/
int change_port(pirate *pirate, char *port);

/* 
Parameters: A Pirate object and new treasure
Returns: 0
Purpose: Used to change the treasure of a pirate object
*/
int change_treasure(pirate *pirate, int value);

/* 
Parameters: A Pirate object and new captain
Returns: 0
Purpose: Used to assign caption to a pirate object
*/
int assign_captain(pirate *p, pirate *captain);

/*
Parameters: skills_list pointer
Returns: None
Purpose: Dertimines based on the length and capacity of the arraylist,
if we should alloc more space.
*/
void skill_expand_if_necessary(skills_list* skills);

/*
Parameters: Pirate pointer and skill name
Returns: None
Purpose: Inserts new skill at the end of skills_list.
*/
void insert_skill(pirate *pirate, char *value);

/*
Parameters: Pirate pointer 
Returns: captain field of a pirate
Purpose: allows access to the captain field of a pirate
*/
pirate *get_captain(pirate *p); 

/*
Parameters: Skill list length
Returns: length field of a skills list
Purpose: allows access to the length field of a skills list
*/
size_t get_list_length(skills_list *skills);

/*
Parameters: Pirate pointer 
Returns: Skills_list field of a pirate
Purpose: allows access to the Skills_list field of a pirate
*/
skills_list *get_skills(pirate *pirate);

/*
Parameters: Skills list pointer
Returns: 0
Purpose: Sorts the skills list by alphabetical order
*/
int skills_sort(skills_list *skills);

/*
Parameters: Skills list pointer and index
Returns: skill pointer
Purpose: Used to access a specific pointer in a skills list
*/
char *skillslist_access(skills_list *skills, size_t idx);

/*
Parameters: Two pirate pointers and letter corresponding to comparison type
Returns: Returns the number corresponding to the type of comparison carried out
Purpose: Used to carry out the sort needed to reorganize the pirate list.
*/
int choose_sort(pirate *p1, pirate *p2, char *type);

/*
Parameters: Pirate pointer
Returns: None
Purpose: Free all the memory associated with a pirate
*/
void pirate_destroy(pirate *p);

#endif
