#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1000006;
const int MOD = 1000000007;
int n, f[2][N];
string s[2];

int dp(int r, int c) {
    if (c == n) return s[r][c] == 'X';
    int &res = f[r][c];
    if (res != -1) return res;

    res = 0;
    for (int i = 0; i < 2; i++) {
        if (s[i][c+1] == 'O') continue;
        res += dp(i, c+1);
        res %= MOD;
    }

    return res;
}

signed main(void) {
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {
        cin >> s[0] >> s[1];
        n = s[0].size();
        s[0] = "*" + s[0];
        s[1] = "*" + s[1];

        fill(f[0], f[0] + N, -1);
        fill(f[1], f[1] + N, -1);

        cout << dp(0,0) << endl;
    }
    
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}