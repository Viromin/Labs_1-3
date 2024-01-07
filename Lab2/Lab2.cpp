#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <Windows.h>

using namespace std;

int stateMenu;

//Функція для заповнення та виведення списку цілих чисел
void fillList(list<int>& List) {
	int number;

	cout << "Введіть цілі числа(при введенні 0 зчитування завершиться): ";
	while (true) {
		cin >> number;
		List.push_back(number);
		if (number == 0) {
			break;
		}
	}

	cout << "Список цілих чисел: " << endl;
	for (const int& value : List) {
		cout << "[" << value << "]" << endl;
	}

}
//Функція для перетворення рядка в список символів
void convertStringToCharList() {
	string input;
	cout << "Введіть рядок: ";
	cin >> input;

	list<char> charList(input.begin(), input.end());

	cout << "Список символів: " << endl;
	for (const char& c : charList) {
		cout << "[" << c << "]" << endl;
	}
	cout << endl;
}
//Функція для перетворення рядка в список атомів
void convertStringToAtomList() {
	string input;
	cout << "Введіть рядок: ";
	cin >> input;

	list<string> listOfAtoms;

	for (char ch : input) {
		string atom = ""; // Створюємо атом (пустий рядок) з одним символом
		listOfAtoms.push_back(atom);
	}
	cout << "Список символів: " << endl;
	for (const string& atom : listOfAtoms) {
		cout << "[" << atom << "]" << endl;
	}
	cout << endl;
}

struct Date {
	int day;
	int month;
	int year;
};
struct Worker {
	string job;
	int salary;
};
struct FamilyMember {
	string firstName;
	string lastName;
	Date birthDate;
	Worker workInfo;
};
struct Family {
	FamilyMember husband;
	FamilyMember wife;
	vector<FamilyMember> children;
};
vector<Family> database;

