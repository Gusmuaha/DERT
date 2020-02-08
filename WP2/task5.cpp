/* ====================================
File name: task5.cpp (or cpp)
Date: 2020-02-07
Group nr 17

Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar


Member not present at demonstration time:
Demonstration code : [31232] Important, No code no exercise points!
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20

void create_random( int *tab);
void count_frequency(int *tab, int *freq);
void draw_histogram(int *freq);
int table[MAX], n;
int frequency[MAXNUMBER];
int *tp, *fp;


int main(void){
    srand(time(NULL));
    tp = table;
    fp = frequency;
    create_random(tp);
  count_frequency(tp, fp);
    draw_histogram(frequency);

    for(int i = 0; i < MAX; i++){
        if(frequency[i] != -1) {
            printf("%d  ---- %d\n", table[i], frequency[i]);
        }
    }
}

void create_random(int *tab){
    for (int i = 0; i < MAX; i++) {
        *tab = rand()%MAXNUMBER;
        *tab++;
    }
}



void count_frequency(int *tab, int *freq){
    //iterate through the array
    //compare the values in the array
    //count how many times the number appears
    //get rid of anything that doesn't show up in the range
    for(int i = 0; i < MAX; i++){
        int count = 1;
        for(int j = i+1; j < MAX; j++){
            if(tab[i] == tab[j]){
                count++;
                freq[j] = -1;
            }
        }
        if(freq[i] != -1){
            freq[i] = count;
        }
    }
}

void draw_histogram(int *freq){
    for(int i = 0; i < MAX; i++){
        if(frequency[i] != -1) {
            printf("%d  ", table[i]);
            for ( int j = 0; j < freq[i]; ++j) {
                printf("x");
            }
            printf("\n");
        }
    }
}