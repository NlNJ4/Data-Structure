#include "bits/stdc++.h"

using namespace std;

int main(){
    int n,k; cin >> n >> k;
    long long bino[n+1][k+1];
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= k ; j++){
            if(i==j || j == 0){
                bino[i][j] = 1;
            }
            else{
                bino[i][j] = bino[i-1][j-1]+bino[i-1][j];
            }
        }
    }
    cout << bino[n][k];
}