#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n, q, x;
    int mi = INT_MAX, mx = INT_MIN;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mi = min(mi, x);
        mx = max(mx, x);
    }

    while (q--) {
        cin >> x;
        cout << ((mi <= x && x <= mx) ? "Yes\n" : "No\n");
    }
    return 0;
}