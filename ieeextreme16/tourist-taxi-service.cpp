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

const int maxN = 10009;
const int INF = 1e9 + 2;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;
int n, m, d[maxN];
vector <iii> ke[maxN];
priority_queue<ii, vector<ii>, greater<ii>> pq;

void dfs(int u, vector <int> dd, int s) {
    if (dd.size() == 5) {
        pq.push({s, u});
        minimize(d[u], s);
        return;
    }
    for (iii i : ke[u]) {
        int v = i.fi.se;
        int w = i.fi.fi;
        int id = i.se;
        int check = 0;
        for (int x : dd) {
            if (id == x) {
                check = 1;
                break;
            }
        }
        if (!check) {
            vector <int> l = dd;
            l.pb(id);
            dfs(v, l, s + w);
        }
    }
    return;
}

void dijkstra() {
    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;
        for (int i = 0; i < ke[u].size(); i++) {
            int v = ke[u][i].fi.second;
            int uv = ke[u][i].first.fi;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push({d[v], v});
            }
        }
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    For (i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].pb({{w, v}, i});
        ke[v].pb({{w, u}, i});
    }
    vector <int> v;
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    dfs(1, v, 0);
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout << d[i] << endl;
    return 0;
}
