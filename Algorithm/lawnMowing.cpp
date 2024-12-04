#include "bits/stdc++.h"

using namespace std;

int main(){
    long long int n,m,k; cin >> n >> m >> k;
    vector<long long> v(n+1,0);
    for(long long int i = 1 ; i <= n ; i++){
        long long int val ; cin >> val;
        v[i] = v[i-1] + val +k;
    }
    for(long long int i = 0 ; i < m ; i++){
        long long int start , budget ; cin >> start >> budget ;

        auto it = upper_bound(v.begin(),v.end(),budget+v[start]);
        if(it == v.begin()+1){
            cout << 0 << endl;
            continue;
        }
        it--;
        cout << *it - v[start] - (it-v.begin()-start)*k << endl;
    }
}