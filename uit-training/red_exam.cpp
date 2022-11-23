#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    long long b1, d1, b2, d2;
    cin >> b1 >> d1 >> b2 >> d2;
    
    auto pw = [](long long x, long long y) {
        long long p = 1, b = x;
        while (y > 0) {
            if (y & 1) p *= b;
            b *= b;
            y >>= 1;
        }
        return b;
    };

    long long l1 = pw(b1, d1-1), r1 = l1 * b1;
    long long l2 = pw(b2, d2-1), r2 = l2 * b2;

    long long lr = max(l1, l2);
    long long rr = min(r1, r2);

    if (lr > rr) cout << 0;
    else cout << rr - lr;
    return 0;
}