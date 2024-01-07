#include <iostream>
#include <stack>
#include <string>
#include "Windows.h"

using namespace std;

// �������� 1
void printStack(const stack<int>& stk) {
    stack<int> temp = stk;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

// �������� 2
void separateEvenOdd(stack<int>& original, stack<int>& evenStack, stack<int>& oddStack) {
    while (!original.empty()) {
        int num = original.top();
        original.pop();

        if (num % 2 == 0) {
            evenStack.push(num);
        }
        else {
            oddStack.push(num);
        }
    }
}

// �������� 3
bool isCorrectSequence(const string& sequence) {
    stack<char> brackets;

    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '[') {
            brackets.push(bracket);
        }
        else if (bracket == ')' || bracket == ']') {
            if (brackets.empty()) {
                return false; // ������� �����, ����������� �����������
            }

            char openBracket = brackets.top();
            brackets.pop();

            if ((bracket == ')' && openBracket != '(') || (bracket == ']' && openBracket != '[')) {
                return false; // ������ �����, ����������� �����������
            }
        }
    }

    return brackets.empty(); // ����������� ���������, ���� ���� �������
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // �������� 1
    stack<int> myStack;
    int n, num;

    cout << "������ ������� ����� ��� �����: ";
    cin >> n;

    cout << "������ ����� ��� �����: ";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        myStack.push(num);
    }

    cout << "����: ";
    printStack(myStack);

    // �������� 2
    stack<int> evenNumbers, oddNumbers;
    separateEvenOdd(myStack, evenNumbers, oddNumbers);

    cout << "���� ������ �����: ";
    printStack(evenNumbers);

    cout << "���� �������� �����: ";
    printStack(oddNumbers);

    // �������� 3
    string sequence;
    cout << "������ ����������� �����: ";
    cin >> sequence;

    if (isCorrectSequence(sequence)) {
        cout << "����������� ���������.\n";
    }
    else {
        cout << "����������� �����������.\n";
    }

    return 0;
}