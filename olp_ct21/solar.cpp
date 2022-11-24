// https://oj.vnoi.info/problem/olp_ct21_solar
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
#define int long long
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


struct Segment{
    int n;
    vector <int> sum, mi;
    Segment(int _n = 0) {
        n = _n;
        sum.resize(4 * n + 9, 0);
        mi.resize(4 * n + 9, LLONG_MAX);
    }
    void update(int i, int l, int r, int u, int c) {
        if (l > r || u > r || l > u)
            return;
        if (l == r) {
            mi[i] = c;
            sum[i] = c;
            return;
        }
        else {
            int m = (l + r) >> 1;
            update(i * 2, l, m, u, c);
            update(i * 2 + 1, m + 1, r, u, c);
            mi[i] = min(mi[i * 2], mi[i * 2 + 1]);
            sum[i] = sum[i * 2] + sum[i * 2 + 1];
        }
    }
    int getSum(int i, int l, int r, int u, int v) {
        if (l > r || u > v || u > r || l > v)
            return 0;
        if (u <= l && r <= v)
            return sum[i];
        int m = (l + r) >> 1;
        return getSum(i * 2, l, m, u, v) + getSum(i * 2 + 1, m + 1, r, u, v);
    }
    int getMin(int i, int l, int r, int u, int v) {
        if (l > r || u > v || u > r || l > v)
            return LLONG_MAX;
        if (u <= l && r <= v)
            return mi[i];
        int m = (l + r) >> 1;
        return min(getMin(i * 2, l, m, u, v), getMin(i * 2 + 1, m + 1, r, u, v));
    }
    int query(int root, int l, int r, int u, int v, int k) {
        if (mi[root] > k) return -1;
        if (r < u || l > v) return -1;
        if (l == r) return l;
        int mid = (l + r) / 2;
        int res = -1; 
        if (mi[root * 2] <= k) {
            res = query(root * 2, l, mid, u, v, k);
        }
        if (res == -1) {
            res = query(root * 2 + 1, mid + 1, r, u, v, k);
        }
        return res;
    }
    int query(int l, int r, int k) {
        return query(1, 0, n-1, l, r, k);
    }
    void update(int u, int c) {
        update(1, 0, n-1, u, c);
    }
    int getSum(int u, int v) {
        return getSum(1, 0, n-1, u, v);
    }
    int getMin(int u, int v) {
        return getMin(1, 0, n-1, u, v);
    }
};

const int N = 2000006;
int n, q, a[N];
int d = 0;
int getIndex(int i) {
    i += d; i %= n*2;
    return i;
}

signed main(void) {
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    cin >> n >> q;
    Segment st(n*2);
    REP(i,n) cin >> a[i];
    FOR(i, n, 2*n - 1) {
        a[i] = a[i - n];
        st.update(i, a[i]);
        st.update(i-n, a[i]);
    }
    
    REP(_,q) {
        int type; cin >> type;
        if (type == 1) {
            int d; cin >> d;
            d %= n;
            ::d += n - d;
            ::d %= n;
        }
        if (type == 2) {
            int l, r, p;
            cin >> l >> r >> p;
            l--; r--;
            l = getIndex(l);
            r = getIndex(r);
            if (r < l) r += n;

            int pos = st.query(l, r, st.getMin(l, r));
            a[pos] = p;
            st.update(pos, p);
            if (pos < n) {
                a[pos+n] = p;
                st.update(pos+n, p);
            } else {
                a[pos-n] = p;
                st.update(pos-n, p);
            }
        }
        if (type == 3) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            l = getIndex(l);
            r = getIndex(r);
            if (r < l) r += n;
            int res = st.getSum(l,r);
            cout << res << endl;
        }
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}
