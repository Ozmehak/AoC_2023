#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int textToNumber(const char * text)
{
  if (strncmp(text, "one", 3) == 0) return 1;
  if (strncmp(text, "two", 3) == 0) return 2;
  if (strncmp(text, "three", 5) == 0) return 3;
  if (strncmp(text, "four", 4) == 0) return 4;
  if (strncmp(text, "five", 4) == 0) return 5;
  if (strncmp(text, "six", 3) == 0) return 6;
  if (strncmp(text, "seven", 5) == 0) return 7;
  if (strncmp(text, "eight", 5) == 0) return 8;
  if (strncmp(text, "nine", 4) == 0) return 9;
  return -1;
}
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

void part2()
{
  FILE * file;
  char line[100];
  char concatenated[1000];
  int number = 0;
  file = fopen("data.txt", "r");

  if (file == NULL)
  {
    perror("Error opening file");
  }

  int total_sum = 0;
  while (fgets(line, sizeof(line), file) != NULL)
  {
    char first_digit_front = '\0';
    char last_digit_back = '\0';
    for (int i = 0; i < strlen(line); i++)
    {
      if (isdigit(line[i]) || isalpha(line[i]))
      {
        if (isdigit(line[i]))
        {
          first_digit_front = line[i];
          break;
        }
        else if (isalpha(line[i]))
        {
          int number =  textToNumber(&line[i]);

          if (number != -1)
          {
            first_digit_front = '0' + number;
            break;
          }
        }
      }
    }

    for (int j = strlen(line) - 1; j >= 0; j--)
    {
      if (isdigit(line[j]) || isalpha(line[j]))
      {
        if (isdigit(line[j]))
        {
          last_digit_back = line[j];
          break;
        }
        else if (isalpha(line[j]))
        {
          int number = textToNumber(&line[j]);

          if (number != -1)
          {
            last_digit_back = '0' + number;
            break;
          }
        }
      }
    }

    snprintf(concatenated, sizeof(concatenated), "%c%c", first_digit_front, last_digit_back);

    printf("Line: %s", line);
    printf("First digit from the front: %c\n", first_digit_front);
    printf("Last digit from the back: %c\n", last_digit_back);
    printf("Concatenated numbers: %s\n", concatenated);
    printf("\n");

    total_sum += atoi(concatenated);
  }

  printf("Total sum of all concatenated numbers: %d\n", total_sum);

  fclose(file);
}

int main()
{
  part1();
  part2();
  return 0;
}
