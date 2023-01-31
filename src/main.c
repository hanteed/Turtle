#include <stdlib.h>
#include <stdio.h>
#include "../include.h"

int main(int ac, char **av)
{
    char command[256];

    if (ac != 2) {
        printf("Error, please enter the path to the file to use after the command : ./Turtle /path/to/the/file.docx\n");
        return (84);
    } else {
        sprintf(command,"cp %s Save/save.docx",av[1]);
        system(command);
        unzip_file(av[1]);
        menu_choice(ac, av);
    }
    
    return EXIT_SUCCESS;
}
