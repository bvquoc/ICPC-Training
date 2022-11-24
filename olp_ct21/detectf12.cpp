// https://oj.vnoi.info/problem/olp_ct21_detectf12
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

const int N = 1003;
int n, f0_id, d;

struct Position {
    int x, y;
    int status;
    Position() {
        x = y = 0;
        status = -1;
    }
} a[N];

bool check(const Position &A, const Position &B, const int &d) {
    int x = A.x - B.x;
    int y = A.y - B.y;
    return (x * x + y * y) < d;
    return x <= d;
}

signed main(void) {
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    cin >> n >> f0_id >> d;
    d *= d;
    FOR(i,1,n) {
        cin >> a[i].x >> a[i].y;
        a[f0_id].status = -1;
    }
    a[f0_id].status = 0;

    int cnt_f1 = 0;
    FOR(i,1,n) if (i != f0_id) {
        if (check(a[i], a[f0_id], d)) {
            cnt_f1++;
            a[i].status = 1;
        } 
    }

    int cnt_f2 = 0;
    FOR(i,1,n) if (a[i].status == 1) {
        FOR(j,1,n) if (j != i && a[j].status == -1)
        if (check(a[i], a[j], d)) {
            cnt_f2++;
            a[j].status = 2;
        } 
    }

    cout << cnt_f1 << ' ' << cnt_f2;
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}