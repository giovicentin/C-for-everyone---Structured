/*
   Opening and reading a file where the first element is 
   the number of elements in a given array (the rest of the 
   integers are in the array)

   Giovani H. Vicentin
   August 23, 2020
*/

#include <stdio.h>

// define the maximum value for the number of elements (1000)
#define MAX_VAL 1000

// Function to read a file using the fscanf from stdio.h
void read_data(FILE *ptr, int d[], int *size)
{
	*size = 0;
	// this produces an array with all the values in file
	while(fscanf(ptr, "%d", &d[*size]) == 1)
		(*size)++;
}

// Printing the data inside an array
void print_data(int d[], int size)
{
	int i;
	for(i = 0; i < size; i++){
		printf("%d\t", d[i]);
		// printing values in rows with 10 elements
		if ((i+1)%10 == 0) printf("\n");
	}
}

// Function to calculate the average value in a given array
double average(int d[], int size)
{
	int i;
	double avg = 0.0;
	for(i = 0; i < size; i++)
		avg += d[i];
	return (avg/size);
}

// Function to calculate the maximum in a given array
int max(int d[], int size)
{
	int i;
	int max = d[0];
	for(i = 1; i < size; i++)
		{if(d[i] > max)	max = d[i];}
	return max;
}

// The main function to call the other functions above
int main()
{
	int i, sz = MAX_VAL;
	FILE *ifp;
	int data[MAX_VAL] = {100, 0};

	// Opening a file using fopen (file.txt is in the same directory)
	ifp = fopen("file.txt", "r");
	read_data(ifp, data, &sz);
	
	// produces an array where the number of elements is the first
	// integer in the file
	int size = data[0];
	int array[size];
	for(i = 0; i < sz; i++)
		array[i] = data[i+1];
	
	//print the array, the average and the maximum value
	printf("The elements (integers) in the array are:\n");
	print_data(array, size);
	printf("\n");

	printf("\nThe average value is %10f", average(array, size));
	printf("\n");

	printf("\nThe maximum value in the array is %d", max(array, size));
	printf("\n");

	// It's a good practice to close the files in the end of the code
	fclose(ifp);
	return 0;
}
