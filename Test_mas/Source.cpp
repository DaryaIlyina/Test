#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	const int MIN_VALUE = 2; // ����������� ���������� ����� ������ �������
	const int MAX_VALUE = 100; // ����������� ������������ ���������� ����� ������ �������
	int max_value = MAX_VALUE; //�������������� �������� � ������ ���������� ����� � ������� ����� ���������� ���������� �������
	srand(time(NULL));
	cout << "������� ����� ��������: ";
	cin >> n;
	cout << endl;
	
	int* pa = new int[n]; // ������, ��� �������� ������ � ���, ������� ����� ����� � ������ �� n-��������
	
	// ��������� ���������� ����� � �������� ���������� � ������ ��
	for (int i = 0; i < n; i++)
	{
		pa[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
		//cout << "� " << i << " ������� " << pa[i] << " �����" << endl;
	}
	// ������ ���������� ����� ������ ������� pa
	for (int i = 0; i < n; i++) {
		for (int k = i + 1; k < n; k++) {
			if (pa[i] == pa[k]) {
				max_value++;
				pa[k] = max_value;
			}
		}
		 cout << "������ " << i << "-�� ������� " << pa[i] << " ��������" << endl;
		 cout << endl;
	}

	int** pp = new int* [n]; // ������, ������� �� ����� ��������� � ������������ � �������, ������� ����������� � ������� ��
	for (int i = 0; i < n; i++) {
		pp[i] = new int[pa[i]];
	}
	// ����� �� ����� ����������� ��������
	for (int i = 0; i < n; i++) {
		cout << i << "-� ������: ";
		for (int j = 0; j < pa[i]; j++) {
			pp[i][j] = rand();
			cout << pp[i][j] << "  ";
		}
		cout << endl << endl;
	}
	//���������� ��������� �� �������� �������� � �������� ���������� �������
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
    //���������� ��������� �� ����������� �������� � ������ ���������� �������
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
	//����� �� ����� ��������������� ��������
	for (int i = 0; i < n; i++) {
		cout << i << "-� ��������������� ������: ";
		for (int j = 0; j < pa[i]; j++) {
			cout << pp[i][j] << "  ";
		}
		cout << endl << endl;
	}






}