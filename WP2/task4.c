/* ====================================
File name: task4.c (or cpp)
Date: 2020-02-07
Group nr 17

Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar


Member not present at demonstration time:
Demonstration code : [31807] Important, No code no exercise points!
====================================== */

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char input[20];
  scanf("%s", input);
  int sSize = strlen(input);
  int boo = 1;
  int i = 0;
  while(boo){
    if (input[i] == input[sSize - 1 - i]) {
      i++;
      if (i >= sSize/2){
        boo = 0;
        printf("we did it! %s! \n", input);
      }
    } else {
      boo = 0;
    }
  }


  return 0;
}
