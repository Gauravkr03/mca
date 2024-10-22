#include <iostream>
#include <cstdlib>

using namespace std;



struct StackNode {
    int data;
    StackNode* next;
};

StackNode* top = nullptr;

bool isStackEmpty() {
    return top == nullptr;
}

void push(int value) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed onto the stack." << endl;
}

int pop() {
    if (isStackEmpty()) {
        cout << "Stack is empty, cannot pop." << endl;
        return -1;
    }
    int value = top->data;
    StackNode* temp = top;
    top = top->next;
    free(temp);
    cout << value << " popped from the stack." << endl;
    return value;
}

void displayStack() {
    if (isStackEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack: ";
    StackNode* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}



struct QueueNode {
    int data;
    QueueNode* next;
};

QueueNode* front = nullptr;
QueueNode* rear = nullptr;

bool isQueueEmpty() {
    return front == nullptr;
}

void enqueue(int value) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = value;
    newNode->next = nullptr;
    if (isQueueEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued to the queue." << endl;
}

int dequeue() {
    if (isQueueEmpty()) {
        cout << "Queue is empty, cannot dequeue." << endl;
        return -1;
    }
    int value = front->data;
    QueueNode* temp = front;
    front = front->next;
    free(temp);
    if (front == nullptr) {
        rear = nullptr;
    }
    cout << value << " dequeued from the queue." << endl;
    return value;
}

void displayQueue() {
    if (isQueueEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    QueueNode* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


void stackOperations() {
    int choice, value;
    do {
        cout << "\nStack Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Back to Main Menu" << endl;
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
                displayStack();
                break;
            case 4:
                if (isStackEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                break; 
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}

void queueOperations() {
    int choice, value;
    do {
        cout << "\nQueue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                if (isQueueEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 5:
                break; 
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}



int main() {
    int mainChoice;

    do {
        cout << "\nMain Menu:" << endl;
        cout << "1. Stack Operations" << endl;
        cout << "2. Queue Operations" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                stackOperations();
                break;
            case 2:
                queueOperations();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (mainChoice != 3);

    return 0;
}
