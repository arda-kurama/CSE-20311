#include <stdio.h>

int main() {

	int dimension, transformation = 0, counter = 0;

	printf("Enter dimension of vector: ");
	scanf("%d", &dimension);
	
	int matrix[dimension * dimension], vector[dimension];

	printf("Enter 1x%d vector:\n", dimension); 
	
	for (int i = 0; i < dimension; i++) {
		scanf("%d", &vector[i]);
	}
	
	printf("Enter %dx%d transformation matrix:\n", dimension, dimension);

	for (int i = 0; i < (dimension * dimension); i++) {
		scanf("%d", &matrix[i]);
	}

	printf("Transformed vector:\n");
	
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			transformation += (matrix[counter + i] * vector[j]);
			counter += 1;
		}
		printf("%d\n", transformation);
		transformation= 0;
		counter -= 1;
	}

	return 0;
}
