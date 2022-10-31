// https://oj.vnoi.info/problem/icpc22_mb_b
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ii = pair<int,int>;

const int M = 1000006;
bool mark[M];

const int N = 11;
int m, n, S;
int a[N], b[N];

int nxtVertex(int s0, int i) {
  return (1LL * s0 * a[i] + b[i]) % m;
}

signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  #ifdef ziwok
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
  cin >> m >> n >> S;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i];
  
  queue <ii> q;
  q.push({S, 0});
  while (q.size()) {
    int u = q.front().first;
    int d = q.front().second;
    if (u == 0) {
      cout << d;
      return 0;
    }
    q.pop();
    mark[u] = true;

    for (int i = 1; i <= n; i++) {
      int v = nxtVertex(u, i);
      if (mark[v]) continue;
      q.push({v, d+1});
    }
  }

  cout << "-1";
  return 0;
}