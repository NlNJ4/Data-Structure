#include "bits/stdc++.h"

using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<pair<int,int>>> G(n);
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = i+1 ; j < n ; j++){
            int cost ; cin >> cost;
            G[i].push_back({cost,j});
            G[j].push_back({cost,i});
        }
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
    pq.push({0,0});
    vector<int> cost(n,INT_MAX);
    vector<bool> visited(n,false);
    int money = 0;
    while(!pq.empty()){
        auto [edgecost, node] = pq.top();
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;

        money += edgecost;

        for(auto pos : G[node]){
            if(!visited[pos.second]){
                pq.push({pos.first,pos.second});
            }
        }
    }
    cout << money;
}