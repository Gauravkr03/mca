

#include <iostream>
using namespace std;

const int MAX_SIZE=10;

void computeLCSLength(char A[], int lenA, char B[], int lenB, int dp[MAX_SIZE][MAX_SIZE]) {
   
    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; 
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1]; 
            }
        }
    }
}


void printLCS(char A[], int lenA, char B[], int lenB, int dp[MAX_SIZE][MAX_SIZE]) {
    int index = dp[lenA][lenB];  
    char lcs[MAX_SIZE];
    lcs[index] = '\0'; 

    int i = lenA, j = lenB;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs[index - 1] = A[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) { 
            i--;
        } else {
            j--;
        }
    }

    cout << "LCS: " << lcs << endl;
}

int main() {
    char A[MAX_SIZE], B[MAX_SIZE];
    int lenA, lenB;

    cout << "Enter length of first sequence: ";
    cin >> lenA;
    cout << "Enter first sequence: ";
    for (int i = 0; i < lenA; i++) {
        cin >> A[i];
    }

    cout << "Enter length of second sequence: ";
    cin >> lenB;
    cout << "Enter second sequence: ";
    for (int i = 0; i < lenB; i++) {
        cin >> B[i];
    }

    int dp[MAX_SIZE][MAX_SIZE] = {0};

    computeLCSLength(A, lenA, B, lenB, dp);

    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << "Length of LCS: " << dp[lenA][lenB] << endl;

    printLCS(A, lenA, B, lenB, dp);

    return 0;
}
