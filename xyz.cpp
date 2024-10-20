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





int insertAtBeginning(int arr[], int n , int newelement){

    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[0] = newelement;

  
    cout << "Updated Array: ";
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}





int insertAtPosition(int arr[], int n,int newelement, int position)
{
    n++; 
 
    for (int i = n; i >= position; i--) 
        arr[i] = arr[i - 1]; 
 
    arr[position - 1] = newelement; 
 cout<<"updated array"<<" ";
 for(int i=0;i<n;i++)
 cout<<arr[i]<<" ";
    return 0; 
} 




int insertAtEnd(int arr[], int n,int newelement)
{
    arr[n++]=newelement;
     cout<<"updated array"<<" ";
 for(int i=0;i<n;i++)
 cout<<arr[i]<<" ";
    return 0;
    }




int deleteAtBeginning(int arr[], int n)
{ for(int i=0;i<n-1;i++)
    arr[i]=arr[i+1];
    cout<<"updated array"<<" ";
 for(int i=0;i<n-1;i++)
 cout<<arr[i]<<" ";
    return 0;
}




int deleteAtPosition(int arr[], int n, int element){
  int i;
    for (i = 0; i < n; i++) 
        if (arr[i] == element) 
            break; 
  
    if (i < n) { 
        
        n = n - 1; 
        for (int j = i; j < n; j++) 
            arr[j] = arr[j + 1]; 
    } 
  
     cout<<"updated array"<<" ";
 for(int i=0;i<n;i++)
 cout<<arr[i]<<" ";
    return 0;}





int deleteAtEnd(int arr[],int n)
{cout<<"array after deletion of last element";
for(int i=0;i<n-1;i++)
cout<<arr[i]<<" ";
return 0;}
int linearSearch(int arr[],int n, int element)
{for (int i = 0; i < n; i++)
        if (arr[i] == element)
            return i+1;
    return 0;}



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
    int a[20];
    int len;
    cout << "Enter size of array:";
    cin >>len;
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
        cout << "2. Insert at beginning" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Insert at an Index " << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete from an Index " << endl;
        cout << "8. Insertion sort " << endl;
        cout << "9. Binary search  " << endl;
        cout << "10. Linear search  " << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:{
                traverse(a,len);
                break;
            }
             case 2: {
             
            cout<<"1.To insert at beginning  "<<endl;
            cout<<"2.To insert at other location  "<<endl;
            cout<<"3.To insert at end "<<endl;
            cout<<"4.Exit "<<endl;
            cout << "Enter your value : ";
            cin>>choice1;
            switch (choice1) {
            case 1:{
                 cout<<"enter the value "<<endl;
                 cin>>m;
                 insertion(a,m,0,len);
                 break;
            }
            case 2:{
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

            