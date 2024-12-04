#include "bits/stdc++.h"

using namespace std;

int main(){
    int n ; cin >> n ; 
    vector<vector<pair<int,int>>> G(n);
    int sim ; cin >> sim;
    G[0].push_back({sim,1});
    G[1].push_back({sim,0});
    for(int i = 2 ; i < n ; i++){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        int time ; cin >> time;
        while(time--){
            int tar,cost ; cin >> tar >> cost;
            tar--;
            G[i].push_back({cost,tar});
            G[tar].push_back({cost,i});
        }
        pq.push({0,0});
        while(!pq.empty()){
            auto [costnow,posnow] = pq.top();
            pq.pop();
            if(costnow > dist[posnow] ) continue;
            if(posnow==1){
                cout << costnow << ' ';
                break;
            }
            for(auto target:G[posnow]){
                if(dist[target.second] > target.first + dist[posnow]){
                    dist[target.second] = target.first + dist[posnow];
                    pq.push({target.first + dist[posnow],target.second});
                }
            }
        }
    }
}