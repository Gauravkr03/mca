#include<bits/stdc++.h>
using namespace std;
void insertionsort(int *nuns,int &len){
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
    int nums[];

     for(int i=0;i<= (len)-1 ;i++){
        int j=i;
        while(j>0 && nums[j-1]>a[j]){
            int temp=a[j-1];
            nums[j-1]=nums[j];
            nums[j]=temp;
            j--;
        }
    }


return 0;
}