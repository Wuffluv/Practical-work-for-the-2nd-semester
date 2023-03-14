//535 Пусть a1 = 1; a2 = 1.5; ai = a[i/2]a[i/3] + 1 ( i = 3, 4...). Дано натуральное число m. Получить am

#include <iostream>
#include <locale>

using namespace std;

// структура узла
struct Node
{
    double u = 0;         // число 
    Node* next = nullptr; // указатель на следующий узел
    Node* prev = nullptr; // указатель на предыдущий узел
};

// возвращает a[i] - смотри условия задачи
double number(Node* head, int n)
{
    Node* node = head;
    for (int i = 1; i < n; i++)
        node = node->next;
    return node->u;
}

// создание списка. Функция возвращает указатель на последний элемент
Node* build_list(Node* head, Node* tail, int n)
{
    head->u = 1;

    for (int i = 2; i <= n; i++)
    {
        Node* node = new Node();
        node->prev = tail;
        tail->next = node;

        if (i == 2)
            node->u = 1.5;
        else
            node->u = number(head, i / 2) * number(head, i / 3) + 1;

        tail = node;
    }
    return tail;
}

// вывод спсика в консоль
void print_list(Node* head)
{
    Node* dop_node = head;
    while (dop_node)
    {
        cout << dop_node->u << " ";
        dop_node = dop_node->next;
    }
}

// вывод |a1|, |a1 + a2|, ..., |a1 + a2 + ... + an|
void out_result(Node* head)
{
    Node* node = head;
    double res = 0;
    while (node)
    {
        res += abs(node->u);
        cout << res << "  ";
        node = node->next;
    }
}

// удаление спсика
void delete_list(Node* head)
{
    Node* dop_node;
    while (head)
    {
        dop_node = head;
        head = head->next;
        delete dop_node;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "535 Пусть a[1] = 1; a[2] = 1.5; a[i] = a[i/2]a[i/3] + 1 ( i = 3, 4...). Дано натуральное число m. Получить a[m]." << endl;

    int m;
    cout << "Введите n = "; cin >> m;

    if (m > 0)
    {
        Node* head; // первый элемент списка
        Node* tail; // последний элемент списка

        head = tail = new Node();

        // создание списка
        tail = build_list(head, tail, m);

        cout << endl << "Действительные числа а1,..., am" << endl;
        print_list(head); // вывод списка

        cout << endl << "Полученное a[m] = " << tail->u << endl;

        delete_list(head); // удаление списка
    }
    else
        cout << " Error -- m < 1 " << endl;
}
