#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

template<class X, class Y>
bool maximize(X &x, const Y &y) {
  X eps = 1e-9;
  if (x + eps < y) {
    x = y;
    return true;
  }
  return false;
}

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

struct DSU { 
  int n;
  vector <int> p;
  DSU(){};
  DSU(int _n) {
    n = _n;
    p.assign(n + 7, -1); 
  }
  void assign(int _n) {
    n = _n;
    p.assign(n + 7, -1); 
  }

  int find_root(int u) {
    if (p[u] < 0) return u;
    return p[u] = find_root(p[u]);
  }

  void join(int u, int v) {
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
} dsu;

const int N = 10004;
int n, a[N];
int f[N][N];

signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  #ifdef ziwok
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int m;
  Read(n); Read(m);
  dsu.assign(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  while (m--) {
    int u, v;
    Read(u); Read(v);
    dsu.join(a[u],a[v]);
  }

  f[1][a[1]] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      f[i][j] = max(f[i-1][j], f[i][j-1]);
      if (dsu.sameSet(a[i], j)) {
        maximize(f[i][j], f[i-1][j-1] + 1);
      }
    }

  Write(f[n][n]);
  return 0;
}

/* Sol:

Gọi dp[i][j]: dãy con dài nhất của dãy con a[1], a[2],...,a[i] và số kết thúc của dãy <= j
assign: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
Nếu a[i] và j thuộc cùng 1 TPLT => maximize(f[i][j], f[i-1][j-1] + 1)

Kết quả: f[n][n]

*/
