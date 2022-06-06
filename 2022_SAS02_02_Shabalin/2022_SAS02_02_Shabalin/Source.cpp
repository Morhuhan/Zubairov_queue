
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
/*   priority_queue - ��������� �� �������  	   */
/*   size -  ���-�� ��������� � �������            */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   �����������                                   */

void view(int* priority_queue, int* rear) {

	printf("\n");
	for (int i = 0; i < *rear+1; i++) {
		printf("%d ", *(priority_queue + i));
	}
	printf("\n");

}

/* ������� is_empty                                */
/* ����������:                                     */
/*  ���������, ����� �� �������                    */
/* ������� ������:                                 */
/*   rear - ��������� �� ����� �������             */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   1 - ���� ������� �����                        */
/*   0 - ���� ������� �� �����                     */

int is_empty(int* rear) {

	if (*rear == -1) {

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
/*   rear - ��������� �� ����� �������             */
/*   last_element_index -  ������ ���������� ��.   */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   1 - ���� ������� ������                       */
/*   0 - ���� ������� �� ������                    */

int is_full(int* rear, int last_element_index ) {

	if (*rear == last_element_index-1) {

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
/*   priority_queue - ��������� ��  ������� 	   */
/*   number - �����, ������ ����� ��������     	   */
/*   rear - ��������� �� ����� �������             */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   ����������                                    */

void enqueue(int* priority_queue, int* rear, int number) {

	*(rear) = *(rear)+1;

	priority_queue[*(rear)] = number;
}

/* ������� delete_min                              */
/* ����������:                                     */
/*  ������� ����������� ����� �� �������           */
/* ������� ������:                                 */
/*   priority_queue - ��������� ��  ������� 	   */
/*   rear - ��������� �� ������ �������            */
/*   size_queue -  ���-�� ��������� � �������      */
/* �������� ������:                                */
/*   �����������                                   */
/* ������������ ��������:                          */
/*   �����, ��������� �� �������                   */

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
			printf("�������� ��������");
			break;
		}
	} while (ch != '0');
}
