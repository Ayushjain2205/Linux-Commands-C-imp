#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"header.h"
#define ROWS 200
#define COLUMNS 100

int main(int argc, char *argv[])
{
    int fileNum = 0;
    int header = 0;
    int top = 0;
    int bottom = 0;
    int top_num=0;
    int bottom_num=0;
    
    if(argc<5){
        printf("Too less arguments try again!!\n");
    }

    if(strcmp(argv[1], "-q") != 0 && strcmp(argv[1], "-h") != 0 && strcmp(argv[1], "-t") != 0 ){
        printf("Enter top or bottom ! try again!! \n");
    }

    if (strcmp(argv[1], "-q") == 0)
    {
        header = 1;
        if (strcmp(argv[2], "-h") == 0 && strcmp(argv[4], "-t") == 0)
        {   fileNum=argc-6;
            top = 1;
            bottom = 1;
            top_num=atoi(argv[3]);
            bottom_num=atoi(argv[5]);
        }
        if (strcmp(argv[2], "-t") == 0)
        {   fileNum=argc-4;
            top = 0;
            bottom = 1;
            bottom_num=atoi(argv[3]);
        }
        if (strcmp(argv[2], "-h") == 0 && strcmp(argv[4], "-t") != 0)
        {   fileNum=argc-4;
            top = 1;
            bottom = 0;
            top_num=atoi(argv[3]);
        }

    }
    else if (strcmp(argv[1], "-q") != 0)
    {
        header = 0;
        if (strcmp(argv[1], "-h") == 0 && strcmp(argv[3], "-t") == 0)
        {   fileNum=argc-5;
            top = 1;
            bottom = 1;
            top_num=atoi(argv[2]);
            bottom_num=atoi(argv[4]);
        }
        if (strcmp(argv[1], "-t") == 0)
        {   fileNum=argc-3;
            top = 0;
            bottom = 1;
            bottom_num=atoi(argv[2]);
        }
        if (strcmp(argv[1], "-h") == 0 && strcmp(argv[3], "-t") != 0)
        {   fileNum=argc-3;
            top = 1;
            bottom = 0;
            top_num=atoi(argv[2]);
        }

    }    
    else{
        printf("invalid number of arguments \n");
    }
    
    for (int count = (argc - (fileNum)); count < argc; count++)
    {   if(header==1){
        printf("------%s-------\n",argv[count]);
        }
        if(top==1){
            read_top(argv[count],top_num);
        }
        if (bottom==1)
        {
            read_bottom(argv[count],bottom_num);
        }
        
       
    }
}
