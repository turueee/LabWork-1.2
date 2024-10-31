#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#include "header.h"


double make_random_number(double minimum_of_random_numbers, double maximum_of_random_numbers)
{
  double zero_one, zero_max_ch;
  zero_one = (double)rand() / RAND_MAX;
  zero_max_ch = zero_one * (maximum_of_random_numbers - minimum_of_random_numbers);
  return zero_max_ch + minimum_of_random_numbers;
}


void file_creater(int *count_of_random_numbers)
{
  int counter;
  double maximum_of_random_numbers, minimum_of_random_numbers;
  FILE* file_of_numbers;
  double random_number;
  printf("Enter the minimum number to generate: ");
  scanf("%lf", &minimum_of_random_numbers);
  printf("Enter the maximum number to generate: ");
  scanf("%lf",&maximum_of_random_numbers);
  printf("Enter the count of generated numbers: ");
  scanf("%d", count_of_random_numbers);
  file_of_numbers = fopen("store_of_random_numbers.txt", "w");
  for (counter = 0; counter < *count_of_random_numbers; counter++)
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
    fscanf(file_of_numbers, "%lf", &number_from_file);
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

void print_for_massive(int count_of_random_numbers, double* massive_of_numbers)
{
  int counter;
  printf("\n");
  for (counter = 0; counter < count_of_random_numbers; counter++)
    printf("%lf\n", massive_of_numbers[counter]);
}


void get_piece_of_massive(int begin_index, int end_index, double* full_massive, double** piece_of_massive)
{
  int len_of_piece, counter = begin_index;
  len_of_piece = end_index - begin_index;
  (*piece_of_massive) = (double*)malloc(sizeof(double) * len_of_piece);
  for (counter; counter < end_index; counter++)
  {
    (*piece_of_massive)[counter - begin_index] = full_massive[counter];
  }
}


void add_piece_to_massive(int begin_index, int end_index, double* full_massive, double* piece_of_massive)
{
  int counter = begin_index;
  for (counter; counter < end_index; counter++)
  {
    full_massive[counter] = (piece_of_massive)[counter - begin_index];
  }
}


void massive_copy(int count_of_random_numbers_in_original_massive, double* original_massive, double** copy_massive)
{
  int counter;
  (*copy_massive) = (double*)malloc(sizeof(double) * count_of_random_numbers_in_original_massive);
  for (counter = 0; counter < count_of_random_numbers_in_original_massive; counter++)
  {
    (*copy_massive)[counter] = original_massive[counter];
  }
}