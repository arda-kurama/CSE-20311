// CSE 20311
// Lab 7 Part 2
// Arda Kurama

#include "statesfunc.h"

// Function to sort states by year they joined the union
void sortStates(State states[], int size)
{
  // Declared new array to preserve old array information
  State preserve[MAX];

  // Populate new array
  for (int i = 0; i < size; i++) {
    preserve[i] = states[i];
  }

  // Bubble sort to sort year ascending
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (states[j].year > states[j + 1].year) {

          // Switches two indicies if preceeding value larger than succeeding value
          State temp = states[j];
          states[j] = states[j + 1];
          states[j + 1] = temp;
      }
    }
  }

  // Display new array
  displayInfo(states, size);

  // Return states array to origional values
  for (int i = 0; i < size; i++) {
    states[i] = preserve[i];
  }
}

// Function to print year a given state joined the union
void nameToYear(State states[])
{
  char choice[SIZE];
  int n = 0;

  // Need to get \n character from display to use fgets
  getchar();

  // Get desired state
  printf("\nEnter a state: ");
  fgets(choice, SIZE, stdin);
  choice[strlen(choice) - 1] = '\0';

  // Convert input to proper case
  for (int i = 0; i < strlen(choice); i++) {
    choice[i] = tolower(choice[i]);
  }
  choice[0] = toupper(choice[0]);

  // Cycle through array until choice equals a state name and return index
  while (strcmp(choice, states[n].name)) {
    n++;

    // Send error message if input is not a state
    if (n > MAX) {
      printf("\nPlease enter a state name!\n");
      break;
    }
  }

  // Print the name and year of the state at that index
  if (!strcmp(choice, states[n].name)) {
    printf("%s joined the union in %d\n", states[n].name, states[n].year); 
  }
}

// Function to guess a state based on its capital
void guessState(State states[], int size)
{
  int random;
  char choice[SIZE];

  // Declare a random int between 0 - 49
  random = rand() % size;

  // Need to get \n character from display to use fgets
  getchar();

  // Get user inputted state
  printf("What state has the capital %s: ", states[random].capital);
  fgets(choice, SIZE, stdin);
  choice[strlen(choice) - 1] = '\0';
  
  // Convert input to proper case
  for (int i = 0; i < strlen(choice); i++) {
    choice[i] = tolower(choice[i]);
  }
  choice[0] = toupper(choice[0]);

  // If chosen state is same as state name at random index, answer is correct
  if (!strcmp(choice, states[random].name)) {
    printf("\nCorrect! \n");
  } else {

    // If not, answer is incorrect and display correct answer
    printf("\nIncorrect! \n");
    printf("%s has the capital %s\n", 
    states[random].name, states[random].capital);
  }
}

// Function to guess a capiptal based on its name
void guessCapital(State states[], int size)
{
  int random;
  char choice[SIZE];

  // Declare a random int between 0 - 49
  random = rand() % size;
  
  // Get char from display
  getchar();

  // Get user inputted capital
  printf("What is the capital of %s: ", states[random].name);
  fgets(choice, SIZE, stdin);
  choice[strlen(choice) - 1] = '\0';
  
  // Convert input to proper case
  for (int i = 0; i < strlen(choice); i++) {
    choice[i] = tolower(choice[i]);
  }
  choice[0] = toupper(choice[0]);

  // If chosen capital is same as capital name at random index, answer is correct
  if (!strcmp(choice, states[random].capital)) {
    printf("\nCorrect! \n");
  } else {

    // If not, answer is incorrect and display correct answer
    printf("\nIncorrect! \n");
    printf("The capital of %s is %s\n", 
    states[random].name, states[random].capital);
  } 
}

// Function to display all info
void displayInfo(State states[], int size)
{
  printf("\nAbbreviation |           Name |        Capital | Year it joined union\n");
  printf("------------------------------------------------------------\n");
  for (int i = 0; i < size; i++) {
    printf("%12s | %14s | %14s | %4d\n", 
    states[i].abv, states[i].name, states[i].capital, states[i].year);
  }
}

// Function to display main U/I
void display()
{
  printf("\nUSA States Test!\n");
  printf("(1) Print all information\n");
  printf("(2) Print year a given state joined the union based on name\n");
  printf("(3) List states ascending based on year they joined the union\n");
  printf("(4) Guess state based on capital\n");
  printf("(5) Guess capital based on state\n");
  printf("(6) Exit\n");
  printf("Please enter your choice: ");
}

// Function to populate state array with file information
int initialize(State states[], FILE *fp)
{
  char currentLine[SIZE * 3];
  int n = 0;

  while(1) {

    // Get information line by line from the file
    fgets(currentLine, SIZE * 3, fp);

    // Exit loop if end of file
    if (feof(fp)) break;

    // Parse individual lines into correct struct positions
    strcpy(states[n].abv, strtok(currentLine, ","));
    strcpy(states[n].name, strtok(NULL, ","));
    strcpy(states[n].capital, strtok(NULL, ","));
    states[n].year = atoi(strtok(NULL, ","));

    // Count number of elements in array
    n++;
  }

  // Return array size
  return n;
}

// Function to set up file pointer
FILE* readFile(char name[])
{
  FILE *fp;

  fp = fopen(name, "r");

  if (fp) return fp;
  else {

    // Send error message if file does not exist
    printf("File does not exist! Please try again.\n");
    return 0;
  } 
}
