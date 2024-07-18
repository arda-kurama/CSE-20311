// Part 3: ASCII Plot
// By: Arda Kurama

#include <stdio.h>
#include <math.h>

int main() {
	
	double x = 0, y, xMax, xMin, yMax, yMin; // Variable declarations

	printf("\nPart 3: ASCII Plot\n");
	printf("By: Arda Kurama\n\n");
	printf("\tPlot for y = 2sin(x)cos(2x) + 3 for x from 0.00 to 20.00\n\n"); // Initial I/O prompting
	printf("\tX\tY\n");
	yMin = ((2 * sin(x)) * (cos(2 * x)) + 3); // Initial assignment of yMin and yMax
	yMax = ((2 * sin(x)) * (cos(2 * x)) + 3);
	
	for (x; x < 20.1; x += 0.1) { // Loop from 0.0 to 20.0 in 0.1 increments
		y = ((2 * sin(x)) * (cos(2 * x)) + 3); // Reassign y for each x
		printf("\t%.2f\t%.2f\t", x, y); // Output current x and y values
		if (y == 0) printf("*"); // If y = 0 print "*"
		if (y > yMax) { // If y > yMax assign and store xMax and yMax for current x and y
			xMax = x;
			yMax = y;
		}	
		if (y < yMin) { // If y < yMin assign and store xMin and yMin for current x and y
			xMin = x;
			yMin = y;
		}		
		while (y > 0) { // Loop while y > 0
			printf("#"); // Print a "#" while y > 0
			y -= 0.1; // Decrement y by 0.1 to print a "#" for each 0.1 of y
		}
		printf("\n");
	}

	printf("\n\tThe maximum of %.2f was at %.2f", yMax, xMax); // Final output for min and max of function
	printf("\n\tThe minimum of %.2f was at %.2f\n", yMin, xMin); 

	return 0;
}
