#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>


#include "header.h"


void print_scripts_menu()
{
  printf("������� ������ ������� �������:\n");
  printf("1 - ������� � �����.\n");
  printf("2 - ������� � ����������.\n");
  printf("3 - ��������� ���������������� �������.\n");
}


void print_result(double bubble_time, double vibor_time, double vstavki_time, double slianie_time, double hoara_time,double shell_time,double counter_time)
{
  system("cls");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  printf("\n|                               ����� ���������� ���������� ���������� � ��������                               |");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  printf("\n|   ���������   |    �������    |   ���������   |   ��������    |     �����     |     �����     |   ���������   |");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  printf("\n|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|");
  printf("\n|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|", bubble_time, vibor_time, vstavki_time, slianie_time, hoara_time,shell_time,counter_time);
  printf("\n|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+\n");
}


void print_for_create_file(int** count_of_random_numbers)
{
  int logic_for_file_creater;
  printf("����� �� ��������� ��������� ����? (1 - ��, 0 - ���): ");
  scanf("%d", &logic_for_file_creater);
  if (logic_for_file_creater == 1)
  {
    file_creater(&(*count_of_random_numbers));
  }
  else
  {
    printf("������� ���������� ����� � �����: ");
    scanf("%d", count_of_random_numbers);
  }
  system("cls");
}


void print_for_create_file_vector(int** count_of_random_numbers)
{
  int logic_for_file_creater;
  printf("����� �� ��������� ��������� ����? (1 - ��, 0 - ���): ");
  scanf("%d", &logic_for_file_creater);
  if (logic_for_file_creater == 1)
  {
    file_creater_vector(&(*count_of_random_numbers));
  }
  else
  {
    printf("������� ���������� ������������ ������� �� �����: ");
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


void print_for_choose_of_enter_massive(int* count_of_random_numbers, double** massive_of_numbers)
{
  int script_number;
  print_scripts_menu();
  printf("��������: ");
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
    break;
  }
}


void print_for_choose_of_enter_vector(int* count_of_random_numbers, double** massive_of_numbers)
{
  int script_number;
  print_scripts_menu();
  printf("��������: ");
  scanf("%d", &script_number);
  switch (script_number)
  {
  case 1:
    print_for_create_file_vector(&(*count_of_random_numbers));
    vector_from_file_creater(*count_of_random_numbers, &*massive_of_numbers);
    break;
  case 2:
    vector_from_keyboard(&*count_of_random_numbers, &*massive_of_numbers);
    break;
  case 3:
    vector_from_random(&*count_of_random_numbers, &*massive_of_numbers);
    break;
  default:
    printf("Script error! Unknown script!\n");
    system("pause");
    system("cls");
    break;
  }
}


void print_for_norma(int count_of_random_numbers, double* massive_of_numbers)
{
  int script;
  printf("�������� ����� ��������\n");
  printf("1 - ������ ����� �������\n");
  printf("2 - ������ ����� �������\n");
  printf("3 - ���������� ����� �������\n");
  printf("4 - ����������� ����� �������\n");
  printf("5 - ���������� �������\n");
  printf("6 - ��� ����� �������\n");
  printf("7 - ����� � ����\n");
  printf("������� ����� ��������: ");
  scanf("%d", &script);
  switch (script)
  {
  case 1:
    printf("������ ����� �������: %lf.\n", first_norma(count_of_random_numbers, massive_of_numbers));
    return;
  case 2:
    printf("������ ����� �������: %lf.\n", second_norma(count_of_random_numbers, massive_of_numbers));
    return;
  case 3:
    printf("���������� ����� �������: %lf.\n", gelder_norma(count_of_random_numbers, massive_of_numbers));
    return;
  case 4:
    printf("����������� ����� �������: %lf\n", endless_norma(count_of_random_numbers, massive_of_numbers));
    return;
  case 5:
    printf("������������� ������:\n");
    vector_norming(count_of_random_numbers, massive_of_numbers);
    add_data_to_file(count_of_random_numbers, massive_of_numbers);
    return;
  case 6:
    all_norma(count_of_random_numbers, massive_of_numbers);
    add_data_to_file(count_of_random_numbers, massive_of_numbers);
    return;
  case 7:
    return;
  default:
    printf("Error script\n");
    system("pause");
    return;
  }
  free_massive(massive_of_numbers);
}


void print_for_sorting(int count_of_random_numbers, double* massive_of_numbers)
{
  int script;
  double* massive_for_sorting;
  printf("������� ����� ���������� ����� ���������\n");
  printf("1 - ���������� ���������\n");
  printf("2 - ���������� �������\n");
  printf("3 - ���������� ���������\n");
  printf("4 - ���������� �����\n");
  printf("5 - ���������� �����\n");
  printf("6 - ���������� ��������\n");
  printf("7 - ���������� ���������\n");
  printf("8 - ��������� ��� ����������\n");
  printf("9 - ����� � ����\n");
  printf("��������: ");
  scanf("%d", &script);
  massive_copy(count_of_random_numbers, massive_of_numbers, &massive_for_sorting);
  switch (script)
  {
  case 1:
    printf("����� ���������� ���������� ���������: %lf\n", bubble_sorting(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 2:
    printf("����� ���������� ���������� �������: %lf\n", sorting_vibor(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 3:
    printf("����� ���������� ���������� ���������: %lf\n", sorting_vstavkami(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 4:
    printf("����� ���������� ���������� �����: %lf\n", sorting_hoara(0, count_of_random_numbers - 1, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 6:
    printf("����� ���������� ���������� ��������: %lf\n", sorting_slianie(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 5:
    printf("����� ���������� ���������� �����: %lf\n", sorting_shell(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 7:
    printf("����� ���������� ���������� ���������: %lf\n", sorting_counter(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 8:
    all_sorting(count_of_random_numbers, massive_for_sorting);
    return;
  case 9:
    return;
  default:
    printf("Error\n");
  }
  free_massive(massive_for_sorting);
}