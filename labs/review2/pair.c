#include <stdio.h>

typedef struct {
  int val1;
  int val2;
} Pair;

void disp(Pair);
void show(Pair[], int);
void func1(Pair);
void func2(Pair[], int);
const int size = 3;

int main()
{
  Pair x1 = {3,5}, x2 = {4,1}, x3 = {6,2};

  Pair trio1[] = {x1, x2, x3};
  show(trio1, size);
  for (int i = 0; i < size; i++) 
    func1(trio1[i]);
  show(trio1, size);

  Pair trio2[] = {x1, x2, x3};
  func2(trio2, size);
  show(trio2, size);

  return 0;
}

void disp(Pair x)
{ printf(" %d,%d ", x.val1, x.val2); }

void show(Pair all[], int size)
{
  for (int i = 0; i < size; i++) 
    disp(all[i]); 
  printf("\n");
}

void func1(Pair x)
{
  (x.val1)++;
  (x.val2)++;
}

void func2(Pair trio[], int size)
{
  for (int i = 0; i < size; i++) {
    (trio[i].val1)++;
    (trio[i].val2)++;
  }
}

