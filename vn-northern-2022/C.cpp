#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
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

const int N = 2003;

struct edge {
  int i;
  int x, y;
};
using ii = pair<int, int>;

double dist(int x, int y, int u, int v) {
  return sqrt((x - u) * (x - u) + (y - v) * (y - v));
}

int n, res;
ii a[N];
vector<edge> adj[N];
bool mark[N];
int d[N];

struct dt {
  int u;
  int d;
  bitset<N> tr;
};

stack<dt> S;

void prepare() {
  for (int i = 0; i < N; i++) {
    adj[i].clear();
    mark[i] = false;
    d[i] = 0;
    while (S.size())
      S.pop();
  }
  for (int i = 1; i <= n; i++) {
    int u, v;
    Read(u);
    Read(v);
    a[i] = {u, v};
  }

  // sort(a+1, a+1+n,[](const ii &A, const ii &B) {
  //   if (A.first < B.first) return true;
  //   if (A.first == B.first && A.second < B.second)
  //     return true;
  //   return false;
  // });

  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
    {
      double d = dist(a[i].first, a[i].second, a[j].first, a[j].second);
      if (d <= 1.3)
        continue;
      adj[i].push_back({j, a[j].first, a[j].second});
      adj[j].push_back({i, a[i].first, a[i].second});
    }
  res = 1;
}

void dfs(int u) {
  bitset<N> tmpp;
  tmpp.set(u);
  S.push({u, 1, tmpp});
  while (S.size())
  {
    int u = S.top().u;
    int d = S.top().d;
    bitset <N> tr(S.top().tr);
    S.pop();
    mark[u] = true;
    res = max(res, d);

    for (auto tmp : adj[u])
    {
      int v = tmp.i;
      if (mark[v])
        continue;
      int x = tmp.x, y = tmp.y;
      bool ok = true;
      for (int i = tr._Find_first(); i <= n; i = tr._Find_next(i)) if (tr[i]) {
        if (dist(x, y, a[i].first, a[i].second) <= 1.3)
        {
          ok = false;
          break;
        }
      }

      if (!ok)
        continue;

      bitset <N> z(tr);
      z.set(v);
      S.push({v, d+1, z});
    }
  }
}

void process() {
  for (int i = 1; i <= n; i++)
  if (!mark[i])
    dfs(i);
}

signed main() {
  while (cin >> n) {
    prepare();
    process();
    Write(res);
    putchar('\n');
  }
  return 0;
}