#include "bits/stdc++.h"

using namespace std;

int main(){
    long long n , t , mx = INT_MAX ; cin >> n >> t;
    vector<long long> v;
    while(t--){
        long long temp ; cin >> temp;
        v.push_back(temp);
        mx = min(mx,temp);
    }
    long long left = 0, right = n*mx;
    while(left < right){
        long long middle = (left+right)/2;
        long long sum = 0 ;
        for(auto val : v){
            sum+=middle/val;
        }
        if(sum>=n){
            right = middle;
        }
        else{
            left = middle+1;
        }
    }
    cout << left;
    return 0;
}