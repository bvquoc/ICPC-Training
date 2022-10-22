#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int get(int &x) {
  x %= 180;
  if (x <= 0) return (x + 180);
  return x;
}

const int N = 10004;
int n, a[N];
set <int> S;

signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  #ifdef ziwok
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      S.insert(get(a[i]));
      // cout << get(a[i]) << ' ';
    }
    // cout << endl;

    if (n == 0) {
      cout << 1 << endl;
    } else {
      cout << 2 * S.size() << endl;
    }
    S.clear();
  }
  return 0;
}