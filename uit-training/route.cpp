#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // input    
    int n, m, k;
    long long mod;

    cin >> n >> m >> k >> mod;
    n--, m--;
    vector<pair<int, int>> p(k);

    // prepare
    vector<long long> dp(k), fact(n + m + 7), ifact(n + m + 7);
    
    fact[0] = 1;
    for (int i = 1; i <= n + m; i ++) fact[i] = fact[i - 1] * i % mod;
    
    auto Pow = [mod](long long _k, long long _n) {
        long long res = 1;
        while (_n > 0) {
            if (_n & 1) res = res * _k % mod;
            _k = _k * _k % mod;
            _n >>= 1;
        }
        return res;
    };

    ifact[n + m] = Pow(fact[n + m], mod - 2);

    for (int i = n + m; i >= 1; i --) ifact[i - 1] = ifact[i] * i % mod;

    auto comp = [=](int _k, int _n) {
        // return fact[_n] * Pow(fact[_k] * fact[_n - _k] % mod, mod - 2) % mod;
        return fact[_n] * ifact[_k] % mod * ifact[_n - _k] % mod;
        // nCk = n! / k! / (n - k)!
    };

    // input
    for (auto &x : p) {
        cin >> x.first >> x.second;
        x.first --, x.second --;
    }

    sort(p.begin(), p.end());
    long long ans = comp(n, n + m);

    // calculate
    for (int i = 0; i < k; i ++) {
        dp[i] = comp(p[i].first, p[i].first + p[i].second);
        for (int j = 0; j < i; j ++) {
            if (p[j].second <= p[i].second) {
                int x = p[i].first - p[j].first;
                int y = p[i].second - p[j].second;

                (dp[i] -= dp[j] * comp(x, x + y) % mod) %= mod;
            }
        }

        // cout << "   " << p[i].first << ' ' << p[i].second << ' ' << dp[i] << endl;
 
        int u = n - p[i].first, v = m - p[i].second;
        (ans -= dp[i] * comp(u, u + v) % mod) %= mod;
    }

    ans = (ans + mod) % mod;
    cout << ans;

    return 0;
}