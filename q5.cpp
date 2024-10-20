#include <bits/stdc++.h>
using namespace std;


struct linkk {
    int data;
    struct linkk *prev;
    struct linkk *next;
};


void printll(linkk* head) {
    if (head == NULL) return;

    linkk *temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


linkk* createll(int val, int num) {
    linkk *head = (struct linkk *)malloc(sizeof(struct linkk));
    head->data = val;
    head->prev = NULL;
    head->next = NULL;

    linkk *temp = head;
    int newval;

    for (int i = 2; i <= num; i++) {
        linkk *newnode = (struct linkk *)malloc(sizeof(struct linkk));
        cout << "Enter data for node " << i << ": ";
        cin >> newval;
        newnode->data = newval;
        newnode->prev = temp;
        newnode->next = NULL;

        temp->next = newnode;
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
    newnode->prev = NULL;

    if (head == NULL) {
        newnode->next = NULL;
        return newnode;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;

    return head;
}


void addatend(linkk *head) {
    int value;
    cout << "Enter the value to enter at end: " << endl;
    cin >> value;

    linkk *newnode = (struct linkk *)malloc(sizeof(struct linkk));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    linkk *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
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
    while (temp != NULL) {
        if (temp->data == index) {
            newnode->next = temp->next;
            newnode->prev = temp;

            if (temp->next != NULL) {
                temp->next->prev = newnode;
            }
            temp->next = newnode;
            return;
        }
        temp = temp->next;
    }

    cout << "Value " << index << " doesn't exist in the linked list." << endl;
}


linkk* delatbeg(linkk *head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return NULL;
    }

    linkk *delnode = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(delnode);
    return head;
}


void delatend(linkk *head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == NULL) {
        free(head);
        return;
    }

    linkk *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}


void delatloc(linkk *head) {
    int value;
    cout << "Enter the value of the node to delete: " << endl;
    cin >> value;

    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    linkk *temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value " << value << " doesn't exist in the linked list." << endl;
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp == head) {
        head = temp->next;
    }

    free(temp);
}


void freeLinkedList(linkk* head) {
    while (head != NULL) {
        linkk *temp = head;
        head = head->next;
        free(temp);
    }
}



int main() {
    linkk* head = NULL;
    int choice, val, num;

    while (true) {
        cout << endl << "Menu:" << endl;
        cout << "1. Create Doubly Linked List" << endl;
        cout << "2. Print Doubly Linked List" << endl;
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
                cout << "Enter the number of nodes in your doubly linked list: " << endl;
                cin >> num;
                cout << "Enter data for node 1: " << endl;
                cin >> val;
                head = createll(val, num);
                break;
            case 2:
                if (head != NULL) {
                    
                } else {
                    cout << "Doubly linked list is empty." << endl;
                }
                break;
            case 3:
                if (head != NULL) {
                    head = addatbeg(head);
                } else {
                    cout << "Doubly linked list is empty. Create a doubly linked list first." << endl;
                }
                break;
            case 4:
                if (head != NULL) {
                    addatend(head);
                } else {
                    cout << "Doubly linked list is empty. Create a doubly linked list first." << endl;
                }
                break;
            case 5:
                if (head != NULL) {
                    addatloc(head);
                } else {
                    cout << "Doubly linked list is empty. Create a doubly linked list first." << endl;
                }
                break;
            case 6:
                if (head != NULL) {
                    head = delatbeg(head);
                } else {
                    cout << "Doubly linked list is empty. Create a doubly linked list first." << endl;
                }
                break;
            case 7:
                if (head != NULL) {
                    delatend(head);
                } else {
                    cout << "Doubly linked list is empty. Create a doubly linked list first." << endl;
                }
                break;
            case 8:
                if (head != NULL) {
                    delatloc(head);
                } else {
                    cout << "Doubly linked list is empty. Create a doubly linked list first." << endl;
                }
                break;
           
            case 9:
                freeLinkedList(head);
            
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
         printll(head);
    }

    return 0;
}
