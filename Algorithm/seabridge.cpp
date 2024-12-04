#include <bits/stdc++.h>

using namespace std;

int main() {
    int r , c ; cin >> r >> c;
    int arr[r][c];
    queue<pair<pair<int,int>,int>> q;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1) q.push({{i,j},1});
        }
    }
    int mn = INT_MAX;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        auto [position,depth] = q.front();
        auto [nowx,nowy] = position;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int newx = nowx+dirs[i][0], newy = nowy+dirs[i][1];
            if(newx<0 or newx>=r or newy < 0 or newy >= c) continue;
            if(arr[newx][newy]==2) mn = min(mn,depth+1);
            if(arr[newx][newy]==0) arr[newx][newy] = 1, q.push({{newx,newy},depth+1});
        }
    }
    cout << mn;
}