// CSE 20311
// Lab 7 Part 2
// Arda Kurama

#include "statesfunc.h"

// Allows command line inputs for testing
int main(int argc, char *argv[]) 
{
  FILE *fp;
  State states[MAX];
  int size, choice;
  char name[SIZE];

  // If no file entered in command line, enter manually
  if (argc == 1) {
    printf("Enter file name: ");
    scanf("%s", name);
    fp = readFile(name); 
  }

  // If file enterd in command line, send directly to function
  if (argc == 2) {
    fp = readFile(argv[1]); 
  }

  // If more than one file entered in command line, send error
  if (argc > 2) {
    printf("Too many arguments! \n\n");
    return -1;
  }

  // Initialize array and get its size
  size = initialize(states, fp);

  // Driving while loop
  while(1) { 

    // Allows for different random values at each iteration
    srand(time(NULL));

    // Print display and get user choice at each iteration
    display();
    scanf("%d", &choice);
   
    // Main switch statement to call correct functions 
    switch (choice) {
      case 1:
        displayInfo(states, size);
        break;
      case 2:
        nameToYear(states);
        break;
      case 3:
        sortStates(states, size);
        break;
      case 4:
        guessState(states, size);
        break;
      case 5:
        guessCapital(states, size);
        break;
      case 6:
        printf("\nGoodbye! \n\n");
        return 0;
      default:
        // Send error message if choice is outside of switch statement
        printf("Please enter a choice 1-6!\n");
        continue;
    }
  }
}
