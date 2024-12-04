#include "bits/stdc++.h"

using namespace std;

int arr[256][256];

void recur(int m, int n, int r , int c){
    if(m==0){
        arr[r][c] = n;    
        return;
    }
    int shift = 1 << (m-1);
    recur(m-1,n,r,c);
    recur(m-1,n-1,r,c+shift);
    recur(m-1,n+1,r+shift,c);
    recur(m-1,n,r+shift,c+shift);
}

int main(){
    int m,n ; cin >> m >> n;
    recur(m,n,0,0);
    int val = pow(2,m);
    for(int i = 0  ; i < val ; i++){
        for(int j = 0  ; j < val ; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}