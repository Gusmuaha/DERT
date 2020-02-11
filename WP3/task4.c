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
int val;
PERSON ppost;

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
    FILE* fileptr;     
    //fileptr= fopen(constchar * filename, constchar* mode);   
    //fclose(fileptr);
    break;

    case 2 :
    FILE* fileptr;     
    //fileptr= fopen(constchar * filename, constchar* mode); 
    //fclose(fileptr);

    break;

    case 3 : 
    FILE* fileptr;     
    //fileptr= fopen(constchar * filename, constchar* mode); 
    //fclose(fileptr);

    break;

    case 4 : 
    FILE* fileptr;     
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
