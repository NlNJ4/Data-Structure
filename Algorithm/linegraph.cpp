#include "bits/stdc++.h"

using namespace std;

int main(){
    int vertex,edge; cin >> vertex >> edge;
    vector<bool> visited(vertex,false);
    vector<vector<int>> G(vertex);
    for(int i = 0 ; i < edge ; i++){
        int a,b ; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int cnt = 0;
    for(int i = 0 ; i < vertex ; i++){
        if(!visited[i]){
            map<int,int> mp; 
            bool check = true;
            stack<int> st;
            st.push(i);
            while(!st.empty()){
                int t = st.top();
                st.pop();
                visited[t] = true;
                if(G[t].size()>2) check = false;
                mp[G[t].size()]++;
                for(auto val : G[t]){
                    if(!visited[val]) st.push(val);
                    if(val==i) check = false;
                }
            }
            if((check && mp[1]==0) || (!check&&mp[1]==2)) {
                cnt++;
            }
        }
    }
    cout << cnt;
}