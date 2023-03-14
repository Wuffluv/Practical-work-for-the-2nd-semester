//527 Даны два текстовых файла f и g. Определить, совпадают ли компоненты файла f с компонентами файла g. Если нет, то получить номер первой строки и
//позицию первого символа в этой строке, в кототых файлы f и g отличаются между собой. Принять во внимание уточнение к задаче 494.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int n = 0, k = 0, str = 1, num = 1;
char s, s2;
FILE* f, * f2;
char name[] = "f.txt";
char name2[] = "g.txt";

int main()
{
	setlocale(LC_ALL, "Rus");

	f = fopen(name, "r");
	f2 = fopen(name2, "r");
	fseek(f, 0, SEEK_END);//Переводим указатель на конец строки
	int size1 = ftell(f);
	fseek(f2, 0, SEEK_END);//Переводим указатель на конец строки
	int size2 = ftell(f2);

	if (size1 < size2) 
	{
		fseek(f2, 0, SEEK_SET);
		fseek(f, 0, SEEK_SET);
		while (!feof(f2))//Пока не равно концу файла
		{
			s = fgetc(f);//получает следующий по порядку символ из входного потока
			s2 = fgetc(f2);//получает следующий по порядку символ из входного потока
			if (s == s2) n++;
			k++;
			if (s2 == '\n')
			{
				str++; n = 0; k = 0;
			}
		}
	}

	if (size1 >= size2)
	{
		fseek(f, 0, SEEK_SET);
		fseek(f2, 0, SEEK_SET);
		while (!feof(f))
		{
			s = fgetc(f);
			s2 = fgetc(f2);
			if (s == s2) n++;
			k++;
			if (s == '\n')
			{
				str++; n = 0; k = 0;
			}
		}
	}
	
	if (n == k) printf_s("Файлы одинаковые"); 
	else printf_s("Первый не совпадающий символ находится в строке %d под номером %d", str, n);
	fclose(f);
	fclose(f2);
}