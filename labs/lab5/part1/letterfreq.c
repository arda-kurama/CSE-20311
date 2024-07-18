// CSE 20311
// Part 1: Justifying Scrabble's letter point values
// By: Arda Kurama

#include <stdio.h>
#include <ctype.h>

// SIZE definition for size of alphabet
#define SIZE 26

// Function declarations
void printOverview(int, int, char[]);
void printCounts(int, int);
void printPercents(int, int, int);
FILE* openFile(char[]);

int main()
{
	char name[30];
	char choice;
	int freq[SIZE] = {};
	int chars = 0, letters = 0;

	// File name prompting
	printf("\nEnter filename to read: ");
	scanf("%s", name);

	// Opens file to pointer fp
	FILE* fp = openFile(name);

	// Driving while loop to loop through all chars of file	
	printf("\n");
	while (!feof(fp)) {
		
		// Temp char variable stored with current char
		char pos = fgetc(fp);
	
		// Print and count each char individually
		// if statement to prevent printing/counting of EOF indicator
		if (feof(fp) == 0) {
			printf("%c", pos);

			// Char storage var to keep track of chars
			chars++;
		}

		// If char is alphabetical, check its position
		// Enter into currect index position of freq array
		if (isalpha(pos) != 0) {
			if (pos < 'a') {
				freq[pos - 'A'] += 1;
			} else if (pos > 'Z') {
				freq[pos - 'a'] += 1;
			}

			// Letter storage var to keep track of letters
			letters++;
		} 
	}

	// Print stat overview
	printOverview(chars, letters, name);

	// Print counting data for each index of freq array
	// Range is 1 <= i <= SIZE to streamline formatting
	// Indexes adjusted by i = i - 1 to accommodate for this
	for (int i = 1; i <= SIZE; i++) {
		printCounts(i - 1, freq[i - 1]);

		// Newline every 6 letters
		if (i % 6 == 0) printf("\n");
	}

	// Print percentage date for each index of freq array
	printf("\n\nLetter percentages: \n");
	for (int i = 1; i <= SIZE; i++) {
		printPercents(i - 1, freq[i - 1], letters);

		if (i % 6 == 0) printf("\n");
	}

	printf("\n\n");

	return 0;
}

// Function to print stat overview
void printOverview(int chars, int letters, char name[20])
{
	printf("\nGeneral summary for %s:", name);
	printf("\n  There were %d total characters", chars);
	printf("\n  There were %d letters", letters);
	printf("\n\nLetter counts: \n");
}

// Function to print letter count data
void printCounts(int pos, int freq)
{
	printf("  %c: %7d", pos + 'a', freq);
}

// Function to print letter percentage data
void printPercents(int pos, int freq, int letters)
{
	printf("  %c: %6.1f%%", pos + 'a', ((float)freq / (float)letters) * 100);	
}

// Function to open file
// Returns file pointer
FILE* openFile(char name[20])
{
	FILE* fp;

	// Open file to "read" mode
	fp = fopen(name, "r");

	// Check if filename exists
	if (fp != NULL) {
		return fp;
	} else {
		printf("File does not exist. Please try again.\n");
		printf("Enter filename to read: ");
		scanf("%s", name);
		FILE* fp = openFile(name);
	}
}
