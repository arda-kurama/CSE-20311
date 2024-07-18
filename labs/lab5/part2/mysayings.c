// CSE 20311
// Part 2: A sayings manager
// By: Arda Kurama

#include <stdio.h>
#include <string.h>

// SIZE and STRLEN definition for database data structure
#define SIZE 50
#define STRLEN 256

// Function declarations
void displayData(char [][STRLEN], int);
int addData(char [][STRLEN], int);
void searchData(char [][STRLEN], int);
FILE* readFile();
FILE* writeFile();
void display();

int main()
{
	int choice, dataSize;
  FILE* fpRead = readFile();
  char database[SIZE][STRLEN];

  // Enter strings from startup file into database
  for (dataSize = 0; dataSize < SIZE; dataSize++) {
    if (feof(fpRead)) break;
    fgets(database[dataSize], STRLEN, fpRead);
  }

  // Driving while and switch statement
	while (choice != 5) {

  // Print display and ask user for choice every loop
	display();
	scanf("%d", &choice);

    switch(choice) {
      case 1:
        displayData(database, dataSize);
        break;
      case 2:
        dataSize = addData(database, dataSize);
        break;
      case 3:
        searchData(database, dataSize);
        break;
      case 4: ; // semicolon to allow variable initialization under a label
        FILE* fpWrite = writeFile();

        // Write strings from database into new file
        for (int i = 0; i < dataSize; i++) {
          fputs(database[i], fpWrite);
        }
        break;
      case 5:
        printf("Goodbye!\n");
        break;
      default:
        printf("Please enter a number (1) - (5)\n");
        continue;
    }
	}

	return 0;
}

// Function to display data
void displayData(char database[][STRLEN], int size)
{
  printf("\n");
  for (int i = 0; i < size; i++) {
    printf("%s", database[i]); 
  }
}

// Function to add data to database
int addData(char database[][STRLEN], int size)
{
  printf("Enter new saying: ");
  getchar(); // must get '\n' char from stdin
  fgets(database[size], STRLEN, stdin);

  // Must return new size of database 
  // ie. how many sayings it currently holds
  return (size += 1);
}

// Function to search for substring
void searchData(char database[][STRLEN], int size)
{
  char substring[STRLEN];

  printf("Enter phrase to search for: ");
  getchar();

  // Must replace '\n' in string with '\0'
  fgets(substring, STRLEN, stdin);
  substring[strlen(substring) - 1] = '\0';

  // Print string if substring is in string
  printf("\n");
  for (int i = 0; i < size; i++) {
    if (strstr(database[i], substring) != NULL) {
      printf("%s", database[i]);
    }
  } 
}

// Function to set up read file pointer
FILE* readFile()
{
  FILE* fp;
  char name[30];

  printf("Enter name of file: ");
  scanf("%s", name);  
  fp = fopen(name, "r");

  // If file does not exist, sends error and prompts user to retry 
  if (fp) return fp;
  else {
    printf("File does not exist. Please try again.\n");
    readFile();
  }
}

// Function to set up write file pointer
FILE* writeFile()
{
  FILE* fp;
  char name[30];

  printf("Enter name of new file: ");
  scanf("%s", name);
  fp = fopen(name, "w");

  return fp;
}

// Function to print display
void display()
{
	printf("\nSayings manager!\n");
	printf("(1) Display all sayings currently in the database.\n");
	printf("(2) Enter a new saying into the database.\n");
	printf("(3) List sayings that contain a given substring entered by the user.\n");
	printf("(4) Save all sayings in a new text file.\n");
	printf("(5) Quit the program.\n");
	printf("What would you like to do: ");
}
