#include "bits/stdc++.h"

using namespace std;

int main(){
    int n ; cin >> n;
    vector<vector<pair<int,int>>> G(n);
    vector<int> dist(n,INT_MAX) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int temp; cin >> temp;
            if(temp>0) G[i].push_back({temp,j});
        }
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
    pq.push({0,0});
    dist[0] = 0;
    while (!pq.empty())
    {
        auto [value,pos] = pq.top();
        pq.pop();
        
        if(value > dist[pos] ) continue;
        for(auto [currentweight,neighbor] : G[pos]){
            int newdist = currentweight+value;
            if(newdist < dist[neighbor]){
                dist[neighbor] = newdist;
                pq.push({newdist,neighbor});
            }
        }
    }
    int mx = -1 ; 
    for(auto val:dist) {
        if(val==INT_MAX){
            mx = -1;
            break;
        }
        mx = max(mx,val);
    }
    cout << mx;
}