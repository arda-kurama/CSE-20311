#include <stdio.h>

int main()
{
	int arr[20];
	int arrSize = 0, n;

	printf("enter <20 positive integers, followed by a -1: ");
	for (int i = 0; i < 20; i++) {
		scanf("%d", &n);
		if (n != -1) {
			arr[i] = n;
			arrSize++;
		} else {
			break;
		}
	}

	printf("%d\n", arrSize);

	for (int i = arrSize - 1; i >= 0; i--) { 
		printf("%d ", arr[i]);
	}

	return 0;
}
