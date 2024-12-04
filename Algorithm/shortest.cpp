#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e,s ; cin >> n >> e >> s;
    int arr[n][n];
    vector<pair<int,int>> path;
    for(int i = 0 ; i < e ; i++){
        int st,en,w; cin >> st >> en >> w;
        arr[st][en] = w;
        path.push_back({st,en});
    }
    vector<long long> dist(n,INT_MAX-1);
    dist[s] = 0;
    for(int i = 0 ; i < n-1 ; i++){
        for(auto [st,en]:path){
            if(dist[en] > dist[st] + arr[st][en]) dist[en] = dist[st] + arr[st][en];
        }
    }
    for(int i = 0 ; i < n-1 ; i++){
        for(auto [st,en]:path){
            if(dist[en] > dist[st] + arr[st][en]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for(auto d:dist){
        cout << d << ' ';
    }
}