#include <bits/stdc++.h>
using namespace std;


struct linkk {
    int data;
    struct linkk *node;
};


void printll(linkk* head) {
    linkk* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->node;
    }
}


linkk* createll(int num) {
    int val;
    if (num <= 0) return NULL;
    
    linkk *head = (struct linkk *)malloc(sizeof(struct linkk));
    cout << "Enter data for node 1: ";
    cin >> val;
    head->data = val;
    head->node = NULL;

    linkk *temp = head;
    for (int i = 2; i <= num; i++) {
        linkk *newnode = (struct linkk *)malloc(sizeof(struct linkk));
        cout << "Enter data for node " << i << ": ";
        cin >> val;
        newnode->data = val;
        newnode->node = NULL;
        temp->node = newnode;
        temp = newnode;
    }

    return head;
}


linkk* mergeSortedLists(linkk* head1, linkk* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    linkk* mergedHead = NULL;

    
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->node;
    } else {
        mergedHead = head2;
        head2 = head2->node;
    }

    linkk* current = mergedHead;

    
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            current->node = head1;
            head1 = head1->node;
        } else {
            current->node = head2;
            head2 = head2->node;
        }
        current = current->node;
    }

    
    if (head1 != NULL) {
        current->node = head1;
    } else {
        current->node = head2;
    }

    return mergedHead;
}


int main() {
    int num1, num2;

    cout << "Enter the number of nodes in the first sorted linked list: ";
    cin >> num1;
    linkk* head1 = createll(num1);

    cout << "Enter the number of nodes in the second sorted linked list: ";
    cin >> num2;
    linkk* head2 = createll(num2);

    cout << "First Linked List: " << endl;
    printll(head1);

    cout << "Second Linked List: " << endl;
    printll(head2);

    linkk* mergedHead = mergeSortedLists(head1, head2);

    cout << "Merged Sorted Linked List: " << endl;
    printll(mergedHead);

    return 0;
}
