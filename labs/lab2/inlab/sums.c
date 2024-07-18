#include <stdio.h>
#include <math.h>

int main()
{
	int num, sumSquare = 0;
	double sumSQRT = 0;

	printf("Enter an integer: ");
	scanf("%d", &num);

	for (double i = 1; i <= num; i++) {
		sumSquare += (pow(i, 2));
		sumSQRT += (sqrt(i));
	}

	printf("Sum of squares of 1 - %d: %d\n", num, sumSquare);
	printf("Sum of square roots of 1 - %d: %lf\n", num, sumSQRT);

	return 0;
}
