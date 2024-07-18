#include <stdio.h>

int main()
{

	int TD, EP, FG, S, score;

	printf("Please enter stats of last Fighting Irish football game.\nTouchdowns: ");
	scanf("%d", &TD);

	printf("Extra Points: ");
	scanf("%d", &EP);

	printf("Field Goals: ");
	scanf("%d", &FG);

	printf("Safeties: ");
	scanf("%d", &S);

	TD = TD * 6;
	EP = EP * 1;
	FG = FG * 3;
	S = S * 2;
	score = TD + EP + FG + S;

	printf("Fighting Irish scored %d points!\n", score);
	
	return 0;
}
