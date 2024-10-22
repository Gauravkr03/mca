#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 5

struct Node {
    int data;
    Node* next;
};

void enqueueLinkedList(Node** front, Node** rear, int value) {
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
    cout << value << " enqueued to the queue (linked list)." << endl;
}

int dequeueLinkedList(Node** front, Node** rear) {
    if (*front == NULL) {
        cout << "Queue is empty (linked list)." << endl;
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
    cout << value << " dequeued from the queue (linked list)." << endl;
    return value;
}

void displayLinkedList(Node* front, Node* rear) {
    if (front == NULL) {
        cout << "Queue is empty (linked list)." << endl;
        return;
    }

    Node* temp = front;
    cout << "Queue (linked list): ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

int queueArray[SIZE];
int frontArray = -1, rearArray = -1;

bool isFullArray() {
    return (rearArray + 1) % SIZE == frontArray;
}

bool isEmptyArray() {
    return frontArray == -1;
}

void enqueueArray(int value) {
    if (isFullArray()) {
        cout << "Queue is full (array)." << endl;
        return;
    } else if (isEmptyArray()) {
        frontArray = rearArray = 0;
        queueArray[rearArray] = value;
    } else {
        rearArray = (rearArray + 1) % SIZE;
        queueArray[rearArray] = value;
    }
    cout << value << " enqueued to the queue (array)." << endl;
}

int dequeueArray() {
    if (isEmptyArray()) {
        cout << "Queue is empty (array)." << endl;
        return -1;
    }

    int value = queueArray[frontArray];
    if (frontArray == rearArray) {
        frontArray = rearArray = -1;
    } else {
        frontArray = (frontArray + 1) % SIZE;
    }
    cout << value << " dequeued from the queue (array)." << endl;
    return value;
}

void displayArray() {
    if (isEmptyArray()) {
        cout << "Queue is empty (array)." << endl;
        return;
    }

    cout << "Queue (array): ";
    if (rearArray >= frontArray) {
        for (int i = frontArray; i <= rearArray; i++)
            cout << queueArray[i] << " ";
    } else {
        for (int i = frontArray; i < SIZE; i++)
            cout << queueArray[i] << " ";
        for (int i = 0; i <= rearArray; i++)
            cout << queueArray[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value, subChoice;
    Node* frontLinkedList = NULL;
    Node* rearLinkedList = NULL;

    while (1) {
        cout << "\nMain Menu: " << endl;
        cout << "1. Circular Queue (Linked List)" << endl;
        cout << "2. Circular Queue (Array)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            while (1) {
                cout << "\nLinked List Queue Menu: " << endl;
                cout << "1. Enqueue" << endl;
                cout << "2. Dequeue" << endl;
                cout << "3. Display" << endl;
                cout << "4. Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    enqueueLinkedList(&frontLinkedList, &rearLinkedList, value);
                } else if (subChoice == 2) {
                    dequeueLinkedList(&frontLinkedList, &rearLinkedList);
                } else if (subChoice == 3) {
                    displayLinkedList(frontLinkedList, rearLinkedList);
                } else if (subChoice == 4) {
                    break;
                } else {
                    cout << "Invalid choice." << endl;
                }
            }
        } else if (choice == 2) {
            while (1) {
                cout << "\nArray Queue Menu: " << endl;
                cout << "1. Enqueue" << endl;
                cout << "2. Dequeue" << endl;
                cout << "3. Display" << endl;
                cout << "4. Check if Full" << endl;
                cout << "5. Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    enqueueArray(value);
                } else if (subChoice == 2) {
                    dequeueArray();
                } else if (subChoice == 3) {
                    displayArray();
                } else if (subChoice == 4) {
                    if (isFullArray()) {
                        cout << "Queue is full (array)." << endl;
                    } else {
                        cout << "Queue is not full (array)." << endl;
                    }
                } else if (subChoice == 5) {
                    break;
                } else {
                    cout << "Invalid choice." << endl;
                }
            }
        } else if (choice == 3) {
            exit(0);
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
