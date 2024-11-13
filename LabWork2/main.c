#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#include "header.h"



void main()
{
  int count_of_random_numbers, script_number;
  double* massive_of_numbers;
  system("chcp 1251>NUL");
  srand(time(0));
  printf("¬ведите способ обработки массива\n");
  printf("1 - сортировка\n");
  printf("2 - норма вектора\n");
  printf("3 - завершить выполнение программы.\n");
  printf("—ценарий: ");
  scanf("%d", &script_number);
  switch (script_number)
  {
  case 2:
    print_for_choose_of_enter_vector(&count_of_random_numbers, &massive_of_numbers);
    print_for_norma(count_of_random_numbers, massive_of_numbers);
    add_data_to_file(count_of_random_numbers, massive_of_numbers);
    free_massive(massive_of_numbers);
    break;
  case 1:
    print_for_choose_of_enter_massive(&count_of_random_numbers, &massive_of_numbers);
    print_for_sorting(count_of_random_numbers, massive_of_numbers);
    free_massive(massive_of_numbers);
    break;
  case 3:
    return;
  default:
    break;
  }
  system("pause");
  system("cls");
  main();
}