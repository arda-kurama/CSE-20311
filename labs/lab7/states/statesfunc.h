// CSE 20311
// Lab 7 Part 2
// Arda Kurama

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// SIZE definition for size of most arrays
#define SIZE 20

// MAX definition for the max number of states
#define MAX 100

// Struct declaration to hold state information
typedef struct {
  char abv[SIZE / 4];
  char name[SIZE];
  char capital[SIZE];
  int year;
} State;

// Function declarations
void sortStates(State [], int);
void nameToYear(State []);
void guessState(State [], int);
void guessCapital(State [], int);
void displayInfo(State [], int);
void display();
int initialize(State [], FILE*);
FILE* readFile(char []);
