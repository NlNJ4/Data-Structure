#include "bits/stdc++.h"

using namespace std;

int main(){
    int r , c ; cin >> r >> c;
    int table[r][c];
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cin >> table[i][j];
        }
    }
    vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
    dist[0][0] = 0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
    pq.push({0,{0,0}});
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!pq.empty()){
        int w = pq.top().first;
        int nowi = pq.top().second.first;
        int nowj = pq.top().second.second;
        pq.pop();
        if(w > dist[nowi][nowj]) continue;
        for(auto dir : dirs){
            int nexti = nowi+dir[0], nextj = nowj+dir[1];
            if(nexti>=0 && nexti < r && nextj>=0 && nextj < c){
                if(dist[nexti][nextj] > w + table[nexti][nextj]){
                    dist[nexti][nextj] = w + table[nexti][nextj];
                    pq.push({dist[nexti][nextj],{nexti,nextj}});
                }
            }
        }
    }
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
}