#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void part1()
{
  FILE * file_pointer;
  char line[100];

  file_pointer = fopen("data.txt", "r");
  if (file_pointer == NULL)
  {
    perror("Error Opening File");
  }
  int total_sum = 0;
  while (fgets(line, sizeof(line), file_pointer) != NULL)
  {
    int length = strlen(line);
    char first_digit = '\0';
    for (int i = 0; i < length; i++)
    {
      if (isdigit(line[i]))
      {
        first_digit = line[i];
        break;
      }
    }

    char last_digit = '\0';
    for (int j = length - 1; j >= 0; j--)
    {
      if (isdigit(line[j]))
      {
        last_digit = line[j];
        break;
      }
    }

    if (first_digit != '\0' && last_digit != '\0')
    {
      int concatenated_value = (first_digit - '0') * 10 + (last_digit - '0');
      total_sum += concatenated_value;
    }
  }

  printf("Total: %d\n", total_sum);

  fclose(file_pointer);
}

int main()
{
  part1();
  return 0;
}
