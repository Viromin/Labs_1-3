#include <iostream>
#include <cstdlib>
#include <math.h>
#include "Windows.h"

using namespace std;

int const N = 100;
int stateMenu, n, j = 0;

//������ ��� ���������� ������
void arrayFilling(int arr[]) {
	int min, max;//���������� ������ ��� ������ �� ������� ���

	cout << "\n������ ������� �������� ��� ���������� ������ (0 - 100): ";
	cin >> n;
	if (n > 0 && n < 100) {
		cout << "������ ����� ���� �������� �������� �������� ��� ���������� ������: ";
		cin >> min;

		cout << "������ ������ ���� �������� �������� �������� ��� ���������� ������: ";
		cin >> max;

		//���� ��� ���������� ������
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (max - min + 1) + min;
		}
		cout << "����� ���������!";
	}
	else {
		cout << "�� ����� ����� ��� �� ������� ����!";
	}
}

//������� ��� ��������� ������
void printArray(int arr[]) {
	cout << "\n��������� �����: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "  ";
	}
}

//(�������� 1) ������� ��� ���������� ������ ������ � �������� ��������, �� ���������� ����� ��������� ��������� ������
void task1(int arr[], int newArr[]) {
	int min = 10000, m;
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			m = i;
		}
	}
	cout << "\n̳�������� ������� ������: " << min << endl;
	cout << "����� ��������� � �������� �������� �� ����������� ����� ��������� ��������� ������: " << endl;

	for (int i = 0; i < m; i++) {
		if (arr[i] % 2 != 0) {
			newArr[j] = arr[i];
			cout << newArr[j] << " ";
			j++;
		}
	}
}

//(�������� 2) ������� ��� ��������� ���� ������� �䒺����� ����� ���� ������
void task2(int arr[], int updArr[]) {
	int l = 0, num = 0;

	//���� ��� ���������� ������� ��'����� ��������
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			num++;
		}
	}

	//�������� �� ����������� ������ ������ (N)
	if (n + num < N) {

		//���� ��� ��������� ���� ������� �䒺����� ����� ���� ������ �� ������������ �������� ������
		for (int i = 0; i < n + num; i++) {
			if (i + n + num < N) {
				if (arr[i] < 0) {
					updArr[i + l] = arr[i];
					updArr[i + l + 1] = abs(arr[i]);
					l++;
				}
				else {
					updArr[i + l] = arr[i];
				}
			}

		}

		//��������� ����������� ������
		cout << "\n���������� �����: ";
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		//��������� �������������� ������
		cout << "\n������������� �����: ";
		for (int i = 0; i < n + num; i++) {
			cout << updArr[i] << " ";
		}
	}
	else {
		cout << "\n��������� �������� �� �������! ʳ������ �������� ����������� ������ �������������� N (100)!\n";
	}
}

//������� ����
void menu() {
	cout << "\n\n0. ����� � ��������." << endl
		<< "1. ��������� �����." << endl
		<< "2. ������� �����." << endl
		<< "3. �������� 1." << endl
		<< "4. �������� 2." << endl
		<< "������� ��: ";
	cin >> stateMenu;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int array[N], newArray[N], updArray[N];
	menu();
	while (stateMenu != 0)
	{
		switch (stateMenu)
		{
		case 1:
			arrayFilling(&array[N]);
			menu();
			break;
		case 2:
			printArray(&array[N]);
			menu();
			break;
		case 3:
			task1(&array[N], &newArray[N]);
			menu();
			break;
		case 4:
			task2(&array[N], &updArray[N]);
			menu();
			break;
		default:
			cout << "\n������ ������ ����!" << endl;
			menu();
			break;
		}
	}

	cout << "������ �������� ���������!" << endl << endl;
	system("pause");
}