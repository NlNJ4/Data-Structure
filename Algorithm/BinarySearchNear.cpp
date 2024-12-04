#include "bits/stdc++.h"

using namespace std;

int main(){
    int x,y; cin >> x >> y;
    vector<int> v;
    for(int i = 0 ; i < x ; i++){
        int val ; cin >> val;
        v.push_back(val);
    }
    for(int i = 0 ; i < y ; i++){
        int val ; cin >> val;
        auto itr = lower_bound(v.begin(),v.end(),val);
        if(*itr==val) cout << val << endl;
        else{
            if(itr==v.begin()) cout << -1 << endl;
            else{
                itr--;
                cout << *itr << endl;
            }
        }
    }
}