#include <stdio.h>
#include <string.h>

int main(void)
{
  // Open file
  FILE *file = fopen("phonebook.csv", "a");

  char name[20];
  char number[20];

  // Get string from user
  printf("Name : ");
  scanf("%s",name);
  printf("Number : ");
  scanf("%s",number);

  // Print strings to file
  fprintf(file,"%s,%s\n",name,number);

  // Close file
  fclose(file);

  return 0;
}