#include <iostream>
#include <cstdlib>
using namespace std;

struct linkk {
    int data;
    struct linkk* next;
    struct linkk* prev;
};

linkk* head = NULL;

void printll() {
    linkk* temp = head;
    cout << "Doubly Linked List: " << endl;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void createll(int val) {
    linkk* newNode = (struct linkk*)malloc(sizeof(linkk));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        linkk* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void addatbeg(int value) {
    linkk* newNode = (struct linkk*)malloc(sizeof(linkk));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void addatend(int value) {
    linkk* newNode = (struct linkk*)malloc(sizeof(linkk));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    linkk* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void delatbeg() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    linkk* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void delatend() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    linkk* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

void delatloc(int loc) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    linkk* temp = head;
    for (int i = 0; temp != NULL && i < loc; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Location does not exist." << endl;
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

int main() {
    int choice, value;
    while (true) {
        cout << "Menu: " << endl;
        cout << "1. Add node (create first node if empty)" << endl;
        cout << "2. Add node at beginning" << endl;
        cout << "3. Add node at end" << endl;
        cout << "4. Delete node at beginning" << endl;
        cout << "5. Delete node at end" << endl;
        cout << "6. Delete node at specific location" << endl;
        cout << "7. Print linked list" << endl;
        cout << "8. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value for new node: ";
                cin >> value;
                createll(value);
                break;
            case 2:
                cout << "Enter value to add at beginning: ";
                cin >> value;
                addatbeg(value);
                break;
            case 3:
                cout << "Enter value to add at end: ";
                cin >> value;
                addatend(value);
                break;
            case 4:
                delatbeg();
                break;
            case 5:
                delatend();
                break;
            case 6:
                cout << "Enter location to delete: ";
                cin >> value;
                delatloc(value);
                break;
            case 7:
                printll();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}