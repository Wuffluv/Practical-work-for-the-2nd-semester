//201 Даны натуральное число n, действительные числа a1,...,an. Получить:
//б) min (a1,...,an);

#include <iostream>
#include <cstdlib>

using namespace std;

const int n = 10;

int main()
{
	int mass[n], min; //Создание массива

	cout << "Elements: |"; //Получение списка массива
	for (int i = 0; i < n; i++) //Заполнение массива рандомными значениями
	{
		mass[i] = rand()%99; //Получение небольших чисел
		cout << mass[i] << "|"; //Вывод массива
	}
	cout << endl;

	min = mass[0];
	for (int i = 1; i < n; i++) //Цикл для решение задачи
	{
		if (min > mass[i]) min = mass[i];//Условие для решения задачи
	}
	cout << "Min: " << min << endl; //Вывод минимального значения из массива

	return 0;
}