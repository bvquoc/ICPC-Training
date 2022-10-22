#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define fi first
#define se second
#define N 100005
#define modl 1000000007
typedef long long ll;
typedef pair<int, int> ii;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int readInt() {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while(true) {
		if(ch == '-') break;
		if(ch >= '0' && ch <= '9') break;
		ch = getchar();
	}

	if(ch == '-') minus = true; else result = ch - '0';
	while(true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}

	if(minus)
		return -result;
	else
		return result;
}

struct Node {
    ll sum, lz;
} tr[4 * N];

vector<int> adj[N];
int timeIn[N], timeOut[N], P[N][18], height[N];
int weight[N], numTest, numNode, numQuery;

ll powermod(ll a, int exponent) {
    ll res(1);
    while(exponent > 0) {
        if(exponent & 1)
            res = res * a % modl;

        a = a * a % modl;
        exponent >>= 1;
    }

    return res;
}

void dfsTour(int u, int p) {
    timeIn[u] = ++timeIn[0];
    for (int &v : adj[u]) {
        if(v != p) {
            height[v] = height[u] + 1;
            dfsTour(v, u);
            P[v][0] = u;
        }
    }

    timeOut[u] = timeIn[0];
}

void build(int id, int l, int r) {
    if(l == r) {
        tr[id] = {1, 1};
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    tr[id].sum = tr[id].lz = 1;
}

void down(int id) {
    ll &lz(tr[id].lz);
    tr[id << 1].sum = tr[id << 1].sum * lz % modl;
    tr[id << 1].lz = tr[id << 1].lz * lz % modl;

    tr[id << 1 | 1].sum = tr[id << 1 | 1].sum * lz % modl;
    tr[id << 1 | 1].lz = tr[id << 1 | 1].lz * lz % modl;

    lz = 1;
}

void update(int id, int l, int r, int u, int v, ll val) {
    if(v < l || u > r)
        return;

    if(u <= l && r <= v) {
        tr[id].sum = tr[id].sum * val % modl;
        tr[id].lz = tr[id].lz * val % modl;
        return;
    }

    if(tr[id].lz != 1)
        down(id);

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    tr[id].sum = tr[id << 1].sum * tr[id << 1 | 1].sum % modl;
}

ll query(int id, int l, int r, int pos) {
    if(pos < l || pos > r)
        return 1;

    if(l == r)
        return tr[id].sum;

    if(tr[id].lz != 1)
        down(id);

    int mid = (l + r) >> 1;
    return query(id << 1, l, mid, pos) * query(id << 1 | 1, mid + 1, r, pos) % modl;
}

int lca(int u, int v) {
    if(height[u] < height[v])
        swap(u, v);

    for (int i1 = height[u] - height[v]; i1 > 0; i1 ^= i1 & -i1) {
        int i = __builtin_ctz(i1 & -i1);
        u = P[u][i];
    }

    if(u == v)
        return u;

    for (int i = log2(height[u]); i >= 0; --i) {
        if(P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }

    return P[u][0];
}

void process() {
    cin >> numTest;
    while(numTest--) {
        cin >> numNode;
        for (int i = 1; i <= numNode; ++i) {
            cin >> weight[i];
            adj[i].clear();
        }

        for (int i = 1; i < numNode; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        P[1][0] = -1;
        timeIn[0] = 0;
        dfsTour(1, -1);

        for (int j = 1; (1 << j) <= numNode; ++j) {
            for (int i = 1; i <= numNode; ++i) {
                if(P[i][j - 1] != -1) {
                    P[i][j] = P[P[i][j - 1]][j - 1];
                } else {
                    P[i][j] = -1;
                }
            }
        }

        build(1, 1, numNode);
        for (int i = 1; i <= numNode; ++i) {
            update(1, 1, numNode, timeIn[i], timeOut[i], weight[i]);
        }

        cin >> numQuery;
        for (int t = 0; t < numQuery; ++t) {
            int type, u, v;
            cin >> type >> u >> v;
            if(type == 1) {
                ll inverse_weightu = powermod(weight[u], modl - 2);
                update(1, 1, numNode, timeIn[u], timeOut[u], inverse_weightu);
                weight[u] = v;
                update(1, 1, numNode, timeIn[u], timeOut[u], weight[u]);
            } else {
                ll res = query(1, 1, numNode, timeIn[u]), inv;
                res = res * query(1, 1, numNode, timeIn[v]) % modl;

                int par = lca(u, v);

                res = res * powermod(weight[par], modl - 2) % modl;
                if(par == 1) {
                    inv = 1;
                } else {
                    par = P[par][0];
                    inv = powermod(query(1, 1, numNode, timeIn[par]), modl - 2);
                }

                res = res * inv % modl * inv % modl;

                cout << res << '\n';
            }
        }

        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    process();
    return 0;
}
