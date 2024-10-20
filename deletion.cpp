#include<bits/stdc++.h>
using namespace std;


void printarray(int *a,int len){
    for(int k=0;k<len; k++){
       cout<<a[k]<<endl;
     }
}
void dele(int *a,int n,int &len){
if(n<len){
   
       
        for ( int i = n; i<=len; i++)
        {
            a[i]=a[i+1];
        }   
        len--;
    }
    else{
        cout<<"Invalid size"<<endl;
    }
}


int main(){
    int a[]={11,12,13,14,15,16,17,18,19,20};
    int len=sizeof(a)/sizeof(a[0]);
    int n;
    cout<<"array before deletion :"<<endl;
    printarray(a,len);
    cout<<"enter the Index at which u want to Delete the element (0 - 9)"<<endl;
    cin>>n;
    dele(a,n,len);
    cout<<"array after deletion :"<<endl;
    printarray(a,len);

return 0;
}