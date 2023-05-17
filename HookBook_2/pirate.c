/*
Name of File: pirate.c
Creator: Tarun Kota
Class: CS223, HookBook2
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

extern char *strdup(const char *s);

#define INITIAL_SIZE 5
#define MULTIPLY_FACTOR 2

//Skills Struct
struct list_implementation {
    char** list_skills; 
    size_t length;
    size_t capacity;
};

//Pirate Struct
struct human
{
    pirate *captain;
    size_t treasures;
    char *name;
    char *title;
    char *vessel;
    char *port;
    skills_list* skills; 
};

/* 
Parameters: None
Returns: a pointer to a skills_list object
Purpose: Initializes a new skills_list, and sets all the fields to 
their base state.
*/
skills_list *create_skills_list() 
{
    skills_list *list = malloc(sizeof(skills_list));
    list->list_skills = malloc(INITIAL_SIZE * sizeof(char *));
    list->length = 0;
    list->capacity = INITIAL_SIZE;
    return list;
}

/* 
Parameters: None
Returns: a pointer to a newpirate object
Purpose: Initializes a new pirate, and sets all the fields to their base state.
*/
pirate* pirate_create()
{
    pirate *newpirate = malloc(sizeof(pirate));
    newpirate->treasures = 0;
    newpirate->captain = NULL;
    newpirate->name = NULL;
    newpirate->title = NULL;
    newpirate->port = NULL;
    newpirate->vessel = NULL;
    newpirate->skills = create_skills_list();
    return newpirate;
}

/* 
Parameters: A Pirate object
Returns: the name of a pirate object
Purpose: Used to access name of a pirate object.
*/
char *get_name(pirate *pirate)
{
    if (pirate == NULL)
    {
        return NULL;
        
    }

    if (pirate->name == NULL) {
        return "(None)";
    }

    char *name = pirate->name;
    return name;
}

/* 
Parameters: A Pirate object
Returns: the title of a pirate object
Purpose: Used to access title of a pirate object.
*/
char *get_title(pirate *pirate)
{
    if (pirate == NULL)
    {
        return NULL;
    }

    if (pirate->title == NULL) {
        return "(None)";
    }

    char *title = pirate->title;
    return title;
}

/* 
Parameters: A Pirate object
Returns: the vessel of a pirate object
Purpose: Used to access vessel of a pirate object.
*/
char *get_vessel(pirate *pirate)
{
    if (pirate == NULL)
    {
        return NULL;
    }

    if (pirate->vessel == NULL) 
    {
        return "(None)";
    }

    char *vessel = pirate->vessel;
    return vessel;
}

/* 
Parameters: A Pirate object
Returns: the port of a pirate object
Purpose: Used to access port of a pirate object.
*/
char *get_port(pirate *pirate)
{
    if (pirate == NULL)
    {
        return NULL;
    }

    if (pirate->port == NULL)
    {
        return "(None)";
    }

    char *port = pirate->port;
    return port;
}

/*
Parameters: Pirate pointer
Returns: Treasure field of a pirate
Purpose: allows access to the treasure field of a pirate
*/
int get_treasures(pirate *pirate) {
    if (pirate == NULL) {
        return -1;
    }

    int treasure = pirate->treasures;
    return treasure;
}

/* 
Parameters: A Pirate object and new name
Returns: 0
Purpose: Used to change the name of a pirate object
*/
int change_name(pirate *pirate, char *name) 
{
    if (pirate->name == NULL) {
        pirate->name = calloc(65, sizeof(char));
    }
    strcpy (pirate->name, name);
    return 0;
}

/* 
Parameters: A Pirate object and new title
Returns: 0
Purpose: Used to change the title of a pirate object
*/
int change_title(pirate *pirate, char *title) 
{
    if (pirate->title == NULL) {
        pirate->title = calloc(65, sizeof(char));
    }
    strcpy (pirate->title, title);
    return 0;
}

/* 
Parameters: A Pirate object and new vessel
Returns: 0
Purpose: Used to change the vessel of a pirate object
*/
int change_vessel(pirate *pirate, char *vessel) 
{
     if (pirate->vessel == NULL) {
        pirate->vessel = calloc(65, sizeof(char));
    }
    strcpy (pirate->vessel, vessel);
    return 0;
}

