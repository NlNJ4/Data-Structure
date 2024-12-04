#include "bits/stdc++.h"

using namespace std;

int main(){
    int vertex,e; cin >> vertex >> e;
    vector<bool> visited(vertex,false);
    vector<vector<int>> v(vertex);
    for(int i = 0 ; i < e ; i++){
        int a,b ; cin >> a >> b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    for(int i = 0 ; i < vertex ; i++){
        if(!visited[i]){
            stack<int> st;
            st.push(i);
            while(!st.empty()){
                int t = st.top();
                st.pop();
                visited[t] = true;
                for(auto val:v[t]){
                    if(!visited[val]){
                        st.push(val);
                    }
                }
            }
            cnt++;
        }
    }
    cout << cnt;
}