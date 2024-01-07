#include <iostream>
#include <stack>
#include <string>
#include "Windows.h"

using namespace std;

// Завдання 1
void printStack(const stack<int>& stk) {
    stack<int> temp = stk;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

// Завдання 2
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

// Завдання 3
bool isCorrectSequence(const string& sequence) {
    stack<char> brackets;

    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '[') {
            brackets.push(bracket);
        }
        else if (bracket == ')' || bracket == ']') {
            if (brackets.empty()) {
                return false; // Непарна дужка, послідовність неправильна
            }

            char openBracket = brackets.top();
            brackets.pop();

            if ((bracket == ')' && openBracket != '(') || (bracket == ']' && openBracket != '[')) {
                return false; // Непарні дужки, послідовність неправильна
            }
        }
    }

    return brackets.empty(); // Послідовність правильна, якщо стек порожній
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Завдання 1
    stack<int> myStack;
    int n, num;

    cout << "Введіть кількість чисел для стеку: ";
    cin >> n;

    cout << "Введіть числа для стеку: ";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        myStack.push(num);
    }

    cout << "Стек: ";
    printStack(myStack);

    // Завдання 2
    stack<int> evenNumbers, oddNumbers;
    separateEvenOdd(myStack, evenNumbers, oddNumbers);

    cout << "Стек парних чисел: ";
    printStack(evenNumbers);

    cout << "Стек непарних чисел: ";
    printStack(oddNumbers);

    // Завдання 3
    string sequence;
    cout << "Введіть послідовність дужок: ";
    cin >> sequence;

    if (isCorrectSequence(sequence)) {
        cout << "Послідовність правильна.\n";
    }
    else {
        cout << "Послідовність неправильна.\n";
    }

    return 0;
}