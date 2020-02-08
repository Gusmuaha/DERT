/* ====================================
File name: task1.c (or cpp)
Date: 2020-mm-dd
Group nr 17

Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar


Member not present at demonstration time:
Demonstration code : []
 Important, No code no exercise points!
====================================== */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void move();
void turn();
int quit();
enum DIRECTION {N,O,S,W}; //0-3
typedef struct{
int xpos;
int ypos;
enum DIRECTION dir;
} ROBOT;
char m, t;

int main(){
    ROBOT boi = {0,0,N};
    ROBOT *findTheBoi = &boi;
    //how to use struct pointer for specific attribute using arrow
    printf("Position x: %d\n", findTheBoi -> xpos);

    do{
        printf("\n");
        printf("Where does the Boi begin? Give an x coordinate between 1-99\n");
        //get the x coordinate and assign to struct boi
        printf("Give an y coordinate between 1-99\n");
        //get y coordinate and assign to struct boi
        //m stands for move 1 direction
        //t stands for rotate 90 degrees
        printf("Where does the Boi go?\n");

        //once boi has been completed take these inputs and apply them to boi until user quits
        move();
        turn();

        printf("x : %d y : %d, direction : %d\n", boi.xpos, boi.ypos, boi.dir);
        printf("\n");
        printf("\n");

        //rinse and repeat until they quit


    }while(quit());
    return 0;
}

void move(){
//parse number of M's into how many steps we need to take and apply to boi
}

void turn(){
//parse number of t's into how far we need to turn and apply to boi
}

int quit(){
    char quit = 'f';
    printf("Abandon the boi by entering 'q'.\n");
    printf("Otherwise, type anything else to give a new starting x coordinate\n");

    scanf("%c",&quit);
    if(quit == 'q'){
        return 0;
    }
    return 1;

}