#include <stdio.h>
#include "operfn.h"

// update

int main()
{
  float x, y;

  printf("enter two non-zero numbers: ");
  scanf("%f %f", &x, &y);

  showinfo(x, y);

  return 0;
}
