#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int dx[] = { 0, 0, 1,-1 };
const int dy[] = { 1,-1, 0, 0 };

const int N = 1000;
int n, m;
char a[N][N];

bool isValid(int x, int y) {
    if (x < 0 || y < 0) return false;
    if (x >= n || y >= m) return false;
    return true;
}

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;

    auto cnt = [](int x, int y) -> int {
        int cntA = 0, cntM = 0;
        for (int i = 0; i < 4; i++) {
            int u = x + dx[i], v = y + dy[i];
            if (!isValid(u, v) || a[u][v] == 'C') continue;
            if (a[u][v] == 'A') cntA++;
            else cntM++;
        }
        return cntA * cntM;
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            if (a[i][j] == 'C') res += cnt(i, j);

    cout << res;
    return 0;
}