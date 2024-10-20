#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void enqueue(Node** front, Node** rear, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (*rear == NULL) {
        *front = *rear = temp;
        (*rear)->next = *front;
    } else {
        (*rear)->next = temp;
        *rear = temp;
        (*rear)->next = *front;
    }
    cout << value << " enqueued to the queue." << endl;
}

int dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        cout << "Queue is empty." << endl;
        return -1;
    }

    int value;
    if (*front == *rear) {
        value = (*front)->data;
        free(*front);
        *front = *rear = NULL;
    } else {
        Node* temp = *front;
        value = temp->data;
        *front = (*front)->next;
        (*rear)->next = *front;
        free(temp);
    }
    cout << value << " dequeued from the queue." << endl;
    return value;
}

void display(Node* front, Node* rear) {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;
    cout << "Queue: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    int choice, value;

    while (1) {
        cout << " Menu: "<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Exit "<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(&front, &rear, value);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
        
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
         display(front, rear);
    }

    return 0;
}
