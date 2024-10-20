#include <iostream>

using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return rear == SIZE - 1;
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full." << endl;
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    cout << value << " enqueued to the queue." << endl;
}

int dequeue() {
    if (isEmpty()) {
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    cout << value << " dequeued from the queue." << endl;
    return value;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (1) {
        cout << " Menu: "<<endl;
        cout << "1. Enqueue "<<endl;
        cout << "2. Dequeue "<<endl;
        cout << "3. Display "<<endl;
        cout << "4. Check if Empty "<<endl;
        cout << "5. Check if Full "<<endl;
        cout << "6. Exit "<<endl;
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
               
                break;
            case 4:
                if (isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 5:
                if (isFull()) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "Queue is not full." << endl;
                }
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
         display();
    }

    return 0;
}
