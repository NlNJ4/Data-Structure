#include "bits/stdc++.h"

using namespace std;

int main(){
    string f,s; cin >> f >> s;
    if(s.size()>f.size()) swap(f,s);
    int mx = 0;
    for(int i = 0 ; i < s.size() ; i++){
        for (int len = 1; i + len <= s.size(); len++) {
            string sub = s.substr(i, len);
            if (f.find(sub) != string::npos) {
                mx = max(mx, len);
            }
        }
    }
    cout << mx;
}