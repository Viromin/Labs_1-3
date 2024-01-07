#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <Windows.h>

using namespace std;

int stateMenu;

//������� ��� ���������� �� ��������� ������ ����� �����
void fillList(list<int>& List) {
	int number;

	cout << "������ ��� �����(��� ������� 0 ���������� �����������): ";
	while (true) {
		cin >> number;
		List.push_back(number);
		if (number == 0) {
			break;
		}
	}

	cout << "������ ����� �����: " << endl;
	for (const int& value : List) {
		cout << "[" << value << "]" << endl;
	}

}
//������� ��� ������������ ����� � ������ �������
void convertStringToCharList() {
	string input;
	cout << "������ �����: ";
	cin >> input;

	list<char> charList(input.begin(), input.end());

	cout << "������ �������: " << endl;
	for (const char& c : charList) {
		cout << "[" << c << "]" << endl;
	}
	cout << endl;
}
//������� ��� ������������ ����� � ������ �����
void convertStringToAtomList() {
	string input;
	cout << "������ �����: ";
	cin >> input;

	list<string> listOfAtoms;

	for (char ch : input) {
		string atom = ""; // ��������� ���� (������ �����) � ����� ��������
		listOfAtoms.push_back(atom);
	}
	cout << "������ �������: " << endl;
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
	family1.husband.lastName = "���������";
	family1.husband.firstName = "�����";
	family1.husband.workInfo.job = "�";
	family1.husband.workInfo.salary = 1600;
	family1.husband.birthDate.day = 10;
	family1.husband.birthDate.month = 5;
	family1.husband.birthDate.year = 1977;
	family1.wife.lastName = "���������";
	family1.wife.firstName = "³�����";
	family1.wife.workInfo.job = "�";
	family1.wife.workInfo.salary = 1300;
	family1.wife.birthDate.day = 14;
	family1.wife.birthDate.month = 6;
	family1.wife.birthDate.year = 1980;
	child1.lastName = "���������";
	child1.firstName = "������";
	child1.birthDate.day = 11;
	child1.birthDate.month = 4;
	child1.birthDate.year = 2002;
	child2.lastName = "���������";
	child2.firstName = "�����";
	child2.birthDate.day = 8;
	child2.birthDate.month = 2;
	child2.birthDate.year = 2005;
	child3.lastName = "���������";
	child3.firstName = "����";
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
	family2.husband.lastName = "�����";
	family2.husband.firstName = "³����";
	family2.husband.workInfo.job = "�";
	family2.husband.workInfo.salary = 900;
	family2.husband.birthDate.day = 14;
	family2.husband.birthDate.month = 5;
	family2.husband.birthDate.year = 1978;
	family2.wife.lastName = "�����";
	family2.wife.firstName = "������";
	family2.wife.workInfo.job = "�";
	family2.wife.birthDate.day = 11;
	family2.wife.birthDate.month = 3;
	family2.wife.birthDate.year = 1981;
	child4.lastName = "�����";
	child4.firstName = "������";
	child4.birthDate.day = 18;
	child4.birthDate.month = 12;
	child4.birthDate.year = 2003;
	child5.lastName = "�����";
	child5.firstName = "���";
	child5.birthDate.day = 8;
	child5.birthDate.month = 11;
	child5.birthDate.year = 2007;
	child6.lastName = "�����";
	child6.firstName = "�����";
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
	family3.husband.lastName = "�����";
	family3.husband.firstName = "�����";
	family3.husband.workInfo.job = "�";
	family3.husband.workInfo.salary = 1700;
	family3.husband.birthDate.day = 11;
	family3.husband.birthDate.month = 11;
	family3.husband.birthDate.year = 1980;
	family3.wife.lastName = "�����";
	family3.wife.firstName = "���";
	family3.wife.workInfo.job = "�";
	family3.wife.workInfo.salary = 900;
	family3.wife.birthDate.day = 1;
	family3.wife.birthDate.month = 8;
	family3.wife.birthDate.year = 1983;
	child7.lastName = "�����";
	child7.firstName = "���������";
	child7.birthDate.day = 20;
	child7.birthDate.month = 2;
	child7.birthDate.year = 2005;
	child8.lastName = "�����";
	child8.firstName = "��������";
	child8.birthDate.day = 24;
	child8.birthDate.month = 9;
	child8.birthDate.year = 2009;
	family3.children.push_back(child7);
	family3.children.push_back(child8);
	database.push_back(family3);

}
//��������� ��'� 
void addFamily() {
	Family family;

	cout << "\n��'� �������: ";
	cin >> family.husband.firstName;
	cout << "����� �������: ";
	cin >> family.husband.lastName;
	cout << "���� ���������� ������� (���� ����� ��): ";
	cin >> family.husband.birthDate.day >> family.husband.birthDate.month >> family.husband.birthDate.year;
	cout << "�� ������ ������?(�/�): ";
	cin >> family.husband.workInfo.job;
	if (family.husband.workInfo.job != "�") {
		cout << "���������: ";
		cin >> family.husband.workInfo.salary;
	}

	cout << "\n��'� Ƴ���: ";
	cin >> family.wife.firstName;
	cout << "����� Ƴ���: ";
	cin >> family.wife.lastName;
	cout << "���� ���������� ���� (���� ����� ��): ";
	cin >> family.wife.birthDate.day >> family.wife.birthDate.month >> family.wife.birthDate.year;
	cout << "�� ������ ����?(�/�): ";
	cin >> family.wife.workInfo.job;
	if (family.wife.workInfo.job != "�") {
		cout << "���������: ";
		cin >> family.wife.workInfo.salary;
	}

	int numChildren;
	cout << "\nʳ������ ����: ";
	cin >> numChildren;
	for (int i = 0; i < numChildren; ++i) {
		FamilyMember child;
		cout << "\n��'� ������: ";
		cin >> child.firstName;
		cout << "����� ������: ";
		cin >> child.lastName;
		cout << "���� ���������� ������ (���� ����� ��): ";
		cin >> child.birthDate.day >> child.birthDate.month >> child.birthDate.year;
		child.workInfo.salary = 0;

		family.children.push_back(child);
	}

	database.push_back(family);

}
//����� ���� � ���� ����� 3 ��� ����� ������
void findFamiliesWithThreeChildren() {
	cout << "\nѳ�'� � ������ � ����� �����:" << endl;
	int i = 1;
	for (const Family& family : database) {
		if (family.children.size() >= 3) {
			cout << "\n ѳ�'� �" << i;
			cout << "\n   ������: " << family.husband.firstName << " " << family.husband.lastName << "  ���� ����������: " << family.husband.birthDate.day << "." << family.husband.birthDate.month << "." << family.husband.birthDate.year << "\n   Ƴ���: " << family.wife.firstName << " " << family.wife.lastName << "  ���� ����������: " << family.wife.birthDate.day << "." << family.wife.birthDate.month << "." << family.wife.birthDate.year << endl;
		}
		i++;
	}
}
//����� ������, �� ����� ���������� ����� ���� �� ��������:
void findWorkingWivesand3kids() {
	cout << "\n�������, �� ����� ���������� ����� ���� �� ��������:" << endl;
	int i = 1;
	for (const Family& family : database) {
		if (family.wife.workInfo.job != "�" && family.children.size() >= 3) {
			cout << "\n ������� �" << i << endl;
			cout << "   " << family.wife.firstName << " " << family.wife.lastName << "  ���� ����������: " << family.wife.birthDate.day << "." << family.wife.birthDate.month << "." << family.wife.birthDate.year << endl;
		}
		i++;
	}
}
//����� ������, �� ��������
void findWorkingWives() {
	cout << "\n�������, �� ��������:" << endl;
	int i = 1;
	for (const Family& family : database) {
		if (family.wife.workInfo.job != "�") {
			cout << "\n ������� �" << i << endl;
			cout << "   " << family.wife.firstName << " " << family.wife.lastName << "  ���� ����������: " << family.wife.birthDate.day << "." << family.wife.birthDate.month << "." << family.husband.birthDate.year << endl;
		}
		i++;
	}
}
//����� ����� ��'� � ������� ������ 1000
void findPeopleWithIncomeLessThan1000() {
	cout << "\n���� � ������� ����� �� 1000:" << endl;
	int i = 1, j = 1;
	for (const Family& family : database) {
		if (family.husband.workInfo.salary < 1000) {
			cout << "\n ������ �" << i << endl;
			cout << "   " << family.husband.firstName << " " << family.husband.lastName << "  ���� ����������: " << family.husband.birthDate.day << "." << family.husband.birthDate.month << "." << family.husband.birthDate.year << endl;
		}
		i++;
		if (family.wife.workInfo.salary < 1000) {
			cout << "\n Ƴ��� �" << j << endl;
			cout << "   " << family.wife.firstName << " " << family.wife.lastName << "  ���� ����������: " << family.wife.birthDate.day << "." << family.wife.birthDate.month << "." << family.wife.birthDate.year << endl;
		}
		j++;
	}
}
//������ ����
void printAllNames() {
	cout << "\n������� �� ��'�:" << endl;
	int i = 1;
	for (const Family& family : database) {
		cout << " ѳ�'� �" << i << endl;
		cout << "   " << family.husband.firstName << " " << family.husband.lastName << "  ���� ����������: " << family.husband.birthDate.day << "." << family.husband.birthDate.month << "." << family.husband.birthDate.year << endl;
		cout << "   " << family.wife.firstName << " " << family.wife.lastName << "  ���� ����������: " << family.wife.birthDate.day << "." << family.wife.birthDate.month << "." << family.wife.birthDate.year << endl;
		cout << " ĳ��:" << endl;
		for (const FamilyMember& child : family.children) {
			cout << "   " << child.firstName << " " << child.lastName << "  ���� ����������: " << child.birthDate.day << "." << child.birthDate.month << "." << child.birthDate.year << endl;
		}
		i++;
	}
}

//����
void menu() {
	cout << "\n\n0. ����� � ��������." << endl
		<< "1. ������� ����� ����� ����� �� ������� ���� � ������." << endl
		<< "2. ����������� ����� � ������ �������." << endl
		<< "3. ����������� ����� � ������ �����." << endl
		<< "4. ������ ��'�." << endl
		<< "5. ������ ��'� � 3 ��� ����� �����." << endl
		<< "6. ������ ��������� ������ � �������� ������ �����" << endl
		<< "7. ������ ��� ��������� ������." << endl
		<< "8. ������ ������� ����� � ��������� ����� 1000." << endl
		<< "9. ������ ��� ����." << endl
		<< "������� ��: ";
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
			cout << "\n������ ������ ����!" << endl;
			menu();
			break;
		}
	}

	cout << "������ �������� ���������!" << endl << endl;
	system("pause");
}