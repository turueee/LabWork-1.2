#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#include "header.h"

double bubble_sorting(int count_of_random_numbers, double* massive_of_numbers)
{
  int counter1, counter2;
  double rezerv;
  clock_t begin = 0, end = 0;
  begin = clock();
  for (counter1 = 0; counter1 < count_of_random_numbers; counter1++)
  {
    for (counter2 = 0; counter2 < (count_of_random_numbers - 1); counter2++)
    {
      if (massive_of_numbers[counter2] > massive_of_numbers[counter2 + 1])
      {
        rezerv = massive_of_numbers[counter2];
        massive_of_numbers[counter2] = massive_of_numbers[counter2 + 1];
        massive_of_numbers[counter2 + 1] = rezerv;
      }
    }
  }
  end = clock();
  return (double)(end - begin) / CLOCKS_PER_SEC;
}


double sorting_vibor(int count_of_random_numbers, double* massive_of_numbers)
{
  int counter1, counter2, minimum;
  double rezerv;
  clock_t begin = 0, end = 0;
  begin = clock();
  for (counter1 = 0; counter1 < count_of_random_numbers; counter1++)
  {
    minimum = counter1;
    for (counter2 = counter1 + 1; counter2 < count_of_random_numbers; counter2++)
    {
      if (massive_of_numbers[minimum] > massive_of_numbers[counter2])
        minimum = counter2;
    }
    rezerv = massive_of_numbers[minimum];
    massive_of_numbers[minimum] = massive_of_numbers[counter1];
    massive_of_numbers[counter1] = rezerv;
  }
  end = clock();
  return (double)(end - begin) / CLOCKS_PER_SEC;
}


double sorting_vstavkami(int count_of_random_numbers, double* massive_of_numbers)
{
  int counter1, counter2;
  double key;
  clock_t begin = 0, end = 0;
  begin = clock();
  for (counter1 = 2; counter1 < count_of_random_numbers; counter1++)
  {
    key = massive_of_numbers[counter1];
    counter2 = counter1 - 1;
    while (counter2 > 0 && massive_of_numbers[counter2] > key)
    {
      massive_of_numbers[counter2 + 1] = massive_of_numbers[counter2];
      counter2--;
    }
    massive_of_numbers[counter2 + 1] = key;
  }
  end = clock();
  return (double)(end - begin) / CLOCKS_PER_SEC;
}


double sorting_slianie(int count_of_rundom_numbers, double* massive_of_numbers)
{
  int counter1 = 2, counter2, ost_begin, ost_end;
  double* piece_of_massive;
  clock_t begin = 0, end = 0;
  begin = clock();
  while (counter1 < count_of_rundom_numbers)
  {
    for (counter2 = 0; counter2 + counter1 < count_of_rundom_numbers; counter2 += counter1)
    {
      get_piece_of_massive(counter2, counter2 + counter1, massive_of_numbers, &piece_of_massive);
      sorting_vstavkami(counter1, piece_of_massive);
      add_piece_to_massive(counter2, counter2 + counter1, massive_of_numbers, piece_of_massive);
      free(piece_of_massive);
    }
    ost_begin = count_of_rundom_numbers - count_of_rundom_numbers % counter1;
    ost_end = count_of_rundom_numbers;
    get_piece_of_massive(ost_begin, ost_end, massive_of_numbers, &piece_of_massive);
    sorting_vibor(ost_end - ost_begin, piece_of_massive);
    add_piece_to_massive(ost_begin, ost_end, massive_of_numbers, piece_of_massive);
    free(piece_of_massive);
    counter1 *= 2;
  }
  sorting_vibor(count_of_rundom_numbers, massive_of_numbers);
  end = clock();
  return (double)(end - begin) / CLOCKS_PER_SEC;
}


double sorting_hoara(int left, int right, double* massive_of_numbers)
{
  int l_hold = left;
  int r_hold = right;
  double pivot;
  int index;
  clock_t begin = 0, end = 0;
  begin = clock();
  pivot = massive_of_numbers[left];
  while (left < right)
  {
    while ((massive_of_numbers[right] > pivot) && (left < right))
      right--;
    if (left != right)
    {
      massive_of_numbers[left] = massive_of_numbers[right];
      left++;
    }
    while ((massive_of_numbers[left] < pivot) && (left < right))
      left++;
    if (left != right)
    {
      massive_of_numbers[right] = massive_of_numbers[left];
      right--;
    }
  }
  massive_of_numbers[left] = pivot;
  index = left;
  left = l_hold;
  right = r_hold;
  if (left < index)
    sorting_hoara(left, index - 1, massive_of_numbers);
  if (right > index)
    sorting_hoara(index + 1, right, massive_of_numbers);
  end = clock();
  return (double)(end - begin) / CLOCKS_PER_SEC;
}


