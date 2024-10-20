#include<bits/stdc++.h>
using namespace std;




struct linkk
{
  int data;
  struct linkk *node;

};


void printll(linkk* head){
   linkk* temp2=head;
  while(temp2!=NULL){
   
    cout<<temp2->data<<endl;
    temp2=temp2->node;
  }

}





struct linkk* createll(int val,int num){
   linkk *head=(struct linkk *)malloc(sizeof(struct linkk));
    head->data=val;
    head->node=NULL;
 
  linkk *temp=head;
  int newval=0;

  for(int i=2;i<=num;i++){
    linkk *newnode=(struct linkk *)malloc(sizeof(struct linkk));
    temp->node=newnode;
    cout<<"enter data for node "<<i<<" : ";
    cin>>newval;
    newnode->data=newval;
    temp=newnode;

  }
  temp->node=NULL;
   return head;

}

struct linkk* addatbeg(linkk* head){
  int value=0;
  cout<<"enter the value to enter at beginning :"<<endl;
  cin>>value;
  linkk *temp=(struct linkk *)malloc(sizeof(struct linkk));
  temp->data=value;
  temp->node=head;
  printll(temp);
  head=temp;
  return head;
}

void addatend(linkk* head){
  int value=0;
  cout<<"enter the value to enter at end :"<<endl;
  cin>>value;
  linkk *temp=(struct linkk *)malloc(sizeof(struct linkk));
  temp->data=value;
  temp->node=NULL;
  linkk *temp2=temp;
  temp=head;
  while(temp->node!=NULL){
    temp=temp->node;

  }
  temp->node=temp2;
  
  printll(head);

}
bool valexists(linkk *head,int value){
  linkk* temp2=head;
  
  while(temp2!=NULL){
  if(temp2->data==value){
    return true;
  }
   temp2=temp2->node;}
 
   return false;
}


void addatloc(linkk *head){
  int value=0;
  int index=0;
  cout<<"enter value after which u want to insert :";
  cin>>index;
  cout<<"enter value for the new node :";
  cin>>value;
  
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

            printll(head);
        }
    } else {
     
        cout << "Value " << index << " doesn't exist in the linked list." << endl;
    }



}
 



void freeLinkedList(struct linkk* head) {
    linkk* temp;
    while (head != NULL) {
        temp = head;
        head = head->node;
        free(temp);
    }
}



int main(){
  int val,num;
  linkk* head=NULL;
  cout<<"enter the no. of nodes in your linked list :";
  cin>>num;
  cout<<"enter data for node 1 : ";
  cin>>val;
  
  head=createll(val,num);
  if(head!=NULL){
    printll(head);

  }

  head=addatbeg(head);
  addatend(head);
  addatloc(head);
  
 
 

 
return 0;
}