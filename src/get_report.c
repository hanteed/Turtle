#include <stdlib.h>
#include <stdio.h>
#include "../include.h"

int get_report(char * id)
{
    char API_KEY[256];
    char command[512];
    char positives[64];
    int positivesint = 0;

    get_api_key(API_KEY); // Getting the API key in the file
    sprintf(command,"curl -s -X GET 'https://www.virustotal.com/vtapi/v2/file/report?apikey=%s&resource=%s' | grep -oP '\"positives\": \\K\\d+' > positives.txt",API_KEY, id);
    system(command); // Executing the command
    FILE *positives_file = fopen("positives.txt", "r"); // Creating the positives file to get the number of positives
    if (positives_file == NULL)
    {
        printf("Error while opening file positives.txt\n"); // Error message if the file can't be opened
        return EXIT_FAILURE;
    }
    fscanf(positives_file, "%s", positives); // Reading the file line by line
    positivesint = atoi(positives); // Converting the positives to an integer
    fclose(positives_file); // Closing the file
    return positivesint; // Returns the positivesint

}
