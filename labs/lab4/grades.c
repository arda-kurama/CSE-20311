// CSE 20311
// Part 1: a simple array
// By: Arda Kurama

#include <stdio.h>
#include <math.h>

// Function declarations
float average(int[], int);
float stdev(int[], int, float);

int main()
{
	int grades[] =
		{ 96, 73, 62, 87, 80, 63, 93, 79, 71, 99,
			82, 83, 80, 97, 89, 82, 93, 92, 95, 89,
			71, 97, 91, 95, 63, 81, 76, 98, 64, 86,
			74, 79, 98, 82, 77, 68, 87, 70, 75, 97,
			71, 94, 68, 87, 79 };
	int size;

	// Array size calculation
	size = (sizeof(grades) / sizeof(grades[0]));

	// Initial output
	printf("\nPart 1: a simple array\n");
	printf("By: Arda Kurama\n\n");

	// Main output	
	printf("\tSize of class is: %d\n", size);
	printf("\tAverage is: %.2lf\n", average(grades, size));
	printf("\tStandard Deviation is: %.2lf\n\n", stdev(grades, size, average(grades, size)));

	return 0;
}

// Function to calculate average
float average(int grades[], int size) 
{
	float total = 0;

	// Stores total of array
	for (int i = 0; i < size; i++) 
		total += grades[i];
	
	// Returns total / size = average	
	return (total / size);
}

// Function to calculate standard deviation
float stdev(int grades[], int size, float ave)
{
	float total = 0;

	// Stores sum of each grade - average grade squared	
	for (int i = 0; i < size; i++)
		total += pow((grades[i] - ave), 2);

	// Returns the sqare root of that total / size = standard deviation
	return sqrt(total / size);		
}

