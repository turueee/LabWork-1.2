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
  print_scripts_menu();
  print_for_choose_of_enter(&count_of_random_numbers, &massive_of_numbers);
  all_sorting(count_of_random_numbers, massive_of_numbers);
}