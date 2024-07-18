// CSE 20311
// Lab 6: Game of Life
// Arda Kurama

#include "lifefunc.h"

// initialize board to random with rand() function
void randomBoard(char board[SZ][SZ])
{
  // set time to NULL for different random values
  srand(time(NULL));
  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
 
      // set variable to random % 2 to recieve value
      // between 0 and 1
      int value = rand() % (1 + 1);
      if (value != 0) board[i][j] = 'X'; 
    }
  }
}

// initialize board to ' '
void nullBoard(char board[SZ][SZ])
{
  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
      board[i][j] = ' ';
    }
  }
}

// set board1 values to board2 values
void swapBoard(char board1[SZ][SZ], char board2[SZ][SZ])
{
  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
      board1[i][j] = board2[i][j];
    }
  }
}

// send commands and populate the board
char interact(char board[SZ][SZ])
{
  char choice;
  int x, y;

  printf("\n(Reminder commands are a, r, n, p, q)");
  printf("\nEnter a command: ");
  scanf("%c", &choice);

  // if command is 'a' scan two more ints for cords 
  if (choice == 'a') {
    scanf("%d %d", &x, &y);
    board[y][x] = 'X';
  }
 
  // if command is 'r' also scan two more ints for cords 
  if (choice == 'r') {
    scanf("%d %d", &x, &y);
    board[y][x] = ' ';
  }

  // return choice value to use in main()
  return choice;
}

// detect how many live cells are around a board index
void detect(char board[SZ][SZ], char nextBoard[SZ][SZ], int x, int y)
{
  int count = 0;

  // x and y [0, SZ] to set up hard borders (no wraparound)
  if (((x >= 0) && (x < (SZ - 1))) && 
      ((y > 0) && (y < (SZ - 1)))) {

    // check all 8 possibilities
    if (board[y + 1][x] == 'X') count++;
    if (board[y - 1][x] == 'X') count++;
    if (board[y][x + 1] == 'X') count++;
    if (board[y][x - 1] == 'X') count++;
    if (board[y + 1][x + 1] == 'X') count++;
    if (board[y + 1][x - 1] == 'X') count++;
    if (board[y - 1][x - 1] == 'X') count++;
    if (board[y - 1][x + 1] == 'X') count++;
  }

  // if cell is dead, bring to life (in correct conditions)
  if (board[y][x] == ' ') {
    if (count == 3) {
      nextBoard[y][x] = 'X';
    }

  // if cell is alive, kill (in correct conditions)
  } else if (board[y][x] == 'X') {
    if ((count < 2) || (count > 3)) {
      nextBoard[y][x] = ' ';
    }
  }
}

// call above detection function for all indexes on board
void detectBoard(char board[SZ][SZ], char nextBoard[SZ][SZ])
{
  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
      detect(board, nextBoard, j, i);
    }
  }
}

// algorithm to play animation continuously
void interactive(char board[SZ][SZ], char nextBoard[SZ][SZ]) 
{
  char choice;

  swapBoard(nextBoard, board);
  while(1) {
    // usleep() to add break between generations
    usleep(50000);
    detectBoard(board, nextBoard); 
    nullBoard(board);
    swapBoard(board, nextBoard);
    display(nextBoard);
  }
}

// reads in files to automate cell population
void batch(char board[SZ][SZ], char nextBoard[SZ][SZ], char name[SZ])
{
  FILE* fp;

  fp = fopen(name, "r");

  while(!feof(fp)) {
    char command;
    int x, y;

    // scan line of commands with space as delimeter
    fscanf(fp,"%c %d %d", &command, &x, &y);

    // if command is 'a', add live cell at cords
    if (command == 'a') {
      board[y][x] = 'X';
    }

    // if command is 'p' show finished board for a moment
    if (command == 'p') {
      display(board);
      usleep(1000000);
    }
  }

  // and then run simulation as usual
  interactive(board, nextBoard);
}

// display rules of the game and commands list
void displayRules()
{
  system("clear");
  for (int i = 0; i < SZ; i++) printf("-");
  printf("\nRules of The Game of Life:");
  printf("\n\n  \"Alive\" cells are denoted with \'X\'");
  printf("\n  \"Dead\" cells are denoted with \' \'");
  printf("\n    1. An alive cell lives only lives if it has 2 or 3 alive neighbors");
  printf("\n       Otherwise it dies.");
  printf("\n    2. A dead cell comes to life if it it has exactly 3 neightbors");
  printf("\n       Otherwise it stays dead.");
  printf("\n\nCommands for Interactive mode:");
  printf("\n\n  Select (2) on the home screen and enter any of the following commands:");
  printf("\n    a [int] [int]: add a new live cell at coordinates (x, y) -> [int] [int]");
  printf("\n    r [int] [int]: remove a life cell at coordinates (x, y) -> [int] [int]");
  printf("\n    n: advance simulation to next iteration");
  printf("\n    q: quit the program");
  printf("\n    p: play the game continuously\n");
  for (int i = 0; i < SZ; i++) printf("-");
}

// display board
void display(char board[SZ][SZ])
{
  system("clear");
  printf("\n");
  for (int i = 0; i < SZ; i++) {
    printf(" -");
  }
  printf("\n");
  for (int i = 0; i < SZ; i++) {
    printf("|");
    for (int j = 0; j < SZ; j++) {
      printf("%2c", board[i][j]);
    }
    printf("|\n");
  }
  for (int i = 0; i < SZ; i++) {
    printf(" -");
  }
  printf("\n");
}
