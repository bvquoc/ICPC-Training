// https://oj.vnoi.info/problem/bedao_g11_easyquery
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

const int N = 100005;
int n, a[N], qsz;

struct Query {
    int type;
    int l, r;
    int id;
    int x;
} q[N];

long long st[4 * N], lazy[4 * N];

void build(int i, int L, int R) {
    lazy[i] = 0;
    st[i] = 0;
    if (L == R) return;
    int mid = (L + R) >> 1;
    build(i << 1, L, mid);
    build(i << 1 | 1, mid + 1, R);
}

void push(int i, int L, int R) {
    st[i] += lazy[i] * (R - L + 1);
    if (L != R) {
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
    }
    lazy[i] = 0;
}

void update(int i, int L, int R, int u, int v, int val) {
    push(i, L, R);
    if (L > v || R < u) return;
    if (L >= u && R <= v) {
        lazy[i] += val;
        push(i, L, R);
        return;
    }
    int mid = (L + R) >> 1;
    update(i << 1, L, mid, u, v, val);
    update(i << 1 | 1, mid + 1, R, u, v, val);
    st[i] = st[i << 1] + st[i << 1 | 1];
}

int get(int i, int L, int R, int u, int v) {
    push(i, L, R);
    if (L > v || R < u) return 0;
    if (L >= u && R <= v) return st[i];
    int mid = (L + R) >> 1;
    int left = get(i << 1, L, mid, u, v);
    int right = get(i << 1 | 1, mid + 1, R, u, v);
    return left + right;
}

signed main(void) {
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    cin >> n >> qsz;
    build(1,1,n);
    FOR(i, 1, n) {
        cin >> a[i];
        update(1, 1, n, i, i, a[i]);
    }

    FOR(i, 1, qsz) {
        cin >> q[i].type;
        
        if (q[i].type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            q[i].l = l; q[i].r = r; q[i].x = x;
            update(1, 1, n, l, r, x);
        }
        
        if (q[i].type == 2) {
            int id; cin >> id;
            q[i].id = id;

            int tmp = -1;
            while (q[id].type == 2) {
                id = q[id].id;
                tmp *= -1;
            }
            update(1, 1, n, q[id].l, q[id].r, tmp * q[id].x);

        }

        if (q[i].type == 3) {
            int l, r; cin >> l >> r;
            q[i].l = l; q[i].r = r;
            cout << get(1, 1, n, l, r) << endl;
        }
    }

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}