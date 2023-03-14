//388 В данной квадратной целочисленной матрице порядка 17 указать индексы всех элементов с наибольшим значением.

#include "iostream"
#include "ctime"
#include "cstdlib"
#include "iomanip"
#include "climits"


using namespace std;


int main() {
	const size_t n = 17; //Размер матрицы
	int a[n][n], m = INT_MIN;//Минимальное значение из матрицы
	srand(time(NULL)); //Генерируем случайные числа
	for (size_t i = 0; i < n; i++) { //Цикл i-той строки
		for (size_t j = 0; j < n; j++) //Цикл j-той строки
			cout << setw(5) << (a[i][j] = rand() % 199 - 99); //Выводим случайные числа в матрице
		cout << endl;//Придаем вид матрице
	}
	for (size_t i = 0; i < n; i++)//Цикл i-той строки
		for (size_t j = 0; j < n; j++)//Цикл j-той строки
			if (a[i][j] > m && i != j && i + j + 1 != n)m = a[i][j];//Условие для получения маскимального значения из матрицы



	for (size_t i = 0; i < n; i++)//Цикл i-той строки
		for (size_t j = 0; j < n; j++)//Цикл j-той строки
			if (i != j && i + j + 1 != n && m == a[i][j]) //Получаем индексы максимальных элементов
				cout << "(" << i << ',' << j << ") "; //Выводим индексы
}