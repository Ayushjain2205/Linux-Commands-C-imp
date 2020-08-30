#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#define LSIZ 200
#define RSIZ 100

int valid(char word[])
{ // checks if username is valid
    int index = 0;
    char ch;
    int flag = 0;
    while (word[index] != '\0')
    {
        ch = word[index];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            return flag;
        }
        index++;
    }
    return flag;
}

int validPath(char word[]) //checks if file path mentioned is correct
{
    int index = 0;
    char ch;
    int flag = 1;
    while (word[index] != '\0')
    {
        ch = word[index];
        if (ch == ',' || ch == ';' || ch == '?')
        {
            flag = 0;
            return flag;
        }
        index++;
    }
    return flag;
}

void runCheck(char filename[]) //runs the check for passwd and shadow files
{
    char line[RSIZ][LSIZ];
    char fname[20];
    FILE *fptr = NULL;
    int i = 0;
    int tot = 0;
    fptr = fopen(filename, "r");
    if (strcmp(filename, "shadow") == 0)
    {
        while (fgets(line[i], LSIZ, fptr))
        {
            line[i][strlen(line[i]) - 1] = '\0';
            i++;
        }
        tot = i;
        for (int j = 0; j < tot; j++)
        {
            char *token = strtok(line[j], ":");
            if (valid(token) == 0)
            {
                printf("%s ", token);
                printf(" is invalid \n");
            }
            while (token != NULL)
            {
                token = strtok(NULL, ":");
            }
        }
        printf("\n");
    }
    else if (strcmp(filename, "passwd") == 0)
    {
        i = 0;
        while (fgets(line[i], LSIZ, fptr))
        {
            line[i][strlen(line[i]) - 1] = '\0';
            i++;
        }
        tot = i;
        for (int j = 0; j < tot; j++)
        {
            char *token = strtok(line[j], ":");
            while (token != NULL)
            {
                token = strtok(NULL, ":");
                if (validPath(token) == 0)
                {
                    printf("invalid path\n");
                }
            }
        }
        printf("\n");
    }
}

void checkShadow() //checks for invalid enteries in shadow file
{
    char line[RSIZ][LSIZ];
    char fname[20];
    FILE *fptr = NULL;
    int i = 0;
    int tot = 0;
    fptr = fopen("shadow", "r");

    while (fgets(line[i], LSIZ, fptr))
    {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    for (int j = 0; j < tot; j++)
    {
        char *token = strtok(line[j], ":");
        if (valid(token) == 0)
        {
            printf("user \'%s\' ", token);
            printf(" has invalid identifier name \n");
        }
        while (token != NULL)
        {
            token = strtok(NULL, ":");
        }
    }
    printf("\n");
}

void checkPasswd() //checks for invalid enteries in passwd file
{
    char line[RSIZ][LSIZ];
    char fname[20];
    FILE *fptr = NULL;
    int i = 0;
    int tot = 0;
    fptr = fopen("passwd", "r");
    while (fgets(line[i], LSIZ, fptr))
    {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    for (int j = 0; j < tot; j++)
    {
        if (validPath(line[j]) == 0)
        {
            char *token = strtok(line[j], ":");
            printf("\'%s\' has invalid path\n", token);
        }
    }

    printf("\n");
}