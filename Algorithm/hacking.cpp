#include "bits/stdc++.h"

using namespace std;

int main(){
    int n,m,k ; cin >> n >> m >> k;
    vector<int> hacked(k);
    for(int i = 0 ; i < k ;i++) cin >> hacked[i];
    vector<vector<int>> G(n);
    vector<int> weight(n);
    for(int i = 0 ; i < n ; i++) cin >> weight[i];
    for(int i = 0 ; i < m ; i++){
        int st,tar ; cin >> st >> tar;
        G[st].push_back(tar);
        G[tar].push_back(st);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
    vector<int> dist(n,INT_MAX);
    for(auto tar : hacked){
        dist[tar] = weight[tar];
        pq.push({weight[tar],tar});
    }
    while(!pq.empty()){
        auto [weightnow,posnow] = pq.top();
        pq.pop();
        if(weightnow > dist[posnow]) continue;
        for(auto pos : G[posnow]){
            //cout << pos << endl;
            if( dist[pos] > weightnow + weight[pos]){
                dist[pos] = weightnow + weight[pos];
                pq.push({weightnow + weight[pos],pos});
            }
        }
    }
    int mx = 0;
    for(auto val:dist) mx = max(mx,val);
    cout << mx;
}