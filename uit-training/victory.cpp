#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin >> n;

    vector <int> h(n), ans(n);
    for (int &x : a) cin >> x;
    sort(h.rbegin(),h.rend());
    
    int p = 0, q = n - 1;
    for (int i = 0; i < n; i++)
        if (i & 1)
            ans[q--] = h[i];
        else 
            ans[p++] = h[i];
    
    for (int x: ans) cout << ans[i] << ' ';
    
    return 0;
}