#include "pathfunc.h"

int main()
{
  FILE* fp = readFile();
  Point path[30];
  int n = 0;
  float length;

  // While loop to store values in struct
  while(1) {
    fscanf(fp, "%f %f", &path[n].x, &path[n].y);
    if (feof(fp)) break;
    n++;
  }

  // Main function calls
  length = distance(path, n);
  display(path, n, length);
}
