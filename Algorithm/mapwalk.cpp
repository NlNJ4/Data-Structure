#include "bits/stdc++.h"

using namespace std;
void check(int nowr,int nowc,int targetr,int targetc,string txt ,vector<vector<int>> table){
    table[nowr][nowc]  = 1;
    //cout << nowr << ' ' << nowc << endl;
    /*for(auto r: table){
        for(auto c:r){
            cout << c << ' ';
        }
        cout << endl;
    }*/
    if(nowr==targetr&&nowc==targetc){
        cout << txt << endl;
        return;
    }
    if(nowc+1<=targetc && table[nowr][nowc+1]==0){
        check(nowr,nowc+1,targetr,targetc,txt+'A',table);
    }
    if(nowr+1<=targetr && table[nowr+1][nowc]==0){
        check(nowr+1,nowc,targetr,targetc,txt+'B',table);
    }
    if(nowr-1>=0 && table[nowr-1][nowc]==0){
        check(nowr-1,nowc,targetr,targetc,txt+'C',table);
    }
}

int main(){
    int r,c; cin >> r >> c;
    vector<vector<int>> table(r,vector<int>(c)) ;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cin >> table[i][j];
        }
    }
    check(0,0,r-1,c-1,"",table);
    cout << "DONE" << endl;
}