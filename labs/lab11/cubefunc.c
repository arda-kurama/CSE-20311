// CSE 20311
// Lab 11: (Mini) Final Project
// By Arda Kurama

#include "cubefunc.h"

// Matrix Multiplication Function
void multiply(double *mat1, double *mat2, double *mat3, int dim) 
{
  // Store values in temporary array so function can be recalled
  double Rtemp[dim][dim];
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      Rtemp[i][j] = *((mat2 + i * dim) + j);
    }
  }

  // Calculates NxN matrix multiplication
  double temp;
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      temp = 0;
      for (int k = 0; k < dim; k++) {
        temp += Rtemp[k][j] * *((mat3 + i * dim) + k);
      }
      *((mat1 + i * dim) + j) = temp;
    }
  }
}

// Vertex rotation function
void rotate(double *oP, double *nP, double t, int vert, int dim)
{
  // 3D Rotation Matrices (for all 3 axis of rotation)
  double R3x[3][3] = { {1, 0, 0},
                       {0, cos(t), -sin(t)},
                       {0, sin(t), cos(t)} };

  double R3y[3][3] = { {cos(t), 0, -sin(t)},
                       {0, 1, 0},
                       {sin(t), 0, cos(t)} };

  double R3z[3][3] = { {cos(t), -sin(t), 0},
                       {sin(t), cos(t), 0},
                       {0, 0, 1} };

  // 4D Rotation Matrices (for all 6 planes of rotation)
  double R4xy[4][4] = { {cos(t), -sin(t), 0, 0},
                        {sin(t), cos(t), 0, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 1} };

  double R4yz[4][4] = { {1, 0, 0, 0},
                        {0, cos(t), -sin(t), 0},
                        {0, sin(t), cos(t), 0},
                        {0, 0, 0, 1} };

  double R4xz[4][4] = { {cos(t), 0, -sin(t), 0},
                        {0, 1, 0, 0},
                        {sin(t), 0, cos(t), 0},
                        {0, 0, 0, 1} };
  
  double R4xw[4][4] = { {cos(t), 0, 0, -sin(t)},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0},
                        {sin(t), 0, 0, cos(t)} };

  double R4yw[4][4] = { {1, 0, 0, 0},
                        {0, cos(t), 0, -sin(t)},
                        {0, 0, 1, 0},
                        {0, sin(t), 0, cos(t)} };

  double R4zw[4][4] = { {1, 0, 0, 0},
                        {0, 1, 0, 0},
                        {0, 0, cos(t), -sin(t)},
                        {0, 0, sin(t), cos(t)} };

  // Main 3D rotation matrix
  double R3[3][3] = { {1, 0, 0},
                      {0, 1, 0},
                      {0, 0, 1} };
  // Rotates about all 3 axis
  multiply((double *)R3,(double *)R3,(double *)R3x, 3); 
  multiply((double *)R3,(double *)R3,(double *)R3y, 3); 
  multiply((double *)R3,(double *)R3,(double *)R3z, 3); 

  // Main 4D rotation matrix
  double R4[4][4] = { {1, 0, 0, 0},
                      {0, 1, 0, 0},
                      {0, 0, 1, 0},
                      {0, 0, 0, 1} };

  // Can rotate about all 6 planes
  //multiply((double *)R4,(double *)R4,(double *)R4xy, 4); 
  //multiply((double *)R4,(double *)R4,(double *)R4yz, 4); 
  //multiply((double *)R4,(double *)R4,(double *)R4xz, 4);
  
  // But I found animation to be more meaningful only rotating about 
  // complex planes (planes contianing w-axis)
  multiply((double *)R4,(double *)R4,(double *)R4xw, 4); 
  multiply((double *)R4,(double *)R4,(double *)R4yw, 4); 
  multiply((double *)R4,(double *)R4,(double *)R4zw, 4); 

  // Runs main matrix vector multiplication
  double temp3;
  double temp4;
  for (int i = 0; i < vert; i++) {
    for (int j = 0; j < dim; j++) {
      temp3 = 0;
      temp4 = 0;

      for (int k = 0; k < dim; k++) {
        temp3 += (R3[k][j] * *((oP + i * dim) + k));
        temp4 += (R4[k][j] * *((oP + i * dim) + k));
      }

      // Adds correct temp to correct dereferenced pointer depending on num of vertices
      if (vert == 16) {
        *((nP + i * dim) + j) = temp4;
      } else if (vert == 8) {
        *((nP + i * dim) + j) = temp3;
      }
    }
  }
}

