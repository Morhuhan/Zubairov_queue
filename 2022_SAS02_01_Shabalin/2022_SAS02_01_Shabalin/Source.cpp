
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
#include <math.h>

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
/*   queue - указатель на расположение очереди 	   */
/*   rear -  указатель на конец очереди            */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   отсутствует                                   */

void view(int* queue, int size_queue, int* rear, int* front) {

	printf("\n");

	int ptr = *front;

	while (ptr != *rear) {

		printf("%d ", queue[ptr]);

		ptr++;

		if (ptr == size_queue) {
			ptr = 0;
		}
	}

	printf("\n");
}

/* Функция is_empty                                */
/* Назначение:                                     */
/*  Проверяет, пуста ли очередь                    */
/* Входные данные:                                 */
/*   front - указатель на начало очереди     	   */
/*   rear - указатель на конец очереди             */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   1 - если очередь пуста                        */
/*   0 - если очередь не пуста                     */

int is_empty(int* front, int* rear) {

	if (*front == *rear) {

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
/*   front - указатель на начало очереди     	   */
/*   rear - указатель на конец очереди             */
/*   size_queue -  кол-во элементов в очереди      */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   1 - если очередь полная                       */
/*   0 - если очередь не полная                    */

int is_full(int front, int rear, int size_queue) {

	rear++;

	if (rear == (size_queue)) {

		rear = 0;

	}

	if (rear == front) {

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
/*   queue - указатель на расположение очереди 	   */
/*   number - число, которе нужно добавить     	   */
/*   rear - указатель на конец очереди             */
/*   size_queue -  кол-во элементов в очереди      */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   отсутсвуют                                    */

void enqueue(int* queue, int size_queue, int* rear, int number) {

	queue[*(rear)] = number;

	*(rear) = *(rear)+1;

	if (*rear == (size_queue)) {

		*rear = 0;

	}
}

/* Функция dequeue                                 */
/* Назначение:                                     */
/*  Удаляет число из очереди                       */
/* Входные данные:                                 */
/*   queue - указатель на расположение очереди 	   */
/*   front - указатель на начало очереди           */
/*   size_queue -  кол-во элементов в очереди      */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   Число, удаленное из очереди                   */

int dequeue(int* queue, int size_queue, int* front) {

	*front = *front + 1;

	printf("\nЧисло %d удаленно из очереди\n", queue[*(front) - 1]);

	if (*front == (size_queue)) {

		*front = 0;

	}

	return  queue[*(front)-1];

}


int main() {

	setlocale(LC_ALL, ".1251");
	char ch;

	int queue[SIZE] = { 0 };
	int size_queue = SIZE;

	int front = 0;
	int rear = 0;

	int number;

	do {

		show_menu();

		scanf_s(" %c", &ch, 1);

		switch (ch) {

		case '0':

			break;

		case '1':

			if (is_full(front, rear, size_queue) != 1) { 

			printf("\nВведите число: \n");

			scanf_s("%d", &number);

			enqueue(queue, size_queue, &rear, number);

			}

			else {
			
				printf("OVERFLOW!");

			}

			break;

		case '2':

			if (is_empty(&front, &rear) != 1) {

				dequeue(queue, size_queue, &front);

			}

			else {
			
				printf("UNDERFLOW!");

			}

			break;

		case '3':

			if (is_empty(&front, &rear) != 1) {
			view(queue, size_queue, &rear, &front);
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