/* 
Parameters: A Pirate object and new port
Returns: 0
Purpose: Used to change the port of a pirate object
*/
int change_port(pirate *pirate, char *port)
{
     if (pirate->port == NULL) {
        pirate->port = calloc(65, sizeof(char));
    }
    strcpy (pirate->port, port);
    return 0;
}

/* 
Parameters: A Pirate object and new treasure
Returns: 0
Purpose: Used to change the treasure of a pirate object
*/
int change_treasure(pirate *pirate, int value)
{
    pirate->treasures = value;
    return 0;
}

/* 
Parameters: A Pirate object and new captain
Returns: 0
Purpose: Used to assign caption to a pirate object
*/
int assign_captain(pirate *p, pirate *captain)
{
    p->captain = captain;
    return 0;
}

/*
Parameters: skills_list pointer
Returns: None
Purpose: Dertimines based on the length and capacity of the arraylist,
if we should alloc more space.
*/
void skill_expand_if_necessary(skills_list* skills)
{
    size_t new_capacity;
    if (skills->length >= skills->capacity) 
    {
        new_capacity = skills->capacity * MULTIPLY_FACTOR; 
        skills->list_skills = realloc(skills->list_skills, 
                                    new_capacity * sizeof(char *));
        skills->capacity = new_capacity;
    }

}

/*
Parameters: Pirate pointer and skill name
Returns: None
Purpose: Inserts new skill at the end of skills_list.
*/
void insert_skill(pirate *pirate, char *value) 
{
    skill_expand_if_necessary(pirate->skills);  
    pirate->skills->length +=1;
    pirate->skills->list_skills[get_list_length(pirate->skills) - 1] = strdup(value); 
}

/*
Parameters: Pirate pointer 
Returns: Skills_list field of a pirate
Purpose: allows access to the Skills_list field of a pirate
*/
skills_list *get_skills(pirate *pirate){
    if (pirate == NULL){
        return NULL;
    }
    skills_list *s = pirate->skills;
    return s;

}

/*
Parameters: Pirate pointer 
Returns: captain field of a pirate
Purpose: allows access to the captain field of a pirate
*/
pirate *get_captain(pirate *p) 
{
    pirate *captain = p->captain;
    return captain;
}

/*
Parameters: Skill list length
Returns: length field of a skills list
Purpose: allows access to the length field of a skills list
*/
size_t get_list_length(skills_list *skills)
{
    size_t length = skills->length;
    return length;
}

/*
Parameters: Skills list pointer
Returns: 0
Purpose: Sorts the skills list by alphabetical order
*/
int skills_sort(skills_list *skills)
{
    int j;
    char *temp;
    for(int i = 1; i < get_list_length(skills); i++)
    {
        j = i - 1;
        temp = skills->list_skills[i];

        while (j >= 0 && strcmp(skills->list_skills[j], temp) > 0) 
        {
            skills->list_skills[j + 1] = skills->list_skills[j];
            j--;
        }
        skills->list_skills[j + 1] = temp;
    }
    return 0;
}

/*
Parameters: Skills list pointer and index
Returns: skill pointer
Purpose: Used to access a specific pointer in a skills list
*/
char *skillslist_access(skills_list *skills, size_t idx) {
    if (idx < 0 || idx >= skills->length) {
        return NULL;
    }

    char *skill = skills->list_skills[idx];
    return skill;
}

/*
Parameters: Two pirate pointers and letter corresponding to comparison type
Returns: Returns the number corresponding to the type of comparison carried out
Purpose: Used to carry out the sort needed to reorganize the pirate list.
*/
int choose_sort(pirate *p1, pirate *p2, char *type) 
{
    int result = 0;
    if (!strcmp(type, "-n")) {
        result = strcmp(get_name(p1), get_name(p2));
    }
    else if (!strcmp(type, "-t")) 
    {
        result = get_treasures(p1) < get_treasures(p2);
    }
    else if (!strcmp(type, "-v")) {
        result = strcmp(get_vessel(p1), get_vessel(p2));
    }
    return result;
}

/*
Parameters: Pirate pointer
Returns: None
Purpose: Free all the memory associated with a pirate
*/
void pirate_destroy(pirate *pirate)
{
    free (pirate->name);
    free (pirate->title);
    free (pirate->vessel);
    free (pirate->port); 
    for (size_t i = 0; i < pirate->skills->length; i++) {
        free(pirate->skills->list_skills[i]);
    }
    free(pirate->skills->list_skills);
    free(pirate->skills);
    free (pirate);
}






