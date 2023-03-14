//846 Исследовать область определения и построить графики следующих функций:

#include <iostream>
#include <locale>
#include <Windows.h> // для рисования 
#include <conio.h>   // для рисования


using namespace std;

double f(double x)
{
	return 3 + (2 / x) + (3 / (x * x));
}

int main()
{
	setlocale(LC_ALL, "rus");

	POINT op;
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	SelectObject(hdc, GetStockObject(WHITE_PEN));

	// рисуем ось x
	MoveToEx(hdc, 0, 400, &op);
	LineTo(hdc, 1000, 400);

	// рисуем ось y
	MoveToEx(hdc, 500, 0, &op);
	LineTo(hdc, 500, 800);

	double y, x;

	// рисуем график
	for (x = -20; x <= 20; x += 0.001)
	{
		if (x != 0)
		{
			SetPixel(hdc, x * 20 + 500, -f(x) * 20 + 400, RGB(255, 255, 255)); // рисуем по пиксельно каждую точку функции (масштаб отличается от реального в 20 раз)
		}
	}

	cout << "Область определения от минус бесконечности до плюс бесконечности, не включая ноль" << endl;
	cout << "На графике x = [-20; 0) U (0;20]." << endl;

	ReleaseDC(hwnd, hdc);
	cin.get();
	return 0;
}
