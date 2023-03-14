//471 Дан файл f, компоненты которого являются действительными числами. Найти:
//б) произвидение компонент файла f;

#include <iostream> 
#include <fstream> 

using namespace std;

int main() {
    ifstream f("f.txt", ifstream::in);//Открываем файл для чтения
    double v = 1, s = 1;
    while (!f.eof()) { //Пока не найден конец файла
        f >> v;//Оператор сдвига влево
        s *= v;//Умножаем произведение
    }
    cout << "Multiple: " << s << endl; //Выводим результат
    return 0;
}