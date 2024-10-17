#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double make_random_number(double minimum_of_random_numbers, double maximum_of_random_numbers)
{
  double zero_one, zero_max_ch, random_number;
  zero_one = (double)rand() / RAND_MAX;
  zero_max_ch = zero_one * (maximum_of_random_numbers - minimum_of_random_numbers);
  return zero_max_ch + minimum_of_random_numbers;
}


void file_creater(double minimum_of_random_numbers, double maximum_of_random_numbers, int count_of_random_numbers)
{
  int counter;
  FILE* file_of_numbers;
  double random_number;
  file_of_numbers = fopen("store_of_random_numbers.txt","w");
  for (counter = 0; counter < count_of_random_numbers; counter++)
  {
    if (file_of_numbers != NULL)
    {
      random_number = make_random_number(minimum_of_random_numbers, maximum_of_random_numbers);
      fprintf(file_of_numbers, "%lf\n", random_number);
    }
    else
      printf("FILE ERROR!!!");
  }
  fclose(file_of_numbers);
}


void massive_from_file_creater(int count_of_numbers, double** massive_of_numbers)
{
  int counter;
  FILE* file_of_numbers;
  double number_from_file;
  *massive_of_numbers = (double*)malloc(sizeof(double) * count_of_numbers);
  file_of_numbers = fopen("store_of_random_numbers.txt", "r");
  for (counter = 0; counter < count_of_numbers; counter++)
  {
    fscanf(file_of_numbers, "%lf",&number_from_file);
    (*massive_of_numbers)[counter] = number_from_file;
  }
  fclose(file_of_numbers);
}


void massive_from_keyboard(int* count_of_numbers, double** massive_of_numbers)
{
  int counter;
  double number_from_keyboard;
  printf("Enter the count of numbers: ");
  scanf("%d", count_of_numbers);
  *massive_of_numbers = (double*)malloc(sizeof(double) * *count_of_numbers);
  for (counter = 0; counter < *count_of_numbers; counter++)
  {
    printf("Enter the massive_of_numbers[%d]: ", counter);
    scanf("%lf", &number_from_keyboard);
    (*massive_of_numbers)[counter] = number_from_keyboard;
  }
}


void massive_from_random(int* count_of_random_numbers, double** massive_of_numbers)
{
  double minimum_of_random_numbers, maximum_of_random_numbers;
  int counter;
  printf("Enter the minimum number to generate: ");
  scanf("%lf", &minimum_of_random_numbers);
  printf("Enter the maximum number to generate: ");
  scanf("%lf", &maximum_of_random_numbers);
  printf("Enter the count of generated numbers: ");
  scanf("%d", count_of_random_numbers);
  (*massive_of_numbers) = (double*)malloc(sizeof(double) * *count_of_random_numbers);
  for (counter = 0; counter < *count_of_random_numbers; counter++)
    (*massive_of_numbers)[counter] = make_random_number(minimum_of_random_numbers, maximum_of_random_numbers);
}

void free_massive(double* massive_of_numbers)
{
  free(massive_of_numbers);
}


double bubble_sorting(int count_of_random_numbers, double* massive_of_numbers)
{
  int counter1, counter2;
  double rezerv;
  clock_t begin = 0, end = 0;
  begin = clock();
  for (counter1 = 0; counter1 < count_of_random_numbers; counter1++)
  {
    for (counter2 = 0; counter2 < (count_of_random_numbers-1); counter2++)
    {
      if (massive_of_numbers[counter2] > massive_of_numbers[counter2 + 1])
      {
        rezerv = massive_of_numbers[counter2];
        massive_of_numbers[counter2] = massive_of_numbers[counter2+1];
        massive_of_numbers[counter2+1] = rezerv;
      }
    }
  }
  end = clock();
  return (double)(end - begin) / CLOCKS_PER_SEC;
}





void all_sorting(int count_of_random_numbers, double* massive_of_numbers)
{
  double bubble_time;
  int counter;
  bubble_time = bubble_sorting(count_of_random_numbers, massive_of_numbers);
  printf("\n%lf\n", bubble_time);
  free_massive(massive_of_numbers);
}


void filling_massive(int* count_of_random_numbers,int** massive_numbers)
{
}

void main()
{
  double minimum_of_random_numbers, maximum_of_random_numbers,bubble_time;
  int count_of_random_numbers, counter, script_number, logic_for_file_creater;
  double* massive_of_numbers;
  srand(time(0));
  printf("Enter the number of script: ");
  scanf("%d", &script_number);
  if (script_number == 1)
  {
    printf("Can I create a file? (1 - Yes, 0 - No): ");
    scanf("%d", &logic_for_file_creater);
    if (logic_for_file_creater == 1)
    {
      printf("Enter the minimum number to generate: ");
      scanf("%lf", &minimum_of_random_numbers);
      printf("Enter the maximum number to generate: ");
      scanf("%lf", &maximum_of_random_numbers);
      printf("Enter the count of generated numbers: ");
      scanf("%d", &count_of_random_numbers);
      file_creater(minimum_of_random_numbers, maximum_of_random_numbers, count_of_random_numbers);
    }
    else
    {
      printf("Enter the count of numbers in file: ");
      scanf("%d", &count_of_random_numbers);
    }
    massive_from_file_creater(count_of_random_numbers, &massive_of_numbers);
    all_sorting(count_of_random_numbers, massive_of_numbers);
  }
  else if (script_number == 2)
  {
    massive_from_keyboard(&count_of_random_numbers, &massive_of_numbers);
    all_sorting(count_of_random_numbers, massive_of_numbers);
  }
  else if (script_number == 3)
  {
    massive_from_random(&count_of_random_numbers, &massive_of_numbers);
    all_sorting(count_of_random_numbers, massive_of_numbers);
  } 
}