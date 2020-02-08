/* ====================================
File name: task6.c (or cpp)
Date: 2020-02-07
Group nr 17

Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar


Member not present at demonstration time:
Demonstration code : [36859] Important, No code no exercise points!
====================================== */
#include<stdio.h>
void initQue( int list[], int max);
int input (int list[], int number, int max);
int output (int list[], int max);

int main(int argc, char const *argv[]) {
  int max = 5;
  int list[max];
  int number = 5;
  initQue(list, max);
  for (int i = 0; i < max; i++){
    printf("%d\n", list[i]);
  }
  printf("\n");
  int result = input(list, number, max);
  for (int i = 0; i < max; i++){
    printf("%d\n", list[i]);
  }
  printf("result is %d\n", result);
  for (int i = 0; i < max; i++) {
    number ++;
    int result = input(list, number, max);
    printf("result is %d\n", result);
  }
  printf("\n");
  for (int i = 0; i < max; i++){
    printf("%d\n", list[i]);
  }

  result = output(list, max);
  printf("result is %d\n", result);
  printf("\n");
  for (int i = 0; i < max; i++){
    printf("%d\n", list[i]);
  }



}

void initQue (int list [], int max){
  for (int i = 0; i < max; i ++){
    list[i] = -1;
  }
}

int input (int list [] , int number, int max){
  for (int i = 0; i < max; i ++){
    if(list[i] == -1){
      list[i] = number;
      return 1;
    }
  } return 0;
}

int output( int list[], int max){
  if (list[0] == -1) {
    return 0;
  } else {
    int value = list[0];
    for (int i = 0; i < max-1; i++) {
        if (list[i + 1] == -1) {
            list[i] == -1;
            return value;
        }
      list[i] = list[i+1];
    }
    list[max-1] = -1;
    return value;
  }
}
