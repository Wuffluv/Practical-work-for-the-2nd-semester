//680 В данной действительности матрице размера n x m (n ≥ 3, m ≥ 3) поменять местами:
//б) столбцы с номерами 3 и n-2
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void task(int** array, int x) {

	int i;

	for (i = 0; i < x; i++)
	{
		int temp = array[i][2];
		array[i][2] = array[i][x - 3];
		array[i][x - 3] = temp;
	}

}

void matrix_output(int** array, int x, int y) {

	int i, j;

	for (i = 0; i < x; i++) // выводим отсортированную
		for (j = 0; j < y; j++)
		{
			if (j % y == 0)
				cout << endl;
			cout << setw(3) << array[i][j];
		}
	cout << endl;
}


int foo_input_output(int x) {
	cout << "Print count line " << endl;
	cin >> x;
	return(x);
}
int foo_input_output1(int y) {
	cout << "Print count columns " << endl;
	cin >>  y;
	return(y);
}

void matrix_output1(int** array, int x, int y) {

	int i, j;

	for (i = 0; i < x; i++) // выводим исходную матрицу
		for (j = 0; j < y; j++)
		{
			if (j % y == 0)
				cout << endl;
			cout << setw(3) << array[i][j]; // setw = изменение ширины поля ввода-вывода
		}
	cout << endl;
}


int matrix_input(int** array, int x, int y) {
	int i, j;

	cout << "Enter matrix " << endl;

	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
			cin >> array[i][j];

	return **array;

}





void main()
{
	int x = 0, y = 0;
	int i, j;

	x = foo_input_output(x); // вводим n

	y = foo_input_output1(y); //вводим m

	int** array; // динамически выделяем память

	array = new int* [x];

	for (i = 0; i < y; i++)
		array[i] = new int[y];

	matrix_input(array, x, y); // вводим матрицу

	matrix_output1(array, x, y); // выводим ориг матрицу

	task(array, x); // выполняем задание

	matrix_output(array, x, y); // выводим матрицу по заданию


	delete array; // освобождаем память
}
