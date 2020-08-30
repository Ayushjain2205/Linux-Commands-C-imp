#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ROWS 200
#define COLUMNS 100

void read_top(char *filename, int lines)
{

    int total = 0;
    int count = 0;
    char line[ROWS][COLUMNS];
    FILE *fptr = NULL;
    fptr = fopen(filename, "r");
    while (fgets(line[count], COLUMNS, fptr))
    {
        line[count][strlen(line[count]) - 1] = '\0';
        count++;
    }
    total = count;
    for (int i = 0; i < lines; i++)
    {
        printf("%s\n", line[i]);
    }
}

void read_bottom(char *filename, int lines)
{

    int total = 0;
    int count = 0;
    char line[ROWS][COLUMNS];
    FILE *fptr = NULL;
    fptr = fopen(filename, "r");
    while (fgets(line[count], COLUMNS, fptr))
    {
        line[count][strlen(line[count]) - 1] = '\0';
        count++;
    }
    total = count;
    for (int i = total - lines; i < total; i++)
    {
        printf("%s\n", line[i]);
    }
}