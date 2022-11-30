#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int solve(int a, int b, int k) {
    int l = 0, r = 100000;
    int res = INT_MAX;
    while (l <= r) {
        int mi = l + (r - l) / 2;
        if (mi + (mi / a) * b >= k) {
            res = mi;
            r = mi - 1;
        } else l = mi + 1;
    }
    return res;
}
signed main(void) {
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(nullptr);

    int nTests; cin >> nTests;
    while (nTests--) {
        int a, b, k;
        cin >> a >> b >> k;
        cout << solve(a, b, k) * 5LL << endl;
    }
    
    return 0;
}