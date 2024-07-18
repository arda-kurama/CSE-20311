// CSE 20311
// Lab 9: Crossword Anagram
// By: Arda Kurama

#include "crossfunc.h"

// Function to print unused words 
void displayUnused(Crossword *board, int size, FILE *fp, int iteration) 
{
  // Different outputs based on iteration of algorithm
  if (iteration == 0) {
    for (int i = 0; i < size; i++) {
      if (strcmp(board->list[i], board->unused[i]) == 0) {
        fprintf(fp, "\n%s was not used\n", board->unused[i]);
      }
    }
  } else if (iteration == 1) {
    for (int i = 0; i < size; i++) {
      if (strcmp(board->list[i], board->unused[i]) == 0) {
        fprintf(fp, "\n%s was STILL not used\n", board->unused[i]);
      }
    }
  }
  fprintf(fp, "\n");
}

// Function to display to stdout or file
void display(Crossword *board, int size, FILE *fp)
{
  char direction[LEN];
  int count;

  // Display unused words
  displayUnused(board, size, fp, 0);

  // Print solution board
  fprintf(fp, "Solution:\n");
  fprintf(fp, "-----------------\n");
  for (int i = 0; i < LEN; i++) {
    fprintf(fp, "|");
    for (int j = 0; j < LEN; j++) {
      fprintf(fp, "%c", board->solution[i][j]);
    }
    fprintf(fp, "|\n");
  }
  fprintf(fp, "-----------------\n");

  // Print crossword puzzle
  fprintf(fp, "\nCrossword Puzzle:\n");
  fprintf(fp, "-----------------\n");
  for (int i = 0; i < LEN; i++) {
    fprintf(fp, "|");
    for (int j = 0; j < LEN; j++) {
      fprintf(fp, "%c", board->puzzle[i][j]);
    }
    fprintf(fp, "|\n");
  }
  fprintf(fp, "-----------------\n");

  // Print clues
  fprintf(fp, "\nCLUES:\n");
  fprintf(fp, "Location | Direction | Anagram\n");
  for (int i = 0; i < size; i++) {
   
    // Make sure word is used 
    if (strcmp(board->list[i], board->unused[i]) == 0) continue;
 
    // Convert integer data to string
    if (board->orientation[i] == 0) {
      strcpy(direction, "Across");
    } else if (board->orientation[i] == 1) {
      strcpy(direction, "Down");
    }
    
    // Print and scrambles clues with strfry() function
    fprintf(fp, "%4d, %2d | %9s | %s\n", 
      board->xPos[i], board->yPos[i], direction, strfry(board->list[i]));
  }

  // Try to place remainding words again
  count = placeAgain(board, size);
  place(board, count);

  // Display remaining unused words
  displayUnused(board, count, fp, 1);
}

// Function to make sure word is not improperly adjacent or intersecting other words
int detect(Crossword *board, int word, int *intersect, int i, int j, int k)
{
  int count = 0;
  int xTemp, yTemp;
  *intersect = 0;

  // Update temporary position
  if (board->orientation[i] == 0) {
    yTemp = board->yPos[word] - k;
    xTemp = board->xPos[word] + j;
  }
  if (board->orientation[i] == 1) {
    yTemp = board->yPos[word] + j;
    xTemp = board->xPos[word] - k;
  }

  // Make sure position values are positive (on board)
  if (yTemp < 0) return 0;
  if (xTemp < 0) return 0;

  // Check head position
  if (board->solution[yTemp - 1][xTemp + 1] == '.') count++; 
  if (board->solution[yTemp - 1][xTemp - 1] == '.') count++; 
  if (board->solution[yTemp + 1][xTemp - 1] == '.') count++; 
  if (board->solution[yTemp + 1][xTemp + 1] == '.') count++;
  
  // Check body position
  if (board->orientation[i] == 1) {
    for (int i = 0; i < strlen(board->list[word]); i++) {
      if (board->solution[yTemp][xTemp + i] != '.') (*intersect)++;
    }
  }
  if (board->orientation[i] == 0) {
    for (int i = 0; i < strlen(board->list[word]); i++) {
      if (board->solution[yTemp + i][xTemp] != '.') (*intersect)++;
    }
  }

  // Check tail position
  if (board->orientation[i] == 1) {
    xTemp += strlen(board->list[word]) - 1; 
    if (board->solution[yTemp - 1][xTemp + 1] == '.') count++; 
    if (board->solution[yTemp - 1][xTemp - 1] == '.') count++; 
    if (board->solution[yTemp + 1][xTemp - 1] == '.') count++; 
    if (board->solution[yTemp + 1][xTemp + 1] == '.') count++;
  }
  if (board->orientation[i] == 0) {
    yTemp += strlen(board->list[word]) - 1; 
    if (board->solution[yTemp - 1][xTemp + 1] == '.') count++; 
    if (board->solution[yTemp - 1][xTemp - 1] == '.') count++; 
    if (board->solution[yTemp + 1][xTemp - 1] == '.') count++; 
    if (board->solution[yTemp + 1][xTemp + 1] == '.') count++;
  }

  return count;
}

// Match characters of one string to another
int match(Crossword *board, int word)
{
  int boundary, intersect;

  // Loop through all previous words
  for (int i = 0; i < word; i++) {

    // Set current position to begining of current word
    board->yPos[word] = board->yPos[i];
    board->xPos[word] = board->xPos[i];

    // Loop through chars of previous words
    for (int j = 0; j < strlen(board->list[i]); j++) {

      // Loop through chars of current word
      for (int k = 0; k < strlen(board->list[word]); k++) {

        // Find position where chars match
        if (board->list[i][j] == board->list[word][k]) {

          // Make sure word is not improperly intersecting or adjacent to other words
          boundary = detect(board, word, &intersect, i, j, k);

          // If all checks are passed
          if ((boundary == 8) && (intersect == 1)) {

            // Update position
            if (board->orientation[i] == 0) {
              board->orientation[word] = 1;
              board->yPos[word] -= k;
              board->xPos[word] += j;
            }

            if (board->orientation[i] == 1) {
              board->orientation[word] = 0;
              board->yPos[word] += j;
              board->xPos[word] -= k;
            }

            // Return success code
            return 1;
          }
        }
      }
    }
  }

  // Return failure code
  return 0;
}

