//708 Даны квадратная матрица А порядка m, натуральное число n.Получить матрицу E + A + A2 + ... + An, где Е - единичная матрица порядка m.
#include <iostream>
#include <locale>

using namespace std;

// функция по заполнению квадратной матрицы mat порядка m
void fill_mat(double** mat, int m)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			mat[i][j] = rand() % 10;
}

// создаёт единичную матрицу порядка m
double** matrix_one(int m)
{
	// выделяем память под матрицу
	double** mat = new double* [m];
	for (int i = 0; i < m; i++)
		mat[i] = new double[m];

	// заполняем её
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i != j)
				mat[i][j] = 0;
			else
				mat[i][j] = 1;
		}
	}

	// возвращаем единичную матрицу (указатель на неё)
	return mat;
}

// вывод квадратной матрицы
void print_mat(double** mat, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			cout << mat[i][j] << "\t"; // "\t" - это табуляция
		cout << endl;
	}
}

// функция по выделению памяти под квадратную матрицу порядка m
double** build_matrix(int m)
{
	double** mat = new  double* [m];
	for (int i = 0; i < m; i++)
		mat[i] = new double[m];
	return mat;
}

// очищение памяти от двумерного массива
void delete_matrix(double** mat, int m)
{
	for (int i = 0; i < m; i++)
		delete[] mat[i];
	delete[] mat;
}

// перемножение квадратной матрицы "a" самой на себя
double** multi(double** a, int m, double** b)
{
	// выделение памяти под матрицу, которая будет хранить в себе результат
	double** res = new double* [m];
	for (int i = 0; i < m; i++)
		res[i] = new double[m];

	// перемжножение
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < m; k++)
				res[i][j] += a[i][k] * b[k][j];
		}

	// удаление старой матрицы
	delete_matrix(a, m);

	// возвращение результата, произведения A*A
	return res;
}

// сложение матриц a и b, результат сохраняется в a
void summa_matrix(double** a, double** b, int m)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = a[i][j] + b[i][j];
}



int main()
{
	setlocale(LC_ALL, "rus");

	cout << "708 Даны квадратная матрица А порядка m, натуральное число n." << endl;
	cout << "Получить матрицу E + A + A^2 + ... + A^n, где Е - единичная матрица порядка m." << endl;

	int n, m;
	cout << "Введите n: "; cin >> n;
	if (n > 0)
	{
		cout << "Введите порядок квадратной матрицы (m >= 1): ";
		cin >> m;
		cout << endl;

		// Создаём единичную матрицу
		double** E = matrix_one(m);
		// и выводим её в консоль
		cout << "Единичная матрица порядка m:" << endl;
		print_mat(E, m);
		cout << endl;


		// создаём двумерный динамический массив - матрицу А размером m*m
		double** A;
		A = build_matrix(m);
		// заполнение матрицы А
		fill_mat(A, m);
		// вывод матрицы А
		cout << "Квадратная матрица А:" << endl;
		print_mat(A, m);
		cout << endl;

		// дополнительная матрица
		double** dop = build_matrix(m);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				dop[i][j] = A[i][j];

		// вычисляем E + A + A^2 + ... + A^n
		summa_matrix(E, A, m); // тут находим сумму E + A
		// а в цикле уже остальные суммы
		for (int i = 1; i < n; i++)
		{
			A = multi(A, m, dop);
			summa_matrix(E, A, m);
		}


		cout << "Результат -- E + A + A^2 + ... + A^n" << endl;
		print_mat(E, m);

		// очищение памяти от двумерных массивов
		delete_matrix(A, m);
		delete_matrix(dop, m);
		delete_matrix(E, m);
	}
	else
		cout << "n не натуральное число, т.е. n < 1" << endl;
}
