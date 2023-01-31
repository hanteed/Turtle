#include <stdlib.h>
#include <stdio.h>
#include "../include.h"

// Function that writes the content of the DOCX in the stock file

void stock_content(char *str)
{
    FILE *stock_content = fopen("stock/stock_content.txt", "w+");
    int i = 0;
    int count = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == '<' && str[i + 1] == 'w' && str[i + 2] == ':' && str[i + 3] == 't' && str[i + 4] == '>') {
            count = 1;
            i += 5;
        }
        if (str[i] == '<' && str[i + 1] == '/'  && str[i + 2] == 'w' && str[i + 3] == ':' && str[i + 4] == 't' && str[i + 5] == '>') {
            count = 0;
        }
        if (count > 0) {
            fprintf(stock_content, "%c", str[i]);
            j += 1;
        }
        i += 1;
    }
}

// Function that parses the "document.xml" file to find the content

int parse_file_content(char file[])
{
    FILE *stream = fopen(file, "r"); // open the file
    char buffer[1024]; // buffer to read the file
    int i = 0;

    while(fgets(buffer, 1024, stream)) { // read the file line by line
        char *tmp = my_strdup(buffer); // copy the line in a string
        stock_content(tmp); // call the function to stock the content
        i += 1;
    }
}

// Function that returns 1 if we are in a content tag or -1 if we are not

int find_balise_content(char *str, int i)
{
    int j = 0;
    int count = 0;
    char balise[7] = "<w:t>"; // tag to find

    while (count < 5) {
        if (str[i] == balise[j]) { // if the character is the same as the tag
            i++;
            j++;
        }
        if (str[i] != balise[j]) // if the character is not the same as the tag
            return (-1);
        count += 1;
        if (count >= 4) {
            return (1);
        }
    }
}

// Function that parses the "document.xml" file to edit the content

int delete_content(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *usurpation = fopen("word/document-2.xml", "w+"); // Creates the file where we are going to make modifications
    char buffer[1024];
    int i = 0;
    int balise = 0;

    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        while (tmp[i] != '\0') {
            balise = find_balise_content(tmp, i);
            if (balise > 0) {
                i += 1;
                while (tmp[i] != '<')
                    i += 1; // Loops to move to the content we want to replace
                fprintf(usurpation, "<w:t>-"); // Replaces the content by a '-' to delete all the content
            }
            fprintf(usurpation, "%c", tmp[i]); // Copies the real file in the fake file created at the beginning
            i += 1;
        }
        i = 0;
    }
    system("rm word/document.xml"); // Deleting the real file
    system("mv word/document-2.xml word/document.xml"); // Renaming the fake file with the real name
}
