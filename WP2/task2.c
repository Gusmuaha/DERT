/* ====================================
File name: task2.c (or cpp)
Date: 2020-mm-dd
Group nr xxx

Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar


Member not present at demonstration time:
Demonstration code : [37536] Important, No code no exercise points!
====================================== */

#include <stdio.h>
#include <stdlib.h>

const int MAX = 10;
int main() {
  int arr[MAX];
  for (int i = 0; i < MAX; i++) {
    arr[i] = rand()%99;
    printf("%d\n", arr[i]);
  }
  printf("The value of the label array(address) is: %pn \n", arr);
  printf("First integer in the array is: %d \n", arr[0]);
  printf("The size of an integer (number of bytes) is: %ld \n", sizeof(arr[0]));
  printf("The size of the whole array is: %ld \n", sizeof(arr));
  int *pointer;
  for (int i = 0; i < (int)sizeof(arr)/4; i++){
    pointer = &arr[i];
    printf("%d \n", *pointer);
  }
  return 0;
}
