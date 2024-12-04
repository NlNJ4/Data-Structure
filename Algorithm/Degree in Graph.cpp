#include "bits/stdc++.h"

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n,0);
    int mx = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int val ; cin >> val;
            if(val==1){
                v[i]++;
                v[j]++;
                //cout << v[i] << ' ' << v[j];
                mx = max(mx,v[j]);
                mx = max(mx,v[i]);
            }
        }
    }
    //for(auto val:v) cout << val << ' '; 
    //cout << mx;
    for(int i = 0 ; i <= mx/2 ; i++){
        int cnt = 0;
        for(auto val:v){
            if(val/2==i) cnt++;
        }
        cout << cnt << ' ';
    }
}