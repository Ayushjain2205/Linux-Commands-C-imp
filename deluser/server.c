#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 200
#define COLUMNS 100

void deleted(char user[],int flag){ //to print the deleted message for a file
    if(flag==1){
        printf("\'%s\' user deleted successfully\n",user);
    }
    else{
        printf("\'%s\' user not found\n",user);
    }
}

void delete(char user[],char *filename){
    char line[ROWS][COLUMNS]; //to store all the lines in an 2-d array
    char fname[20];

    //initialising  file pointers
    FILE *fptr = NULL; 
    FILE *fptr_o=NULL;
    
    //counting and flaag variables
    int count = 0;
    int total = 0;
    int flag=0;

    //opening files
    fptr = fopen(filename, "r");
    fptr_o=fopen("temp","w");

    //putting all the data off a file into a 2-d array
    while (fgets(line[count], COLUMNS, fptr))
    {
        line[count][strlen(line[count]) - 1] = '\0';
        count++;
    }
    total = count;

    //traversing through the data
    for (int counter = 0; counter < total; counter++)
    {   
        char line_o[200];
        strcpy(line_o,line[counter]);

        char *token = strtok(line[counter], ":");
        if (strcmp(token,user)==0) //if the user matches with user to be deleted line is skipped
        {  
            flag=1;
            continue;         
        }
        
        else{ //else line is opied into the file
            fputs(line_o,fptr_o);
            fputs("\n",fptr_o);
        }
       
    }
    fclose(fptr);
    fclose(fptr_o);

    //removing and renaming files
    remove(filename);
    rename("temp", filename);

     //displaying the final user deleted message once
    if(strcmp(filename,"passwd")==0){
         deleted(user,flag);
    }
   
}