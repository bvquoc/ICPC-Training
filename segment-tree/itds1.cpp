// https://oj.vnoi.info/problem/segtree_itds1
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(a) (signed(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define endl '\n'
// #define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    }
    return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    }
    return false;
}

using ii = pair <int, int>;
using ll = long long;

const int N = 100005;
int n, q, a[N];

signed main(void) {
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    cin >> n >> q;
    FOR(i,1,n) cin >> a[i];

    int type;
    while (q--) {
        cin >> type;
        
        if (type == 1) { // `1 i v`: set a[i] = v
            int i, v;
            cin >> i >> v;
            a[i] = v;
        } else { // `2 L R k`: min([l,r]) >= k (Print -1 if not exist).
            int l, r, k;
            cin >> l >> r >> k;
            int res = INT_MAX;
            FOR(i, l, r) if (a[i] >= k) minimize(res, a[i]);
            if (res == INT_MAX) res = -1;
            cout << res << endl;
        }
    
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}
