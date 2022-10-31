#include <bits/stdc++.h>
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

const int N = 16;
const string Color[] = { "White", "Silver", "Gray", "Black", "Red", "Maroon", "Yellow", "Olive", "Lime", "Green", "Aqua", "Teal", "Blue", "Navy", "Fuchsia", "Purple" };
const int    R[]     = {  255,     192,      128,    0,       255,   128,      255,      128,       0,      0,       0,      0,      0,      0,    255,       128 };
const int    G[]     = {  255,     192,      128,    0,         0,     0,      255,      128,     255,    128,     255,    128,      0,      0,      0,         0 };
const int    B[]     = {  255,     192,      128,    0,         0,     0,        0,        0,       0,      0,     255,    128,    255,    128,    255,       128 };

double sqr(int x) {
  return (double) x * x;
}
double dist(int r1, int g1, int b1, int r2, int g2, int b2) {
  return sqrt(sqr(r1 - r2) + sqr(g1 - g2) + sqr(b1 - b2));
}

signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  #ifdef ziwok
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int r, g, b;
  while (cin >> r >> g >> b) {
    if (r == -1 && g == -1 && b == -1) return 0;
    int x = 0;
    double res = DBL_MAX;
    for (int i = 0; i < N; i++) {
      double cur = dist(r,g,b,R[i],G[i],B[i]);
      if (minimize(res, cur))
        x = i;
    }
    cout << Color[x] << endl;
  }
  return 0;
}