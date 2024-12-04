#include "bits/stdc++.h"

using namespace std;

int main(){
    int n ; cin >> n;
    vector<int> v;
    v[0] = 0;
    v[1] = 1;
    v[2] = 3;
    for(int i = 3 ; i <= n ; i++){
        v[i] = (v[i-1] + 2*v[i-2])%(1000000007);
    }
    cout << v[n];
}