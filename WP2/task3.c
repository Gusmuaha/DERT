/* ====================================
File name: task3.c (or cpp)
Date: 2020-02-07
Group nr 17

Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar


Member not present at demonstration time:
Demonstration code : [35453] Important, No code no exercise points!
====================================== */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compareString();    

int main(int argc, char* argv[]) {  
    if(argc == 1){ 
        printf("No strings given for comparison\n"); 
    }if(argc == 2){
        printf("Only one string given\n");
    }if(argc == 3 && strcmp(argv[1], argv[2]) == 0){ 
            printf("The strings are identical\n");
    }if(argc == 3 && strcmp(argv[1], argv[2]) != 0){ 
            printf("The strings are not identical\n"); 
    }if(argc > 3){
        printf("More than two strings, they cannot be compared\n");
    }
    return 0; 
}

int compareString(char str1[], char str2[]){
    int counter = 0;
    while(str1[counter]==str2[counter])
    {
        if(str1[counter]=='\0'||str2[counter]=='\0')
            break;
        counter++;
    }
    if(str1[counter]=='\0' && str2[counter]=='\0')
        return 0;
    else
        return -1;
}
