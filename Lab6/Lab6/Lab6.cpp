#include <iostream>
#include <math.h>
#include <conio.h>
#include<stdlib.h>
#include<cstdlib>;
#include<ctime>;
using namespace std;///Задание 	13. В квадратной матрице найти максимальный среди элементов, лежащих ниже побочной диагонали.

int main()
{
	setlocale(LC_ALL, "ru");
	int** a, n, m, i, j;
	cout << "Введите значение строк и столбцов";
	cin >> n;
	while (cin.fail() or n < 1) {
		cin.clear();
		cin.ignore(100000, '\n');

		cout << " Введите повторно длинну массива =";
		cin >> n;
	}

	a = new int* [n];
	for (i = 0;i < n; ++i) {
		a[i] = new int[n];
	}

	cout << "Рандомное заполнение массива(1); Самостоятельное заполнение массива(ELSE)" "\n";
	if (_getch() == '1')
	{
		srand(time(NULL));
		for (j = 0; j < n;++j) {
			for (i = 0;i < n;++i) {
				a[i][j] = rand() % 21 - 10;
				cout << a[i][j] << "\t";

			}
			cout << endl;
		}
	}
	else {
		for (i = 0;i < n;++i)
			for (j = 0;j < n;++j) {
				cout << "a[" << i + 1 << "][" << j + 1 << "]=";
				cin >> a[i][j];
			}
	}

	int maxtek = a[1][n - 1];
	for (i = 1; i < n; i++)
		for (j = n - i; j < n; j++)
			if (a[i][j] > maxtek) maxtek = a[i][j];

	cout << "local max=" << maxtek << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	system("pause");
	return 0;
}

