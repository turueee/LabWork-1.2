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


void print_result(double bubble_time, double vibor_time, double vstavki_time, double slianie_time, double hoara_time,double shell_time,double counter_time)
{
  system("cls");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  printf("\n|                                      Algorithm execution time in seconds                                      |");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  printf("\n|                     Range                     |       Count of numbers        |            Script             |");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  //printf("\n\t|\t%lf\t%lf\t%d\t%d", min_in_range, max_in_range, count_of_numbers, script);
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  printf("\n|  Bubble sort  | Selection sort| Insertion sort|   Merge sort  |   Quicksort   |   Shell sort  |  Counter sort |");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  printf("\n|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|");
  printf("\n|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|", bubble_time, vibor_time, vstavki_time, slianie_time, hoara_time,shell_time,counter_time);
  printf("\n|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
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
  system("cls");
}


void print_for_massive(int count_of_random_numbers, double* massive_of_numbers)
{
  int counter;
  printf("\n");
  for (counter = 0; counter < count_of_random_numbers; counter++)
    printf("%lf\n", massive_of_numbers[counter]);
}


void print_for_choose_of_enter(int* count_of_random_numbers, double** massive_of_numbers)
{
  int script_number;
  print_scripts_menu();
  scanf("%d", &script_number);
  switch (script_number)
  {
  case 1:
    print_for_create_file(&(*count_of_random_numbers));
    massive_from_file_creater(*count_of_random_numbers, &*massive_of_numbers);
    break;
  case 2:
    massive_from_keyboard(&*count_of_random_numbers, &*massive_of_numbers);
    break;
  case 3:
    massive_from_random(&*count_of_random_numbers, &*massive_of_numbers);
    break;
  default:
    printf("Script error! Unknown script!\n");
    system("pause");
    system("cls");
    print_for_choose_of_enter(&*count_of_random_numbers, &*massive_of_numbers);
    break;
  }
}
