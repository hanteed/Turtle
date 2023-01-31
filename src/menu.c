#include <stdlib.h>
#include <stdio.h>
#include "../include.h"

void display_menu()
{
    system("clear");
    printf("\n");
    titleascii();
    turtleascii();
    printf("\n\n");
    printf(" Choose an option from the list below :\n\n");
    printf(" 01 - Unzip the docx file\n");
    printf(" 02 - Analyse the file for threats\n");
    printf(" 03 - Fetch the file content\n");
    printf(" 04 - Fetch metadata from the file\n");
    printf(" 05 - Fetch data & metadata from the file\n");
    printf(" 06 - Edit the file's last modifier name\n");
    printf(" 07 - Edit the file's creator name\n");
    printf(" 08 - Edit the file's links\n");
    printf(" 09 - Edit the file's fonts\n");
    printf(" 10 - Edit the file's pictures\n");
    printf(" 11 - Delete the file's content\n");
    printf(" 12 - Delete the file's pictures\n");
    printf(" 13 - Zip the file & save changes\n\n");
    printf(" q  - Quit\n\n>");
}

int menu_redirection(int ac, char **av)
{
    char menu_value[256];
    printf("\n 1 - Go to the main menu\n q - Quit\n\n>");
    scanf("%s", menu_value);
    if(my_strlen(menu_value) > 1)
    {
        menu_redirection(ac, av);
    }
    if (menu_value[0] != '1' && menu_value[0] != 'q')
    {
        menu_redirection(ac, av);
    }
    else
    {
        if (menu_value[0] == '1')
        {
            menu_choice(ac, av);
        }
        else if (menu_value[0] == 'q')
        {
            return EXIT_SUCCESS;
        }
    }
}

int menu_choice(int ac, char **av)
{
    display_menu();
    int menu_value;
    char input[256];
    input[0] = '\0';

    scanf("%s", input);

    if(my_strlen(input) > 2 && input[0] == 'q')
    {
        system("clear");
        menu_choice(ac, av);
    }

    if (input[0] == 'q')
    {
        return EXIT_SUCCESS;
    }

    menu_value = atoi(input);
    if (menu_value < 1 || menu_value > 13)
    {
        system("clear");
        printf(" Please enter a valid value.\n");
        menu_choice(ac, av);
    }
    else
    {
        if (menu_value == 1)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t\t  • UNZIP •\t\n\n\n");
            turtleascii();
            unzip_file(av[1]);
            printf("\n Unzip done. \n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 2)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t\t • ANALYSIS •\t\n\n\n");
            turtleascii();
            find_malwares(ac, av);
            printf("\n Analysis done. \n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 3)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t\t • FETCH DATA •\t\n\n\n");
            turtleascii();
            parse_file_content("word/document.xml");
            parse_file_links("word/_rels/document.xml.rels");
            printf("\n Data extraction done. \n Files created in stock/\n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 4)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t      • FETCH METADATA •\t\n\n\n");
            turtleascii();
            parse_creator_name("docProps/core.xml");
            parse_modif_name("docProps/core.xml");
            parse_creation_date("docProps/core.xml");
            parse_modification_date("docProps/core.xml");
            printf("\n Metadata extraction done. \n Files created in stock/\n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 5)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t   • FETCH DATA & METADATA •\t\n\n\n");
            turtleascii();
            parse_file_content("word/document.xml");
            parse_file_links("word/_rels/document.xml.rels");
            parse_creator_name("docProps/core.xml");
            parse_modif_name("docProps/core.xml");
            parse_creation_date("docProps/core.xml");
            parse_modification_date("docProps/core.xml");
            printf("\n Data & Metadata extraction done. \n Files created in stock/\n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 6)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t    • EDIT MODIFIER NAME •\t\n\n\n");
            turtleascii();
            printf("\n");
            parse_modif_name("docProps/core.xml");
            edit_modif_name("docProps/core.xml");
            printf("\n Last modifier name edited. \n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 7)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t     • EDIT CREATOR NAME •\t\n\n\n");
            turtleascii();
            printf("\n");
            parse_creator_name("docProps/core.xml");
            edit_creator_name("docProps/core.xml");
            printf("\n Creator name edited. \n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 8)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t\t • EDIT LINKS •\t\n\n\n");
            turtleascii();
            edit_link("word/_rels/document.xml.rels");
            printf("\n Links edited. \n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 9)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t\t• EDIT FONTS •\t\n\n\n");
            turtleascii();
            edit_police_ascii("word/document.xml");
            printf("\n Fonts edited. \n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 10)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t\t• EDIT PICTURES •\t\n\n\n");
            turtleascii();
            printf("\n");
            edit_image();
            printf("\n Pictures edited. \n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 11)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t\t• DELETE CONTENT •\t\n\n\n");
            turtleascii();
            parse_file_content("word/document.xml");
            delete_content("word/document.xml");
            printf("\n Content deleted. \n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 12)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t\t• DELETE PICTURES •\t\n\n\n");
            turtleascii();
            delete_pictures();
            printf("\n Pictures deleted. \n\n");
            menu_redirection(ac,av);
        }
        if (menu_value == 13)
        {
            system("clear");
            printf("\n\n\n\n\n\t\t\t   • ZIP •\t\n\n\n");
            turtleascii();
            printf("\n\n");
            system("make zip");
            printf("\n");
            menu_redirection(ac,av);
        }
    }
    return EXIT_SUCCESS;
} 
