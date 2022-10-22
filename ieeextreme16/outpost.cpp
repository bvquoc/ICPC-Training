#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define fi first
#define se second
#define N 50003
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

int val[11][N], P[N][16], Pa[N][16], maxv[N], minv[N], Pi[N][16], row, col, maxDiff;

int getMax(int l, int r) {
    int log = log2(r - l + 1);
    return max(maxv[P[l][log]], maxv[P[r - (1 << log) + 1][log]]);
}

int getMin(int l, int r) {
    int log = log2(r - l + 1);
    return min(Pi[l][log], Pi[r - (1 << log) + 1][log]);
}

int getMaxIn(int l, int r) {
    int log = log2(r - l + 1);
    return max(Pa[l][log], Pa[r - (1 << log) + 1][log]);
}

void process() {
    cin >> row >> col >> maxDiff;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            cin >> val[i][j];
        }
    }

    int ans(0);
    for (int i = 1; i <= row; ++i) {
        for (int k = 1; k <= col; ++k)
            maxv[k] = 0, minv[k] = 1e9+7;

        for (int j = i; j <= row; ++j) {
            for (int k = 1; k <= col; ++k) {
                maxv[k] = max(maxv[k], val[j][k]);
                minv[k] = min(minv[k], val[j][k]);
                P[k][0] = k;
                Pi[k][0] = minv[k];

                Pa[k][0] = max(val[i][k], val[j][k]);
            }

            for (int l = 1; (1 << l) <= col; ++l) {
                for (int k = 1; k + (1 << l) - 1 <= col; ++k) {
                    Pi[k][l] = min(Pi[k][l - 1], Pi[k + (1 << (l - 1))][l - 1]);
                    Pa[k][l] = max(Pa[k][l - 1], Pa[k + (1 << (l - 1))][l - 1]);

                    if(maxv[P[k][l - 1]] > maxv[P[k + (1 << (l - 1))][l - 1]]) {
                        P[k][l] = P[k][l - 1];
                    } else {
                        P[k][l] = P[k + (1 << (l - 1))][l - 1];
                    }
                }
            }

            for (int k = 1; k <= col; ++k) {
                int l(k), r(col), opt(0);
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    if(getMax(k, mid) - getMin(k, mid) <= maxDiff) {
                        opt = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }

                if(!opt)
                    continue;

                if(getMaxIn(k, opt) == getMax(k, opt) || maxv[k] == getMax(k, opt)) {
                    ans = max(ans, (j - i + 1) * (opt - k + 1));
                } else {
                    int log = log2(opt - k + 1);
                    opt = (maxv[P[k][log]] > maxv[P[opt - (1 << log) + 1][log]]) ? P[k][log] : P[opt - (1 << log) + 1][log];
                    ans = max(ans, (j - i + 1) * (opt - k + 1));
                }
            }
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    process();
    return 0;
}

/*
#include <bits/stdc++.h>
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
*/