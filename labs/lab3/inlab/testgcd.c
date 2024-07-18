// Exercise 2
// By: Arda Kurama

#include <stdio.h>

int get_gcd(int, int);

int main() 
{
	int n1, n2;

	printf("Enter two integers: ");
	scanf("%d %d", &n1, &n2);

	printf("GCD: %d\n", get_gcd(n1, n2));

	return 0;
}

int get_gcd(int n1, int n2) 
{ 
	int gcd;

	for (int i = 1; (i <= n1) && (i <= n2); i++) {
		if ((n1 % i == 0) && (n2 % i == 0)) {
			gcd = i;
		} 
	}
	
	return gcd;

}
