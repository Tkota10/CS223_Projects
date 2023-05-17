/*
Name of File: pirate_list.c
Creator: Tarun Kota
Class: CS223, HookBook1
Date: 03/11/23
Purpose: This file contains the implementation of an arraylist
that is used to store the pirates bring read into from the text file.
Here, we define functions on manipulating and using this arraylist to
carry out the functionality of our program. Note that I never use the contract
function in my implementation, which could case some discrepancy in my 
result and test cases.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pirate.h"
#include "pirate_list.h"

#define INITIAL_CAPACITY 25
#define RESIZE_FACTOR 2

struct implementation //pirate_list
{
    pirate **list_pirate; 
    size_t length;
    size_t capacity;
};

/* 
Parameters: None
Returns: A pointer to the new pirate_list
Purpose: It's used to initaliaze a new pirate list
and alloc enough memory for all the fields.
*/
pirate_list* list_create()
{
    pirate_list *pirates = malloc(sizeof(pirate_list));
    pirates->list_pirate = malloc(INITIAL_CAPACITY * sizeof(pirate*));
    pirates->length = 0;
    pirates->capacity = INITIAL_CAPACITY;
    return pirates;
}

/*
 Parameters: Pirate_list pointer and pirate pointer
 Returns: An index to the desirated pirate
 Purpose: Return the index of the pirate with the same name as p, 
 or a value greater than or equal to the length of the list 
 if there is no pirate in the list with a matching name.
 */
size_t list_index_of(pirate_list* pirates, pirate* p){
    for (int i = 0; i < pirates->length; i++)
    {
        if(strcmp(get_name(pirates->list_pirate[i]), get_name(p)) == 0)
        {
            return i;
        }
    }
    return pirates->length;
}

/*
Parameters: Pirate List pointer
Returns: None
Purpose: Dertimines based on the length and capacity of the arraylist,
if we should alloc more space.
*/
void list_expand_if_necessary(pirate_list* pirates)
{
    size_t new_capacity;
    if (pirates->length >= pirates->capacity) 
    {
        new_capacity = pirates->capacity * RESIZE_FACTOR;
        pirates->list_pirate = realloc(pirates->list_pirate, new_capacity * sizeof(pirate*));
        pirates->capacity = new_capacity;
        fprintf(stderr, "Expand to %zu\n", new_capacity);
    }

}

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
pirate *list_insert(pirate_list *pirates, pirate *p, size_t idx)
{
    list_expand_if_necessary(pirates);  
  
    if(list_index_of(pirates, p) == pirates->length)
    {

        for (int i = pirates->length; i > idx; i--)
        {
            pirates->list_pirate[i] = pirates->list_pirate[i-1];
        }
        pirates->list_pirate[idx] = p; 
        pirates->length++;
        return NULL;

    }
    else
    {
        return p;
    }
}

/*
Parameters: Pirate List pointer
Returns: None
Purpose: Dertimines based on the length and capacity of the arraylist,
if we contract the space we are using.
*/
void list_contract_if_necessary(pirate_list *pirates)
{
    if (pirates->length < pirates->capacity / RESIZE_FACTOR) {
        size_t new_capacity = pirates->capacity / RESIZE_FACTOR;
        pirates->capacity = new_capacity;
        pirates->list_pirate = realloc(pirates->list_pirate, 
                                new_capacity * sizeof(pirate*)); 
        fprintf(stderr, "Contract to %zu\n", new_capacity);
    }    
}

/*
Parameters: Pirate_list pointer and pirate pointer
Returns: pirate pointer
Purpose: Remove the pirate from the list with the same name as p, 
and return a pointer to it. If there is no pirate in the list with the same 
name as p, return NULL
 */
pirate *list_remove(pirate_list *pirates, pirate *p)
{
    list_contract_if_necessary(pirates); 
    
    if (list_index_of(pirates, p) == pirates->length)
    {
        return NULL;
    }
    else
    {
        for (int i = list_index_of(pirates,p); i < pirates->length; i++)
        {
            pirates->list_pirate[i] = pirates->list_pirate[i-1];
        }
        pirates->length--;
        return p;
    }
}

/*
Parameters: Pirate_list pointer and index
Returns: pirate pointer
Purpose: Return a pointer to the pirate pointed to by index idx in the list, 
or NULL if idx is not a valid index (i.e., it is >= the length of the list).
*/
pirate *list_access(pirate_list *pirates, size_t idx)
{
    if (idx >= pirates->length) 
    { 
        return NULL; 
    } 
    else 
    {
        return (pirates->list_pirate[idx]); 
    }
}

/*
Parameters: Pirate_list pointer 
Returns: None
Purpose: Sort the list of pirates in alphabetical order by name
*/
void list_sort(pirate_list *pirates)

{
    int j;
    pirate *temp;
    for(int i = 1; i < pirates->length; i++)
    {
        j = i - 1;
        temp = pirates->list_pirate[i];

        while ((j >= 0) && 
                (strcmp(get_name(pirates->list_pirate[j]), get_name(temp)) > 0)) 
        {
            pirates->list_pirate[j + 1] = pirates->list_pirate[j];
            j--;
        }
        pirates->list_pirate[j + 1] = temp;
    }
}

/*
Parameters: Pirate_list pointer
Returns: None
Purpose: Return the number of pirates in the list. 
*/
size_t list_length(pirate_list *pirates)
{
    return pirates->length;
}

/*
Parameters: Pirate_list pointer
Returns: None
Purpose: Free all memory associated with the pirate_list, but leaves the 
memory associated with the pirates in the list untouched 
 */
void list_destroy(pirate_list *pirates)
{
    free(pirates->list_pirate);
    free(pirates);
}





