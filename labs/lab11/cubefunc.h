// CSE 20311
// Lab 11: (Mini) Final Project
// By Arda Kurama

#include "gfx.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>

// 3D Cube data structure
typedef struct {
  double vert[8][3];
  int numVert;
  int dim;
} Cube3D;

// 4D Cube data structure
typedef struct {
  double vert[16][4];
  int numVert;
  int dim;
} Cube4D;

// Function declarations
void multiply(double *, double *, double *, int);
void rotate(double *, double *, double, int, int);
void draw(double *, double, int, int, int, int, int);
