#include<bits/stdc++.h>
using namespace std;

void traverse(int *a, int &len) {
    for (int i = 0; i < (len); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int linearSearch(int *a, int &len, int element) {
    for (int i = 0; i < (len) ; i++) {
        if (a[i] == element) {
            return i;
        }
    }
    return -1;
}


void dele(int *a,int n,int &len){
if(n < (len)){
        for ( int i = n; i<(len); i++)
        {
            a[i]=a[i+1];
        }   
        len--;
    }
    else{
        cout<<"Invalid size"<<endl;
    }
}

void insertion(int *a, int m,int n,int &len){
    
   
    if(n>=0 && n<((len))){
        (len)++;
        for ( int i = (len); i>=n; i--)
        {
            a[i+1]=a[i];
        }
        a[n]=m;
    }
    else{
        cout<<"Invalid size"<<endl;
    }

}
void insertend(int *a,int &len,int element){
    a[len]=element;
    len++;
}

int  binarsearch(int *a,int low,int high,int element){
    if(low>high){
        cout<<"element not found "<<endl;
        return -1;

    }
  int mid=(low+high)/2;
  if(a[mid]==element){
    cout<<"Element found at : "<<mid<<endl;
   
  }
  else if(a[mid]>element){
    return binarsearch(a,low,mid-1,element);
  }
  else{
    return binarsearch(a,mid+1,high,element);
  }

}


void insertionsort(int *a,int &len){
    for(int i=0;i<= (len)-1 ;i++){
        int j=i;
        while(j>0 && a[j-1]>a[j]){
            int temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j--;
        }
    }

}
int main(){
    int len;
    cout << "Enter size of array:";
    cin >>len;
    int a[len];
    for(int i=0; i<len; i++){
        cout<<"enter element :";
        cin >> a[i];
        cout<<endl;
    }
    int m,n,element;
    bool innerloop=true;
    int choice,choice1;
    do {
        cout << "Menu:" << endl;
        cout << "1. Traverse" << endl;
        cout << "2. Insert at any index" << endl;
        cout << "3. Delete from any index" << endl;
        cout << "4. Linear search" << endl;
        cout << "5. Insertion sort " << endl;
        cout << "6. Binary search  " << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:{
                traverse(a,len);
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
                 cout<<"enter the value "<<endl;
                 cin>>m;
                 insertion(a,m,0,len);
                 break;
            }
            case 2:{
                 cout<<"enter the location at which u want to insert the element"<<endl;
                  cin>>n;
                 cout<<"enter the value "<<endl;
                 cin>>m;
                 insertion(a,m,n,len);
                 break;
               
            }
            case 3:{
                cout<<"enter the value "<<endl;
                cin>>m;
                insertend(a,len,m);
                break;
            }
            case 4:{
                innerloop=false;
                break ;
            }
            default:{
                cout << "Invalid choice" << endl;
            } 
            }

            }
            while(innerloop);  
            break;
             }  
            
             case 3: {
                cout<<"enter the Index at which u want to Delete the element "<<endl;
                cin>>n;
                dele(a, n,len);
                break;
             }
             case 4: {
                int element;
                cout << "Enter the element to search: ";
                cin >> element;
                int result = linearSearch(a,len, element);
                if (result == -1) {
                    cout << "Element not found" << endl;
                } else {
                    cout << "Element found at location " << result << endl;
                }
                break;
            }
             
            case 5: {
                 cout << "Sorting this array"<<endl;
                 insertionsort(a,len);
                 break;
            }
                
            case 6:{
                cout << "Enter the number to search : "<<endl;
                cin>>element;
                 binarsearch(a,0,len-1,element);
                 break;
                
            }
            case 7:{
                exit(0);
            }
            default:{
                cout << "Invalid choice" << endl;
            }
        }
    } while (true);
    return 0;
}

            