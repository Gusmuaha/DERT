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
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20

void create_random( int *tab);
void count_frequency(int *tab, int *freq);
void draw_histogram(int *freq);


void main(){
int table[MAX], n ;
int frequency[MAXNUMBER];
for (int i = 0; i < MAX; i++) {
    table[i] = rand()%99;
    printf("%d\n", table[i]);
  }

}