#include <stdio.h>
#include <malloc.h>
#include <locale.h>

typedef struct node {
	int info;
	struct node* link;
}node;

/* Функция show_menu                               */
/* Назначение:                                     */
/*   показывает меню для работы со списком         */
/* Входные данные:                                 */
/*   отсутствуют                                   */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   отсутствуют                                   */

void show_menu() {
	printf("\n");
	printf("1. Добавить в начало списка\n");
	printf("2. Добавить в конец списка\n");
	printf("3. Удалить элемент в начале списка\n");
	printf("4. Удалить элемент в конце списка\n");
	printf("5. Добавить после указанного элемента\n");
	printf("6. Удалить указанный элемент\n");
	printf("7. Просмотреть содержимое списка\n");
	printf("0. Выход\n");
	printf("\nВыберите операцию: \n");
}

/* Функция view                                    */
/* Назначение:                                     */
/*   показывает все элменты спсика                 */
/* Входные данные:                                 */
/*   корень                                        */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   отсутствуют                                   */

void view(node** first) {

	node* temp = *first;

	int i = 0;

	if (*first != NULL) {

		do {
			printf("\nELEMENT #%d\n", i);
			printf("info =  %d\n", temp->info);
			temp = (temp->link);
			i++;
		} while (temp != NULL);
	}

	else {
		printf("\nСписок пуст!\n");
	}
}

/* Функция create_node                             */
/* Назначение:                                     */
/*   создает элемент списка                        */
/* Входные данные:                                 */
/*   число, которое нужно добавть в список         */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   адрес нового элемента                         */

node* create_node(int number) {
	node* new_node = (node*)malloc(1 * sizeof(node));
	new_node->info = number;
	new_node->link = NULL;
	return new_node;
}

/* Функция search_node                             */
/* Назначение:                                     */
/*   находит элемент с указанным номером           */
/* Входные данные:                                 */
/*   номер элемента и указатель на корень          */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   адрес соответствующего элемента               */
/*   NULL если такого элемента не существует       */

node* search_node(int number_in_list, node** first) {

	node* ptr = *first;
	
	for (int i = 0; i < number_in_list; i++) {
		ptr = ptr->link;
		
		if (ptr == NULL) {
			return NULL;
		}

	}
	return ptr;
}

/* Функция add_first                               */
/* Назначение:                                     */
/*   добавляет элемент в начало списка             */
/* Входные данные:                                 */
/*   число, которое нужно добавить                 */
/*   корень списка                                 */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   отстуствует                                   */

void add_first(node** first, int number) {

	node* new_node = create_node(number);
	node* temp;

	if (*first == NULL) {  // Если элемент единственный
		*first = new_node;
	}

	else {  // Если элемент не единственный
		temp = *first;
		new_node->link = temp;
		*first = new_node;
	}
}

/* Функция add_last                                */
/* Назначение:                                     */
/*   добавляет элемент в конец списка              */
/* Входные данные:                                 */
/*   число, которое нужно добавить                 */
/*   корень списка                                 */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   отстуствует                                   */

void add_last(node** first, int number) {					

	node* new_node = create_node(number);
	node* temp = *first;

	if (*first == NULL) {  // Если элемент единственный
		*first = new_node;
	}

	else {  // Если элемент не единственный

		while (temp -> link != NULL) {
			temp = temp->link;
		}

		temp->link = new_node;
	}
}

/* Функция add_after_target                        */
/* Назначение:                                     */
/*   добавляет элемент после указанного            */
/* Входные данные:                                 */
/*   адрес целевого элемента			           */
/*   корень                  			           */
/*   число, которое нужно добавить  	           */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   отстуствует                                   */

void add_after_target(node* target, node** first, int number) {

	node* ptr = *first;
	node* new_node = create_node(number);
	node* temp;

	while (ptr != target) {
		ptr = ptr->link;
	}

	if (ptr->link == NULL) {
		printf("\nЭлемент добавлен в конец списка!\n");
		add_last(first, number);
	}

	else {
		temp = ptr->link;
		ptr->link = new_node;
		new_node->link = temp;
	}

}

