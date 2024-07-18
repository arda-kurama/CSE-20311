// CSE 20311
// Part 1: multiple quadratics
// By: Arda Kurama

#include <stdio.h>
#include <math.h>

// Function declarations
double disc(double, double, double);
void calc(double, double, double, double);

int main()
{
	double a = 1, b, c; // a = 1 so a != 0 for while loop. has no effect on first calculation

	// Initial I/O
	printf("Part 1: multiple quadratics\n");
	printf("By: Arda Kurama\n\n");

	// Driving while loop to prompt inputs
	while (a != 0) {
		printf("\tEnter equation's (real) coefficients a, b, and c: ");
		scanf("%lf %lf %lf", &a, &b, &c);
		if (a == 0) break; // Prevents final calculation when a = 0
		calc(a, b, c, disc(a, b, c));
	}

	return 0;
}

// Function to calculate discriminant
double disc(double a, double b, double c)
{
	double disc;
	disc = pow(b, 2) - (4 * a * c);
	return disc;
}

// Function to determine sign of discriminant and output proper solution(s)
void calc(double a, double b, double c, double disc)
{ 
	double d1, d2;
	if (disc > 0) {
		d1 = (-b + sqrt(disc)) / (2 * a);
		d2 = (-b - sqrt(disc)) / (2 * a);
		printf("\tSolutions: %lf, %lf\n", d1, d2);	
	} else if (disc == 0) {
		d1 = (-b + sqrt(disc)) / (2 * a);
		printf("\tSolution: %lf\n", d1);
	} else {
		printf("\tNo Real Solution.\n");
	}
}
