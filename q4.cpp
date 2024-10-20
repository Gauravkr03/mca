#include <bits/stdc++.h>
using namespace std;

struct linkk {
    int data;
    struct linkk *node;
};


void printll(linkk *head) {
    if (head == NULL){
        return;}

    linkk *temp = head;
    do {
        cout << temp->data << endl;
        temp = temp->node;
    } while (temp != head);
}


linkk* createll(int val, int num) {
    linkk *head = (struct linkk *)malloc(sizeof(struct linkk));
    head->data = val;
    head->node = head; 

    linkk *temp = head;
    int newval;

    for (int i = 2; i <= num; i++) {
        linkk *newnode = (struct linkk *)malloc(sizeof(struct linkk));
        cout << "Enter data for node " << i << ": ";
        cin >> newval;
        newnode->data = newval;

        temp->node = newnode;
        newnode->node = head;  
        temp = newnode;
    }
    return head;
}


linkk* addatbeg(linkk *head) {
    int value;
    cout << "Enter the value to enter at beginning: " << endl;
    cin >> value;

    linkk *newnode = (struct linkk *)malloc(sizeof(struct linkk));
    newnode->data = value;

    if (head == NULL) {
        newnode->node = newnode; 
        return newnode;
    }

    linkk *temp = head;
    while (temp->node != head) {
        temp = temp->node;
    }
    temp->node = newnode;  
    newnode->node = head;  
    head = newnode;  

    return head;
}


void addatend(linkk *head) {
    int value;
    cout << "Enter the value to enter at end: " << endl;
    cin >> value;

    linkk *newnode = (struct linkk *)malloc(sizeof(struct linkk));
    newnode->data = value;

    if (head == NULL) {
        newnode->node = newnode;
        head = newnode;
        return;
    }

    linkk *temp = head;
    while (temp->node != head) {
        temp = temp->node;
    }

    temp->node = newnode;
    newnode->node = head;
}


void addatloc(linkk *head) {
    int value, index;
    cout << "Enter value after which you want to insert: " << endl;
    cin >> index;
    cout << "Enter value for the new node: " << endl;
    cin >> value;

    linkk *newnode = (struct linkk *)malloc(sizeof(struct linkk));
    newnode->data = value;

    linkk *temp = head;
    do {
        if (temp->data == index) {
            newnode->node = temp->node;
            temp->node = newnode;
            return;
        }
        temp = temp->node;
    } while (temp != head);

    cout << "Value " << index << " doesn't exist in the linked list." << endl;
}


linkk* delatbeg(linkk *head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return NULL;
    }

    if (head->node == head) {
        free(head);
        return NULL;
    }

    linkk *temp = head;
    while (temp->node != head) {
        temp = temp->node;
    }

    linkk *delnode = head;
    temp->node = head->node;
    head = head->node;
    free(delnode);

    return head;
}


void delatend(linkk *head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->node == head) {
        free(head);
        return;
    }

    linkk *temp = head;
    while (temp->node->node != head) {
        temp = temp->node;
    }

    linkk *delnode = temp->node;
    temp->node = head;
    free(delnode);
}


void delatloc(linkk *head) {
    int value;
    cout << "Enter the value of the node to delete: " << endl;
    cin >> value;

    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data == value) {
        head = delatbeg(head);
        return;
    }

    linkk *temp = head;
    do {
        if (temp->node->data == value) {
            linkk *delnode = temp->node;
            temp->node = delnode->node;
            free(delnode);
            return;
        }
        temp = temp->node;
    } while (temp != head);

    cout << "Value " << value << " doesn't exist in the linked list." << endl;
}


void freeLinkedList(linkk* head) {
    if (head == NULL) return;

    linkk* temp = head;
    do {
        linkk* next = temp->node;
        free(temp);
        temp = next;
    } while (temp != head);
}


int main() {
    linkk* head = NULL;
    int choice, val, num;

    while (true) {
        cout << endl << "Menu:" << endl;
        cout << "1. Create Circular Linked List" << endl;
        cout << "2. Print Circular Linked List" << endl;
        cout << "3. Add at Beginning" << endl;
        cout << "4. Add at End" << endl;
        cout << "5. Add at Specific Location" << endl;
        cout << "6. Delete at Beginning" << endl;
        cout << "7. Delete at End" << endl;
        cout << "8. Delete at Specific Location" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of nodes in your circular linked list: " << endl;
                cin >> num;
                cout << "Enter data for node 1: " << endl;
                cin >> val;
                head = createll(val, num);
                break;
            case 2:
                if (head != NULL) {
                    printll(head);
                } else {
                    cout << "Circular linked list is empty." << endl;
                }
                break;
            case 3:
                if (head != NULL) {
                    head = addatbeg(head);
                } else {
                    cout << "Circular linked list is empty. Create a circular linked list first." << endl;
                }
                break;
            case 4:
                if (head != NULL) {
                    addatend(head);
                } else {
                    cout << "Circular linked list is empty. Create a circular linked list first." << endl;
                }
                break;
            case 5:
                if (head != NULL) {
                    addatloc(head);
                } else {
                    cout << "Circular linked list is empty. Create a circular linked list first." << endl;
                }
                break;
            case 6:
                if (head != NULL) {
                    head = delatbeg(head);
                } else {
                    cout << "Circular linked list is empty. Create a circular linked list first." << endl;
                }
                break;
            case 7:
                if (head != NULL) {
                    delatend(head);
                } else {
                    cout << "Circular linked list is empty. Create a circular linked list first." << endl;
                }
                break;
            case 8:
                if (head != NULL) {
                    delatloc(head);
                } else {
                    cout << "Circular linked list is empty. Create a circular linked list first." << endl;
                }
                break;
            case 9:
                freeLinkedList(head);
                
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
