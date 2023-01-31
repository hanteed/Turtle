#include <stdlib.h>
#include <stdio.h>
#include "../include.h"

int go_to_link(char *str)
{
    int i = 0;
    int j = 0;
    int stock = 0;
    char balise[11] = "hyperlink";

    while (str[i] != '\0') {
        while (str[i] == balise[j]) {
            if (j == 8)
                return(i + 11);
            i += 1;
            j += 1;
        }
        j = 0;
        i += 1;
    }
    return (0);
}

int parse_file_links(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *stock_links = fopen("stock/stock_links.txt", "w+");
    char buffer[1024];
    int i = 0;
    int value = 0;

    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        value = go_to_link(tmp);
        if (value > 0) {
            while (tmp[value] != '"') {
                fprintf(stock_links, "%c", tmp[value]);
                value += 1;
            }
        }
        i += 1;
    }
}

// Function that returns 1 if we are in a hyperlink balise or -1 if we are not

int find_link_balise(char *str, int i)
{
    int j = 0;
    int count = 0;
    char balise[10] = "hyperlink";

    while (count < 8) {
        if (str[i] == balise[j]) {
            i++;
            j++;
        }
        if (str[i] != balise[j])
            return (-1);
        count += 1;
        if (count >= 7) {
            return(1);
        }
    }
}

// Function that parses the "document.xml" file to edit the link

int edit_link(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *usurpation = fopen("word/_rels/document-2.xml.rels", "w+"); // Creates the file where we are going to make modifications
    char buffer[1024];
    char link[200];
    int i = 0;
    int count = 0;
    int balise = 0;

    printf("\n Enter the link you want to replace the original one with :\n >");
    scanf("%s", link);
    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        while (tmp[i] != '\0') {
            balise = find_link_balise(tmp, i);
            if (balise > 0) {
                i += 1;
                while (count != 3) {
                    if (tmp[i] == '\"')  // Loops to move after the tag and avoid printing it two times
                        count += 1;
                    i += 1;
                }
                fprintf(usurpation, "hyperlink\" Target=\"%s\"", link); // Replacing with the new link
            }
            fprintf(usurpation, "%c", tmp[i]); // Writing the source file content in the new xml file
            i += 1;
        }
        i = 0;
    }
    system("rm word/_rels/document.xml.rels"); // Deleting the real file
    system("mv word/_rels/document-2.xml.rels word/_rels/document.xml.rels"); // Renaming the fakefile with the real name
}
