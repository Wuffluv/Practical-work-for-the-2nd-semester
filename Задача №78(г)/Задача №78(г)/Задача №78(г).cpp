//Даны действительное число а, натуральное число n. Вычислить: (Г)

#include <cmath>
#include <iostream>

using namespace std;


int main()
{
    int a, n, f;
    double sum;
   

    cout << "Enter final number: "; //Ввод последнего числа
    cin >> f; //Ввод
    cout << "Enter number a: "; //Ввод значения переменной
    cin >> a; //Ввод
    sum = 1.0 / a; 

    for (n = 1; n <= f; n++) { //Цикл для нахождения ответа
        sum = sum + 1 / pow(a, 2 * n); //Решение задачи
    }
    cout << "Your summ is equal = " << sum; //Вывод результата
}   