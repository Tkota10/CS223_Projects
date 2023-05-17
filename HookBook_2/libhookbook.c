/*
Name of File: libhookbook.c
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
void get_pirates(pirate_list* p, FILE *f) {
    pirate *newpirate = NULL;
    char* label = calloc(65, sizeof(char));
    char* value = calloc(65, sizeof(char));
    int result = 0;
    while ((result = fscanf(f, "%65[^:]:%65[^\n]\n", label, value)) != EOF)
    {
        if(!strcmp(label, "name")) 
        {
            if (newpirate != NULL)
            {
                list_insert(p, newpirate, list_length(p));
            }
            newpirate = pirate_create();
            change_name(newpirate, value);
        }
        else if (!strcmp(label, "port"))
        {
            change_port(newpirate, value);
        }
        else if (!strcmp(label, "title"))
        {
            change_title(newpirate, value);
        }
        else if (!strcmp(label, "treasure"))
        {
            int num = atoi(value);
            change_treasure(newpirate, num);
        }
        else if (!strcmp(label, "vessel"))
        {
            change_vessel(newpirate, value);
        }
        else if(!strcmp(label, "skill"))
        {
            insert_skill(newpirate, value);
        }
    }
    if (newpirate != NULL)
    {
        list_insert(p, newpirate, list_length(p));
    }
    free(label);
    free(value);
}

/*
 Parameters: Pirate_list pointer and file pointer
 Returns: None
 Purpose: It reads in a pirate/captains pairing text file and assigns captains
 to pirates!
 */
void get_captains(pirate_list* pirates, FILE *f)
{
    char* label = calloc(65, sizeof(char));
    char* value = calloc(65, sizeof(char));
    while (fscanf(f, "%65[^/]/%65[^\n]\n", label, value) != EOF) 
    {
        pirate *subordindate = pirate_create();
        change_name(subordindate, label);
        pirate *worker = list_access(pirates, list_index_of(pirates, subordindate));

        if ((list_index_of(pirates, subordindate) == list_length(pirates)))
        {
            continue;
        }

        pirate *captain = pirate_create();
        change_name(captain, value);
        pirate *leader = list_access(pirates, list_index_of(pirates, captain));

        if (!(list_index_of(pirates, captain) == list_length(pirates)))
        {
            assign_captain(worker, leader);
        }
        pirate_destroy(subordindate);
        pirate_destroy(captain);
    }
    free(label);
    free(value);

}

/*
 Parameters: Pirate_list pointer and index
 Returns: None
 Purpose: It prints all the skills in the correct order and format. 
 */
void print_skills(pirate_list *pirates, int idx){
    skills_sort(get_skills(list_access(pirates, idx)));
    if (skillslist_access(get_skills(list_access(pirates, idx)), 0) == NULL) 
    {
        printf("    Skills: (None)");
    }
    else 
    {
        printf("    Skills: %s *", skillslist_access(get_skills(list_access(pirates, idx)), 0));
        int j = 1;
        while (j < get_list_length(get_skills(list_access(pirates, idx)))) 
        {
            if (!strcmp(skillslist_access(get_skills(list_access(pirates, idx)), j), 
                skillslist_access(get_skills(list_access(pirates, idx)), j-1))) {
                printf("*");
            }
            else 
            {
                printf("\n");
                printf("            %s *", skillslist_access(get_skills(list_access(pirates, idx)), j));
            }
            j++;
        }
    }
}

/*
 Parameters: Pirate_list pointer and index
 Returns: None
 Purpose: Building on the print skills function it prints out the asteriks's on 
 the side of all the names. It does this by searching for duplicates and adding 
 as asterik everytime a duplicate is found.
 */
void order_skills(pirate_list *pirates, int idx){
    printf("    Skills: %s *", skillslist_access(get_skills(list_access(pirates, idx)), 0));
    int j = 1;
    while (j < get_list_length(get_skills(list_access(pirates, idx)))) 
    {
        if (!strcmp(skillslist_access(get_skills(list_access(pirates, idx)), j), 
            skillslist_access(get_skills(list_access(pirates, idx)), j-1))) 
        {
            printf("*");
        }
        else 
        {
            printf("\n");
            printf("            %s *", skillslist_access(get_skills(list_access(pirates, idx)), j));
        }
            j++;
    }

}

/*
 Parameters: Pirate_list pointer 
 Returns: None
 Purpose: Prints out all the profile information of a pirate list based on the 
 format given by the specification.
 */
int print_information(pirate_list *pirates){
    for (int i = 0; i < list_length(pirates); i++) 
    {
        printf("Pirate: %s\n", get_name(list_access(pirates, i)));

        if (get_title(list_access(pirates, i)) != NULL) 
        {
            printf("%*sTitle: %s\n", 4, "", get_title(list_access(pirates, i)));
        }

        if (get_captain(list_access(pirates, i)) != NULL) 
        {
            printf("%*sCaptain: %s\n", 4, "", get_name(get_captain(list_access(pirates, i))));
            printf("        Captain's Title: %s\n", get_title(get_captain(list_access(pirates, i))));
            printf("        Captain's Favorite Port of Call: %s\n", get_port(get_captain(list_access(pirates, i))));
        }
        else 
        {
            printf("    Captain: (None)\n");
        }

        printf("%*sVessel: %s\n", 4, "", get_vessel(list_access(pirates, i)));

        printf("%*sTreasure: %d\n", 4, "", get_treasures(list_access(pirates, i)));



        printf("%*sFavorite Port of Call: %s\n", 4, "", get_port(list_access(pirates, i)));

        print_skills(pirates, i);

        printf("\n");
        printf("\n");
    
    }
    return 0;

}

/*
 Parameters: Pirate_list pointer 
 Returns: None
 Purpose: This frees all the memory allocated during the entire runtime of this
 program ensuring that all heap blocks were freed and memory was effectively
 managed.
 */
int destroy_everything(pirate_list *pirates)
{
    for (int i = 0; i < list_length(pirates); i++) 
    {
        pirate_destroy(list_access(pirates, i));
    }
    list_destroy(pirates);
    return 0;
}





