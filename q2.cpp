#include<bits/stdc++.h>
using namespace std;




bool issparse(int valnonzer, int row,int col){
    if(valnonzer>(row*col)/4){
        cout<<"no"<<endl;
        return 0;
    }
    cout<<"yes"<<endl;
    return 1;}



int main(){
    int row,col;
    cout << "Enter Number of rows : ";
    cin >> row;
    cout << "Enter Number of columns : ";
    cin >> col;
    int arr[row][col];
    cout << "Enter "<< row*col <<" elements: "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }
    cout<<"matrix : "<<endl;
    
   for (int i = 0; i < row; i++){
         for (int j = 0; j < col; j++){
            cout <<arr[i][j] << " ";
        }
        cout << endl;
    }
    int valnonzer=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                valnonzer++;}}}


    

    if(issparse(valnonzer,row,col)){
    int newarr[row+1][col];
    newarr[0][0] = row;
    newarr[0][1] = col;
    newarr[0][2] = valnonzer;
    int fixedcol=1;
    for (int i = 0; i < row; i++){
         for (int j = 0; j < col; j++) {
            if (arr[i][j] != 0) {
                newarr[fixedcol][0] = i;
                newarr[fixedcol][1] = j;
                newarr[fixedcol][2] = arr[i][j];
                fixedcol++;
            }
        }
    }
    
    cout << "Sparse Array is:"<<endl;
         for(int i=0; i<=valnonzer; i++){
            for(int j=0; j<3; j++){
                cout <<newarr[i][j] <<" ";
            }
            cout<<endl;
        }
    }

    else{
        cout << "Sparse array cannot be created ";
    }
    return 0;
    }

    


