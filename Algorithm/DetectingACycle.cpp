#include "bits/stdc++.h"

using namespace std;

bool dfs(int now , int end , vector<vector<int>>& ed ,vector<bool>& visited){
    visited[now] = true;
    for(auto pos:ed[now]){
        if(!visited[pos]){
            if(dfs(pos,now,ed,visited)){
                return true;
            }
        }
        else if(pos!=end){
            return true;
        }
    }
    return false;
}

int main(){
    int t; cin >> t;
    for(int i = 0 ; i < t ;i++){
        int vertex,edge; cin >> vertex >> edge;
        vector<vector<int>> ed(vertex); 
        vector<bool> visited(vertex,false);
        for(int j = 0 ; j < edge ; j++){
            int a,b; cin >> a >> b;
            ed[a].push_back(b);
            ed[b].push_back(a);
        }
        bool ind = false;
        for(int j = 0 ; j < vertex; j++){
            if(!visited[j]){
                if(dfs(j,-1,ed,visited)){
                    ind = true;
                    break;
                }
            }
        }
        cout << (ind ? "YES" : "NO") << endl;
    }
}