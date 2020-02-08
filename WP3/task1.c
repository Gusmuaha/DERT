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
#define MAX 100
int quit();
enum DIRECTION {N,O,S,W}; //0-3
typedef struct{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;
void move(ROBOT *m);
void turn(ROBOT *t);
char m, t;

int main(){
    int get;
    //how to use struct pointer for specific attribute using arrow
  //  printf("Position x: %d\n", findTheBoi -> dir);

    do{
        ROBOT boi = {0,0,N};
        ROBOT *findTheBoi = &boi;
        char commands[MAX];
        printf("\n");
        printf("Where does the Boi begin? Give an x coordinate between 1-99\n");
        scanf("%d", &get);
        if(get < 1 || get > 100){
            printf("that is not a valid selection\n");
            //fix this so you have to try again

        }else{
            findTheBoi->xpos = get;
        }
        printf("Give an y coordinate between 1-99\n");
        scanf("%d", &get);
        if(get < 1 || get > 100){
            printf("that is not a valid selection\n");

            //fix this so you have to try again
        }else{
            findTheBoi->ypos = get;
        }

        printf("Where does the Boi go?\n");
        printf("Type any number of 't's to turn him 90 degrees \n");
        printf("Type any number of 'm's to make him step forward\n");
        getchar();
        fgets(commands, MAX, stdin);
        for(int i = 0; i<MAX; i++){
            if(commands[i] == 't'){
                turn(findTheBoi);
            }if(commands[i] == 'm'){
                move(findTheBoi);
            }if(commands[i] == 0){
                break;
            }
        }


        printf("x : %d y : %d\n", boi.xpos, boi.ypos);
        printf("\n");
        printf("\n");

        //rinse and repeat until they quit


    }while(quit());
    return 0;
}

void move(ROBOT *m){
    if(m->dir == 0){
        m->xpos++;
    }if(m->dir == 1){
        m->ypos++;
    }if(m->dir == 2  && m->xpos > 0 ){
        m->xpos--;
    }if(m->dir == 3  && m->ypos > 0){
        m->ypos--;
    }
}

void turn(ROBOT *t){
    if(t->dir < 3){
        t->dir++;
    }else{
        t->dir = 0;
    }
}

int quit(){
    char quit = 'f';
    printf("Abandon the boi by entering 'q, otherwise type anything else to start over.\n");
    scanf("%c",&quit);
    if(quit == 'q'){
        return 0;
    }
    return 1;
}