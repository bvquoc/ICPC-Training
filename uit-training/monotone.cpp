#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(void) {
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    int n;
    long long c;
    string s;
    cin >> n >> c >> s;

    int j = 0;
    int64_t a = 0, b = 0, ab = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && ab <= c) {
            res = max(res, j - i);
            if (s[j] == 'a') a++;
            else if (s[j] == 'b') b++, ab += a;
            j++;
        }
        if (ab <= c) res = max(res, j - i);
        if (s[i] == 'b') b--;
        else if (s[i] == 'a') ab -= b, a--;
    }
    cout << res;
    return 0;
}