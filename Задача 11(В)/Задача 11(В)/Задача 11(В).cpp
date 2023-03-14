//11 Даны x, y, z. Вычислить a, b, если (В)

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	float x, y, z, a, b;

	cout << "Enter x, y, z\n" << endl; //Пользователь вводит значения для получения результата
	cin >> x >> y >> z; //Ввод значения

	a = (1 + y)*((x+(y/(x*x+4)))/(exp(-x-2)+(1/(x*x+4)))); //Ищем значение a из уравнения
	b = (1 + cos(y - 2)) / ((pow(x, 4) / 2) + pow(sin(z), 2)); //Ищем значение b из уравнения

	cout << "a = " << a << " b = " << b << endl; //Получение результата
}
