#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n, a, b;
    cin >> n >> a >> b;
    
    int res = (a <= b ? (n - (b - a - 1)) : (n + 1 + (a - b - 1)));
    cout << res;
    return 0;
}