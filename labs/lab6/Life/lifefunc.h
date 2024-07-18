// CSE 20311
// Lab 6: Game of Life
// Arda Kurama

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// global board size definition
#define SZ 40

// function declarations
void randomBoard(char [SZ][SZ]);
void nullBoard(char [SZ][SZ]);
void swapBoard(char [SZ][SZ], char [SZ][SZ]);
char interact(char [SZ][SZ]);
void detect(char [SZ][SZ], char [SZ][SZ], int, int);
void detectBoard(char [SZ][SZ], char [SZ][SZ]);
void interactive(char [SZ][SZ], char[SZ][SZ]);
void batch(char [SZ][SZ], char [SZ][SZ], char [SZ]);
void displayRules();
void display(char [SZ][SZ]);
