/* ====================================
File name: task1.c (or cpp)
Date: 2020-mm-dd
Group nr xxx

Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist

Member not present at demonstration time:
Demonstration code : [<Ass code 1-4> <abc>] Important, No code no exercise points!
====================================== */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copyString();
char arr1[20];
char arr2[20];


int main() {

    FILE *fptr;
    if ((fptr = fopen("/home/hannah/hithere.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    fscanf(fptr, "%[^\n]", arr1);

    printf("Data from the file: %s\n", arr1);
    fclose(fptr);

    strcpy(arr2, arr1);

    printf("Copied string from the file: %s\n", arr2);


    printf("Type the string you would like copied\n");
    fgets(arr1, sizeof(arr1), stdin);

    printf("The string: %s\n", arr1);

    strcpy(arr2, arr1);

    printf("Copied string: %s\n", arr2);

}

void copyString() {

    FILE *fptr;
    if ((fptr = fopen("/home/hannah/hithere.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    fscanf(fptr, "%[^\n]", arr1);

    printf("Data from the file: %s\n", arr1);
    fclose(fptr);

    for(int i = 0; arr1[i] != '\0'; i++){
        arr2[i] = arr1[i];
    }
    printf("Copied string: %s\n", arr2);


    printf("Type the string you would like copied\n");
    fgets(arr1, sizeof(arr1), stdin);
    printf("The string: %s\n", arr1);


    for(int i = 0; arr1[i] != '\0'; i++){
        arr2[i] = arr1[i];
    }
    printf("Copied string: %s\n", arr2);

}

