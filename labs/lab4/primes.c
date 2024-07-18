// CSE 20311
// Part 2: prime numbers
// By: Arda Kurama

#include <stdio.h>

// SIZE definition for range of prime calculations
#define SIZE 1000

int main()
{
	int prime[SIZE];
	int counter;

	// Initial Output
	printf("\nPart 2: prime numbers\n");
	printf("By: Arda Kurama\n");
	printf("\nAll Primes Numbers from 0 - 1000:\n");	

	// Driving for loop of SIZE
	// Starts at first prime (2)
	for (int i = 2; i < SIZE; i++) {

		// Set entire array to 1
		prime[i] = 1;

		for (int j = 2; j < SIZE; j++) {

			// If i is divisible by j with no remainer, and i != j, i is not a prime
			if ((i % j == 0) && (i != j)) {
				prime[i] = 0;
			}
		}
	
		// If array value remains 1, i is a prime
		if (prime[i] == 1) {
			printf("%5d", i);
			counter++;
		}

		// Every 10 integers printed, print a new line
		if (counter == 10) {
			printf("\n");
			counter = 0;
		}	
	}

	printf("\n\n");

	return 0;
}
