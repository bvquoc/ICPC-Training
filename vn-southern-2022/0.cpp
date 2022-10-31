#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define sz(a) (signed(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define endl '\n'
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
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

using ii = pair <int, int>;
using ll = long long;

signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);

  return 0;
}