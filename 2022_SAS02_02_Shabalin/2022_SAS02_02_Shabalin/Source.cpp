
/* Файл 2022_SAS02_01_Shabalin.sln                 */
/* ОТИ МИФИ                                        */
/* 1ИВТ-11Д                                        */
/* Шабалин Кирилл Андреевич	                       */
/* Основы алгоритмизации и программирования        */
/* Реализация очереди   				           */
/* Основной модуль						           */
/* 23.05.2022							           */

#include <stdio.h> 
#include <locale.h>

#define SIZE 6

/* Функция show_menu                               */
/* Назначение:                                     */
/*   выводит на экран меню для работы с программой */
/* Входные данные:                                 */
/*   отстутствуют								   */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   отстуствует                                   */

void show_menu() {
	printf("\n1 - Поместить число в очередь\n");
	printf("2 - Удалить число из очереди\n");
	printf("3 - Показать очередь\n");
	printf("0 - Выход\n");
}

/* Функция view                                    */
/* Назначение:                                     */
/*  выводит на экран все числа, стоящие в очереди  */
/* Входные данные:                                 */
/*   priority_queue - указатель на очередь  	   */
/*   size -  кол-во элементов в очереди            */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   отсутствует                                   */

void view(int* priority_queue, int* rear) {

	printf("\n");
	for (int i = 0; i < *rear+1; i++) {
		printf("%d ", *(priority_queue + i));
	}
	printf("\n");

}

/* Функция is_empty                                */
/* Назначение:                                     */
/*  Проверяет, пуста ли очередь                    */
/* Входные данные:                                 */
/*   rear - указатель на конец очереди             */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   1 - если очередь пуста                        */
/*   0 - если очередь не пуста                     */

int is_empty(int* rear) {

	if (*rear == -1) {

		return 1;

	}

	else {

		return 0;

	}
}

/* Функция is_full                                 */
/* Назначение:                                     */
/*  Проверяет, полная ли очередь                   */
/* Входные данные:                                 */
/*   rear - указатель на конец очереди             */
/*   last_element_index -  индекс полседнего эл.   */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   1 - если очередь полная                       */
/*   0 - если очередь не полная                    */

int is_full(int* rear, int last_element_index ) {

	if (*rear == last_element_index-1) {

		return 1;

	}

	else {
	
		return 0;
	}

}

/* Функция enqueue                                 */
/* Назначение:                                     */
/*  Добавляет число в очередь                      */
/* Входные данные:                                 */
/*   priority_queue - указатель на  очередь 	   */
/*   number - число, которе нужно добавить     	   */
/*   rear - указатель на конец очереди             */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   отсутсвуют                                    */

void enqueue(int* priority_queue, int* rear, int number) {

	*(rear) = *(rear)+1;

	priority_queue[*(rear)] = number;
}

/* Функция delete_min                              */
/* Назначение:                                     */
/*  Удаляет минимальное число из очереди           */
/* Входные данные:                                 */
/*   priority_queue - указатель на  очередь 	   */
/*   rear - указатель на начало очереди            */
/*   size_queue -  кол-во элементов в очереди      */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   Число, удаленное из очереди                   */

int delete_min(int* priority_queue, int size_queue, int* rear) {

	int min = priority_queue[0];

	int min_index = 0;

	int tmp;

	for (int i = 0; i < *rear+1; i++) {

		if (priority_queue[i] < min) {

			min = priority_queue[i];

			min_index = i;
		}
	}

	for (int i = min_index+1; i < *rear+1; i++) {

		tmp = priority_queue[i];

		priority_queue[i - 1] = tmp;
	}

	*rear = *rear - 1;

	return min;
}





int main() {

	setlocale(LC_ALL, ".1251");
	char ch;

	int priority_queue[SIZE] = { 0 };
	int size_queue = SIZE;

	int rear = -1;

	int number;

	do {

		show_menu();

		scanf_s(" %c", &ch, 1);

		switch (ch) {

		case '0':
			break;

		case '1':
			if (is_full(&rear, size_queue) != 1) {
				printf("\nEnter the number!\n");
				scanf_s("%d", &number);
				enqueue(priority_queue, &rear, number);
			}

			else {
				printf("OVERFLOW!");
			}
			break;

		case '2':

			if (is_empty(&rear) != 1) {
				printf("Element %d has been deleted", delete_min(priority_queue, size_queue, &rear));
			}

			else {
				printf("UNDERFLOW!");
			}

			break;

		case '3':

			if (is_empty(&rear) != 1) {
				view(priority_queue, &rear);
			}

			else {

				printf("Queue is empty");

			}

			break;

		default:
			printf("Неверная операция");
			break;
		}
	} while (ch != '0');
}
