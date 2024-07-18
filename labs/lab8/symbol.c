// CSE 20311
// Arda Kurama
// Lab 8 Part 1

#include "gfx.h"
#include <math.h>

#define SIZE 50
#define HS (SIZE / 2)

void drawCircle(int, int);
void drawSquare(int, int);
void drawTriangle(int, int);
void drawPolygon(int, int, int);

int main()
{
  char c;

  // Opens graphics window
  int wid = 1280, ht = 720;
  gfx_open(wid, ht, "Symbolic Typewriter");

  // Driving while loop
  while(1) {
    // Waits for event
    c = gfx_wait();

    // Gets mouse position at event
    int xc, yc;
    xc = gfx_xpos();
    yc = gfx_ypos();

    // Driving switch statement to call functions
    switch(c) {
      case 'c':
        drawCircle(xc, yc); 
        break;
      case 1:
        drawSquare(xc, yc);
        break;
      case 't':
        drawTriangle(xc, yc);
        break;
      case '3':
        drawPolygon(xc, yc, 3);
        break;
      case '4':
        drawPolygon(xc, yc, 4);
        break;
      case '5':
        drawPolygon(xc, yc, 5);
        break;
      case '6':
        drawPolygon(xc, yc, 6);
        break;
      case '7':
        drawPolygon(xc, yc, 7);
        break;
      case '8':
        drawPolygon(xc, yc, 8);
        break;
      case '9':
        drawPolygon(xc, yc, 9);
        break;
      case 27:
        gfx_clear();
        break;
    }

    // Breaks out of the while loop
    if (c == 'q') break;
  }
}

// Function to draw circle
void drawCircle(int xc, int yc) 
{
  gfx_color(255, 255, 255);
  gfx_circle(xc, yc, HS);
}

// Function to draw square
void drawSquare(int xc, int yc)
{
  gfx_color(0, 0, 255);

  gfx_line(xc - HS, yc - HS, xc + HS, yc - HS);
  gfx_line(xc + HS, yc - HS, xc + HS, yc + HS);
  gfx_line(xc + HS, yc + HS, xc - HS, yc + HS);
  gfx_line(xc - HS, yc + HS, xc - HS, yc - HS);
}

// Function to draw triangle
void drawTriangle(int xc, int yc)
{
  gfx_color(0, 255, 0);

  gfx_line(xc - HS, yc + HS, xc + HS, yc + HS);
  gfx_line(xc + HS, yc + HS, xc, yc - HS);
  gfx_line(xc - HS, yc + HS, xc, yc - HS);
}

// Function to draw polygons
void drawPolygon(int xc, int yc, int sides)
{
  gfx_color(255, 0, 255);

  double theta, x1, y1, x2, y2;

  // Sets up angle in radians depending on how many sides
  theta = (360 / sides) * (M_PI / 180);

  // Uses polar coordinates to draw lines between all verticies of polygon
  for (int i = 0; i < sides; i++) {
    x1 = HS * cos(theta * i);
    y1 = HS * sin(theta * i);
    x2 = HS * cos(theta * (i + 1));
    y2 = HS * sin(theta * (i + 1));
    gfx_line(xc + x1, yc + y1, xc + x2, yc + y2); 
  } 
}
