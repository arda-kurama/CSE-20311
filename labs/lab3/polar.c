// CSE 20311
// Part 2: quadrants and polar coordinates
// By: Arda Kurama

#include <stdio.h>
#include <math.h>

// Function declarations
int get_quadrant(double, double);
double get_radius(double, double);
double get_angle(double, double);
void show_info(int, double, double);

int main()
{
	double x, y, r, theta;
	int quad;

	// Initial I/O prompting	
	printf("Part 2: quadrants and polar coordinates\n");
	printf("By: Arda Kurama\n\n");	
	printf("\tEnter cartesian (x, y) coordinates: ");
	scanf("%lf %lf", &x, &y);

	// Main function calls
	quad = get_quadrant(x, y);
	r = get_radius(x, y);
	theta = get_angle(x, y);
	show_info(quad, r, theta);
	return 0;
}

// Function to determine quadrant
int get_quadrant(double x, double y) 
{
	if ((x > 0) && (y > 0)) {
		return 1;
	} else if ((x < 0) && (y > 0)) {
		return 2;
	} else if ((x < 0) && (y < 0)) {
		return 3;
	} else if ((x > 0) && (y < 0)) {
		return 4;
	} else {
		return 0;
	}
}

// Function to determine radius
double get_radius(double x, double y) 
{
	double radius;

	radius = sqrt(pow(x, 2) + pow(y, 2)); 

	return radius;
}

// Function to determine angle
double get_angle(double x, double y)
{
	double theta;

	theta = (atan2(y, x) * (180 / M_PI)); // atan2() used for extended range

	return theta;
}

// Function to print calculations
void show_info(int quad, double r, double theta) 
{
	// Switch statment based on return int from get_quadrant()
	switch (quad) {
		case 0:
			printf("\tYour point is on an axis\n");
			break;
		case 1:
			printf("\tYour point is in quadrant I\n");
			break;
		case 2:
			printf("\tYour point is in quadrant II\n");
			break;
		case 3:
			printf("\tYour point is in quadrant III\n");
			break;	
		case 4:
			printf("\tYour point is in quadrant IV\n");
			break;
	}
	
	// Final output of radius and angle
	printf("\tThe radius of your point is %g\n", r);
	printf("\tThe angle of your point is %g degrees\n\n", theta);
}	
