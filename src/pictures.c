#include <stdlib.h>
#include <stdio.h>
#include "../include.h"

// Function to delete pictures in the media folder

void delete_pictures()
{
    system("rm -rf media");
}

void edit_image()
{
    char link_image[500];
    char command[512];
    char *old_name = malloc(sizeof(char ) * 15);
    char *new_name = malloc(sizeof(char ) * 15);

    old_image_name("word/_rels/document.xml.rels", old_name); // Returns the name of the image currently in the docx file
    printf("\n Enter the link of the picture you want to replace the original one with :\n >");
    scanf("%s", link_image);
    printf("\n");
    new_picture_name(link_image, new_name); // Returns the name of the image the user want to replace in the new dpcx file
    sprintf(command, "wget %s", link_image); // Download the new image
    system(command);
    sprintf(command, "mv %s media", new_name); // Moving the new picture in the media folder
    system(command);
    sprintf(command, "rm media/%s", old_name); // Deleting the old picture
    system(command);
    sprintf(command, "mv media/%s media/%s", new_name, old_name); // Renaming the new picture with the old picture name
    system(command);
}

char *new_picture_name(char *str, char *str2)
{
    int count = 0;
    int i = 0;
    int j = 0;
    int count2 = 0;
    char new_name[30];

    while (str[i] != '\0') {
        if (str[i] == '/')
            count += 1;
        i += 1;
    }
    i = 0;
    while (count2 != count) {
        if (str[i] == '/')
            count2 += 1;
        i += 1;
    }
    while (str[i] != '\0') {
        new_name[j] = str[i];
        j += 1;
        i += 1;
    }
    new_name[j] = '\0';
    my_strcpy(str2, new_name);
    return (str2);
}

int balise_image(char *str, int i)
{
    int j = 0;
    int count = 0;
    int stock = 0;
    char balise[12] = "ships/image";

    while (count < 10) {
        if (str[i] == balise[j]) {
            i++;
            j++;
        }
        if (str[i] != balise[j])
            return (-1);
        count += 1;
        if (count >= 8) {
            return(1);
        }
    }
}

char *old_image_name(char file[], char *new)
{
    FILE *stream = fopen(file, "r");
    char buffer[1024];
    char name[15];
    int j = 0;
    int i = 0;
    int count = 0;
    int balise = 0;

    while(fgets(buffer, 1024, stream)) {
        char *tmp = my_strdup(buffer);
        while (tmp[i] != '\0') {
            balise = balise_image(tmp, i);
            if (balise > 0) {
                i += 10;
                while (count != 2) {
                    if (tmp[i] == '/')
                        count += 1;
                    i += 1;
                }
                while (tmp[i] != '"') {
                    name[j] = tmp[i];
                    j += 1;
                    i += 1;
                }
                name[j] = '\0';
            }
            i += 1;
        }
        i = 0;
    }
    my_strcpy(new, name);
    return (new);
}
