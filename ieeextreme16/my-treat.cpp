#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n = 0;
map<string,int> mp;

int getTag(string name) {
  if (mp.find(name) == mp.end()) {
    mp[name] = ++n;
    return n;
  }
  return mp[name];
}

const int N = 100005;
int ans[N];

void removeData() {
  for (int i = 1; i <= n; i++) {
    ans[i] = 0;
  }
  n = 0;
  mp.clear();
}
signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  #ifdef ziwok
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
  int T;
  cin >> T;
  while (T--) {
    int q, m;
    cin >> q;
    while (q--) {
      string name;
      cin >> name;
      int u = getTag(name);
      cin >> m;
      for (int i = 1; i <= m; i++) {
        cin >> name;
        int v = getTag(name);
        ans[v]++;
      }
      ans[u] -= m;
    }

    int res1 = 0, res2 = 0;
    for (int i = 1; i <= n; i++) {
      if (ans[i] < 0)
        res1 = max(res1, abs(ans[i]));
      if (ans[i] > 0)
        res2 += ans[i];
    }
    cout << res2 << " " << res1 << endl;
    removeData();
  }
  return 0;
}