#include "bits/stdc++.h"

using namespace std;

int main(){
    int n,e ; cin >> n >> e;
    int table[n][e] = {0};
    int cnt = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < e ; j++){
            table[i][j] = 0;
        }
    }
    for(int i = 0 ; i < e ; i++){
        int a , b ; cin >> a >> b;
        table[a][b]++;
        cnt = max(cnt,table[a][b]);  
        if(a>0&&b>0){ 
            table[a-1][b]++;  
            cnt = max(cnt,table[a-1][b]);
            table[a-1][b-1]++;  
            cnt = max(cnt,table[a-1][b-1]);
        }
        if(a>0&&b<e-1){
            table[a][b+1]++;
            cnt = max(cnt,table[a][b+1]);
            table[a-1][b+1]++;
            cnt = max(cnt,table[a-1][b+1]);
        }
        if(a<e-2&&b>0){
            table[a][b-1]++;
            cnt = max(cnt,table[a][b-1]);
            table[a+1][b-1]++;
            cnt = max(cnt,table[a+1][b-1]);
        }
        if(a<e-1&&b<e-1){
            table[a+1][b]++;
            cnt = max(cnt,table[a+1][b]);
            table[a+1][b+1]++;
            cnt = max(cnt,table[a+1][b+1]);
        }

    }
    /*for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < e ; j++){
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }*/
    cout << cnt;
}