#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#include "header.h"

double first_norma(int count_of_random_numbers, double* massive_of_numbers)
{
  int counter;
  double first_norma = 0;
  for (counter = 0; counter < count_of_random_numbers; counter++)
    first_norma += massive_of_numbers[counter];
  return first_norma;
}


double second_norma(int count_of_random_numbers, double* massive_of_numbers)
{
  double second_norma = 0;
  int counter;
  for (counter = 0; counter < count_of_random_numbers; counter++)
    second_norma += (massive_of_numbers[counter] * massive_of_numbers[counter]);
  return sqrt(second_norma);
}


double endless_norma(int count_of_random_numbers, double* massive_of_numbers)
{
  double maxi = 
}