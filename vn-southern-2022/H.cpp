#include <bits/stdc++.h>
#define file "file"
#define int long long
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

const int maxN = 1;
typedef pair <int, int> ii;
int n;
const int MOD = 1e9 + 7;
int ans = 1;
string l, r;

int calc(int a, int b) {
    int ans = 0;
    for (int i = a; i <= b; i++) {
        int x = i;
        int res = 1;
        while (x > 0) {
            res = res * (x % 10) % MOD;
            x /= 10;
        }
        if (res > ans)
            ans = res;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> l >> r;
    int n = r.size();
    int m = l.size();

    if (n > m) {
        for (int i = 1; i <= n - m; i++)
            l = "0" + l;
        m = l.size();
    }
    if (m > n) {
        for (int i = 1; i <= m - n; i++)
            r = "0" + r;
        n = r.size();
    }
    r = " " + r;
    l = " " + l;
    int dem = 0;
    int check = 0, vt = n + 1, ok = 0;
    for (int i = 1; i <= n; i++) {
        int x = (int)(r[i] - '0');
        int y = (int)(l[i] - '0');
        if (x > y && i == 1) {
            for (int j = i + 2; j <= n; j++) {
                int z = (int)(r[j] - '0');
                if (z != 9) {
                    check = 1;
                    break;
                }
            }
            vt = 1;
            break;
        }
        if (x == 0 && y == 0 && dem == 0)
            continue;
        if (x != 0 || y != 0)
            dem = 1;
        if (x == y) {
            if (x == 0)
                return cout << 0, 0;
            ans *= x;
            ans %= MOD;
        }
        if (x > y) {
            if (x == 1) {
                ok = 1;
                continue;
            }
            for (int j = i + 2; j <= n; j++) {
                int z = (int)(r[j] - '0');
                if (z != 9) {
                    check = 1;
                    break;
                }
            }
            vt = i;
            break;
        }
        if (x < y && ok) {
            return cout << 0, 0;
        }
    }
    if (check == 0 && vt <= n) {
        int x = (int)(r[vt] - '0');
        int y = 1;
        if (vt < n) {
            y = (int)(r[vt + 1] - '0');
            x = x * 10 + y;
        }
        int z = (int)(l[vt] - '0');
        if (vt < n) {
            y = (int)(l[vt + 1] - '0');
            z = z * 10 + y;
        }
        ans *= calc(z, x);
        ans %= MOD;
        for (int i = vt + 2; i <= n; i++) {
            ans *= 9;
            ans %= MOD;
        }
    }
    if (check == 1 && vt <= n) {
        int x = (int)(r[vt] - '0');
        int y = 1;
        if (vt < n) {
            y = (int)(r[vt + 1] - '0');
            if (y > 0)
                x = x * 10 + y - 1;
            else {
                y = 9;
                x = (x - 1) * 10 + 9;
            }
        }
        int z = (int)(l[vt] - '0');
        if (vt < n) {
            y = (int)(l[vt + 1] - '0');
            z = z * 10 + y;
        }
        ans *= calc(z, x);
        ans %= MOD;
        for (int i = vt + 2; i <= n; i++) {
            ans *= 9;
            ans %= MOD;
        }
    }
    cout << ans;
    return 0;
}
