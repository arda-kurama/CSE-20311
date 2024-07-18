// CSE 20311
// Part 3: text menu calculator
// By: Arda Kurama

#include <stdio.h>

// Function declarations
void display();
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
void calc(int);


int main()
{
	int choice;

	// Initial I/O
	printf("\nPart 3: text menu calculator\n");
	printf("By: Arda Kurama\n");

	// Driving while loop
	while (choice != 5) {
		display(); // Calls display
		printf("\tEnter your choice: ");
		scanf("%d", &choice);

		// Print "Goodbye!" and end program (by breaking out of loop) if choice = 5
		if (choice == 5) {
			printf("\tGoodbye!\n\n");
			break;
		}
		
		// Print error message and restart loop if choice != [1,5]
		if ((choice < 1) || (choice > 5)) {
			printf("\tPlease enter a choice 1-5\n");
			continue;
		}	

		// Call calculation function
		calc(choice);
	}

	return 0;
}

// Function to show display
void display() 
{
	printf("\n\tWhat would you like to do?\n");
	printf("\t\t1 for addition\n");
	printf("\t\t2 for subtraction\n");
	printf("\t\t3 for multiplcation\n");
	printf("\t\t4 for division\n");
	printf("\t\t5 to exit\n");
}

// Function to add n1 and n2
double add(double n1, double n2)
{
	return n1 + n2;
}

// Function to subtract n1 and n2
double subtract(double n1, double n2)
{
	return n1 - n2;
}

// Function to multiply n1 and n2
double multiply(double n1, double n2)
{
	return n1 * n2;
}

// Function to divide n1 and n2
double divide(double n1, double n2)
{
	return n1 / n2;
}

// Function to call correct calculation function 
void calc(int choice) 
{
	double n1, n2;

	printf("\tEnter your two numbers: ");
	scanf("%lf %lf", &n1, &n2);

	// Driving switch function to do and print correct calculation based on choice
	switch(choice) {
		case 1:
			printf("\t(%g) + (%g) = %g\n", n1, n2, add(n1, n2));
			break;
		case 2:
			printf("\t(%g) - (%g) = %g\n", n1, n2, subtract(n1, n2));
			break;
		case 3:
			printf("\t(%g) * (%g) = %g\n", n1, n2, multiply(n1, n2));
			break;
		case 4:
			// If statement to display error if dividing by 0
			if (n2 == 0) {
				printf("\tYou cannot divide by 0\n");
				printf("\tPlease try again\n");
				break;
			}	else {
				printf("\t(%g) / (%g) = %g\n", n1, n2, divide(n1, n2));
				break;
			}
	}
}
