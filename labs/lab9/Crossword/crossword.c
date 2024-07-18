// CSE 20311
// Lab 9: Crossword Anagram
// By: Arda Kurama

#include "crossfunc.h"

int main(int argc, char *argv[])
{
  Crossword board;
  int size;
  FILE *wfp;


  // Correct method of data input based on number of strings in command line 
  if (argc == 1) {
    printf("\nAnagram Crossword Puzzle Generator");
    printf("\n----------------------------------\n");
    size = manualInput(&board);
  }
  if (argc == 2) {
    printf("\nAnagram Crossword Puzzle Generator");
    printf("\n----------------------------------\n");
    size = readFile(&board, argv[1]); 
  }
  if (argc == 3) {
    size = readFile(&board, argv[1]);
    wfp = writeFile(&board, argv[2]);
    fprintf(wfp, "\nAnagram Crossword Puzzle Generator");
    fprintf(wfp, "\n----------------------------------\n");
  }


  // Formats list of words and initializes board
  allUpper(&board, size);
  allSort(&board, size);
  initBoard(&board);

  // Runs main algorithm for placing words
  placeFirst(&board, size);
  place(&board, size);

  // Correct method of data output based on number of strings in command line
  if (argc != 3) display(&board, size, stdout);
  else if (argc == 3) display(&board, size, wfp);
}
