#include <stdlib.h>
#include <stdio.h>
#include "../include.h"

int unzip_file(char *str)
{
    char command[1024];
    sprintf(command, "unzip -q -o %s", str); // -q: quiet, -o: overwrite
    if (system(command) != 0)
    {
        printf("Error: Failed to unzip the docx file");
    }
    FILE *file = fopen("word/document.xml", "r"); // Open the file in read mode
    char buffer[1024]; // Create a buffer to store the API key
    while (fgets(buffer, sizeof(buffer), file)) { // Read the file line by line
        if (my_strpbrk(buffer, "<w:t>")) // If the line contains the string "<w:t>"
        {
            char text[1024]; // Create a buffer to store the text
            sscanf(buffer, "<w:t>%s", text); // Scan the line and store the text in the text buffer
        }
    }
    fclose(file); // Close the file
    return 0;
}
