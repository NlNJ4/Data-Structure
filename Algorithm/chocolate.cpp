#include "bits/stdc++.h"

using namespace std;

int main(){
    int n,k ; cin >> n >> k;
    int dp[n+1] = {0};
    int s[k];
    dp[0] = 1;
    for(int i = 0 ; i < k ; i++){
        int val ; cin >> val;
        s[i] = val;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < k ; j++){
            if(i-s[j]>=0) dp[i] = (dp[i] + dp[i-s[j]])%1000003;
        }
    }
    cout << dp[n];
}