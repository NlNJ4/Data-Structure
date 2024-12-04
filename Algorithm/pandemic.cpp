#include "bits/stdc++.h"

using namespace std;

int main(){
    int r,c,t ; cin >> r >> c >> t;
    int table[r][c];
    int ans = 0;
    queue<pair<int,int>> q;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cin >> table[i][j];
            if(table[i][j]==1){
                ans++;
                q.push({i,j});
            }
        }
    }
    while(t--){
        //cout << ans << ' ' ;
        int sz = q.size();
        while(sz--){
            auto dir = q.front();
            int x = dir.first;
            int y = dir.second;
            q.pop();
            if(x>0){
                if(table[x-1][y]==0){
                    table[x-1][y] = 1;
                    q.push({x-1,y});
                    ans++;
                }
            }
            if(y>0){
                if(table[x][y-1]==0){
                    table[x][y-1] = 1;
                    q.push({x,y-1});
                    ans++;
                }
            }
            if(x+1<r){
                if(table[x+1][y]==0){
                    table[x+1][y] = 1;
                    q.push({x+1,y});
                    ans++;
                }
            }
            if(y+1<c){
                if(table[x][y+1]==0){
                    table[x][y+1] = 1;
                    q.push({x,y+1});
                    ans++;
                }
            }
        }
    }
    cout << ans;
    /*for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }*/
}