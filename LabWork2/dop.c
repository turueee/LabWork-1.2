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
  double maxi = massive_of_numbers[0];
  int counter;
  for (counter = 1; counter < count_of_random_numbers; counter++)
  {
    if (massive_of_numbers[counter] > maxi)
      maxi = massive_of_numbers[counter];
  }
  return maxi;
}


double gelder_norma(int count_of_random_numbers, double* massive_of_numbers)
{
  double sum = 0;
  int counter;
  for (counter = 0; counter < count_of_random_numbers; counter++)
    sum += pow(massive_of_numbers[counter], (double)count_of_random_numbers);
  return pow(sum, 1 / (double)count_of_random_numbers);
}


void vector_norming(int count_of_random_numbers, double* massive_of_numbers)
{
  double maximum = endless_norma(count_of_random_numbers, massive_of_numbers);
  int counter;
  for (counter = 0; counter < count_of_random_numbers; counter++)
  {
    massive_of_numbers[counter] /= maximum;
  }
  printf("[ ");
  for (counter = 0; counter < count_of_random_numbers; counter++)
    printf("%lf\t", massive_of_numbers[counter]);
  printf("]\n");
}


void all_norma(int count_of_random_numbers, double* massive_of_numbers)
{
  printf("Первая норма вектора: %lf.\n", first_norma(count_of_random_numbers, massive_of_numbers));
  printf("Вторая норма вектора: %lf.\n", second_norma(count_of_random_numbers, massive_of_numbers));
  printf("Гельдерова норма вектора: %lf.\n", gelder_norma(count_of_random_numbers, massive_of_numbers));
  printf("Бесконечная норма вектора: %lf\n", endless_norma(count_of_random_numbers, massive_of_numbers));
  printf("Нормированный вектор:\n");
  vector_norming(count_of_random_numbers, massive_of_numbers);
}