#include <stdio.h>
#include "../include.h"

char *get_api_key(char *API_KEY)
{
    FILE *apistream = fopen(".setup", "r"); // Open the file in read mode
    char apibuffer[1024]; // Create a buffer to store the API key

    while (fgets(apibuffer, 1024, apistream)) { // Read the file line by line
        char *apitmp = my_strdupin(apibuffer); // Copy the line in a temporary variable
        my_strcpy(API_KEY,apitmp); // Copy the temporary variable in the API_KEY variable
        API_KEY[my_strlen(API_KEY) - 1] = '\0'; // Remove the newline character at the end of the API_KEY variable
    }
    return API_KEY; // Return the API_KEY variable
}
