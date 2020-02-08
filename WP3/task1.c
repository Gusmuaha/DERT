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
    int get;
    ROBOT boi = {0,0,N};
    ROBOT *findTheBoi = &boi;
    //how to use struct pointer for specific attribute using arrow
    printf("Position x: %d\n", findTheBoi -> xpos);

    do{
        printf("\n");
        printf("Where does the Boi begin? Give an x coordinate between 1-99\n");
        scanf("%d", &get);
        if(get < 0 || get > 100){
            printf("that is not a valid selection\n");
            //fix this so you have to try again
        }else{
            findTheBoi->xpos = get;
        }
        printf("Give an y coordinate between 1-99\n");
        scanf("%d", &get);
        if(get <0 || get > 100){
            printf("that is not a valid selection\n");
            return 1;
        //fix this so you have to try again
        }else{
          findTheBoi->ypos = get;
        }
        //m stands for move 1 direction
        //t stands for rotate 90 degrees
        printf("Where does the Boi go?\n");
        printf("Type any number of 't's to turn him\n");
        printf("Type any number of 'm's to make him step forward\n");


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
//parse number of m's into how many steps we need to take and apply to boi
}

void turn(){
//parse number of t's into how far we need to turn and apply to boi
}

int quit(){
    char quit = 'f';
    printf("Abandon the boi by entering 'q, otherwise type anything else to start over.\n");
    scanf("%c",&quit);

    scanf("%c",&quit);
    if(quit == 'q'){
        return 0;
    }
    return 1;

}