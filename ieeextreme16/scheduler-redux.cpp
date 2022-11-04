#include <bits/stdc++.h>
#define int long long
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

const int maxN = 300009;
const int MOD = 1e9 + 7;
typedef pair <int, int> ii;
int a[maxN], x[maxN], ans = 0;
int n, m;
int b[maxN], cnt[maxN];
int c[maxN];
map<int, int> M[maxN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int maxc = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    x[0] = 1;
    for (int i = 1; i <= 300000; i++) {
        x[i] = x[i - 1] * 2 % MOD;
    }
    sort(a + 1, a + 1 + n);
    while (n >= 1) {
        M[1][a[n]]++;
        int x = a[n];
        while (M[1][x] == 2) {
            M[1][x] = 0;
            M[1][x + 1]++;
            x++;
        }
        maxc = x;
        n--;
        for (int i = 2; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (!M[i][maxc]) {
                    M[i][a[j]]++;
                    int x = a[j];
                    while (M[i][x] == 2 && x < maxc) {
                        M[i][x] = 0;
                        M[i][x + 1]++;
                        x++;
                    }
                    if (j == 1) {
                        n = 0;
                    }
                }
                else {
                    n = j;
                    break;
                }
            }
        }
    }
    ans = 0;
    For (i, 0, 300000) {
        if (M[1][i]) {
            ans += x[i];
            ans %= MOD;
        }
    }
    cout << ans;
    return 0;
}