double sorting_shell(int count_of_random_numbers, double* massive_of_numbers)
{
  int counter1, counter2, step;
  double reserv;
  clock_t begin = 0, end = 0;
  begin = clock();
  for (step = count_of_random_numbers/2;step>0;step/=2)
    for (counter1 = step; counter1 < count_of_random_numbers; counter1++)
    {
      reserv = massive_of_numbers[counter1];
      for (counter2 = counter1; counter2 >= step; counter2 -= step)
      {
        if (reserv < massive_of_numbers[counter2 - step])
          massive_of_numbers[counter2] = massive_of_numbers[counter2 - step];
        else
          break;
      }
      massive_of_numbers[counter2] = reserv;
    }
  end = clock();
  return (double)(end - begin) / CLOCKS_PER_SEC;
}


double sorting_counter(int count_of_random_numbers, double* massive_of_numbers)
{
  int counter1,counter2;
  double reserv;
  double* copy;
  clock_t begin = 0, end = 0;
  begin = clock();
  massive_copy(count_of_random_numbers, massive_of_numbers, &copy);
  int* massive_of_indexes = (int*)malloc(sizeof(int) * count_of_random_numbers);
  for (counter1 = 0; counter1 < count_of_random_numbers; counter1++)
    massive_of_indexes[counter1] = 0;
  for (counter1 = 0; counter1 < count_of_random_numbers; counter1++)
  {
    reserv = copy[counter1];
    for (counter2 = 0; counter2 < count_of_random_numbers; counter2++)
    {
      if (copy[counter1] > copy[counter2])
        massive_of_indexes[counter1] += 1;
    }
  }
  for (counter1 = 0; counter1 < count_of_random_numbers; counter1++)
  {
    massive_of_numbers[massive_of_indexes[counter1]] = copy[counter1];
  }
  free(massive_of_indexes);
  free(copy);
  end = clock();
  return (double)(end - begin) / CLOCKS_PER_SEC;
}


void all_sorting(int count_of_random_numbers, double* massive_of_numbers)
{
  double bubble_time, vibor_time, vstavki_time, slianie_time, hoara_time,shell_time,counter_time;
  double* massive_for_sorting;
  massive_copy(count_of_random_numbers, massive_of_numbers, &massive_for_sorting);
  bubble_time = bubble_sorting(count_of_random_numbers, massive_for_sorting);
  free_massive(massive_for_sorting);
  massive_copy(count_of_random_numbers, massive_of_numbers, &massive_for_sorting);
  vibor_time = sorting_vibor(count_of_random_numbers, massive_for_sorting);
  free_massive(massive_for_sorting);
  massive_copy(count_of_random_numbers, massive_of_numbers, &massive_for_sorting);
  vstavki_time = sorting_vstavkami(count_of_random_numbers, massive_for_sorting);
  free_massive(massive_for_sorting);
  massive_copy(count_of_random_numbers, massive_of_numbers, &massive_for_sorting);
  slianie_time = sorting_slianie(count_of_random_numbers, massive_for_sorting);
  free_massive(massive_for_sorting);
  massive_copy(count_of_random_numbers, massive_of_numbers, &massive_for_sorting);
  hoara_time = sorting_hoara(0, count_of_random_numbers - 1, massive_for_sorting);
  add_data_to_file(count_of_random_numbers, massive_for_sorting);
  free_massive(massive_for_sorting);
  massive_copy(count_of_random_numbers, massive_of_numbers, &massive_for_sorting);
  shell_time = sorting_shell(count_of_random_numbers, massive_for_sorting);
  free_massive(massive_for_sorting);
  massive_copy(count_of_random_numbers, massive_of_numbers, &massive_for_sorting);
  counter_time = sorting_counter(count_of_random_numbers, massive_for_sorting);
  free_massive(massive_for_sorting);
  print_result(bubble_time, vibor_time, vstavki_time, slianie_time, hoara_time,shell_time,counter_time);
}