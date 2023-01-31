#include <stdlib.h>
#include <stdio.h>
#include "../include.h"

// Function that finds the tag of the creator name

int find_creator_name(char *str)
{
    int i = 0;
    int j = 0;
    char balise[11] = "creator"; 

    while (str[i] != '\0') {
        while (str[i] == balise[j]) {
            if (j == 6)
                return(i + 2); // Returns i + 2 to directly go to where we have to edit the name
            i += 1;
            j += 1;
        }
        j = 0;
        i += 1;
    }
    return (0);
}

// Function that finds the tag of the last modificator name

int find_modif_name(char *str)
{
    int i = 0;
    int j = 0;
    char balise[11] = "ModifiedBy";

    while (str[i] != '\0') {
        while (str[i] == balise[j]) {
            if (j == 9)
                return(i + 2); // Returns i + 2 to directly go to where we have to edit the name
            i += 1;
            j += 1;
        }
        j = 0;
        i += 1;
    }
    return (0);
}

// Function to stock the creator name in a stock file

int parse_creator_name(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *stock_name = fopen("stock/stock_creator_name.txt", "w+"); // Creating the stock file
    char buffer[1024];
    int i = 0;
    int value = 0;

    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        value = find_creator_name(tmp); // Value = index of the name in the tmp string
        if (value > 0) {
            while (tmp[value] != '<') {
                fprintf(stock_name, "%c", tmp[value]); // Writing the name in the stock file
                value += 1;
            }
        }
        i += 1;
    }
}

// Function to stock the last modificator name in a stock file

int parse_modif_name(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *stock_modif_name = fopen("stock/stock_modif_name.txt", "w+"); // Creating the stock file
    char buffer[1024];
    int i = 0;
    int value = 0;

    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        value = find_modif_name(tmp); // Value = indice of the name in the tmp string
        if (value > 0) {
            while (tmp[value] != '<') {
                fprintf(stock_modif_name, "%c", tmp[value]); // Writing the name in the stock file
                value += 1;
            }
        }
        i = 0;
    }
}

// Function that returns 1 if we are in the modificator name tag or -1 if we are not

int find_edit_modif_name(char *str, int i)
{
    int j = 0;
    int count = 0;
    char balise[18] = "<lastModifiedBy>";

    while (count < 16) {
        if (str[i] == balise[j]) {
            i++;
            j++;
        }
        if (str[i] != balise[j])
            return (-1);
        count += 1;
        if (count >= 15) {
            return(1);
        }
    }
}

// Function that returns 1 if we are in the creator name balise or -1 if we are not

int find_edit_creator_name(char *str, int i)
{
    int j = 0;
    int count = 0;
    char balise[18] = "<dc:creator>";

    while (count < 12) {
        if (str[i] == balise[j]) {
            i++;
            j++;
        }
        if (str[i] != balise[j])
            return (-1);
        count += 1;
        if (count >= 11) {
            return(1);
        }
    }
}

// Function to edit the creator name

int edit_creator_name(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *usurpation = fopen("docProps/core-2.xml", "w+"); // Create the file where we are going to make modifications
    char nom[30] = "NOM";
    char prenom[30] = "prenom";
    char buffer[1024];
    int i = 0;
    int balise = 0;

    printf("\n What surname do you want to use ?\n >");
    scanf("%s", nom);
    printf("\n What firstname do you want to use ?\n >");
    scanf("%s", prenom);
    my_strMin2Maj(nom);
    my_strMaj2Min(prenom);
    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        while (tmp[i] != '\0') {
            balise = find_edit_creator_name(tmp, i);
            if (balise > 0) {
                i += 1;
                while (tmp[i] != '<') // Loops to move to the content we want to replace
                    i += 1;
                fprintf(usurpation, "<dc:creator>%s %s", nom, prenom); // Editing the name in the balise
            }
            fprintf(usurpation, "%c", tmp[i]); // Copy the real file in the fake file created at the beginning
            i += 1;
        }
        i = 0;
    }
    system("rm docProps/core.xml");
    system("mv docProps/core-2.xml docProps/core.xml");
}

// Function that edits the last modificator name

int edit_modif_name(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *usurpation = fopen("docProps/core-2.xml", "w+"); // Creates the file where we are going to make modifications
    char nom[30] = "NOM";
    char prenom[30] = "prenom";
    char buffer[1024];
    int i = 0;
    int balise = 0;

    printf("\n What surname do you want to use ?\n >");
    scanf("%s", nom);
    printf("\n What firstname do you want to use ?\n >");
    scanf("%s", prenom);
    my_strMin2Maj(nom);
    my_strMaj2Min(prenom);
    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        while (tmp[i] != '\0') {
            balise = find_edit_modif_name(tmp, i);
            if (balise > 0) {
                i += 1;
                while (tmp[i] != '<') // Loops to move to the content we want to replace
                    i += 1;
                fprintf(usurpation, "<lastModifiedBy>%s %s", nom, prenom); // Editing the name in the balise
            }
            fprintf(usurpation, "%c", tmp[i]); // Copying the real file in the fake file created at the beginning
            i += 1;
        }
        i = 0;
    }
    system("rm docProps/core.xml"); // Deleting the real file
    system("mv docProps/core-2.xml docProps/core.xml"); // Renaming the fake file with the real name
}
