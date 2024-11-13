#ifndef __HEADER_H__
#define __HEADER_H__

double bubble_sorting(int count_of_random_numbers, double* massive_of_numbers);
double sorting_vibor(int count_of_random_numbers, double* massive_of_numbers);
double sorting_vstavkami(int count_of_random_numbers, double* massive_of_numbers);
double sorting_slianie(int count_of_rundom_numbers, double* massive_of_numbers);
void all_sorting(int count_of_random_numbers, double* massive_of_numbers);
double sorting_hoara(int left, int right, double* massive_of_numbers);
double sorting_shell(int count_of_random_numbers, double* massive_of_numbers);
double sorting_counter(int count_of_random_numbers, double* massive_of_numbers);

double make_random_number(double minimum_of_random_numbers, double maximum_of_random_numbers);
void file_creater(int *count_of_random_numbers);
void massive_from_file_creater(int count_of_numbers, double** massive_of_numbers);
void massive_from_keyboard(int* count_of_numbers, double** massive_of_numbers);
void massive_from_random(int* count_of_random_numbers, double** massive_of_numbers);
void free_massive(double* massive_of_numbers);
void get_piece_of_massive(int begin_index, int end_index, double* full_massive, double** piece_of_massive);
void add_piece_to_massive(int begin_index, int end_index, double* full_massive, double* piece_of_massive);
void massive_copy(int count_of_random_numbers_in_original_massive, double* original_massive, double** copy_massive);

void print_scripts_menu();


void print_for_create_file(int** count_of_random_numbers);
void print_for_sorting(int count_of_random_numbers, double* massive_of_numbers);

void print_for_massive(int count_of_random_numbers, double* massive_of_numbers);
void print_result(double bubble_time, double vibor_time, double vstavki_time, double slianie_time, double hoara_time, double shell_time,double counter_time);
void print_for_choose_of_enter_massive(int* count_of_random_numbers, double** massive_of_numbers);

void print_for_choose_of_enter_vector(int* count_of_random_numbers, double** massive_of_numbers);
void print_for_norma(int count_of_random_numbers, double* massive_of_numbers);
void vector_from_file_creater(int count_of_numbers, double** massive_of_numbers);
void file_creater_vector(int* count_of_random_numbers);
void vector_from_keyboard(int* count_of_numbers, double** massive_of_numbers);
void vector_from_random(int* count_of_random_numbers, double** massive_of_numbers);
void vector_norming(int count_of_random_numbers, double* massive_of_numbers);
void add_data_to_file(int count_of_random_numbers, double** massive_of_numbers);

void all_norma(int count_of_random_numbers, double* massive_of_numbers);
double gelder_norma(int count_of_random_numbers, double* massive_of_numbers);
double endless_norma(int count_of_random_numbers, double* massive_of_numbers);
double second_norma(int count_of_random_numbers, double* massive_of_numbers);
double first_norma(int count_of_random_numbers, double* massive_of_numbers);
#endif //!__HEADER_H__