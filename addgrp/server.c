#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int id;
char *password;
char *name;
char *usersList;

void encrypt(char password[], int key) //simple encryption for password 
{
    unsigned int i;
    for (i = 0; i < strlen(password); ++i)
    {
        password[i] = password[i] - key;
    }
}

void getData(char *first, char *second, char *third, char *users) //handles data coming from comman line args
{
    char *temp;
    temp = first;
    id = atoi(temp);
    password = second;
    name = third;
    usersList = users;
    for (int i = 0; i < strlen(usersList); i++)
    {
        if (usersList[i] == ',')
        {
            usersList[i] = ':';
        }
    }
}
int check(char *first, char *second, char *third)//checks if args are valid
{
    if (strcmp(first, "-gid") == 0 && strcmp(second, "-p") == 0 && strcmp(third, "-n") == 0)
    {
        return 1;
    }
    else
        return 0;
}

void putData()//puts the data in the group and gshadow file
{
    FILE *fptr1,*fptr2;
    fptr1 = fopen("group", "a");
    fptr2 = fopen("gshadow", "a");
    encrypt(password, 10);
    fprintf(fptr1, "%s:x:%d:%s\n", name, id, usersList);
    fprintf(fptr2, "%s:%s:%s\n", name, password, usersList);
}
