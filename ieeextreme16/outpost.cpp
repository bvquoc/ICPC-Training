#include <bits/stdc++.h>
#define endl '\n'
// #define int long long
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


struct MaxST {
    int n;
    vector <int> Max;
    MaxST (int _n = 0) {
        n = _n;
        Max.resize(4 * n + 9, 0);
    }
    void update(int i, int l, int r, int u, int c) {
        if (l > r || u > r || l > u)
            return;
        if (l == r) {
            maximize(Max[i], c);
            return;
        }
        int m = (l + r) >> 1;
        update(i * 2, l, m, u, c);
        update(i * 2 + 1, m + 1, r, u, c);
        Max[i] = max(Max[i * 2], Max[i * 2 + 1]);
    }
    int get(int i, int l, int r, int u, int v) {
        if (l > r || u > v || u > r || l > v)
            return 0;
        if (u <= l && r <= v)
            return Max[i];
        int m = (l + r) >> 1;
        return max(get(i * 2, l, m, u, v), get(i * 2 + 1, m + 1, r, u, v));
    }
    void update(int u, int c) {
        update(1, 1, n, u, c);
    }
    int get(int u, int v) {
        return get(1, 1, n, u, v);
    }
};
struct MinST {
    int n;
    vector <int> Min;
    MinST (int _n = 0) {
        n = _n;
        Min.resize(4 * n + 9, INT_MAX);
    }
    void update(int i, int l, int r, int u, int c) {
        if (l > r || u > r || l > u)
            return;
        if (l == r) {
            minimize(Min[i], c);
            return;
        }
        int m = (l + r) >> 1;
        update(i * 2, l, m, u, c);
        update(i * 2 + 1, m + 1, r, u, c);
        Min[i] = min(Min[i * 2], Min[i * 2 + 1]);
    }
    int get(int i, int l, int r, int u, int v) {
        if (l > r || u > v || u > r || l > v)
            return INT_MAX;
        if (u <= l && r <= v)
            return Min[i];
        int m = (l + r) >> 1;
        return min(get(i * 2, l, m, u, v), get(i * 2 + 1, m + 1, r, u, v));
    }
    void update(int u, int c) {
        update(1, 1, n, u, c);
    }
    int get(int u, int v) {
        return get(1, 1, n, u, v);
    }
};

