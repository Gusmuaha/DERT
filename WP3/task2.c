/* ====================================
File name: task2.c (or cpp)
Date: 2020-mm-dd
Group nr 17

Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar


Member not present at demonstration time: 
Demonstration code : [22454]
 Important, No code no exercise points!
====================================== */
#include <stdio.h>

int search_number( int number, int tab[], int size);
void sort (int number, int tab []);

int main(void)
{
	int test [] = { 1,2,34,5,67,3,23,12,13,10}; //Array is given in Problem Statement/
	int i, n, res, size;
	size = sizeof(test)/sizeof(int); //Size of the array
	
	printf("Enter a number to search in the list\n");
	scanf("%d", &n);
	
	res = search_number(n, test, size); /* Searching */
	if(res != -1)
		printf("%d is present in the list at index : %d\n", n, res);
	else
		printf("%d is not present in the list\n", n);
	
	sort(size, test); /* Sorting */
	
	for (i=0; i < size; i++)
		printf("%d ", test[i]); //Printing the sorted array/
	printf("\n");
	
	return 0;
}

//Linear Search algorithm/
int search_number( int number, int tab[], int size)
{
	int i;
	for (i=0; i < size; i++)
		if(tab[i] == number)
			return i;
	return -1;
}

//Bubble Sort algorithm/
void sort (int number, int tab [])
{
	int i, j;
	for (i=0; i < number -1; i++)
		for (j=0; j < number-i-1; j++)
			if(tab[j] > tab[j+1])
			{
				int temp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = temp;
			}
}