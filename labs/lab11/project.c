// CSE 20311
// Lab 11: (Mini) Final Project
// By Arda Kurama

#include "cubefunc.h"

int main()
{
  int wid = 600;
  int ht = 600;
  int xc = (wid / 2);
  int yc = (ht / 2);

  // Populate 3D Cube struct 
  Cube3D cube0 = { { {0.5, 0.5, 0.5},
                     {0.5, -0.5, 0.5},
                     {-0.5, 0.5, 0.5},
                     {-0.5, -0.5, 0.5}, 
                     {0.5, 0.5, -0.5},
                     {0.5, -0.5, -0.5},
                     {-0.5, 0.5, -0.5},
                     {-0.5, -0.5, -0.5} }, 8, 3};
  Cube3D cube1;
  cube1 = cube0;

  // Populate 4D Cube (hypercube) struct
  Cube4D hyper0 = { { {0.5, 0.5, 0.5, 0.5},
                     {0.5, -0.5, 0.5, 0.5},
                     {-0.5, 0.5, 0.5, 0.5},
                     {-0.5, -0.5, 0.5, 0.5}, 
                     {0.5, 0.5, -0.5, 0.5},
                     {0.5, -0.5, -0.5, 0.5},
                     {-0.5, 0.5, -0.5, 0.5},
                     {-0.5, -0.5, -0.5, 0.5}, 
                     {0.5, 0.5, 0.5, -0.5},
                     {0.5, -0.5, 0.5, -0.5},
                     {-0.5, 0.5, 0.5, -0.5},
                     {-0.5, -0.5, 0.5, -0.5}, 
                     {0.5, 0.5, -0.5, -0.5},
                     {0.5, -0.5, -0.5, -0.5},
                     {-0.5, 0.5, -0.5, -0.5},
                     {-0.5, -0.5, -0.5, -0.5} }, 16, 4};
  Cube4D hyper1;
  hyper1 = hyper0;

  double t = 0;
  char c;
  gfx_open(wid, ht, "Cube Window");
  while (1) {
    usleep(20000);

    if (gfx_event_waiting()) 
    c = gfx_wait();
    gfx_clear();

    // 'r' to start animation
    if (c == 'r') t += (M_PI / 128);

    // SPACE to reset animation
    if (c == 32) t = 0;

    // Any other keys pause animation

    double FOV = M_PI / 4;
    int len = 400;

    // Call draw and rotate function and send pointers to 3D cube members 
    draw((double *)cube1.vert, FOV, len, xc, yc, cube0.numVert, cube0.dim);
    rotate((double *)cube0.vert, (double *)cube1.vert, t, cube0.numVert, cube0.dim);

    // Call draw and rotate function and send pointers to 4D cube members 
    draw((double *)hyper1.vert, FOV, len, xc, yc, hyper0.numVert, hyper0.dim);
    rotate((double *)hyper0.vert, (double *)hyper1.vert, t, hyper0.numVert, hyper0.dim);

    if (c == 'q') break;
  }
}
