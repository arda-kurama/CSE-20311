#include "pathfunc.h"

// Function to read file
FILE* readFile()
{
  FILE* fp;
  char name[25];

  // Prompt to enter file name
  printf("Enter filename: ");
  scanf("%s", &name);

  // Opens file if it exists, sends error if it does not exist
  fp = fopen(name, "r");
  if (fp) return fp;
  else {
    printf("File does not exist. Please try again. \n");
    readFile();
  }
}

// Function to calculate distance between all points
float distance(Point path[], int size)
{
  float length = 0;

  // Uses distance formula individually between all points
  for (int i = 0; i < (size - 1); i++) {
    length += sqrt(pow(path[i + 1].y - path[i].y, 2) +
                   pow(path[i + 1].x - path[i].x, 2));
  }

  return length;
}

// Function to display data
void display(Point path[], int size, float length)
{
  printf("\nThere are %d points:\n\n", size);
  printf("     x   |   y   \n");
  printf("  -------+-------\n");
  for (int i = 0; i < size; i++) {
    printf("  %6g |%6g\n", path[i].x, path[i].y);
  }
  printf("\nThe length of the path around them is %.2f\n\n", length);
}
