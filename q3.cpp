#include<bits/stdc++.h>
using namespace std;

struct linkk {
    int data;
    struct linkk *node;
};

void printll(linkk* head) {
    linkk* temp2 = head;
    while (temp2 != NULL) {
        cout << temp2->data << endl;
        temp2 = temp2->node;
    }
}

// struct linkk* createll(int val, int num) {
//     linkk *head = (struct linkk *)malloc(sizeof(struct linkk));
//     head->data = val;
//     head->node = NULL;

//     linkk *temp = head;
//     int newval = 0;

//     for (int i = 2; i <= num; i++) {
//         linkk *newnode = (struct linkk *)malloc(sizeof(struct linkk));
//         temp->node = newnode;
//         cout << "Enter data for node " << i << ": ";
//         cin >> newval;
//         newnode->data = newval;
//         temp = newnode;
//     }
//     temp->node = NULL;
//     return head;
// }

struct linkk* addatbeg(linkk* head) {
    int value = 0;
    cout << "Enter the value to enter at the beginning: ";
    cin >> value;
    linkk *temp = (struct linkk *)malloc(sizeof(struct linkk));
    temp->data = value;
    temp->node = head;
    head = temp;
    return head;
}

void addatend(linkk* head) {
    int value = 0;
    cout << "Enter the value to enter at the end: ";
    cin >> value;
    linkk *temp = (struct linkk *)malloc(sizeof(struct linkk));
    temp->data = value;
    temp->node = NULL;
    linkk *temp2 = temp;
    temp = head;
    while (temp->node != NULL) {
        temp = temp->node;
    }
    temp->node = temp2;
}

bool valexists(linkk *head, int value) {
    linkk* temp2 = head;
    while (temp2 != NULL) {
        if (temp2->data == value) {
            return true;
        }
        temp2 = temp2->node;
    }
    return false;
}

void addatloc(linkk *head) {
    int value = 0, index = 0;
    cout << "Enter value after which you want to insert: ";
    cin >> index;
    cout << "Enter value for the new node: ";
    cin >> value;

    if (valexists(head, index)) {
        linkk *temp1 = head;
        while (temp1 != NULL && temp1->data != index) {
            temp1 = temp1->node;
        }
        if (temp1 != NULL) {
            linkk *temp = (struct linkk *)malloc(sizeof(struct linkk));
            temp->data = value;
            temp->node = temp1->node;
            temp1->node = temp;
        }
    } else {
        cout << "Value " << index << " doesn't exist in the linked list." << endl;
    }
}

linkk* deleteatbeg(linkk* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return NULL;
    }
    linkk* temp = head;
    head = head->node;
    free(temp);
    return head;
}


linkk* deleteatend(linkk* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return NULL;
    }
    if (head->node == NULL) {
        free(head);
        head = NULL;
        return NULL;
    }
    linkk* temp = head;
    while (temp->node->node != NULL) {
        temp = temp->node;
    }
    linkk *temp2=temp->node;
    temp->node = NULL;
    free(temp2);
    return head;
    
}


void deleteatloc(linkk* head) {
    int index;
    cout << "Enter the value of the node to delete: ";
    cin >> index;

    if (!valexists(head, index)) {
        cout << "Value " << index << " doesn't exist in the linked list." << endl;
        return;
    }

    if (head->data == index) {
        cout << "Use deleteatbeg to delete the first node." << endl;
        return;
    }

    linkk* temp = head;
    while (temp->node != NULL && temp->node->data != index) {
        temp = temp->node;
    }

    if (temp->node != NULL) {
        linkk* delNode = temp->node;
        temp->node = delNode->node;
        free(delNode);
    }
}


int countNodes(linkk* head) {
    int count = 0;
    linkk* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->node;
    }
    return count;
}

linkk* reversell(linkk* head) {
    linkk *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->node;
        curr->node = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void freell(struct linkk* head) {
    linkk* temp;
    while (head != NULL) {
        temp = head;
        head = head->node;
        free(temp);
    }
}

int main() {
    linkk* head = NULL;
    int choice,val ,num;
    cout << "Enter the number of nodes in your linked list: ";
     cin >> num;
    cout << "Enter data for node 1: ";
     cin >> val;
    head = (struct linkk *)malloc(sizeof(struct linkk));
    head->data = val;
    head->node = NULL;

    linkk *temp = head;
    int newval = 0;

    for (int i = 2; i <= num; i++) {
        linkk *newnode = (struct linkk *)malloc(sizeof(struct linkk));
        temp->node = newnode;
        cout << "Enter data for node " << i << ": ";
        cin >> newval;
        newnode->data = newval;
        temp = newnode;
    }
     temp->node = NULL;
     

    while (true) {
        // cout << "1. Create Linked List"<<endl;
        cout << "2. Print Linked List"<<endl;
        cout << "3. Add at Beginning "<<endl;
        cout << "4. Add at End "<<endl;
        cout << "5. Add at Specific Location "<<endl;
        cout << "6. Delete at Beginning "<<endl;
        cout << "7. Delete at End "<<endl;
        cout << "8. Delete at Specific Location "<<endl;
        cout << "9. Count Nodes "<<endl;
        cout << "10. Reverse Linked List "<<endl;
        cout << "11. Exit "<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            // case 1:
             
            //     head = createll(val, num);
            //     break;
            case 2:
                if (head != NULL) {
                   
                } else {
                    cout << "Linked list is empty "<<endl;
                }
                break;
            case 3:
                if (head != NULL) {
                    head = addatbeg(head);
                } else {
                    cout << "Linked list is empty , Create a linked list first "<<endl;
                }
                break;
            case 4:
                if (head != NULL) {
                    addatend(head);
                } else {
                    cout << "Linked list is empty , Create a linked list first "<<endl;
                }
                break;
            case 5:
                if (head != NULL) {
                    addatloc(head);
                } else {
                    cout << "Linked list is empty , Create a linked list first "<<endl;
                }
                break;
            case 6:
                if (head != NULL) {
                    head = deleteatbeg(head);
                } else {
                    cout << "Linked list is empty, Create a linked list first "<<endl;
                }
                break;
            case 7:
                if (head != NULL) {
                    head=deleteatend(head);
                } else {
                    cout << "Linked list is empty, Create a linked list first "<<endl;
                }
                break;
            case 8:
                if (head != NULL) {
                    deleteatloc(head);
                } else {
                    cout << "Linked list is empty , Create a linked list first "<<endl;
                }
                break;
            case 9:
                if (head != NULL) {
                    cout << "Number of nodes in the linked list: " << countNodes(head) << endl;
                } else {
                    cout << "Linked list is empty ";
                }
                break;
            case 10:
                if (head != NULL) {
                    head = reversell(head);
                    cout << "Linked list reversed "<<endl;
                } else {
                    cout << "Linked list is empty "<<endl;
                }
                break;
            case 11:
                freell(head);
                return 0;
            default:
                cout << "Invalid choice. Please try again "<<endl;
        }
        printll(head);
    }

    return 0;
}