void createFamily() {
	Family family1;
	FamilyMember child1;
	FamilyMember child2;
	FamilyMember child3;
	family1.husband.lastName = "Сенькович";
	family1.husband.firstName = "Роман";
	family1.husband.workInfo.job = "т";
	family1.husband.workInfo.salary = 1600;
	family1.husband.birthDate.day = 10;
	family1.husband.birthDate.month = 5;
	family1.husband.birthDate.year = 1977;
	family1.wife.lastName = "Сенькович";
	family1.wife.firstName = "Вікторія";
	family1.wife.workInfo.job = "т";
	family1.wife.workInfo.salary = 1300;
	family1.wife.birthDate.day = 14;
	family1.wife.birthDate.month = 6;
	family1.wife.birthDate.year = 1980;
	child1.lastName = "Сенькович";
	child1.firstName = "Дмитро";
	child1.birthDate.day = 11;
	child1.birthDate.month = 4;
	child1.birthDate.year = 2002;
	child2.lastName = "Сенькович";
	child2.firstName = "Софія";
	child2.birthDate.day = 8;
	child2.birthDate.month = 2;
	child2.birthDate.year = 2005;
	child3.lastName = "Сенькович";
	child3.firstName = "Марія";
	child3.birthDate.day = 11;
	child3.birthDate.month = 11;
	child3.birthDate.year = 2009;
	family1.children.push_back(child1);
	family1.children.push_back(child2);
	family1.children.push_back(child3);
	database.push_back(family1);

	Family family2;
	FamilyMember child4;
	FamilyMember child5;
	FamilyMember child6;
	family2.husband.lastName = "Багрій";
	family2.husband.firstName = "Віктор";
	family2.husband.workInfo.job = "т";
	family2.husband.workInfo.salary = 900;
	family2.husband.birthDate.day = 14;
	family2.husband.birthDate.month = 5;
	family2.husband.birthDate.year = 1978;
	family2.wife.lastName = "Багрій";
	family2.wife.firstName = "Наталія";
	family2.wife.workInfo.job = "н";
	family2.wife.birthDate.day = 11;
	family2.wife.birthDate.month = 3;
	family2.wife.birthDate.year = 1981;
	child4.lastName = "Багрій";
	child4.firstName = "Василь";
	child4.birthDate.day = 18;
	child4.birthDate.month = 12;
	child4.birthDate.year = 2003;
	child5.lastName = "Багрій";
	child5.firstName = "Юра";
	child5.birthDate.day = 8;
	child5.birthDate.month = 11;
	child5.birthDate.year = 2007;
	child6.lastName = "Багрій";
	child6.firstName = "Назар";
	child6.birthDate.day = 12;
	child6.birthDate.month = 7;
	child6.birthDate.year = 2011;
	family2.children.push_back(child4);
	family2.children.push_back(child5);
	family2.children.push_back(child6);
	database.push_back(family2);

	Family family3;
	FamilyMember child7;
	FamilyMember child8;
	family3.husband.lastName = "Повар";
	family3.husband.firstName = "Тарас";
	family3.husband.workInfo.job = "т";
	family3.husband.workInfo.salary = 1700;
	family3.husband.birthDate.day = 11;
	family3.husband.birthDate.month = 11;
	family3.husband.birthDate.year = 1980;
	family3.wife.lastName = "Повар";
	family3.wife.firstName = "Яна";
	family3.wife.workInfo.job = "т";
	family3.wife.workInfo.salary = 900;
	family3.wife.birthDate.day = 1;
	family3.wife.birthDate.month = 8;
	family3.wife.birthDate.year = 1983;
	child7.lastName = "Повар";
	child7.firstName = "Олександр";
	child7.birthDate.day = 20;
	child7.birthDate.month = 2;
	child7.birthDate.year = 2005;
	child8.lastName = "Повар";
	child8.firstName = "Анастасія";
	child8.birthDate.day = 24;
	child8.birthDate.month = 9;
	child8.birthDate.year = 2009;
	family3.children.push_back(child7);
	family3.children.push_back(child8);
	database.push_back(family3);

}
//Створення сім'ї 
void addFamily() {
	Family family;

	cout << "\nІм'я Чоловіка: ";
	cin >> family.husband.firstName;
	cout << "Фамілія Чоловіка: ";
	cin >> family.husband.lastName;
	cout << "Дата народження чоловіка (день місяць рік): ";
	cin >> family.husband.birthDate.day >> family.husband.birthDate.month >> family.husband.birthDate.year;
	cout << "Чи працює чоловік?(т/н): ";
	cin >> family.husband.workInfo.job;
	if (family.husband.workInfo.job != "н") {
		cout << "Зарплатня: ";
		cin >> family.husband.workInfo.salary;
	}

	cout << "\nІм'я Жінки: ";
	cin >> family.wife.firstName;
	cout << "Фамілія Жінки: ";
	cin >> family.wife.lastName;
	cout << "Дата народження жінки (день місяць рік): ";
	cin >> family.wife.birthDate.day >> family.wife.birthDate.month >> family.wife.birthDate.year;
	cout << "Чи працює жінка?(т/н): ";
	cin >> family.wife.workInfo.job;
	if (family.wife.workInfo.job != "н") {
		cout << "Зарплатня: ";
		cin >> family.wife.workInfo.salary;
	}

	int numChildren;
	cout << "\nКількість дітей: ";
	cin >> numChildren;
	for (int i = 0; i < numChildren; ++i) {
		FamilyMember child;
		cout << "\nІм'я дитини: ";
		cin >> child.firstName;
		cout << "Фамілія дитини: ";
		cin >> child.lastName;
		cout << "Дата народження дитини (день місяць рік): ";
		cin >> child.birthDate.day >> child.birthDate.month >> child.birthDate.year;
		child.workInfo.salary = 0;

		family.children.push_back(child);
	}

	database.push_back(family);

}
//Пошук сімей в яких більше 3 або більше дитини
void findFamiliesWithThreeChildren() {
	cout << "\nСім'ї з трьома і більше дітьми:" << endl;
	int i = 1;
	for (const Family& family : database) {
		if (family.children.size() >= 3) {
			cout << "\n Сім'я №" << i;
			cout << "\n   Чоловік: " << family.husband.firstName << " " << family.husband.lastName << "  Дата народження: " << family.husband.birthDate.day << "." << family.husband.birthDate.month << "." << family.husband.birthDate.year << "\n   Жінка: " << family.wife.firstName << " " << family.wife.lastName << "  Дата народження: " << family.wife.birthDate.day << "." << family.wife.birthDate.month << "." << family.wife.birthDate.year << endl;
		}
		i++;
	}
}
//Пошук дружин, які мають щонайменше трьох дітей та працюють:
void findWorkingWivesand3kids() {
	cout << "\nДружини, які мають щонайменше трьох дітей та працюють:" << endl;
	int i = 1;
	for (const Family& family : database) {
		if (family.wife.workInfo.job != "н" && family.children.size() >= 3) {
			cout << "\n Дружина №" << i << endl;
			cout << "   " << family.wife.firstName << " " << family.wife.lastName << "  Дата народження: " << family.wife.birthDate.day << "." << family.wife.birthDate.month << "." << family.wife.birthDate.year << endl;
		}
		i++;
	}
}
//Пошук дружин, які працюють
void findWorkingWives() {
	cout << "\nДружини, які працюють:" << endl;
	int i = 1;
	for (const Family& family : database) {
		if (family.wife.workInfo.job != "н") {
			cout << "\n Дружина №" << i << endl;
			cout << "   " << family.wife.firstName << " " << family.wife.lastName << "  Дата народження: " << family.wife.birthDate.day << "." << family.wife.birthDate.month << "." << family.husband.birthDate.year << endl;
		}
		i++;
	}
}
//Пошук членів сім'ї з доходом меншим 1000
void findPeopleWithIncomeLessThan1000() {
	cout << "\nЛюди з доходом менше ніж 1000:" << endl;
	int i = 1, j = 1;
	for (const Family& family : database) {
		if (family.husband.workInfo.salary < 1000) {
			cout << "\n Чоловік №" << i << endl;
			cout << "   " << family.husband.firstName << " " << family.husband.lastName << "  Дата народження: " << family.husband.birthDate.day << "." << family.husband.birthDate.month << "." << family.husband.birthDate.year << endl;
		}
		i++;
		if (family.wife.workInfo.salary < 1000) {
			cout << "\n Жінка №" << j << endl;
			cout << "   " << family.wife.firstName << " " << family.wife.lastName << "  Дата народження: " << family.wife.birthDate.day << "." << family.wife.birthDate.month << "." << family.wife.birthDate.year << endl;
		}
		j++;
	}
}
//Список сімей
void printAllNames() {
	cout << "\nВивести всі сім'ї:" << endl;
	int i = 1;
	for (const Family& family : database) {
		cout << " Сім'я №" << i << endl;
		cout << "   " << family.husband.firstName << " " << family.husband.lastName << "  Дата народження: " << family.husband.birthDate.day << "." << family.husband.birthDate.month << "." << family.husband.birthDate.year << endl;
		cout << "   " << family.wife.firstName << " " << family.wife.lastName << "  Дата народження: " << family.wife.birthDate.day << "." << family.wife.birthDate.month << "." << family.wife.birthDate.year << endl;
		cout << " Діти:" << endl;
		for (const FamilyMember& child : family.children) {
			cout << "   " << child.firstName << " " << child.lastName << "  Дата народження: " << child.birthDate.day << "." << child.birthDate.month << "." << child.birthDate.year << endl;
		}
		i++;
	}
}

