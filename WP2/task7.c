/* ====================================
File name: task7.c (or cpp)
Date: 2020-02-07
Group nr 17
Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Member not present at demonstration time:
Demonstration code : [<Ass code 1-4> <abc>] Important, No code no exercise points!
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11
char person[MAX];

int readPersnr(char *person);
int ControlDigit(const char *persnr);
int validateDate(int year, int month, int day);
int contains(int *array, int sizeOfArray, int number);
int quit();

int main(){
    do
    {
        printf("Gimme that personnummer\n ");
        fgets(person, MAX, stdin);
        int c;
        while( (c=getchar()) != '\n' && c!=EOF){}
        int passed = 1;

        if(ControlDigit(person) == 0 || readPersnr(person) == -1){
            passed = 0;
        }
        if(passed == 1){
            printf("The person number: %s is correct.\n", person);
        }else{
            printf("The person number: %s is incorrect.\n", person);
        }
    } while(quit());
    return 0;
}

int quit(){
        char quit = 'f';
        printf("If you wish to end the program press 'q'.");
        scanf("%c",&quit);
        if(quit == 'q'){
            return 0;
        }
        return 1;
}

int readPersnr(char *person){

    char yChar[3];

    yChar[0] = person[0];

    yChar[1] = person[1];

    yChar[2] = '\0';

    int year = atoi(yChar);

    char mChar[3];

    mChar[0] = person[2];

    mChar[1] = person[3];

    mChar[2] = '\0';

    int month = atoi(mChar);

    char dChar[3];

    dChar[0] = person[4];

    dChar[1] = person[5];

    dChar[2] = '\0';

    int day = atoi(dChar);

    if(validateDate(year,month,day) == 0) return -1;
    
    char test[2];

    test[0] = person[9];

    test[1] = '\0';

    int result = atoi(test);

    return result;
}

int contains(int *array, int sizeOfArray, int number){
    for(int i = 0; i < sizeOfArray; i++){
        if(array[i] == number) return 1;
    }
    return 0;
}

int ControlDigit(const char *persnr){
    int nSum       = 0;
    int nDigits    = strlen(persnr);
    int nParity    = (nDigits-1) % 2;
    char cDigit[2] = "\0";

    for (int i = nDigits; i > 0 ; i--){
        cDigit[0]  = persnr[i-1];
        int nDigit = atoi(cDigit);
        if (nParity == i % 2)
            nDigit = nDigit * 2;
        nSum += nDigit/10;
        nSum += nDigit%10;
    }
    return 0 == nSum % 10;
}


int validateDate(int year, int month, int day){
    int thirtyOne[7] = {1,3,5,7,8,10,12};
    int thirty[4] = {4,6,9,11};
    int upperBound =
            contains(thirtyOne, sizeof(thirtyOne)/sizeof(int), month) ? 31 :
            contains(thirty,sizeof(thirty)/sizeof(int), month) ? 30 :
            (month == 2) ? ((year % 4 == 0) ? 29 : 28)
                         : 0;
    return day <= upperBound && day > 0;

}
