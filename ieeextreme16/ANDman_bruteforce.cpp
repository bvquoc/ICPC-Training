#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

template <typename T>
inline void Read(T& x) {
  bool Neg = false;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') Neg = !Neg;
  x = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
    x = (x << 3) + (x << 1) + (c - '0');
  if (Neg) x = -x;
}

template <typename T>
inline void Write(T x) {
  if (x < 0) { putchar('-'); x = -x; }
  T p = 1;
  for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
  for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

using ii = pair <int, int>;
const int MOD = 1000000007;
const int N = 100005;

int n, q, w[N];
vector <int> adj[N];
bool mark[N];

void process(int U, int V) {
  for (int i = 1; i <= n; i++)
    mark[i] = false;
  queue<ii> q;
  q.push({U, w[U]});
  while (q.size()) {
    int u = q.front().first;
    int d = q.front().second;
    q.pop();
    mark[u] = true;
    if (u == V) {
      Write(d);
      putchar(endl);
      return;
    }
    for (int v: adj[u]) if (!mark[v]) {
      int dv = (1LL * d * w[v]) % MOD;
      q.push({v, dv});
    }
  }
}

signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  #ifdef ziwok
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
  int T; Read(T);
  while (T--) {
    Read(n);
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      Read(w[i]);
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      Read(u); Read(v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    Read(q);
    while (q--) {
      int qType;
      Read(qType);
      int u, v;
      Read(u); Read(v);
      if (qType == 1) {
        w[u] = v;
      } else {
        process(u, v);
      }
    }
  }
  return 0;
}