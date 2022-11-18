#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct DSU {
    int n;
    vector <int> p;
    void assign(int _n) {
        n = _n;
        p.assign(n + 7, -1);
    }
    DSU(){};
    DSU(int _n) { assign(_n); }

    int find_root(int u) { 
        if (p[u] < 0) return u;
        return p[u] = find_root(p[u]);
    }

    void Union(int u, int v) {
        int x = find_root(u);
        int y = find_root(v);
        if (x == y) return;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }

    bool sameSet(int u, int v) {
        return find_root(u) == find_root(v);
    }
};

const int N = 200005;
struct Query {
    char type;
    int u, v, s;
    char ans;
};

int n, qsz;
Query q[N];
DSU dsu;
vector <int> id_snapshot[N];

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    cin >> n >> qsz;
    dsu.assign(n);

    for (int i = 1; i <= qsz; i++) {
        Query &x = q[i];
        x.ans = '#';
        cin >> x.type;
        if (x.type == '?' || x.type == 'Q') x.ans = '*';

        if (x.type == 'C') continue;

        if (x.type == 'Q') {
            cin >> x.s;
            id_snapshot[x.s].push_back(i);
        }
        cin >> x.u >> x.v;
    }

    int curSnapshot = 0;
    for (int i = 1; i <= qsz; i++) {
        Query &x = q[i];
        if (x.type == 'A') {
            dsu.Union(x.u, x.v);
            continue;
        }
        if (x.type == '?') {
            x.ans = (dsu.sameSet(x.u, x.v) ? 'Y' : 'N');
            continue;
        }
        if (x.type == 'C') {
            curSnapshot++;
            for (int j: id_snapshot[curSnapshot]) {
                Query &cur = q[j];
                cur.ans = (dsu.sameSet(q[j].u, q[j].v) ? 'Y' : 'N');
            }
            continue;
        }

        // query
        if (x.s == 0 && x.ans == '*') {
            x.ans = ((x.u == x.v) ? 'Y' : 'N');
        }
    }


    for (int i = 1; i <= qsz; i++) {
        if (q[i].ans == '#') continue;
        cout << q[i].ans;
    }

    return 0;
}