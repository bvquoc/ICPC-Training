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

const int N = 1000006;
int n, a[N], b[N];

int getMEX(int a[], int n) {
    int res = 0;
    sort(a,a+n);
    if (a[0] > 0) res = 0;
    else {
        res = a[n-1]+1;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            if (j >= n) continue;
            if (a[i] + 1 == a[j]) continue;
            res = a[i]+1;
            break;
        }
    }
    return res;
}
signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    Read(n);
    for (int i = 0; i < n; i++) Read(a[i]);

    int cur = getMEX(a, n);
    for (int i = 0; i < n; i++) {
        b[i] = cur;
        bool unique_ai = true;
        if (i > 0 && a[i] == a[i-1]) unique_ai = false;
        if (i < n-1 && a[i] == a[i+1]) unique_ai = false;
        if (unique_ai && a[i] < cur)
            b[i] = a[i];
    }
    
    Write(getMEX(b, n));

    return 0;
}