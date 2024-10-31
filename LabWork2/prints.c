#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>


#include "header.h"


void print_scripts_menu()
{
  printf("Enter how you want to read the array:\n");
  printf("1 - Read from file.\n");
  printf("2 - Read from keyboard.\n");
  printf("3 - Make array of random numbers.\n");
}


void print_result(double bubble_time, double vibor_time, double vstavki_time, double slianie_time, double hoara_time)
{
  printf("\n\t+---------------+---------------+---------------+---------------+---------------+");
  printf("\n\t|                      Algorithm execution time in seconds                      |");
  printf("\n\t+---------------+---------------+---------------+---------------+---------------+");
  printf("\n\t|  Bubble sort  | Selection sort| Insertion sort|   Merge sort  |   Quicksort   |");
  printf("\n\t+---------------+---------------+---------------+---------------+---------------+");
  printf("\n\t|\t\t|\t\t|\t\t|\t\t|\t\t|");
  printf("\n\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|", bubble_time, vibor_time, vstavki_time, slianie_time, hoara_time);
  printf("\n\t|\t\t|\t\t|\t\t|\t\t|\t\t|");
  printf("\n\t+---------------+---------------+---------------+---------------+---------------+");
}


void print_for_create_file(int** count_of_random_numbers)
{
  int logic_for_file_creater;
  printf("Can I create a file? (1 - Yes, 0 - No): ");
  scanf("%d", &logic_for_file_creater);
  if (logic_for_file_creater == 1)
  {
    file_creater(&(*count_of_random_numbers));
  }
  else
  {
    printf("Enter the count of numbers in file: ");
    scanf("%d", count_of_random_numbers);
  }
}
