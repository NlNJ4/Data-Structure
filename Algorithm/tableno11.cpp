#include "bits/stdc++.h"

using namespace std;

int main(){
    int n; cin >> n;
    long long A[n+1];
    A[0] = 1 , A[1] = 3;
    for(int i = 2; i < n+1 ; i++){
        A[i] = (A[i-1]*2 + A[i-2])%100000007;
    }
    cout << A[n];
}