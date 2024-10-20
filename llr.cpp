#include<iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};

void insertatbeg(node *head, int val){
    node *temp;
    temp->info=val;
    temp->next=head;
    head=temp;

}

void insertatloc(node *head, int val, int loc){
    node *temp=NULL;
    node *temp1=head;
    temp->info=val;
    while(!temp1->info!=loc)
        temp1=temp1->next;
    temp->next=temp1->next;
    temp1->next=temp;
}

void insertatend(node *head, int val){
    node *temp=NULL;
    node *temp1=head;
    temp->info=val;
    while(temp1->next!=NULL)
        temp1=temp1->next;
    temp1->next=temp;
    temp->next=NULL;

}

int deletefrombeg(node *head){
    if(head=NULL){
        cout<<"\nNO NODES LEFT IN LIST";
        return -1;
    }
    node *temp=head;
    head=head->next;
    delete temp;
    return 0;
}

int deletefromloc(node*head, int loc){
    if(head=NULL){
        cout<<"\nNO NODES LEFT IN LIST";
        return -1;
    }
    node *temp1,*temp=head;
    while(temp->info!=loc){
        temp1=temp;
        temp=temp->next;}
    temp1->next=temp->next;
    delete temp;
    
}

int deletefromend(node *head){
    if(head=NULL){
        cout<<"\nNO NODES LEFT IN LIST";
        return -1;
    }
    node *temp1,*temp=head;
    while(temp->next!=NULL){
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=NULL;
    delete temp;
       
}

void display(node *head){
    if (head==NULL)
        cout<<"LIST IS EMPTY";
    else{
    node *temp;
    while(temp->next!=NULL){
        temp=temp->next;
        cout<<temp->info<<"   ->    ";
    }cout<<"NULL";}

}

int countll(node *head){
    int count=0;
    node *temp;
    while (temp->next!=NULL)
    {   temp=temp->next;
        count++;

    }
    return count;
    
}
node * reversal(node *head){
    if (head==NULL){
        cout<<"\nLIST IS EMPTY\n";
        return NULL;}
    node *curr=head;
    node *prev=NULL;
    node *save;
        while(curr!=NULL){
            save=curr->next;
            curr->next=prev;
            prev=curr;
            curr=save;
        }
        head=prev;
        return head;
}

int main() 
{
    node *head=NULL;
    while(1){ 
        cout<<"-----LINKED LIST-----\n";
        cout<<"Initialise the linked list, Add elements:\n";
        int flag=1,val;
        while(flag=1)
        {
        cin>>val;
        insertatend(head, val);
        cout<<"Element added!\n";
        cout<<"Continue?(y=1/n=0)\n";
        cin>>flag;
        }
        bool innerloop=true;
        bool innerloop2=true;
        bool innerloop3=true;
        int choice,choice1;
        int flag1=1;
        do {
        cout << "-----MENU FOR OPERATIONS----" << endl;
        cout << "1. Traversal" << endl;
        cout << "2. Insertion" << endl;
        cout << "3. Deletion" << endl;
        cout << "4. Reversal" << endl;
        cout << "5. Count of elements " << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:{
                cout<<"\nYour linked list is: \n";
                display(head);
                break;
            }
             case 2: {
                do{
             
            cout<<"1.To insert at beginning  "<<endl;
            cout<<"2.To insert at other location  "<<endl;
            cout<<"3.To insert at end "<<endl;
            cout<<"4.Exit "<<endl;
            cout << "Enter your choice ";
            cin>>choice1;
            switch (choice1) {
            case 1:{
                int m;
                cout<<"\nEnter the value: "<<endl;
                cin>>m;
                insertatbeg(head,m);
                cout<<"\nElement added"<<endl;
                display(head);
                break;
            }
            case 2:{
                int m,n;
                cout<<"\nEnter the value of location after which you want to insert the element"<<endl;
                cin>>n;
                cout<<"Enter the value "<<endl;
                cin>>m;
                insertatloc(head,m,n);
                cout<<"\nElement added"<<endl;
                display(head);
                break;
               
            }
            case 3:{
                int m;
                cout<<"\nEnter the value "<<endl;
                cin>>m;
                insertatend(head,m);
                cout<<"\nElement added"<<endl;
                display(head);
                break;
            }
            case 4:{
                innerloop=false;
                break ;
            }
            default:{
                cout << "\nInvalid choice" << endl;
            } 
            }

            }
            while(innerloop);  
            break;
             }  
            
             case 3: {
                   do{
             
            cout<<"1.To delete from beginning  "<<endl;
            cout<<"2.To delete from a location  "<<endl;
            cout<<"3.To delete from end "<<endl;
            cout<<"4.Exit "<<endl;
            cout << "Enter your choice ";
            cin>>choice1;
            switch (choice1) {
            case 1:{
                deletefrombeg(head);
                cout<<"\nElement deleted\n";
                break;
            }
            case 2:{
                int n;
                cout<<"\nEnter the value at the location from which you want to delete the element"<<endl;
                cin>>n;
                deletefromloc(head,n);
                cout<<"\nElement deleted\n";
                break;
               
            }
            case 3:{
                deletefromend(head);
                break;
            }
            case 4:{
                innerloop2=false;
                break ;
            }
            default:{
                cout << "Invalid choice" << endl;
            } 
            }

            }
            while(innerloop2);  
            break;
            }
            case 4: {
                if(reversal(head)!= NULL){
                cout<<"\nReversed list is:";
                display(head);
                cout<<"\nDo you want to continue with the reversed list-y=1/n=0?";
                int flag;
                    cin>>flag;
                    if(flag == 0)
                        reversal(head);
                }
                else
                    reversal(head);
            }
            
            case 5: {
                 cout <<"Counting elements..."<<endl;
                 cout<<"Number of nodes: "<<countll(head);
                 break;
            }
                
            case 6:{
                flag=0;
                break;
                }
    
            default:{
                cout << "Invalid choice" << endl;
            }
        }
    } while (flag1);
    char cont;
    cout<<"Do you want to continue for another linked list?(y/n)";
    cin>>cont;
    if (cont == 'y'||cont =='Y')
        continue;
    else
        break;
    }
    return 0;
}