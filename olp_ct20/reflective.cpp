// https://oj.vnoi.info/problem/olp_ct20_reflective
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll f(ll x) {
    ll sum = 0;
    while(x > 0) { 
        x >>= 1;
        sum += x;
    }
    return sum;
}

signed main(void) {
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    ll l, r;
    cin >> l >> r;
    cout << f(r) - f(l-1);
    return 0;
}