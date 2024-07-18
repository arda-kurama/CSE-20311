// CSE 20311
// Arda Kurama
// Lab 8 Part 2

#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define RAD 25

int main()
{
  // Sets random rand() seed
  srand(time(NULL));
  
  // Opens GFX window 
  int wid = 393, ht = 852;
  gfx_open(wid, ht, "Bouncing Ball");

  // Declares and sets first circle center position
  int xc, yc;
  xc = 100;
  yc = 100;

  // Declares and sets first velocity vector
  int dx, dy;
  dx = 2;
  dy = 2;

  int randX, randY;

  char c;
  while (1) {
    // Clears screen and draws new circle
    gfx_clear();
    gfx_circle(xc, yc, RAD);

    // Checks if an event is waiting
    if (gfx_event_waiting()) {

      // Detects event
      c = gfx_wait();
      switch(c) {
        case 1: ; // allows declaration of vars inside a label

          // Sets center of circle to mouse position at event
          xc = gfx_xpos();
          yc = gfx_ypos();

          // Generates random numbers between [0 - 10]
          int randX = rand() % 11;
          int randY = rand() % 11;

          // Subtracts 5 from both numbers to make range [-5 - 5]
          randX -= 5;
          randY -= 5;

          // Assigns values to velocity vector
          dx = randX;
          dy = randY;
          break;
      }
    }

    // Collision detection with walls
    if ((xc + RAD) >= wid) dx = -dx;
    if ((xc - RAD) <= 0) dx = -dx;
    if ((yc + RAD) >= ht) dy = -dy;
    if ((yc - RAD) <= 0) dy = -dy;

    // Updates center of circle
    xc += dx;
    yc += dy;

    // Pauses and flushes memory
    usleep(10000);
    gfx_flush();

    // Quits if event is 'q'
    if (c == 'q') break;
  }
}
