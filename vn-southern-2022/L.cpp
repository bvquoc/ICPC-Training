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

const int maxN = 1009;
typedef pair <int, int> ii;
const int INF = 1e9;
int f[maxN], n, ok[maxN];
string a, b, c;

signed main()
{
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    while (cin >> n) {
        if (n == 0)
            return 0;
        cin >> a >> b >> c;
        a = " " + a;
        b = " " + b;
        c = " " + c;
        For (i, 1, n)
            ok[i] = 0;
        Dow (i, n, 1) {
            int X = (int)a[i] - '0';
            int Y = (int)b[i] - '0';
            int Z = (int)c[i] - '0';
            if ((X + Y) % 10 == Z) {
                f[i] = n - i;
                ok[i] = 1;
            }
            else
                f[i] = n - i + 1;
            Dow (j, n, i + 1) {
                int x = (int)a[j] - '0';
                int y = (int)b[j] - '0';
                int z = (int)c[j] - '0';
                int X = (int)a[i] - '0';
                int Y = (int)b[i] - '0';
                int Z = (int)c[i] - '0';
                int nho = 0;
                if (ok[j] == 1) {
                    if (x + y > z)
                        nho = 1;
                    if ((X + Y + nho) % 10 == Z && ok[j] == 1) {
                        if (minimize(f[i], f[j] + (j - i - 1))) {
                            ok[i] = 1;
                        }
                    }
                }
            }
        }
        int ans = n;
        For (i, 1, n) {
            int X = (int)a[i] - '0';
            int Y = (int)b[i] - '0';
            int Z = (int)c[i] - '0';
            if (X + Y <= Z && ok[i] == 1) {
                minimize(ans, f[i] + i - 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