int m, n, t;
int A[50004];
void process_1D() {
  MinST mi(n);
  MaxST mx(n);
  for (int i = 1; i <= n; i++) {
    Read(A[i]);
    mi.update(1, 1, n, i, A[i]);
    mx.update(1, 1, n, i, A[i]);
  }

  int res = 1;
  int lo = 1, hi = n;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    bool ok = false;
    for (int l = 1; l+mid-1 <= n; l++) {
      int r = l+mid-1;
      int MIN = mi.get(1, 1, n, l, r);
      int MAX = mx.get(1, 1, n, l, r);
      if ((MAX - MIN) > t) continue;
      ok = true;
      break;
    }
    
    if (ok) {
      maximize(res, mid);
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  Write(res);
}

int a[11][5003];
int Pmx[11][5003][10][20];
int Pmi[11][5003][10][20];

const int tab32[32] = {
     0,  9,  1, 10, 13, 21,  2, 29,
    11, 14, 16, 18, 22, 25,  3, 30,
     8, 12, 20, 28, 15, 17, 24,  7,
    19, 27, 23,  6, 26,  5,  4, 31};

int log2 (uint32_t value)
{
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    return tab32[(uint32_t)(value*0x07C4ACDD) >> 27];
}

void RMQ2D() {
  for (int i = m; i >= 1; --i) {
    for (int j = n; j >= 1; --j) {
      Pmx[i][j][0][0] = a[i][j];
      for (int q = 1; i + (1 << q) - 1 <= m; ++q)
        Pmx[i][j][q][0] = max(Pmx[i][j][q - 1][0], Pmx[i + (1 << (q - 1))][j][q - 1][0]);

      for (int k = 1; j + (1 << k) - 1 <= n; ++k)
        Pmx[i][j][0][k] = max(Pmx[i][j][0][k - 1], Pmx[i][j + (1 << (k - 1))][0][k - 1]);

      for (int q = 1; i + (1 << q) - 1 <= m; ++q) {
        for (int k = 1; j + (1 << k) - 1 <= n; ++k) {
          Pmx[i][j][q][k] = max({Pmx[i][j][q - 1][k - 1], Pmx[i][j + (1 << (k - 1))][q - 1][k - 1],
          Pmx[i + (1 << (q - 1))][j][q - 1][k - 1], Pmx[i + (1 << (q - 1))][j + (1 << (k - 1))][q - 1][k - 1]});
        }
      }
    }
  }

  for (int i = m; i >= 1; --i) {
    for (int j = n; j >= 1; --j) {
      Pmi[i][j][0][0] = a[i][j];
      for (int q = 1; i + (1 << q) - 1 <= m; ++q)
        Pmi[i][j][q][0] = min(Pmi[i][j][q - 1][0], Pmi[i + (1 << (q - 1))][j][q - 1][0]);

      for (int k = 1; j + (1 << k) - 1 <= n; ++k)
        Pmi[i][j][0][k] = min(Pmi[i][j][0][k - 1], Pmi[i][j + (1 << (k - 1))][0][k - 1]);

      for (int q = 1; i + (1 << q) - 1 <= m; ++q) {
        for (int k = 1; j + (1 << k) - 1 <= n; ++k) {
          Pmi[i][j][q][k] = min({Pmi[i][j][q - 1][k - 1], Pmi[i][j + (1 << (k - 1))][q - 1][k - 1],
          Pmi[i + (1 << (q - 1))][j][q - 1][k - 1], Pmi[i + (1 << (q - 1))][j + (1 << (k - 1))][q - 1][k - 1]});
        }
      }
    }
  }
}
int getMax(int x1, int y1, int x2, int y2) {
  int k = log2(y2 - y1 + 1), q = log2(x2 - x1 + 1);
  return max({Pmx[x1][y1][q][k], Pmx[x2 - (1 << q) + 1][y2 - (1 << k) + 1][q][k],
    Pmx[x1][y2 - (1 << k) + 1][q][k], Pmx[x2 - (1 << q) + 1][y1][q][k]});
}
int getMin(int x1, int y1, int x2, int y2) {
  int k = log2(y2 - y1 + 1), q = log2(x2 - x1 + 1);
  return min({Pmi[x1][y1][q][k], Pmi[x2 - (1 << q) + 1][y2 - (1 << k) + 1][q][k],
    Pmi[x1][y2 - (1 << k) + 1][q][k], Pmi[x2 - (1 << q) + 1][y1][q][k]});
}

signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  #ifdef ziwok
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
  Read(m); Read(n); Read(t);
  if (m == 1) {
    process_1D();
    return 0;
  }

  for (int i = 1; i <= m; i++) 
    for (int j = 1; j <= n; j++)
      Read(a[i][j]);

  RMQ2D();

  int res = 1;
  for (int x1 = 1; x1 <= m; x1++) for (int y1 = 1; y1 <= n; y1++) {
    for (int y2 = n; y2 >= y1; y2--) for (int x2 = m; x2 >= x1; x2--) {
      if ((x2-x1+1) * (y2-y1+1) <= res) break;
      int MAX = getMax(x1, y1, x2, y2);
      int MIN = getMin(x1, y1, x2, y2);
      if (MAX - MIN > t) continue;

      int mx1 = getMax(x1,y1,x1,y2);
      int mx2 = getMax(x2,y1,x2,y2);
      int mx3 = getMax(x1,y1,x2,y1);
      int mx4 = getMax(x1,y2,x2,y2);

      if (max({mx1, mx2, mx3, mx4}) == MAX) {
        maximize(res, (x2-x1+1) * (y2-y1+1));
        break;
      }
    }
  }
  Write(res);

  return 0;
}

//