//Меню
void menu() {
	cout << "\n\n0. Вихід з програми." << endl
		<< "1. Зчитати рядок цілих чисел та занести його в список." << endl
		<< "2. Перетворити рядок в список символів." << endl
		<< "3. Перетворити рядок в список атомів." << endl
		<< "4. Додати сім'ю." << endl
		<< "5. Знайти сім'ю з 3 або більше дітьми." << endl
		<< "6. Знайти працюючих дружин з принаймні трьома дітьми" << endl
		<< "7. Знайти всіх працюючих дружин." << endl
		<< "8. Знайти прізвища людей з прибутком менше 1000." << endl
		<< "9. Список всіх сімей." << endl
		<< "Виберіть дію: ";
	cin >> stateMenu;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	createFamily();

	list<int> intList;

	menu();
	while (stateMenu != 0)
	{
		switch (stateMenu)
		{
		case 1:
			fillList(intList);
			menu();
			break;
		case 2:
			convertStringToCharList();
			menu();
			break;
		case 3:
			convertStringToAtomList();
			menu();
			break;
		case 4:
			addFamily();
			menu();
			break;
		case 5:
			findFamiliesWithThreeChildren();
			menu();
			break;
		case 6:
			findWorkingWivesand3kids();
			menu();
			break;
		case 7:
			findWorkingWives();
			menu();
			break;
		case 8:
			findPeopleWithIncomeLessThan1000();
			menu();
			break;
		case 9:
			printAllNames();
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