// Function to draw vertices and edges
void draw(double *p, double FOV, int len, int xc, int yc, int vert, int dim)
{
  // Store positions of all points
  int x3[vert];
  int y3[vert];
  int x4[vert];
  int y4[vert];

  // First project onto dim - 1 subspace
  for (int i = 0; i < vert; i++) {
    x3[i] = ((len * *((p + i * dim) + 0) / (*((p + i * dim) + 2) + 2) * tan(FOV / 2))) + xc;
    y3[i] = ((len * *((p + i * dim) + 1) / (*((p + i * dim) + 2) + 2) * tan(FOV / 2))) + yc;

    // If cube is 3D, draw after first projection
    if (dim == 3) {
      gfx_text(xc - 0.58 * xc, yc - 0.35 * yc, "3D Cube");
      x3[i] -= 0.5 * xc;
      gfx_circle(x3[i], y3[i], 2);
    }
  }

  // If cube is 4D, project points in 3D subspace again
  if (dim == 4) {
    for (int i = 0; i < vert; i++) {
      x4[i] = ((len / 100) * ((x3[i] - xc) / (*((p + i * dim) + 3) + 2) * tan(FOV / 2))) + xc;
      y4[i] = ((len / 100) * ((y3[i] - yc) / (*((p + i * dim) + 3) + 2) * tan(FOV / 2))) + yc;

      // Now draw double projected points
      gfx_text(xc + 0.42 * xc, yc - 0.35 * yc, "4D Cube");
      x4[i] += 0.5 * xc;
      gfx_circle(x4[i], y4[i], 2); 
    }
  }

  // Draw lines between all vertices of 3D Cube (12 edges)
  if (dim == 3) {
    gfx_color(255, 0, 0);
    // Back Face
    gfx_line(x3[0], y3[0], x3[1], y3[1]);
    gfx_line(x3[0], y3[0], x3[2], y3[2]);
    gfx_line(x3[3], y3[3], x3[1], y3[1]);
    gfx_line(x3[3], y3[3], x3[2], y3[2]);

    gfx_color(255, 255, 255);
    // Side Edges
    gfx_line(x3[0], y3[0], x3[4], y3[4]);
    gfx_line(x3[1], y3[1], x3[5], y3[5]);
    gfx_line(x3[2], y3[2], x3[6], y3[6]);
    gfx_line(x3[3], y3[3], x3[7], y3[7]);
    
    gfx_color(0, 255, 255);
    // Front Face
    gfx_line(x3[4], y3[4], x3[5], y3[5]);
    gfx_line(x3[4], y3[4], x3[6], y3[6]);
    gfx_line(x3[7], y3[7], x3[5], y3[5]);
    gfx_line(x3[7], y3[7], x3[6], y3[6]);
    gfx_color(255, 255, 255);
  }

  // Draw lines between all vertices of 4D Cube (32 edges)
  if (dim == 4) {
    gfx_color(255, 0, 0);
    // Back Subcube
    // Back Face
    gfx_line(x4[0], y4[0], x4[1], y4[1]);
    gfx_line(x4[0], y4[0], x4[2], y4[2]);
    gfx_line(x4[3], y4[3], x4[1], y4[1]);
    gfx_line(x4[3], y4[3], x4[2], y4[2]);

    // Side Edges
    gfx_line(x4[0], y4[0], x4[4], y4[4]);
    gfx_line(x4[1], y4[1], x4[5], y4[5]);
    gfx_line(x4[2], y4[2], x4[6], y4[6]);
    gfx_line(x4[3], y4[3], x4[7], y4[7]);

    // Front Face
    gfx_line(x4[4], y4[4], x4[5], y4[5]);
    gfx_line(x4[4], y4[4], x4[6], y4[6]);
    gfx_line(x4[7], y4[7], x4[5], y4[5]);
    gfx_line(x4[7], y4[7], x4[6], y4[6]);

    gfx_color(0, 255, 255);
    // Front Subcube
    // Back Face
    gfx_line(x4[8], y4[8], x4[9], y4[9]);
    gfx_line(x4[8], y4[8], x4[10], y4[10]);
    gfx_line(x4[11], y4[11], x4[9], y4[9]);
    gfx_line(x4[11], y4[11], x4[10], y4[10]);
    
    // Side Edges
    gfx_line(x4[15], y4[15], x4[11], y4[11]);
    gfx_line(x4[14], y4[14], x4[10], y4[10]);
    gfx_line(x4[13], y4[13], x4[9], y4[9]);
    gfx_line(x4[12], y4[12], x4[8], y4[8]);

    // Front Face
    gfx_line(x4[15], y4[15], x4[14], y4[14]);
    gfx_line(x4[15], y4[15], x4[13], y4[13]);
    gfx_line(x4[12], y4[12], x4[14], y4[14]);
    gfx_line(x4[12], y4[12], x4[13], y4[13]);

    gfx_color(255, 255, 255);
    // Connecting Edges between subcubes
    gfx_line(x4[11], y4[11], x4[3], y4[3]);
    gfx_line(x4[10], y4[10], x4[2], y4[2]);
    gfx_line(x4[9], y4[9], x4[1], y4[1]);
    gfx_line(x4[8], y4[8], x4[0], y4[0]);

    gfx_line(x4[4], y4[4], x4[12], y4[12]);
    gfx_line(x4[5], y4[5], x4[13], y4[13]);
    gfx_line(x4[6], y4[6], x4[14], y4[14]);
    gfx_line(x4[7], y4[7], x4[15], y4[15]);
  }
}
