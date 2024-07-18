// CSE 20311
// Part 3: ND football
// By: Arda Kurama

#include <stdio.h>

// PRESENT definition for present year
// Easily changable to work in the future
#define PRESENT 2024

// Gloabal arrays to store win and lose values
int wins[] = 
 { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4, 6,
   7, 7, 6, 7, 8, 6, 3, 9, 9, 10, 8, 9,
   10, 7, 9, 7, 5, 9, 10, 6, 6, 3, 6, 7, 
   6, 6, 8, 7, 7, 8, 7, 9, 8, 7, 8, 9,
   9, 10, 4, 7, 7, 9, 9, 8, 2, 7, 6, 5, 
   2, 5, 5, 2, 9, 7, 9, 8, 7, 8, 10, 8, 
   8, 11, 10, 8, 9, 11, 9, 7, 9, 5, 6, 7, 
   7, 5, 5, 8, 12, 12, 9, 10, 10, 11, 6, 9, 
   8, 7, 9, 5, 9, 5, 10, 5, 6, 9, 10, 3, 
   7, 6, 8, 8, 12, 9, 8, 10, 4, 10, 12, 11, 
   10, 11, 9, 10 };

int losses[] = 
 { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1, 0,
   0, 0, 2, 1, 1, 1, 1, 0, 0, 1, 1, 1,
   0, 2, 1, 1, 4, 0, 0, 2, 2, 5, 3, 1,
   2, 2, 1, 2, 2, 0, 2, 1, 2, 2, 0, 0,
   0, 0, 4, 2, 2, 0, 1, 2, 8, 3, 4, 5,
   8, 5, 5, 7, 1, 2, 0, 2, 2, 2, 1, 2,
   3, 0, 2, 3, 3, 1, 3, 4, 2, 6, 4, 5,
   5, 6, 6, 4, 0, 1, 3, 3, 1, 1, 5, 3,
   3, 6, 3, 7, 3, 6, 3, 7, 6, 3, 3, 9,
   6, 6, 5, 5, 1, 4, 5, 3, 8, 3, 1, 2,
   2, 2, 4, 3 };

// Function declarations
void display();
int yearToArr();
void formatting(int, int);
void printYears(int, int);
void record();
void nWins();
void nLosses();
void winOrLoss();
void moreWins();
void moreLosses();
void tie();

int main()
{
	int choice;

	// Initial Output	
	printf("\nPart 3: ND football\n");
	printf("By: Arda Kurama");

	// Driving while loop
	while (choice != 8) {

	// Prints display at each iteration and scans choice input
	display();
	scanf("%d", &choice);
		switch(choice) {
			case 1:
				record();
				break;
			case 2:
				nWins();
				break;
			case 3:
				nLosses();	
				break;
			case 4:
				winOrLoss();
				break;
			case 5:
				moreWins();
				break;
			case 6:
				moreLosses();
				break;
			case 7:
				tie();
				break;
			case 8:
				printf("Goodbye!\n");
				break;
			default:
				printf("Please enter a choice between 1-7");
				continue;
		}
	}

	return 0;
}

// Function to print display
void display()
{
	printf("\n\nND Football Statistics:\n");
	printf("(between 1900 - %d)\n", PRESENT - 1);
	printf("(1) Display the record for a given year\n");
	printf("(2) Display years with at least 'n' wins\n");
	printf("(3) Display years with at least 'n' losses\n");
	printf("(4) Display whether there were more wins or losses for a given year\n");
	printf("(5) Display years with more wins than losses\n");
	printf("(6) Display years with more losses than wins\n"); 
	printf("(7) Display years with the same number of wins and losses\n"); 
	printf("(8) Exit\n");
	printf("Enter your choice: ");
}

// Function to convert inputted years to correct array position
int yearToArr()
{
	int year;

	printf("\nEnter the year: ");
	scanf("%d", &year);

	if ((year >= 1900) && (year < PRESENT)) {
		return(year - 1900);
	
	// Only allows for years between 1900 - 2023
	} else {
		printf("Please Enter a year from 1900 - %d", PRESENT - 1);
		yearToArr();
	}
}

// Function to minimize repetative code in printing years
void formatting(int counter, int i)
{
	if (counter == 0) {
		printf("%d", i + 1900);
		counter++;
	} else {
		printf(", %d", i + 1900);
		counter++;
	}
}

// Function to print correct years based on inputted choice
void printYears(int n, int choice)
{
	int more, counter = 0;

	// For loop from position 0 to 123
	for (int i = 0; i < (PRESENT - 1900); i++) {

		// Various outputs depending on choice
		switch (choice) {
			case 2:	
				if (wins[i] >= n) {
					formatting(counter, i);
					counter++;
				}
				break;
			case 3:
				if (losses[i] >= n) {
					formatting(counter, i);
					counter++;
				}
				break;

			// Ternary expressions to compare number of wins and losses
			case 5:
				more = (wins[i] > losses[i]) ? wins[i] : losses[i];
				if ((more == wins[i]) && (more != losses[i])) {
					formatting(counter, i);
					counter++;
				}
				break;
			case 6:
				more = (wins[i] > losses[i]) ? wins[i] : losses[i];
				if ((more == losses[i]) && (more != wins[i])) {
					formatting(counter, i);
					counter++;
				}
				break;
			case 7:
				more = (wins[i] > losses[i]) ? wins[i] : losses[i];
				if ((more == losses[i]) && (more == wins[i])) {
					formatting(counter, i);
					counter++;
				}
				break;
		}

		// Prints a new line every 10 years
		if (counter > 10) {
			printf(",\n");
			counter = 0;
		}
	}

}

// Function to determine record of an inputted year
void record()
{
	int arrPos = yearToArr();

	printf("Wins: %d", wins[arrPos]);
	printf("\nLosses: %d", losses[arrPos]);

}

// Function to determine years with at least n wins
void nWins()
{
	int n;

	printf("Enter minimum amount of wins: ");
	scanf("%d", &n);
	printf("\nYears with at least %d wins:\n", n);

	printYears(n, 2);
}

// Function to determine years with at least n losses
void nLosses()
{
	int n, counter = 0;

	printf("Enter minimum amount of losses: ");
	scanf("%d", &n);
	printf("\nYears with at least %d losses:\n", n);

	printYears(n, 3);
}

// Function to determine whether there were more wins or losses for an inputted year
void winOrLoss()
{
	int arrPos = yearToArr();
	int more;

	more = (wins[arrPos] > losses[arrPos]) ? wins[arrPos] : losses[arrPos];

	if ((more == wins[arrPos]) && (more == losses[arrPos]))
		printf("In %d, there were the same number of wins and losses", arrPos + 1900);
	else if (more == wins[arrPos]) 
		printf("In %d, there were more wins than losses", arrPos + 1900);
	else if (more == losses[arrPos])
		printf("In %d, there were more losses than wins", arrPos + 1900);
	
}

// Function to print years with more wins than losses
void moreWins()
{
	printf("\nYears with more wins than losses:\n");
	printYears('\0', 5);
}

// Function to print years with more losses than wins
void moreLosses()
{
	printf("\nYears with more losses than wins:\n");
	printYears('\0', 6);
}

// Function to print years with the same number of wins and losses
void tie()
{
	printf("\nYears with the same number of wins and losses:\n");
	printYears('\0', 7);
}
