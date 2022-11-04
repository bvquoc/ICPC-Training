#include <bits/stdc++.h>
#define file "file"
#define pb push_back
#define fi first
#define se second
#define For(i, a, b) for (int i = a; i <= b; i++)
#define Dow(i, a, b) for (int i = a; i >= b; i--)
#define MASK(i) (1LL << (i))
#define BIT(i, a) (((a) >> (i)) & 1)
#define endl '\n'

using namespace std;

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
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

const int maxN = 100009;
const int MOD = 1e9 + 7;
typedef pair <int, int> ii;
int a[maxN], x[maxN], ans = 0;
int n, m;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int maxc = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maximize(maxc, a[i]);
    }
    x[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        x[i] = x[i - 1] * 2 % MOD;
    }
    if (m == 1) {
        for (int i = 1; i <= n; i++)
            ans = (ans + x[a[i]]) % MOD;
        return cout << ans, 0;
    }
    cout << x[maxc];
    return 0;
}
