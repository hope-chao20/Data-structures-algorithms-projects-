#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

// POP operation
void pop() {
    if (top == -1) {
        cout << "Stack Underflow!\n";
    } else {
        cout << "Deleted element: " << stack[top] << endl;
        top--;
    }
}

// Display stack elements
void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements:\n";

        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

int main() {
    int choice;

    // Add some elements to the stack
    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;

    cout << "Stack before POP:\n";
    display();

    pop();

    cout << "\nStack after POP:\n";
    display();

    return 0;
}
