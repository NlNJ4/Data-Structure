#include "bits/stdc++.h"

using namespace std;

int main(){
    int n ; cin >> n;
    int table[n][n];
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> table[i][j];
        }
    }
    int mx = -INT_MAX;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            int val = 0 ;
            for(int k = 0 ; k < min(n-i,n-j) ; k++){
                val += table[i+k][j+k];
                mx = max(mx,val);
            }
        }
    }
    cout << mx;
}