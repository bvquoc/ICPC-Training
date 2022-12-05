// https://oj.vnoi.info/problem/kquery
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
// #define int int
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
using ll = int;

struct SegTree {
    int n;
    vector <int> sum;
    SegTree (int _n = 0) {
        n = _n;
        sum.resize(4 * n + 9, 0);
    }
    void update(int i, int l, int r, int u, int c) {
        if (l > r || u > r || l > u)
            return;
        if (l == r) {
            sum[i] = c;
            return;
        }
        else {
            int m = (l + r) >> 1;
            update(i * 2, l, m, u, c);
            update(i * 2 + 1, m + 1, r, u, c);
            sum[i] = sum[i * 2] + sum[i * 2 + 1];
        }
    }
    int get(int i, int l, int r, int u, int v) {
        if (l > r || u > v || u > r || l > v)
            return 0;
        if (u <= l && r <= v)
            return sum[i];
        int m = (l + r) >> 1;
        return get(i * 2, l, m, u, v) + get(i * 2 + 1, m + 1, r, u, v);
    }
    void update(int u, int c) {
        update(1, 1, n, u, c);
    }
    int get(int u, int v) {
        return get(1, 1, n, u, v);
    }
};

const int MaxN = 30004, MaxQ = 200005;

struct Query {
    int id;
    int l, r, k;
    int ans;
};

int n, qsz;
ii a[MaxN];
Query q[MaxQ];

signed main(void) {
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    cin >> n;
    SegTree st(n);
    FOR(i, 1, n) {
        cin >> a[i].first;
        a[i].second = i;
        st.update(i, 1);
    }
    sort(a+1, a+1+n);

    cin >> qsz;
    FOR(i, 1, qsz) {
        cin >> q[i].l >> q[i].r >> q[i].k;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + qsz, [&](const Query &A, const Query &B) {
        return A.k < B.k;
    });
    
    int cur = 1;
    FOR(i, 1, qsz) {
        int k = q[i].k;
        while (cur <= n && a[cur].first <= k) {
            st.update(a[cur].second, 0);
            cur++;
        }
        q[i].ans = st.get(q[i].l, q[i].r);
    }


    sort(q + 1, q + 1 + qsz, [&](const Query &A, const Query &B) {
        return A.id < B.id;
    });
    FOR(i,1,qsz) cout << q[i].ans << endl;
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}