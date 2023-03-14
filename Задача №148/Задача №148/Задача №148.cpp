//148 Получить таблицу температур по Цельсию от 0 до 100 градусов и их эквивалентов по шкале Фаренгейта, используя для перевода формулу tF = (9/5)tc + 32.
#include <iostream>

using namespace std;

int i = 0;

typedef struct ListStruct { // Односвязный список
	int x;
	struct ListStruct* next;
} my_list;

void push_end(my_list* h, my_list* n) { // Добавить в конец списка
	my_list* act = h;
	while (act->next != nullptr) {
		act = act->next;
	}
	act->next = n;
}

void new_list(my_list* h) { // Создать элемент списка
	my_list* next = new my_list;
	next->x = i;
	next->next = nullptr;
	push_end(h, next);
}

void view_list(my_list* h) { // Вывести список на экран
	my_list* act = h;
	while (act != nullptr) {
		cout << act->x << " ";
		act = act->next;
	}
	cout << endl;
}

int temper(my_list* h) {
	int temp = 0;
	my_list* act = h;
	while (act != nullptr)
	{
		temp = (1.8 * act->x) + 32; // tF = (9 / 5)tc + 32.
		cout << "Temperature C=" << act->x << " —> F=" << temp << endl;
		act = act->next;
	}
	return temp;
}

void delete_list(my_list* h) { // Удалить список
	my_list* act;
	while (h != nullptr) {
		act = h;
		h = h->next;
		act->next = nullptr;
		free(act);
	}
}

int main() {

	my_list* head = new my_list;
	head->x = 0;
	head->next = nullptr;

	for (i = 1; i < 101; i++) {
		new_list(head); // собираю цельсии
	}

	//view_list(head);

	temper(head); // перевод из цельсия в фаренгейты
	delete_list(head);
	return 0;
}