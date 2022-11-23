#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 200005;
int n, k, r, a[N];

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    cin >> n >> k >> r;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector <int> b(k+1);
    for (int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
        b[u] = v;
    }

    int p = 0, q = 0, ans = n + 1, bad = r;
    for (p = 0; p < n; p++) {
        while (q < n && bad > 0) {
            b[a[q]]--;
            if (b[a[q]] == 0) bad--;
            q++;
        }
        if (bad == 0) ans = min(ans, q-p);
        b[a[p]]++;
        bad += (b[a[p]] == 1);
    }

    if (ans == n + 1) cout << "Impossible!";
    else cout << ans;
    return 0;
}