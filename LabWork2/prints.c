#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>


#include "header.h"


void print_scripts_menu()
{
  printf("Введите способ задания массива:\n");
  printf("1 - Считать с файла.\n");
  printf("2 - Считать с клавиатуры.\n");
  printf("3 - Заполнить псевдослучайными числами.\n");
}


void print_result(double bubble_time, double vibor_time, double vstavki_time, double slianie_time, double hoara_time,double shell_time,double counter_time)
{
  system("cls");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  printf("\n|                               Время выполнения алгоритмов сортировки в секундах                               |");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  printf("\n|   Пузырьком   |    Выбором    |   Вставками   |   Слиянием    |     Хоара     |     Шелла     |   Подсчетом   |");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+");
  printf("\n|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|");
  printf("\n|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|", bubble_time, vibor_time, vstavki_time, slianie_time, hoara_time,shell_time,counter_time);
  printf("\n|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|");
  printf("\n+---------------+---------------+---------------+---------------+---------------+---------------+---------------+\n");
}


void print_for_create_file(int** count_of_random_numbers)
{
  int logic_for_file_creater;
  printf("Нужно ли программе заполнять файл? (1 - Да, 0 - Нет): ");
  scanf("%d", &logic_for_file_creater);
  if (logic_for_file_creater == 1)
  {
    file_creater(&(*count_of_random_numbers));
  }
  else
  {
    printf("Введите количество чисел в файле: ");
    scanf("%d", count_of_random_numbers);
  }
  system("cls");
}


void print_for_create_file_vector(int** count_of_random_numbers)
{
  int logic_for_file_creater;
  printf("Нужно ли программе заполнять файл? (1 - Да, 0 - Нет): ");
  scanf("%d", &logic_for_file_creater);
  if (logic_for_file_creater == 1)
  {
    file_creater_vector(&(*count_of_random_numbers));
  }
  else
  {
    printf("Введите количество размерностей вектора из файла: ");
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
  printf("Сценарий: ");
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
  printf("Сценарий: ");
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
  printf("Выберите номер сценария\n");
  printf("1 - первая норма вектора\n");
  printf("2 - вторая норма вектора\n");
  printf("3 - Гельдерова норма вектора\n");
  printf("4 - бесконечная норма вектора\n");
  printf("5 - нормировка вектора\n");
  printf("6 - все нормы вектора\n");
  printf("7 - выход в меню\n");
  printf("Введите номер сценария: ");
  scanf("%d", &script);
  switch (script)
  {
  case 1:
    printf("Первая норма вектора: %lf.\n", first_norma(count_of_random_numbers, massive_of_numbers));
    return;
  case 2:
    printf("Вторая норма вектора: %lf.\n", second_norma(count_of_random_numbers, massive_of_numbers));
    return;
  case 3:
    printf("Гельдерова норма вектора: %lf.\n", gelder_norma(count_of_random_numbers, massive_of_numbers));
    return;
  case 4:
    printf("Бесконечная норма вектора: %lf\n", endless_norma(count_of_random_numbers, massive_of_numbers));
    return;
  case 5:
    printf("Нормированный вектор:\n");
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
  printf("Введите какую сортировку нужно выполнить\n");
  printf("1 - сортировка пузырьком\n");
  printf("2 - сортировка выбором\n");
  printf("3 - сортировка вставками\n");
  printf("4 - сортировка Хоара\n");
  printf("5 - сортировка Шелла\n");
  printf("6 - сортировка слиянием\n");
  printf("7 - сортировка подсчетом\n");
  printf("8 - выполнить все сортировки\n");
  printf("9 - выход в меню\n");
  printf("Сценарий: ");
  scanf("%d", &script);
  massive_copy(count_of_random_numbers, massive_of_numbers, &massive_for_sorting);
  switch (script)
  {
  case 1:
    printf("Время выполнения сортировки пузырьком: %lf\n", bubble_sorting(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 2:
    printf("Время выполнения сортировки выбором: %lf\n", sorting_vibor(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 3:
    printf("Время выполнения сортировки вставками: %lf\n", sorting_vstavkami(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 4:
    printf("Время выполнения сортировки Хоара: %lf\n", sorting_hoara(0, count_of_random_numbers - 1, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 6:
    printf("Время выполнения сортировки слиянием: %lf\n", sorting_slianie(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 5:
    printf("Время выполнения сортировки Шелла: %lf\n", sorting_shell(count_of_random_numbers, massive_for_sorting));
    add_data_to_file(count_of_random_numbers, massive_for_sorting);
    return;
  case 7:
    printf("Время выполнения сортировки подсчетом: %lf\n", sorting_counter(count_of_random_numbers, massive_for_sorting));
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