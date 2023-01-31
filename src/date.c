#include <stdio.h>
#include "../include.h"

// Function that finds the tag of the creation date

int find_creation_date(char *str)
{
    int i = 0;
    int j = 0;
    char balise[18] = "<dcterms:created";

    while (str[i] != '\0') {
        while (str[i] == balise[j]) {
            if (j == 15)
                return(i + 28); // Returns i + 28 to directly go to where we have to edit the date
            i += 1;
            j += 1;
        }
        j = 0;
        i += 1;
    }
    return (0);
}

// Function to find the tag of the modification date

int find_modification_date(char *str)
{
    int i = 0;
    int j = 0;
    char balise[18] = "<dcterms:modified";

    while (str[i] != '\0') {
        while (str[i] == balise[j]) {
            if (j == 16)
                return(i + 28); // Returns i + 28 to directly go to where we have to edit the date
            i += 1;
            j += 1;
        }
        j = 0;
        i += 1;
    }
    return (0);
}

// Function that stocks the creation date in a stock file

int parse_creation_date(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *stock_creation_date = fopen("stock/stock_creation_date.txt", "w+"); // Creates the stock file
    char buffer[1024];
    int i = 0;
    int value = 0;

    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        value = find_creation_date(tmp); // Value = indice of the date in the tmp string
        if (value > 0) {
            while (tmp[value] != '.') {
                fprintf(stock_creation_date, "%c", tmp[value]); // Writes the date in the stock file
                value += 1;
            }
        }
        i += 1;
    }
}

// Function that stocks the modification date in a stock file

int parse_modification_date(char file[])
{
    FILE *stream = fopen(file, "r");
    FILE *stock_modification_date = fopen("stock/stock_modif_date.txt", "w+"); // Creates the stock file
    char buffer[1024];
    int i = 0;
    int value = 0;

    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        value = find_modification_date(tmp); // Value = indice of the date in the tmp string
        if (value > 0) {
            while (tmp[value] != '.') {
                fprintf(stock_modification_date, "%c", tmp[value]); // Writes the date in the stock file
                value += 1;
            }
        }
        i += 1;
    }
}
