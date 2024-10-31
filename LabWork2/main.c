#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#include "header.h"


void print_for_choose()


void main()
{
  int count_of_random_numbers, script_number, logic_for_file_creater;
  double* massive_of_numbers;
  system("chcp 1251>NUL");
  srand(time(0));
  print_scripts_menu();
  scanf("%d", &script_number);
  switch (script_number)
  {
  case 1:
    print_for_create_file(&count_of_random_numbers);
    massive_from_file_creater(count_of_random_numbers, &massive_of_numbers);
    all_sorting(count_of_random_numbers, massive_of_numbers);
    break;
  case 2:
    massive_from_keyboard(&count_of_random_numbers, &massive_of_numbers);
    all_sorting(count_of_random_numbers, massive_of_numbers);
    break;
  case 3:
    massive_from_random(&count_of_random_numbers, &massive_of_numbers);
    all_sorting(count_of_random_numbers, massive_of_numbers);
    break;
  default:
    printf("Script error! Unknown script!\n");
    system("pause");
    system("cls");
    main();
    break;
  }
}