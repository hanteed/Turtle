#include <stdlib.h>
#include <stdio.h>
#include "../include.h"
#include <unistd.h>

int check_response_code(char * id, int timeout)
{
    char API_KEY[256];
    char command[512];
    char response[64];
    int responsecode = 0;
    int time_elapsed = 0;

    get_api_key(API_KEY);
    printf("\n\n Analysis starting, please wait.\n\n");
    while(responsecode != 1) {
        sprintf(command, "curl -s -X GET 'https://www.virustotal.com/vtapi/v2/file/report?apikey=%s&resource=%s' | grep -oP '\"response_code\": \\K\\d+' > response_code.txt", API_KEY, id); // Sending the request to the VirusTotal API
        system(command); // Executing the command
        FILE* response_file = fopen("response_code.txt", "r"); // Creating the reponse_code file to check if the API is still analysing the file sent
        if (response_file == NULL) {
            printf("Error opening file response_code.txt\n"); // Error message if the file can't be opened
            return EXIT_FAILURE;
        }
        fscanf(response_file, "%s", response);
        responsecode = atoi(response); // Converting the reponse code to an integer
        fclose(response_file); // Closing the file
        if (responsecode == -2) {
            printf("Waiting for the analysis to be finished...");
            sleep(5);
            time_elapsed += 5;
            if (time_elapsed >= timeout) {
                printf("Waiting time exceeded, analysis may not be finished.\n");
                return -2;
            }
        }
    }
    return responsecode; // Returns the reponsecode
}
