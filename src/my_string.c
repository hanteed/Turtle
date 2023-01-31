#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include.h"

bool DEBUG=false;

int my_strlen(const char *str)
{
    int i = 0;
    while (*str++) i++;
    return (i);
}

char *my_strdup(const char * src)
{
    char *tmp;
    char *dest = malloc(my_strlen(src) * sizeof(char));
    tmp = dest;
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return tmp;
}

char *my_strpbrk(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    while (s1[i] != '\0')
    {
        while (s2[j] != '\0')
        {
            if (s1[i] == s2[j])
            {
                return &s1[i];
            }
            j++;
        }
        j = 0;
        i++;
    }
    return NULL;
}

char *my_strcpy(char * dest, const char * src)
{
    char * tmp;
    tmp = dest;
    while(*src != '\0')
    {
        *dest=*src;
        dest++;
        src++;
    }
    *dest = '\0';
    if(DEBUG)
    {
        printf("Copy String : %s\n",tmp);
    }
    return tmp;
}

char * my_strdupin(const char * src)
{
    char * tmp;
    char * dest = malloc(my_strlen(src) * sizeof(char));
    tmp = dest;
    while(*src != '\0')
    {
        *dest=*src;
        dest++;
        src++;
    }
    *dest='\0';
    return tmp;
}

char *my_strMin2Maj(char *str)
{
    while(*str != '\0')
    {
        if(*str >= 'a' && *str <= 'z')
        {
            *str = *str - 32;
        }
        str++;
    }
    return str;
}

char *my_strMaj2Min(char *str)
{
    while(*str != '\0')
    {
        if(*str >= 'A' && *str <= 'Z')
        {
            *str = *str + 32;
        }
        str++;
    }
    return str;
}
