#include "bits/stdc++.h"

using namespace std;

int main(){
    int k , n ; cin >> k >> n;
    int c[k],a[k];
    for(int i = 0 ; i < k ; i++) cin >> c[i];
    for(int i = 0 ; i < k ; i++) cin >> a[i];
    for(int i = k ; i <= n ; i++) {
        int ans = 0;
        for(int j = 0 ; j < k ; j++) {
            ans = (ans%32717+a[k-j-1]*c[j]%32717)%32717;
        }
        for (int j = 0; j < k - 1; j++) {
            a[j] = a[j + 1];
        }
        a[k-1] = ans;
    }
    cout << a[k-1];
}