/* ====================================
File name: task1.c (or cpp)
Date: 2020-mm-dd
Group nr xxx

Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar


Member not present at demonstration time:
Demonstration code : [38194]
 Important, No code no exercise points!
====================================== */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXCHAR 1000
void copyString();
char arr1[20];
char arr2[20];



int main(){


int nr;
bool format = true;
char userInput[22]; // Used for user string, takes 20 chars and with room for /0 at end.
char copiedString[22];


while (format) {
format = false;
printf("Type 1 for keybord string input or 2 for input via file \n");

scanf("%d",&nr); // Reads input

switch (nr) {

case 1 : {
printf("\n Please enter a string with maximum 20 characters \n");

getchar(); // "removes" the new line \n char from stdin so that fgets dont already have an input and skips real user input
fgets(userInput, 21, stdin);

printf("userInput to be copied is : %s \n", userInput);

strcpy(copiedString, userInput);
printf("copiedString is : %s \n", copiedString);

break;
}

case 2 : {

FILE *fp; // declaring pointer of FILE type
char str[MAXCHAR];
char *filename = "c:\\temp\\myfile.txt";

// pointing fp1 to a file with the name of filename string.
fp = fopen(filename, "r"); // r searches for the file and returns null if error encountered

if (fp == NULL) {
printf("Could not open file %s", filename);
return 1;
}

while (fgets(str, MAXCHAR, fp) != NULL) // reads string from file into
printf("%s", str);
fclose(fp);
break;
}


default :
printf("\nInput was not a number of 1 or 2. ");
format = true;
}
}


return 0;

}