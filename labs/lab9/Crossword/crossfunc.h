// CSE 20311
// Lab 9: Crossword Anagram
// By: Arda Kurama

// _GNU_SOURCE allows for use of strfry() function
#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LEN 15
#define MAX 20

// Driving struct declaration 
typedef struct {
  char list[MAX][LEN];
  char puzzle[LEN][LEN];
  char solution[LEN][LEN];
  int orientation[LEN];
  int xPos[LEN];
  int yPos[LEN];
  char unused[MAX][LEN];
} Crossword;

// Function declarations
void displayUnused(Crossword *, int, FILE *, int);
void display(Crossword *, int, FILE *);
int detect(Crossword *, int, int *, int, int, int);
int match(Crossword *, int);
void place(Crossword *, int);
void placeFirst(Crossword *, int);
int placeAgain(Crossword *, int);
void initBoard(Crossword *);
void allSort(Crossword *, int);
void allUpper(Crossword *, int);
int checkLine(char []);
int manualInput(Crossword *);
FILE *writeFile(Crossword *, char []);
int readFile(Crossword *, char []);
