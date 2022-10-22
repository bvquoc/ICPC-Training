#include <bits/stdc++.h>
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

const int maxN = 1009;
typedef pair <int, int> ii;
const int INF = 1e9;
int n, ok[maxN], c[maxN];
int N = 0;
vector <ii> ke[maxN], Ke[maxN], canh[maxN];
map<string,int> mp;
int getTag(string name) {
  if (mp.find(name) == mp.end()) {
    mp[name] = ++N;
    return N;
  }
  return mp[name];
}
int d[maxN];

int prim(int start) {
    int Answer = 0;
    priority_queue<ii> qu;
    for (int i = 1; i <= N; i++)
        d[i] = INF;
    d[start] = 0;
    qu.push({0, start});
    while (qu.size()) {
        ii top = qu.top();
        qu.pop();
        int u = top.se;
        if (d[u] != -top.fi)
            continue;
        Answer += d[u];
        d[u] = 0;
        for (int i = 0; i < Ke[u].size(); i++) {
            int v = Ke[u][i].se;
            if (minimize(d[v], Ke[u][i].fi))
                qu.push({-d[v], v});
        }
    }
    return Answer;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin >> n;
    For (i, 1, n) {
        string a, b;
        int w, type;
        cin >> a >> b >> w >> type;
        int u = getTag(a), v = getTag(b);
        if (type == 1) {
            ok[u] = 1;
            ok[v] = 1;
            canh[u].pb({w, v});
            canh[v].pb({w, u});
        }
        else {
            ke[u].pb({w, v});
            ke[v].pb({w, u});
        }
    }
    int z = 0;
    For (i, 1, N) {
        if (ok[i]) {
            c[++z] = i;
        }
    }
    int ans = INF;
    For (mask, 0, (1 << z) - 1) {
        for (int i = 1; i <= N; i++)
            Ke[i] = ke[i];
        int cnt = 0;
        for (int bit = mask; bit > 0; bit ^= bit & (-bit)) {
            int i = __builtin_ctz(bit & (-bit));
            cnt++;
            i++;
            for (ii x : canh[c[i]]) {
                Ke[c[i]].pb({x.fi, x.se});
                Ke[x.se].pb({x.fi, c[i]});
            }
        }
        int check = 0;
        int res = prim(1);
        For (i, 1, N) {
            if (d[i] == INF) {
                check = 1;
                break;
            }
        }
        if (!check)
            minimize(ans, res + cnt * 10000LL);
    }
    cout << ans;
    return 0;
}
