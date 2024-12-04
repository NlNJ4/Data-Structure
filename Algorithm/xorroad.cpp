#include "bits/stdc++.h"

using namespace std;

int main(){
    long long n; cin >> n;
    vector<long long> w(n);
    vector<bool> visited(n,false);
    vector<vector<pair<long long,long long>>> G(n);
    for(long long i = 0 ; i < n ; i++) cin >> w[i];
    for(long long i = 0 ; i < n ; i++) {
        for(long long j = 0 ; j < n ; j++) {
            if(i!=j){
                G[i].push_back({w[i]^w[j],j});
            }                
        }
    }
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>> pq;
    long long beautiful = 0;
    pq.push({0,0});
    while(!pq.empty()){
        auto [value,pos] = pq.top();
        pq.pop();
        if(visited[pos]) continue; beautiful+=value;
        visited[pos] = true;
        for(auto [val,dir] : G[pos]){
            if(!visited[dir]) pq.push({val,dir});
        }
    }
    cout << beautiful;
}