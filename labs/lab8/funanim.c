// CSE 20311
// Arda Kurama
// Lab 8 Part 3

#include "gfx.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RAD 250 
#define SIZE 25
#define N 12

// Struct for polygon info
typedef struct {
  int color[3];
  int edges;
} Polygon;

void genRandom(Polygon []);
void drawPolygon(int, int, int [], int);
void drawPolygons(int, int, int, int, Polygon [], double);

int main()
{
  // Sets random rand() seed
  srand(time(NULL));

  // Opens GFX window
  int wid = 1280, ht = 720;
  gfx_open(wid, ht, "Rotating Animation");
 
  // Set initial centerpoint at middle of screen 
  int xc, yc;
  xc = (wid / 2);
  yc = (ht / 2);

  // Initialize Polygon array
  Polygon polygons[N];
  genRandom(polygons); 

  char c;
  double theta = 0;

  while(1) {
    
    // Clear screen and draw new polygons
    gfx_clear();  
    drawPolygons(wid, ht, xc, yc, polygons, theta);

    // If event (not q) is pressed, reinitialize all polygon info
    if (gfx_event_waiting()) {
      c = gfx_wait();
      genRandom(polygons);
    }

    // Increment angle
    theta += M_PI / 128;

    // Reset centerpoint at middle of screen
    xc = (wid / 2);
    yc = (ht / 2);

    // Sleep and flush memory
    usleep(10000);
    gfx_flush();

    // Quit the program 
    if (c == 'q') break;
  }
}

// Generate random polygon info
void genRandom(Polygon polygons[])
{
  // rand() % (upper_bound - lower_bound + 1) + lower_bound
  for (int i = 0; i < N; i++) {

    // Creates triangles - octagons
    polygons[i].edges = (rand() % (8 - 3 + 1)) + 3;

    // 0 - 255 for RGB values
    for (int j = 0; j < 3; j++) {
      polygons[i].color[j] = (rand() % (255 + 1));
    }
  }
}

// Draw single polygon
void drawPolygon(int xc, int yc, int color[], int sides)
{
  // Set color to color array
  gfx_color(color[0], color[1], color[2]);

  // Set angle in radians for number of sides 
  double theta, x1, y1, x2, y2;
  theta = (360 / sides) * (M_PI / 180);
 
  // Use polar coordinates to draw lines between all verticies of polygon 
  for (int i = 0; i < sides; i++) {
    x1 = SIZE * cos(theta * i);
    y1 = SIZE * sin(theta * i);
    x2 = SIZE * cos(theta * (i + 1));
    y2 = SIZE * sin(theta * (i + 1));
    gfx_line(xc + x1, yc + y1, xc + x2, yc + y2);
  }
}

// Draw batch of polygons
void drawPolygons(int wid, int ht, int xc, int yc, Polygon polygons[], double theta)
{

  // Cycle through N polygons
  for (int i = 0; i < N; i++) {

    // Reset centerpoint at middle of screen
    xc = (wid / 2);
    yc = (ht / 2);

    // Make centerpoint follow unit circle of radius RAD 
    yc -= RAD * sin(theta);
    xc += RAD * cos(theta);

    // Call singular polygon function
    drawPolygon(xc, yc, polygons[i].color, polygons[i].edges);

    // Increment angle in radians
    theta += (M_PI / 6);
  }

}
