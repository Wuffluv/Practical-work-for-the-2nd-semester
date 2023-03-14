//425 Даны действительные числа s, t. Получить

#include <math.h>
#include <iostream>

using namespace std;


double g(int a, int b) {
    return (pow(a, 2) + pow(b, 2)) / pow(a, 2) + (2 * a * b) + (3 * pow(b, 2)) + 4; //Вычисления по формуле из условия задачи
}

int enter() { //Функция ввода значений переменных
    int s, t;
    int solution;
    cout << "Enter parametres: " << endl; //Ввод параметров
    cin >> s;
    cin >> t;
    cout << "You entered: " << s << ", " << t << endl; //Вывод введенных параметров
    solution = g(1.2, s) + g(t, s) - g(2 * s - 1, s * t);//Главное решение задачи
    cout << "Your solution: " << solution << endl;//Вывод ответа
    return g(s, t);
}


int main()
{
    enter();
}
