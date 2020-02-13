/*********************************
*********** DIT1165 Program file
exerc_3_3.c
**
2018-01-04
**
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//####Konstanter #####
#define MAX 5
// ##### Typedefs####
typedef struct q{
  int number;
  struct q *next;
  struct q *prev;
} REGTYPE;
// ##### Funcion declarations#####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main(int argc, char *argv[]){
  int nr=0;
  REGTYPE* akt_post , *head=NULL;
  srand( time(0));  //   Random seed
  head = random_list();
  akt_post=head;
  while( akt_post!=NULL){
    printf("\n Post nr %d : %d" , nr++, akt_post->number);
    akt_post=akt_post->next;
  }
  head = add_first(head, 37);
  akt_post = head;
  nr = 0;
  while( akt_post!=NULL){
    printf("\n Post nr %d : %d" , nr++, akt_post->number);
    akt_post=akt_post->next;
  }
// ---Free of allocated memory ---
  while((akt_post=head)!=NULL){
    head=akt_post->next;
    free(akt_post);
  }
//------------------
  return 0;
}
// ====     End of main   ======================================
REGTYPE* random_list(void ){
  int nr,i=0;
  REGTYPE *top, *old, *item;
  top = (REGTYPE*)malloc(sizeof(REGTYPE));
  top -> next = NULL;
  top -> prev = NULL;
  nr = rand() % 99;
  top -> number = nr;
  item = top;
  for (i = 0; i< MAX; i++){
    old = item;
    item = (REGTYPE *)malloc(sizeof(REGTYPE));
    item -> next = NULL;
    item -> prev = old;
    nr = rand() % 99;
    item -> number = nr;
    old -> next = item;
  }
  return(top);
}

//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
  REGTYPE* newNode;
  newNode = (REGTYPE *)malloc(sizeof(REGTYPE));
  newNode -> number = data;
  newNode -> prev = NULL;
  temp ->prev = newNode;
  newNode ->next = temp;
  return newNode;
}
