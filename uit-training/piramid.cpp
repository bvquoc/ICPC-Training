#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using int128_t = __int128;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int t; cin >> t;
    ll n, m, r1, r2;

    int128_t r, p = 1000000000000000000;
    while (t--) {
        cin >> n >> m;
        if (n > m) swap(n, m);

        r = (int128_t)n * (n + 1) * (3 * m - n + 1) / 6;
        r1 = r / p; r2 = r % p;
        if (r1 > 0) {
            cout << r1 << setw(18) << setfill('0') << r2 << '\n';
        }
        else cout << r2 << '\n';
    }

    return 0;
}