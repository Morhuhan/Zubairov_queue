
/* ���� 2022_SAS02_01_Shabalin.sln                 */
/* ��� ����                                        */
/* 1���-11�                                        */
/* ������� ������ ���������	                       */
/* ������ �������������� � ����������������        */
/* ���������� �������   				           */
/* �������� ������						           */
/* 23.05.2022							           */

#include <stdio.h> 
#include <locale.h>
#include <math.h>

#define SIZE 6

/* ������� show_menu                               */
/* ����������:                                     */
/*   ������� �� ����� ���� ��� ������ � ���������� */
/* ������� ������:                                 */
/*   ������������								   */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   �����������                                   */

void show_menu() {
	printf("\n1 - ��������� ����� � �������\n");
	printf("2 - ������� ����� �� �������\n");
	printf("3 - �������� �������\n");
	printf("0 - �����\n");
}

/* ������� view                                    */
/* ����������:                                     */
/*  ������� �� ����� ��� �����, ������� � �������  */
/* ������� ������:                                 */
/*   queue - ��������� �� ������������ ������� 	   */
/*   rear -  ��������� �� ����� �������            */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   �����������                                   */

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

/* ������� is_empty                                */
/* ����������:                                     */
/*  ���������, ����� �� �������                    */
/* ������� ������:                                 */
/*   front - ��������� �� ������ �������     	   */
/*   rear - ��������� �� ����� �������             */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   1 - ���� ������� �����                        */
/*   0 - ���� ������� �� �����                     */

int is_empty(int* front, int* rear) {

	if (*front == *rear) {

		return 1;

	}

	else {

		return 0;

	}
}

/* ������� is_full                                 */
/* ����������:                                     */
/*  ���������, ������ �� �������                   */
/* ������� ������:                                 */
/*   front - ��������� �� ������ �������     	   */
/*   rear - ��������� �� ����� �������             */
/*   size_queue -  ���-�� ��������� � �������      */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   1 - ���� ������� ������                       */
/*   0 - ���� ������� �� ������                    */

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

/* ������� enqueue                                 */
/* ����������:                                     */
/*  ��������� ����� � �������                      */
/* ������� ������:                                 */
/*   queue - ��������� �� ������������ ������� 	   */
/*   number - �����, ������ ����� ��������     	   */
/*   rear - ��������� �� ����� �������             */
/*   size_queue -  ���-�� ��������� � �������      */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   ����������                                    */

void enqueue(int* queue, int size_queue, int* rear, int number) {

	queue[*(rear)] = number;

	*(rear) = *(rear)+1;

	if (*rear == (size_queue)) {

		*rear = 0;

	}
}

/* ������� dequeue                                 */
/* ����������:                                     */
/*  ������� ����� �� �������                       */
/* ������� ������:                                 */
/*   queue - ��������� �� ������������ ������� 	   */
/*   front - ��������� �� ������ �������           */
/*   size_queue -  ���-�� ��������� � �������      */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   �����, ��������� �� �������                   */

int dequeue(int* queue, int size_queue, int* front) {

	*front = *front + 1;

	printf("\n����� %d �������� �� �������\n", queue[*(front) - 1]);

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

			printf("\n������� �����: \n");

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
			printf("�������� ��������");
			break;
		}
	} while (ch != '0');
}
