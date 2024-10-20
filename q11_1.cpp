#include <iostream>


using namespace std;

#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (rear + 1) % SIZE == front;  
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full." << endl;
        return;
    } else if (isEmpty()) {
        front = rear = 0;
        queue[rear] = value;
    } else {
        rear = (rear + 1) % SIZE;  
        queue[rear] = value;
    }
    cout << value << " enqueued to the queue." << endl;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }

    int value = queue[front];
    if (front == rear) {
        front = rear = -1;  
    } else {
        front = (front + 1) % SIZE;  
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
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
    } else {
        for (int i = front; i < SIZE; i++)
            cout << queue[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (1) {
        cout << " Menu:"<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Check if Full"<<endl;
        cout << "5. Exit"<<endl;
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
                if (isFull()) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "Queue is not full." << endl;
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
