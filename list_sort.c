/* 
    Sorting a list with 100 elements generated randomly
    Giovani H. Vicentin
    August 21, 2020
*/

#include<stdio.h> 
#include<stdlib.h> 

// define the size = 100 for the list and range = 1000 for the random numbers
// so the numbers in the list will be in the range [1, 1000]
#define SIZE	100
#define RANGE	1000
#define VALUE	rand()% RANGE
#define FILL	for(i=0; i < SIZE; i++) \
			arr[i] = VALUE

// structure for a node
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

// function to swap data of two nodes a and b
// Remember to use pointers *a and *b
void swap(struct Node *a, struct Node *b) 
{ 
	int temp = a->data; 
	a->data = b->data; 
	b->data = temp; 
} 

// Function to insert a node at the beginning of a linked list
void insertBegin(struct Node **start_ref, int data) 
{ 
	// using malloc(sizeof(...)) to allocate the memory
	struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node)); 
	ptr1->data = data; 
	ptr1->next = *start_ref; 
	*start_ref = ptr1; 
} 

// Function to print nodes in a given linked list
void printList(struct Node *start) 
{ 
	struct Node *temp = start;
	int j = 0; 
	printf("\n"); 
	while (temp!=NULL) 
	{ 	
		// Printing values in rows of 5 on the screen
		if(j%5 == 0) {printf("\n");}
		printf("%d\t", temp->data); 
		temp = temp->next; 
		j++;
	} 
} 

// Bubble sort the linked list
void bubbleSort(struct Node *start) 
{ 
	int swapped, i; 
	struct Node *ptr1; 
	struct Node *lptr = NULL; 

	if (start == NULL) 
		return; 
	do
	{ 
		swapped = 0; 
		ptr1 = start; 

		while (ptr1->next != lptr) 
		{ 
			if (ptr1->data > ptr1->next->data) 
			{ 
				swap(ptr1, ptr1->next); 
				swapped = 1; 
			} 
			ptr1 = ptr1->next; 
		} 
		lptr = ptr1; 
	} 
	while (swapped); 
} 

// Main function to call the other functions
int main() 
{  
	int i;
	int arr[SIZE];
	// provides random values to the array arr[]
	FILL;

	// start with empty list
	struct Node *start = NULL; 

	// Using the array arr[] create linked list
	for (i = 0; i< SIZE; i++) 
		insertBegin(&start, arr[i]); 

	// print list before sorting
	printf("\nInitial linked list"); 
	printList(start); 
	printf("\n\n");

	// sort the linked list
	bubbleSort(start); 

	// print the sorted list
	printf("\nSorted list"); 
	printList(start);
	printf("\n\n");
 
	return 0; 
}

