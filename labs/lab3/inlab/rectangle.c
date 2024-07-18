// Exercise 1
// By: Arda Kurama

#include <stdio.h>

int find_perim(int, int);
int find_area(int, int);
void display(int, int);

int main()
{
	float len, wid;
	float perim, area;

	printf("enter the rectangle's length and width: ");
	scanf("%f %f", &len, &wid);

	perim = find_perim(len, wid);
	area = find_area(len, wid);

	display(perim, area);

	return 0;
}

int find_perim(int x, int y)
{
	return (2 * x) + (2 * y);
}

int find_area(int x, int y)
{
	return (x * y);
}

void display(int p, int a)
{
	printf("perimeter: %d\narea: %d\n", p, a); 
}
