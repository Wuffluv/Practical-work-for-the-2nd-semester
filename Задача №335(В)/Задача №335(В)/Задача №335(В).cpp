//335 Дано натуральное число n.Вычислить:
#include <iostream>
#include <math.h>

using namespace std;

int fact(int p) {
	int q = 1;
	for (int i = p - 1; i > 0; i--) {
		p = p * i;
	}
	cout << p << endl;//Проверка факториала
	return p;
}

int main()
{
	int n;
	double sum = 0.0;

	cin >> n;

	for (int k = 1; k <= n; k++) {
		sum = sum + 1.0 / (fact(pow(k, 2)));
	}

	cout << sum;

}