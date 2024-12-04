#include "bits/stdc++.h"

using namespace std;

int main(){
    int n,m ; cin >> n >> m;
    int cnt = 0 ;
    int table[n][m];
    queue<pair<int,int>> q;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> table[i][j];
            if(table[i][j]==2) {
                q.push({i,j});
                cnt++;
            }

        }
    }
    int sum = 0;
    while(!q.empty()){
        auto f = q.front();
        int x = f.first;
        int y = f.second;
        q.pop();
        queue<pair<pair<int,int>,int>> bfs;
        bfs.push({{0,0},0});
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        //cout << x << ' ' << y << endl;
        while(!bfs.empty()){
            auto f = bfs.front();
            auto ff = f.first;
            int depth = f.second;
            int i = ff.first;
            int j = ff.second;
            bfs.pop();
            visited[i][j] = true;
            //cout << depth << endl;
            if(i==x&&y==j){
                sum+=(depth*2);
                table[i][j] = 1;
                break;
            }
            if(i>0) if(!visited[i-1][j]&&table[i-1][j]!=0)bfs.push({{i-1,j},depth+1});
            if(j>0) if(!visited[i][j-1]&&table[i][j-1]!=0)bfs.push({{i,j-1},depth+1});
            if(i+1<n) if(!visited[i+1][j]&&table[i+1][j]!=0) bfs.push({{i+1,j},depth+1});
            if(j+1<m) if(!visited[i][j+1]&&table[i][j+1]!=0) bfs.push({{i,j+1},depth+1});
        }
    }
    cout << sum;
}