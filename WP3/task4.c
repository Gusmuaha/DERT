/* ====================================
File name: exerc_3_4.c (or cpp)
Date: 2019-mm-dd
Group Number:17
Members that contributed:
Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar
Demonstration code: [<Ass code 1-3> <abc>]        Important !
====================================== */
#include <stdlib.h>
#include <stdio.h>
// 

typedef struct {
char firstname[20];
char famnamne[20];
char pers_number[13]; // yyyymmddnnnc
}PERSON;

PERSON input_record( void);// Reads in a person record.
void write_new_file(PERSON *inrecord); //Creats a file and write a first record
void printfile(void); // print out all persons in the file
void search_by_firstname( char *name);// print out person if in list 
void append_file(PERSON *inrecord);// appends a new person to the file



int main( void){
FILE* fileptr;     
int val;
PERSON ppost;
PERSON *personptr = &ppost;

    printf("Pick a menu option\n");
    printf("1. Create a new file and delete the old one\n");
    printf("2. Add a new person to the file\n");
    printf("3. Search for a person in the file\n");
    printf("4. Print the entire file\n");
    printf("5. Quit the program\n");
    scanf("%d", &val);

    switch (val)
    {
    case 1 :
    write_new_file(personptr);
    break;

    case 2 :
    append_file(personptr);
    break;

    case 3 : 
    //needs a char pointer
    search_by_firstname();
    break;

    case 4 : 
    printfile();
    break;

    case 5 :
    //
    break;   
    
    default:
    printf("That is not a valid selection, please pick an option between 1-5\n");
        break;
    }




return(0);

}

void write_new_file(PERSON *inrecord){
    //creates a new file with name file.txt
    //needs to also delete the old file

    //fp = fopen ("file.txt", "w+");
    //fileptr= fopen(constchar * filename, constchar* mode);   
    //fclose(fileptr);

}

void printfile(void){
    //fileptr= fopen(constchar * filename, constchar* mode); 
    /* while(1) {
      c = fgetc(fileptr);
      if( feof(fileptr) ) {
         break;
      }
      printf("%c", c);
   }
   */
    //fclose(fileptr);
}

void search_by_firstname( char *name){
        //needs search code

    //fileptr= fopen(constchar * filename, constchar* mode); 
    //fclose(fileptr);
}

void append_file(PERSON *inrecord){
        //code for writing to file
        //need to make sure we don't delete the original text


    //fileptr= fopen(constchar * filename, constchar* mode); 
    //fprintf(fileptr, "%s %s %s %d", "We", "are", "in", 2012);
    //fclose(fileptr);

}


