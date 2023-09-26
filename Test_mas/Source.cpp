#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	const int MIN_VALUE = 2; // минимальное количество чисел внутри массива
	const int MAX_VALUE = 100; // изначальное максимальное количество чисел внутри массива
	int max_value = MAX_VALUE; //дополнительный максимум в случае одинаковых чисел в массиве после рандомного заполнения числами
	
	srand(time(NULL));
	
	cout << "Введите число массивов: ";
	cin >> n;
	cout << endl;
	
	int* pa = new int[n]; // массив, где хранятся данные о том, сколько чисел будет в каждом из n-массивов
	
	// рандомное наполнение чисел в заданном промежутке в массив ра
	for (int i = 0; i < n; i++)
	{
		pa[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
		//cout << "В " << i << " массиве " << pa[i] << " чисел" << endl;
	}
	// замена одинаковых чисел внутри массива pa
	for (int i = 0; i < n; i++) {
		for (int k = i + 1; k < n; k++) {
			if (pa[i] == pa[k]) {
				max_value++;
				pa[k] = max_value;
			}
		}
		 cout << "Внутри " << i << "-го массива " << pa[i] << " элемента" << endl << endl;
	}

	int** pp = new int* [n]; // массив, который мы будем наполнять в соответствии с числами, которые заполнились в массиве ра
	for (int i = 0; i < n; i++) {
		pp[i] = new int[pa[i]];
	}
	// вывод на экран изначальных массивов
	for (int i = 0; i < n; i++) {
		cout << i << "-é Ìàññèâ: ";
		for (int j = 0; j < pa[i]; j++) {
			pp[i][j] = rand();
			cout << pp[i][j] << "  ";
		}
		cout << endl << endl;
	}
	//сортировка пузырьком по убыванию Массивов с нечётным порядковым номером
	for (int k = 1; k < n; k = k + 2) {
		for (int i = 1; i < pa[k]; i++) {
			for (int j = 0; j < pa[k] - i; j++) {
				if (pp[k][j] < pp[k][j + 1]) {
					int temp = pp[k][j];
					pp[k][j] = pp[k][j + 1];
					pp[k][j + 1] = temp;
				}
			}
		}
	}
        //сортировка пузырьком по возрастанию Массивов с чётным порядковым номером
	for (int k = 0; k < n; k = k + 2) {
		for (int i = 1; i < pa[k]; i++) {
			for (int j = 0; j < pa[k] - i; j++) {
				if (pp[k][j] > pp[k][j + 1]) {
					int temp = pp[k][j];
					pp[k][j] = pp[k][j + 1];
					pp[k][j + 1] = temp;
				}
			}
		}
	}
	//вывод на экран отсортированных массивов
	for (int i = 0; i < n; i++) {
		cout << i << "-é îòñîðòèðîâàííûé Ìàññèâ: ";
		for (int j = 0; j < pa[i]; j++) {
			cout << pp[i][j] << "  ";
		}
		cout << endl << endl;
	}
}
