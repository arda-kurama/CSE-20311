#include <stdio.h>

int main()
{
	int arr[5];

	printf("enter five positive integers: ");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 4; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
