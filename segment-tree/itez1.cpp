// https://oj.vnoi.info/problem/segtree_itez1
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

struct SegTree {
    int n;
    vector <int> mx;
    SegTree (int _n = 0) {
        n = _n;
        mx.resize(4 * n + 9, 0);
    }
    void update(int i, int l, int r, int u, int c) {
        if (l > r || u > r || l > u)
            return;
        if (l == r) {
            mx[i] = c;
            return;
        }
        else {
            int m = (l + r) >> 1;
            update(i * 2, l, m, u, c);
            update(i * 2 + 1, m + 1, r, u, c);
            mx[i] = max(mx[i * 2], mx[i * 2 + 1]);
        }
    }
    int get(int i, int l, int r, int u, int v) {
        if (l > r || u > v || u > r || l > v)
            return INT_MIN;
        if (u <= l && r <= v)
            return mx[i];
        int m = (l + r) >> 1;
        return max(get(i * 2, l, m, u, v), get(i * 2 + 1, m + 1, r, u, v));
    }
    void update(int u, int c) {
        update(1, 1, n, u, c);
    }
    int get(int u, int v) {
        return get(1, 1, n, u, v);
    }
};

const int N = 100005;
int n, a[N];

signed main(void) {
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    cin >> n;
    SegTree st(n);
    FOR(i,1,n) {
        cin >> a[i];
        st.update(i, a[i]);
    }

    int q; cin >> q;
    int type, l, r;
    while (q--) {
        cin >> type >> l >> r;
        if (type == 1) { // set a[l] = r
            st.update(l, r);
        } else { // (type == 2) -> maximum([l,r])
            int mx = st.get(l, r);
            cout << mx << endl;
        }
    
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}