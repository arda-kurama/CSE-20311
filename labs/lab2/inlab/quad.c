#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, discriminant, d, dNeg, dPos;

	printf("Enter equation's (real) coefficients a, b, and c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	discriminant = (pow(b, 2) - (4 * a * c));

	if (discriminant > 0) {
		dPos = (-b + sqrt(discriminant)) / (2 * a);
		dNeg = (-b - sqrt(discriminant)) / (2 * a);
		printf("Solutions: %lf, %lf\n", dPos, dNeg);	
	} else if (discriminant == 0) {
		d = (-b + sqrt(discriminant)) / (2 * a);
		printf("Solution: %lf\n", d);
	} else {
	  printf("No Solution.\n");
	}

	return 0;
}
