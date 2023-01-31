#include <stdlib.h>
#include <stdio.h>
#include "../include.h"

char *get_file_id(char *id, char *API_KEY, char **av)
{
    char command[512];
    sprintf(command, "curl -s -X POST -F 'file=@%s' https://www.virustotal.com/vtapi/v2/file/scan --form apikey=%s | grep -oP '\"resource\": \"([^\"]*)\"' | cut -d ':' -f 2 | tr -d ' \" ' > id.txt", av[1], API_KEY); // Sending the request to the VirusTotal API to get the file ID
    system(command); // Executing the command

    FILE *stream = fopen("id.txt", "r"); // Creating the id file to get the file ID
    char buffer[1024]; // Buffer to store the file ID
    while (fgets(buffer, 1024, stream)) // Reading the file line by line
    {
        char* tmp = my_strdupin(buffer); // Copying the line in a temporary variable
        my_strcpy(id,tmp); // Copying the temporary variable in the id variable
        id[my_strlen(id) - 1] = '\0'; // Removing the newline character at the end of the id variable
    }
}
