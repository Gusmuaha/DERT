/* ====================================
File name: task4.c (or cpp)
Date: 2019-mm-dd
Group Number:17
Members that contributed:
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar
Member not present at demonstration time: 

Demonstration code: [22088]       
====================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----Typedefs -------
typedef struct {
    char firstname[20];
    char famnamne[20];
    char pers_number[13]; // yyyymmddnnnc
}PERSON;

char * filename = "Test.bin";
static int count = 0;

// Function declaration (to be extend)
PERSON input_record( void); // Reads in a person record.
void write_new_file( PERSON *inrecord); //Creats a file and write a first record
void printfile(void); // print out all persons in the file
void search_by_firstname( char *name);// print out person if in list
void append_file(PERSON *inrecord);// appends a new person to the file

int main( void){
    PERSON ppost;
    int ch;
    FILE *fptr;
    char firstname[20];
    char famnamne[20];
    char pers_number[13];
    while(1)
    {
        printf("Select an option\n");
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file .\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                    printf("Enter Student First name, Family Name, Person Number");
                    scanf("%s %s %s", firstname, famnamne, pers_number);
                    strcpy(ppost.firstname, firstname);
                    strcpy(ppost.famnamne, famnamne);
                    strcpy(ppost.pers_number, pers_number);
                    write_new_file( &ppost);
                    break;
            case 2:
                    printf("Enter Student First name, Family Name, Person Number");
                    scanf("%s %s %s", firstname, famnamne, pers_number);
                    strcpy(ppost.firstname, firstname);
                    strcpy(ppost.famnamne, famnamne);
                    strcpy(ppost.pers_number, pers_number);
                    append_file(&ppost);
                    break;
            case 3:
                    printf("Enter Student First name");
                    scanf("%s", firstname);
                    search_by_firstname( firstname);
                    break;
            case 4: printfile();
                    break;
            case 5:
                    fptr = fopen(filename,"w");
                    fclose(fptr);
                    return 0;
            default: break;
        }
    }
    fptr = fopen(filename,"w");
    fclose(fptr);
    return(0);
}

PERSON input_record( void) // Reads in a person record.
{
    PERSON ppost;
    FILE *fptr;
    fptr = fopen(filename,"rb");
     if (!fptr)
     {
        printf("Unable to open file!");
        return;
     }
    fread(&ppost,sizeof(PERSON),1,fptr);
    fclose(fptr);
    return ppost;
}
void write_new_file( PERSON *inrecord) //Creats a file and write a first record
{
    FILE *fptr;
    fptr = fopen(filename,"w");
    if (!fptr)
    {
        printf("Unable to creat/open file!");
        return;
    }
    fwrite(inrecord, sizeof(PERSON), 1, fptr);
    fclose(fptr);
    count = 1;
}
void printfile(void) // print out all persons in the file
{
    PERSON ppost;
    FILE *fptr;
    int i, tc = count;
    fptr = fopen(filename,"rb");
    if (!fptr)
    {
        printf("Unable to open file!");
        return;
    }
    while(tc != 0)
    {
        fread(&ppost,sizeof(PERSON),1,fptr);
        printf("%s\n",ppost.firstname);
        printf("%s\n",ppost.famnamne);
        printf("%s\n",ppost.pers_number);
        tc--;
    }
    fclose(fptr);
}
void search_by_firstname( char *name)// print out person if in list
{
    PERSON ppost;
    FILE *fptr;
    int i, flag = 0, tc = count;
    fptr = fopen(filename,"rb");
    if (!fptr)
    {
        printf("Unable to open file!");
        return;
    }
    while(tc != 0)
    {
        fread(&ppost,sizeof(PERSON),1,fptr);
        if(strcmp(ppost.firstname, name) == 0)
        {
            flag = 1;
            break;
        }
        tc--;
    }
    if(flag == 1)
        printf("Enter name is found in the record.\n");
    else
        printf("Enter name is NOT found in the record.\n");
    fclose(fptr);
}
void append_file(PERSON *inrecord)// appends a new person to the file
{
    FILE *fptr;
    fptr = fopen(filename,"a");
    if (!fptr)
    {
        printf("Unable to open file!");
        return;
    }
    fwrite(inrecord, sizeof(PERSON), 1, fptr);
    count++;
    fclose(fptr);
}


