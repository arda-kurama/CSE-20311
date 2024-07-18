#include <stdio.h>

int main()
{
	int number, dig;

	printf("enter an integer number: ");
	scanf("%d", &number);

	while (number > 0) {
		dig = number%10;
		printf("%d\n", dig);
		number = number/10;
	}	

	return 0;
}
