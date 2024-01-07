#include <iostream>
#include <cstdlib>
#include <math.h>
#include "Windows.h"

using namespace std;

int const N = 100;
int stateMenu, n, j = 0;

//Фунція для заповнення масиву
void arrayFilling(int arr[]) {
	int min, max;//оголошення змінних для нижньої та верхньої межі

	cout << "\nВкажіть кількість елементів для доповнення масиву (0 - 100): ";
	cin >> n;
	if (n > 0 && n < 100) {
		cout << "Вкажіть нижню межу діапазону значення елементів для доповнення масиву: ";
		cin >> min;

		cout << "Вкажіть верхню межу діапазону значення елементів для доповнення масиву: ";
		cin >> max;

		//Цикл для заповнення масиву
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (max - min + 1) + min;
		}
		cout << "Масив створенно!";
	}
	else {
		cout << "Ви ввели число яке не відповідає умові!";
	}
}

//Функція для виведення масиву
void printArray(int arr[]) {
	cout << "\nСтворений масив: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "  ";
	}
}

//(Завдання 1) Функція для формування нового масиву з непарних елементів, що розташовані перед мінімальним елементом масиву
void task1(int arr[], int newArr[]) {
	int min = 10000, m;
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			m = i;
		}
	}
	cout << "\nМінімальний елемент масиву: " << min << endl;
	cout << "Масив утворений з непарних елементів які знаходяться перед мінімальним елементом масиву: " << endl;

	for (int i = 0; i < m; i++) {
		if (arr[i] % 2 != 0) {
			newArr[j] = arr[i];
			cout << newArr[j] << " ";
			j++;
		}
	}
}

//(Завдання 2) Функція для додавання після кожного від’ємного числа його модуля
void task2(int arr[], int updArr[]) {
	int l = 0, num = 0;

	//Цикл для визначення кількості від'ємних елементів
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			num++;
		}
	}

	//Перевірка на перевищення розміру масиву (N)
	if (n + num < N) {

		//Цикл для додавання після кожного від’ємного числа його модуля та перестановки елементів масиву
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

		//Виведення початкового масиву
		cout << "\nПочатковий масив: ";
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		//Виведення новоутвореного масиву
		cout << "\nНовоутворений масив: ";
		for (int i = 0; i < n + num; i++) {
			cout << updArr[i] << " ";
		}
	}
	else {
		cout << "\nДодавання елементів не можливе! Кількість елементів доповненого масиву перевищуватиме N (100)!\n";
	}
}

//Функція меню
void menu() {
	cout << "\n\n0. Вихід з програми." << endl
		<< "1. Заповнити масив." << endl
		<< "2. Вивести масив." << endl
		<< "3. Завдання 1." << endl
		<< "4. Завдання 2." << endl
		<< "Виберіть дію: ";
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
			cout << "\nТакого пункту немає!" << endl;
			menu();
			break;
		}
	}

	cout << "Роботу програми завершено!" << endl << endl;
	system("pause");
}