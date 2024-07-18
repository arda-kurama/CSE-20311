// Part 1: Multiplication Table
// By: Arda Kurama

#include <stdio.h>

int main() 
{

	int X, Y; // Variable declarations

	printf("\nPart 1: Multiplication Table\n"); // Initial I/O prompting
	printf("By: Arda Kurama\n\n");
	printf("\tEnter Number of Rows: "); 
	scanf("%d", &Y);
	printf("\tEnter Number of Columns: ");
	scanf("%d", &X);
	printf("\n\t%d by %d Multiplication Table: \n\n", Y, X);

	for (int i = 1; i <= Y; i++) { // For-Loop length of Y to print Y rows
		if (i == 1) {
			printf("\t     ");
			for (int j = 1; j <= X; j++) { // If on first row, print X column headers
				printf("%8d", j);
			}

			printf("\n\t     ");
			for (int j = 1; j <= X; j++) { // After, print X sections of "-" for readability
				printf("--------");
			}

			printf("\n");
		}

		printf("\t%-4d|", i); // Print "|" at beggining of each row for readability
		for (int j = 1; j <= X; j++) {
			printf("%8d", j * i); // Print j * i (X * Y) at each (X, Y) corresponding to (j, i)
		}

		printf("\n");
	}

	printf("\n");

	return 0;
}
