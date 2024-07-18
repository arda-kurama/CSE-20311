// CSE 20311
// Lab 6: Game of Life
// Arda Kurama

#include "lifefunc.h"

int main(int argc, char *argv[])
{
  char board[SZ][SZ];
  char nextBoard[SZ][SZ];
  char choice;
  int mode = 0;
  char name[SZ];

  // initializes the board to ' '
  nullBoard(board);

  // if no files in command line, enter manual mode
  if (argc == 1) {
    printf("\nWelcome to The Game of Life!");
    printf("\nWritten in the C Programming Language");
    printf("\nBy Arda Kurama");

    while(mode != 5) {
      // home screen
      printf("\nHome of The Game of Life!");
      printf("\n  (1) to read the rules");
      printf("\n  (2) to enter interactive mode");
      printf("\n  (3) to enter random mode");
      printf("\n  (4) to enter batch mode");
      printf("\n  (5) to quit the program");
      printf("\nPlease enter your choice: ");
      scanf("%d", &mode);

      switch(mode) {
        case 1:
          // display rules
          displayRules(); 
          continue;
        case 2:
          // call commands until 'p' is chosen
          while (choice != 'p') {
            display(board);
            choice = interact(board);

            // if 'n' is chosen run algorithm once
            if (choice == 'n') {
              swapBoard(nextBoard, board);
              detectBoard(board, nextBoard);
              nullBoard(board);
              swapBoard(board, nextBoard);
              display(nextBoard);
            }

            // if 'q' is chosen quit the program
            if (choice == 'q') return 0; 
          }
          interactive(board, nextBoard);
          break;
        case 3:
          // initialize the board randomly and then run
          randomBoard(board);
          interactive(board, nextBoard);
          break;
        case 4: ;
          // ask and store file name manually and then run
          printf("File name: ");
          scanf("%s", name);
          batch(board, nextBoard, name);
          break;
        case 5:
          // quit program
          printf("\nGoodbye!\n\n");
          break;
        default:
          // error message
          printf("\nPlease enter a choice 1 - 5\n");
          continue;
      }
    }
    return 1;
    
    // if file entered in command line enter automatic mode
  } else if (argc == 2) {

    // call same command as previous batch mode w/ command line input
    batch(board, nextBoard, argv[1]); 
    return 2;
    
    // if >1 file entered with executable, send error
  } else {
    printf("Too many arguments.\n");
    return -1;
  }
}
