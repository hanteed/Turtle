#include <stdlib.h>
#include <stdio.h>
#include "../include.h"


// This function returns 1 if we are in a content tag or -1 if we are not

int find_balise_ascii(char *str, int i)

{
    int j = 0;
    int count = 0;
    int stock = 0;
    char balise[11] = "ascii";

    while (count < 5) {
        if (str[i] == balise[j]) {
            i++;
            j++;
        }
        if (str[i] != balise[j])
            return (-1);
        count += 1;
        if (count >= 4) {
            return(1);
        }
    }
}

int edit_police_ascii(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *usurpation = fopen("word/document-2.xml", "w+");  // Creates the file where we are gonna make modifications
    char buffer[1024];
    int i = 0;
    int count = 0;
    int balise = 0;

    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        while (tmp[i] != '\0') {
            balise = find_balise_ascii(tmp, i);
            if (balise > 0) {
                i += 1;
                while (count != 2) {
                    if (tmp[i] == '\"')
                        count += 1; // Loops to move after the balise and avoid printing it two times
                    i += 1;
                }
                fprintf(usurpation, "ascii=\"D050000L\""); // Writing the new font
            }
            fprintf(usurpation, "%c", tmp[i]);
            count = 0;
            i += 1;
        }
        i = 0;
    }
    system("rm word/document.xml"); // Deleting the real file
    system("mv word/document-2.xml word/document.xml"); // Renaming the fake file with the real name
}

// This function returns 1 if we are in a hAnsi tag or -1 if we are not

int find_balise_hAnsi(char *str, int i)
{
    int j = 0;
    int count = 0;
    char balise[11] = "hAnsi";

    while (count < 5) {
        if (str[i] == balise[j]) {
            i++;
            j++;
        }
        if (str[i] != balise[j])
            return (-1);
        count += 1;
        if (count >= 4) {
            return(1);
        }
    }
}

int edit_police_hAnsi(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *usurpation = fopen("word/document-2.xml", "w+"); // Creates the file where we are going to make modifications
    char buffer[1024];
    int i = 0;
    int count = 0;
    int balise = 0;

    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        while (tmp[i] != '\0') {
            balise = find_balise_hAnsi(tmp, i);
            if (balise > 0) {
                i += 1;
                while (count != 2) {
                    if (tmp[i] == '\"') // Loops to move after the tag and avoid printing it two times
                        count += 1;
                    i += 1;
                }
                fprintf(usurpation, "hAnsi=\"D050000L\"");// Writing the new font
            }
            fprintf(usurpation, "%c", tmp[i]);
            count = 0;
            i += 1;
        }
        i = 0;
    }
    system("rm word/document.xml");// Deleting the real file
    system("mv word/document-2.xml word/document.xml");// Renaming the fake file with the real name
}
