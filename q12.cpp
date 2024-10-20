#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

bool isEmpty() {
    return top == nullptr;
}

void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed onto the stack." << endl;
}

int pop() {
    if (isEmpty()) {
       
        return -1;
    }
    int value = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);
    cout << value << " popped from the stack." << endl;
    return value;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack: ";
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (1) {
        cout << "Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
               
                break;
            case 4:
                if (isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
         display();
    }

    return 0;
}