/* Функция delete_first                            */
/* Назначение:                                     */
/*   удаляет первый элемент списка                 */
/* Входные данные:                                 */
/*   корень     								   */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   Число, которое было удалено                   */
/*   0, если список пуст                           */

int delete_first(node **first) {

	int number;
	node* temp;

	if (*first != NULL) {
		temp = *first;
		*first = (*first)->link;
		number = temp->info;
		free(temp);
		return number;
	}

	else {
		printf("\nСписок пуст!\n");
		return 0;
	}
}

/* Функция delete_last                             */
/* Назначение:                                     */
/*   удаляет последний элемент списка              */
/* Входные данные:                                 */
/*   корень      								   */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   Число, которое было удалено                   */
/*   0, если список пуст                           */

int delete_last(node** first) {

	int number;
	int flag = 0;
	node* temp1 = *first;
	node* temp2 = *first;

	if (*first != NULL) {

		while ((temp1 -> link) != NULL) {

			temp2 = temp1;

			temp1 = temp1->link;

			flag = 1;
		}

		if (flag != 1) {
			*first = NULL;
			number = temp1->info;
			return number;
		}

		temp2->link = NULL;
		number = temp1->info;
		return number;
	}

	else {
		printf("\nСписок пуст!\n");
		return 0;
	}
}

/* Функция delete_last                             */
/* Назначение:                                     */
/*   удаляет указанный элемент списка              */
/* Входные данные:                                 */
/*   корень      								   */
/*   указатель на целевой элемент				   */
/* Выходные данные:                                */
/*   отсутствуют                                   */
/* Возвращаемое значение:                          */
/*   Число, которое было удалено                   */
/*   0, если список пуст                           */

int delete_target(node** first, node* target) {

	node* ptr = *first;
	node* temp = ptr;
	int number;
	
	if (*first != NULL) {

		while (ptr != target) {
			temp = ptr;
			ptr = ptr->link;
			number = ptr->info;
		}

		if (ptr->link == NULL) {
			temp->link = NULL;
		}

		else {
			temp->link = ptr->link;
		}

		return number;
	}

	else {
		printf("\nСписок пуст!\n");
		return 0;
	}

}


int main() {

	setlocale(LC_ALL, ".1251");
	int key;
	int number;
	int number_in_list;
	node* first = NULL;

	do {
		show_menu(); 
		scanf_s("%d", &key);

		switch (key) {

		case 0:
			break;

		case 1:
			printf("\n");
			printf("Введите целое число для добавления в начало списка: ");
			scanf_s("%d", &number);
			add_first(&first, number);
			break;

		case 2:
			printf("\n");
			printf("Введите целое число для добавления в конец списка: ");
			scanf_s("%d", &number);
			add_last(&first, number);
			break;

		case 3:
			if(first != NULL) {
				printf("\nЭлемент: %d удален из списка\n", delete_first(&first));
			}
			else {
				printf("\nСписок пуст!\n");
			}
			break;

		case 4:
			if (first != NULL) {
				printf("\nЭлемент: %d удален из списка\n", delete_last(&first));
			}
			else {
				printf("\nСписок пуст!\n");
			}
			break;

		case 5:

			printf("\nВведите номер элемента:\n");
			scanf_s("%d", &number_in_list);

			if (search_node(number_in_list, &first) != NULL) {
				printf("\nВведите число:\n");
				scanf_s("%d", &number);
				add_after_target(search_node(number_in_list, &first), &first, number);
			}

			else {
				printf("\nУказанного элемента не существует!\n");
			}
			
			break;

		case 6:
			printf("\nВведите номер элемента:\n");
			scanf_s("%d", &number_in_list);

			if (search_node(number_in_list, &first) != NULL) {
				printf("\nЭлемент: %d удален из списка\n", delete_target(&first, search_node(number_in_list, &first)));
			}

			else {
				printf("\nУказанного элемента не существует!\n");
			}

			break;

		case 7:
			view(&first);
			break;

		default:
			printf("\n");
			printf("Такой операции не существует.");
			break;
		}
	} while (key != 0);

	return 0;
}
