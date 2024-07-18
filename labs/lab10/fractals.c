// CSE 20311
// By Arda Kurama
// Lab 10: Recursion and Fractals

#include "gfx.h"
#include <math.h>
#include <stdlib.h>

// Function declarations (with variable names)
void spiral(int xc, int yc, double rad, double th);
void fern(int x1, int y1, int len, double th);
void tree(int x1, int y1, int len, double th);
void snowflake(int xc, int yc, double rad, double th);
void lace(int xc, int yc, double rad, double th);
void spiralsq(int xc, int yc, double len, double rad, double th);
void squares(int xc, int yc, int len, int mgn);
void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3);
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

int main()
{
  int wid = 700, ht = 700, mgn = 20;
  int xc = wid / 2;
  int yc = ht / 2;
  char c;

  // Opens gfx window
  gfx_open(wid, ht, "Fractals Window");

  // Driving while loop
  while(1) {
    c = gfx_wait();

    // Clears screen calls correct case
    gfx_clear();
    switch (c) {
      case '1':
        sierpinski(mgn, mgn, wid - mgn, mgn, wid / 2, ht - mgn);
        break;
      case '2':
        squares(xc, yc, wid - (2 * mgn), mgn);
        break;
      case '3':
        spiralsq(xc, yc, wid / 4, wid * 0.6, 0);
        break;
      case '4':
        lace(xc, yc, wid / 3, 0);
        break;
      case '5':
        snowflake(xc, yc, wid / 3, M_PI / 10);
        break;
      case '6':
        tree(wid / 2, ht - mgn, wid / 4, M_PI / 2);
        break;
      case '7':
        fern(wid / 2, ht - mgn, wid * 0.6, M_PI / 2);
        break;
      case '8':
        spiral(xc, yc, wid, 0);
        break;
      default:
        gfx_clear();
        break;
    }

    // If 'q' is pressed exit the program
    if (c == 'q') break;
  }
}

// Function to draw spiral of spirals fractal
void spiral(int xc, int yc, double rad, double th)
{
  // Base case
  if (abs(rad) < 1) return;

  // Draw a point
  gfx_point(xc + (rad * cos(th)), yc + (rad * sin(th)));

  // Recursive calls:
  // Prints sub-spirals
  spiral(xc + (rad * cos(th)), yc + (rad * sin(th)), rad / 4, th);
  // Prints main spiral
  spiral(xc, yc, rad * 0.945, th + (M_PI / 8));
}

// Function to draw fern fractal
void fern(int x1, int y1, int len, double th)
{
  // Base case
  if (abs(len) < 4) return;

  // Draw a line
  int xf = x1 + (len * cos(th));
  int yf = y1 - (len * sin(th));
  gfx_line(x1, y1, xf, yf);

  // Recursive calls
  for (int i = 0; i < 4; i++) {
    fern(xf - (i * (len / 4) * cos(th)), yf + (i * (len/4) * sin(th)), len * 0.35, th - (M_PI/5));
    fern(xf - (i * (len / 4) * cos(th)), yf + (i * (len/4) * sin(th)), len * 0.35, th + (M_PI/5));
  }
}

// Function to draw tree fractal
void tree(int x1, int y1, int len, double th)
{
  // Base case
  if (abs(len) < 1) return;

  // Draw a line
  gfx_line(x1, y1, x1 + (len * cos(th)), y1 - (len * sin(th)));

  // Recusive calls
  tree(x1 + (len * cos(th)), y1 - (len * sin(th)), len * 0.7, th - (M_PI / 5));
  tree(x1 + (len * cos(th)), y1 - (len * sin(th)), len * 0.7, th + (M_PI / 5));
}

// Function to draw snowflake fractal
void snowflake(int xc, int yc, double rad, double th)
{
  // Base case
  if (abs(rad) < 1) return;

  // Draw five lines
  for (int i = 0; i < 5; i++) {
    gfx_line(xc, yc, xc + (rad * cos(th)), yc + (rad * sin(th)));
    th += (2 * M_PI / 5);
  }

  // Recursive calls
  for (int i = 0; i < 5; i++) {
    snowflake(xc + (rad * cos(th)), yc + (rad * sin(th)), rad * 0.35, th += (2 * M_PI / 5));
  }
}

// Function to draw circular lace fractal
void lace(int xc, int yc, double rad, double th)
{
  // Base case
  if (abs(rad) < 1) return;

  // Draw a circle
  gfx_circle(xc, yc, rad);

  // Recursive calls
  for (int i = 0; i < 6; i++) {
    lace(xc + (rad * cos(th)), yc + (rad * sin(th)), rad / 3, th += (M_PI / 3));
  }
}

// Function to draw spiral of squares fractal
void spiralsq(int xc, int yc, double len, double rad, double th)
{
  // Base case
  if (abs(rad) < 1) return;

  // Draw a square from corner position
  int x = xc + (rad * cos(th));
  int y = yc + (rad * sin(th));
  drawSquare(x, y, x + len, y, x + len, y + len, x, y + len);

  // Recursive call
  spiralsq(xc, yc, len * 0.88, rad * 0.9, th + (M_PI / 5));
}

// Function to draw shrinking squares fractal
void squares(int xc, int yc, int len, int mgn) 
{
  // Base case
  if (abs(len) < 2) return;

  // Draw a square from center position
  int ql = len / 4;
  drawSquare(xc - ql, yc - ql, xc + ql, yc - ql, xc + ql, yc + ql, xc - ql, yc + ql);

  // Recursive calls
  squares(xc - ql, yc - ql, (ql * 2) - mgn, mgn / 2);
  squares(xc + ql, yc - ql, (ql * 2) - mgn, mgn / 2);
  squares(xc + ql, yc + ql, (ql * 2) - mgn, mgn / 2);
  squares(xc - ql, yc + ql, (ql * 2) - mgn, mgn / 2);
}

// Function to draw a square
void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  gfx_line(x1, y1, x2, y2);
  gfx_line(x2, y2, x3, y3);
  gfx_line(x3, y3, x4, y4);
  gfx_line(x4, y4, x1, y1);
}

// Function to draw sierpinski triangle fractal
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3)
{
  // Base case 
  if (abs(x2 - x1) < 5) return;

  // Draw a triangle
  drawTriangle(x1, y1, x2, y2, x3, y3);

  // Recursive calls
  sierpinski(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, (x1 + x3) / 2, (y1 + y3) / 2);
  sierpinski((x1 + x2) / 2, (y1 + y2) / 2, x2, y2, (x2 + x3) / 2, (y2 + y3) / 2);
  sierpinski((x1 + x3) / 2, (y1 + y3) / 2, (x2 + x3) / 2, (y2 + y3) / 2, x3, y3);
}

// Function to draw a fractal
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
  gfx_line(x1, y1, x2, y2);
  gfx_line(x2, y2, x3, y3);
  gfx_line(x3, y3, x1, y1);
}

