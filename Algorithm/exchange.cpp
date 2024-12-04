#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;cin >> n;
    while(n--){
        int sz ; cin >> sz;
        float table[sz][sz];
        for(int i = 0 ; i < sz ; i++){
            for(int j = 0 ; j < sz ; j++){
                cin >> table[i][j];
                table[i][j] = -log(table[i][j]);
            }
        }
        for(int k = 0 ; k < sz ; k++){
            for(int i = 0 ; i < sz ; i++){
                for(int j = 0 ; j < sz ; j++){
                    if(table[i][j] > table[i][k]+table[k][j]) table[i][j] = table[i][k]+table[k][j];
                }
            }
        }
        bool check = false;
        for(int i = 0 ; i < sz ; i++){
            if(table[i][i] < 0) {
                check = true;
            }
        }
        cout << (check? "YES" : "NO") << endl;
    }
}