#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> v(100001);
vector<int> visited(100001,-1);
int ans = -1;
void dfs(int before , int now, int deep){
    visited[now] = deep;
    for(auto val : v[now]){
        if(val!=before && ans == -1){
            if(visited[val]==-1) dfs(now,val,deep+1);
            else{
                ans = deep + 1 - visited[val];
                return;
            }
        }  
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int a,b ; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int before = -1;
    dfs(-1,0,0);
    cout << ans;
}