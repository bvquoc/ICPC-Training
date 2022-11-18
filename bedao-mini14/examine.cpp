#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

using ii = pair<int,int>;
long long Mul(long long x, long long y,long long m) {
    x %= m; y %= m;
    long long q = (long double) x * y / m;
    long long r = (x * y - q * m) % m;
    if (r < 0) r += m;
    return r;
}

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int nTest;
    cin >> nTest;
    const int MOD = 1000000007;
    long long n, res;

    
    while (nTest--) {
        cin >> n;
        int sum = n + 1;
        for (int x = 2; 1LL * x * x <= n; ++x) {
            if (n % x != 0) continue;
            int y = n / x;
            if (__gcd(x, y) != 1) continue;
            sum += (x + y);
        }
        res = Mul(n, sum, MOD);
        cout << res << endl;
    }

    return 0;
}