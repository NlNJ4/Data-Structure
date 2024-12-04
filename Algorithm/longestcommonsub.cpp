#include "bits/stdc++.h"

using namespace std;

int lcs(string s1, string s2, int n , int m){
    vector<vector<int>> table(n+1,vector<int>(m+1,0));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1]==s2[j-1]){
                table[i][j] = table[i-1][j-1]+1;
            }
            else{
                table[i][j] = max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    return table[n][m];
}

int main(){
    string s1,s2; cin >> s1 >> s2;
    cout << lcs(s1,s2,s1.size(),s2.size());
}