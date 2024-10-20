#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow! Cannot push " << val << endl;
    } else {
        top++;
        stack[top] = val;
        cout << val << " pushed into stack." << endl;
    }
}

void pop() {
    if (top < 0) {
        cout << "Stack Underflow! Cannot pop from empty stack." << endl;
    } else {
        cout << stack[top] << " popped from stack." << endl;
        top--;
    }
}

void peek() {
    if (top < 0) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

bool isEmpty() {
    return (top < 0);
}

bool isFull() {
    return (top >= MAX - 1);
}

void printStack() {
    if (top < 0) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, val;

    while (true) {
        cout << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Print Stack" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                if (isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
            case 6:
                printStack();
                break;
            case 7:
                
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
