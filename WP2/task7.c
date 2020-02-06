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
char arr1[10];
int arr2[10];
int readPersnr(char *person);
int *pp = arr1;
int controlDigit( const char * persnr);

int main(){
    printf("Gimme that personnummer\n");
    fgets(arr1, sizeof(arr1), stdin);
    readPersnr(arr1);
    controlDigit(arr1);

    return 0;
}

int readPersnr(char *person){

    sscanf(arr1, "%d", &pp);
    printf("Personnumer is: %d\n", pp);

}

int controlDigit(const char * persnr){
    sscanf(arr1, "%d", &pp);
    int temp = pp;
    int sum = 0;
    for(int i=1; i < 10; i++){
        int digit = temp % 10LL;
        if(i % 2  != 0){
            digit *=2;
            if(digit > 9){
                digit -= 9;
            }
        }
        sum += digit;
        temp /= 10LL;
    }
    int checksum = (sum % 10);
    printf("%d", checksum);

    for (int i = 9; i >= 0; i--){
        arr2[i] = temp % 10;
        temp = temp / 10;
    }
/*
    for (int i = 1; i < 10; i++){
        printf("%d\n", arr2[i]);
    }
    */
    printf("%d", sum);
    return sum;
}

