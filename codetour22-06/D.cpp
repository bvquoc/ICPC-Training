#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

using ii = pair<int,int>;

const int N = 100005;
int n, a[N];
bool mark[N];
int group[N];

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    Read(n);
    for (int i = 1; i <= n; i++) {
        Read(a[i]);
        group[a[i]]++;
    }

    {
        vector <ii> tmp;
        for (int i = 0; i < N; i++) {
            if (group[i] == 0) continue;
            tmp.push_back(ii(group[i], i));
            group[i] = 0;
        }
        for (ii x: tmp)
            group[x.first]++;
    }

    int res = 0;
    for (int i = N-1; i > 0;) {
        if (group[i] <= 1) {
            i--;
            continue;
        }
        int cnt = group[i] - 1, tmp = i;
        i--;
        while (i > 0) {
            if (group[i] != 0 || cnt == 0) break;

            group[i] = 1;
            cnt--;
            res += (tmp - i);
            i--;
        }
        
        res += tmp * cnt;
    }
    Write(res);
    
    return 0;
}