#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 1000000007;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int nTest;
    cin >> nTest;

    
    while (nTest--) {
        long long n;
        cin >> n;
        long long sum = n + 1;
        for (int x = 2; 1LL * x * x <= n; ++x) {
            if (n % x != 0) continue;
            long long y = n / x;
            if (__gcd(1LL * x, y) != 1) continue;
            sum += (x + y);
        }
        n %= MOD; sum %= MOD;
        long long res = (n * sum) % MOD;
        cout << res << endl;
    }

    return 0;
}