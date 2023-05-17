/*
Name of File: pirate_list.h
Creator: Tarun Kota
Class: CS223, HookBook2
Date: 03/11/23
Purpose: This file contains the implementation of an arraylist
that is used to store the pirates bring read into from the text file.
Here, we define functions on manipulating and using this arraylist to
carry out the functionality of our program. Note that I added a parameter in 
my list_sort function in order to allow to sort based on different types
(treasure, vessel, etc. )
*/

#ifndef __PIRATE_LIST_H__
#define __PIRATE_LIST_H__

#include <stdlib.h>

#include "pirate.h"

// Type of a list of pirates
typedef struct implementation pirate_list;

/* 
Parameters: None
Returns: A pointer to the new pirate_list
Purpose: It's used to initaliaze a new pirate list
and alloc enough memory for all the fields.
*/
pirate_list *list_create();

/*
 Parameters: Pirate_list pointer and pirate pointer
 Returns: An index to the desirated pirate
 Purpose: Return the index of the pirate with the same name as p, 
 or a value greater than or equal to the length of the list 
 if there is no pirate in the list with a matching name.
 */
size_t list_index_of(pirate_list *pirates, pirate *p);

/*
Parameters: Pirate List pointer
Returns: None
Purpose: Dertimines based on the length and capacity of the arraylist,
if we should alloc more space.
*/
void list_expand_if_necessary(pirate_list* pirates);

/*
Parameters: Pointer to a pirate list, pirate pointer, index
Returns: Pointer to a pirate
Purpose: if there is no pirate in the list with the same name as p, 
insert pirate p into the list at index idx by copying the pointer, shifting the 
latter part of the list one “slot” to the right.
If there is a pirate in the list with the same name as p, do nothing, and 
return a pointer to the pirate that was not inserted.
If the pirate was inserted into the list, return NULL
 */
pirate *list_insert(pirate_list *pirates, pirate *p, size_t idx);

/*
Parameters: Pirate List pointer
Returns: None
Purpose: Dertimines based on the length and capacity of the arraylist,
if we contract the space we are using.
*/
void list_contract_if_necessary(pirate_list *pirates);

/*
Parameters: Pirate_list pointer and pirate pointer
Returns: pirate pointer
Purpose: Remove the pirate from the list with the same name as p, 
and return a pointer to it. If there is no pirate in the list with the same 
name as p, return NULL
 */
pirate *list_remove(pirate_list *pirates, pirate *p);

/*
Parameters: Pirate_list pointer and Index
Returns: pirate pointer
Purpose: Return a pointer to the pirate pointed to by index idx in the list, 
or NULL if idx is not a valid index (i.e., it is >= the length of the list).
*/
pirate *list_access(pirate_list *pirates, size_t idx);

/*
Parameters: Pirate_list pointer 
Returns: None
Purpose: Sort the list of pirates based on the argument type given.
*/
void list_sort(pirate_list *pirates, char* type);

/*
Parameters: Pirate_list pointer
Returns: Size of Pirate List
Purpose: Return the number of pirates in the list. 
*/
size_t list_length(pirate_list *pirates);

/*
Parameters: Pirate_list pointer
Returns: None
Purpose: Free all memory associated with the pirate_list, but leaves the 
memory associated with the pirates in the list untouched 
 */
void list_destroy(pirate_list *pirates);

#endif
