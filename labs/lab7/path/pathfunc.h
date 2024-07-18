#include <stdio.h>
#include <math.h>

// Main struct declaration
typedef struct {
  float x;
  float y;
} Point;

// Function declarations
FILE* readFile();
float distance(Point [], int);
void display(Point [], int, float);
