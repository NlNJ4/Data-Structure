#include "bits/stdc++.h"

using namespace std;

void dfs(int val, vector<vector<int>>& vec , vector<bool> & visited , int k){
    visited[val] = true;
    if(k>0){
        for(auto pos:vec[val]){
            dfs(pos,vec,visited,k-1);
        }
    }
}

int main(){
    int n,e,k; cin >> n >> e >> k;
    vector<vector<int>> vec(n);
    for(int i = 0 ; i < e ; i++){
        int a,b ; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int mx = 0;
    for(int i = 0 ; i < n ; i++){
        int cnt = 0;
        vector<bool> visited(n,false);
        dfs(i,vec,visited,k);
        for(auto v:visited) if(v) cnt++;
        mx = max(cnt,mx);
    }
    cout << mx;
}