// Function to place words on crossword
void place(Crossword *board, int size)
{
  int status;

  for (int i = 1; i < size; i++) {

    // Find matches between chars of words and return status 
    status = match(board, i);
   
    // If status is a success 
    if (status == 1) {

      // If orientation of word is horizontal place word horizontally
      if (board->orientation[i] == 0) {
        for (int j = 0; j < strlen(board->list[i]); j++) {
          board->solution[board->yPos[i]][board->xPos[i] + j] = board->list[i][j];
          board->puzzle[board->yPos[i]][board->xPos[i] + j] = ' ';
        }
      }

      // If orientation of word is vertical place word vertically
      if (board->orientation[i] == 1) {
        for (int j = 0; j < strlen(board->list[i]); j++) {
          board->solution[board->yPos[i] + j][board->xPos[i]] = board->list[i][j];
          board->puzzle[board->yPos[i] + j][board->xPos[i]] = ' ';
        }
      }
    } else {
      
      // If status is failure store unplaced words
      strcpy(board->unused[i], board->list[i]);
    }
  }
}

// Function to place first word on crossword
void placeFirst(Crossword *board, int size)
{
  // Set x and y position to middle of board
  board->yPos[0] = LEN / 2;
  board->xPos[0] = (LEN - strlen(board->list[0])) / 2;

  // Place first word
  board->orientation[0] = 0;
  for (int i = 0; i < strlen(board->list[0]); i++) {
    board->solution[board->yPos[0]][board->xPos[0] + i] = board->list[0][i];
    board->puzzle[board->yPos[0]][board->xPos[0] + i] = ' ';
  }
}

// Function to run algorithm again and place remaining words
int placeAgain(Crossword *board, int size)
{
  int count = 1;
  Crossword temp;

  // Store values in temp struct
  temp = *board;

  // Reset board struct
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < LEN; j++) {
      board->list[i][j] = '\0';
    }
  }

  // Fill board struct with only unused words
  for (int i = 0; i < size; i++) {
    if (strcmp(board->unused[i], temp.list[i]) == 0) {
      strcpy(board->list[count], temp.list[i]);
      count++;
    }
  }
 
  // Return new size of board->list[] array 
  return count;
}

// Function to initialize boards
void initBoard(Crossword *board)
{
  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      board->puzzle[i][j] = '#';
      board->solution[i][j] = '.';
    } 
  }
}

// Function to sort words
void allSort(Crossword *board, int size)
{
  // Create a temporary place to store words
  Crossword temp;
  for (int i = 0; i < size; i++) {
    strcpy(temp.list[i], board->list[i]);
  }

  // Bubble sort words
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (strlen(board->list[j]) < strlen(board->list[j + 1])) {
        strcpy(temp.list[j], board->list[j]);
        strcpy(board->list[j], board->list[j + 1]);
        strcpy(board->list[j + 1], temp.list[j]);
      }
    }
  }
}

// Function to make characters of words all uppercase
void allUpper(Crossword *board, int size)
{
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < strlen(board->list[i]); j++) {
      board->list[i][j] = toupper(board->list[i][j]);
    }
  }
}

// Function to check input and return codes
int checkLine(char line[])
{
  if (line[0] == '.') return 0; 
  for (int i = 0; i < strlen(line); i++) {
    if (!isalpha(line[i])) return 1;
  }
  if (strlen(line) < 2) return 2;
  if (strlen(line) > LEN) return 3;
  else return 4;
}

// Function to allow manual input of words
int manualInput(Crossword *board)
{
  char word[LEN * LEN];
  int n = 0, code;

  printf("\nEnter a list of words:\n");

  // Parses and reads in words manually rejecting improperly formatted words
  while(1) {
    fgets(word, (LEN * LEN), stdin);
    word[strlen(word) - 1] = '\0';

    code = checkLine(word);
    if (code == 0) break;
    if (code == 1) printf("not all letters!\n"); 
    if (code == 2) printf("too short!\n");
    if (code == 3) printf("too long!\n");
    if (code == 4) {
      strcpy(board->list[n], word);
      n++;
    }
    if (n == MAX) break;
  }
  return n;
}

// Function to write output to a file
FILE *writeFile(Crossword *board, char name[])
{
  FILE *fp;

  // Sets up a file pointer in "write" mode
  fp = fopen(name, "w");
  return fp;
}

// Function to read output from a file
int readFile(Crossword *board, char name[])
{
  FILE *fp;
  char word[LEN * LEN];
  int n = 0, code;

  // Sets up a file pointer in "read" mode
  fp = fopen(name, "r");

  // Reads in words from file rejecting improperly formatted words
  if (fp) {
    while(1) {
      fgets(word, (LEN * LEN), fp);
      if (feof(fp)) break;
      word[strlen(word) - 1] = '\0';

      code = checkLine(word);
      if (code == 0) break;
      if (code == 1) printf("not all letters!\n"); 
      if (code == 2) printf("too short!\n");
      if (code == 3) printf("too long!\n");
      if (code == 4) {
        strcpy(board->list[n], word);
        n++;
      }
      if (n == MAX) break;
    }
    return n;
  } else {
    printf("file does not exist!\n");
    return 0;
  }
}
