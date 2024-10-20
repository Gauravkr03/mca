#include<bits/stdc++.h>
using namespace std;

void insertion(int *a, int m,int n,int len){
    if(n>=0 && n<=len-1){
         len++;
        for ( int i = len -1; i>=n; i--)
        {
            a[i+1]=a[i];
        }
        a[n]=m;
        
    for(int k=0;k<=len-1; k++){
      cout<<a[k]<<endl;
    }
    
        
    }
    else{
        cout<<"Invalid size"<<endl;
    }

}
int main(){
    int a[]={1,2,3,4,5,6};
    int len=sizeof(a)/sizeof(a[0]);
    int m,n;
    cout<<"enter the location at which u want to insert the element"<<endl;
    cin>>n;
    cout<<"enter the value "<<endl;
    cin>>m;
    insertion(a,m,n,len);
   

  
return 0;
}