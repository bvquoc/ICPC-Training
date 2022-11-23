#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int dx1[] = {0, 1, 0, -1};
const int dy1[] = {1, 0, -1, 0};
const int dx2[] = {0, 1, 1, -1, -1};
const int dy2[] = {0, 1, -1, 1, -1};

const int N = 1003;
int n, m, a[N][N];

signed main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	#ifdef ziwok
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			char c; cin >> c;
			a[i][j] = ((c == '*') ? 2 : 1);
		}
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			bool ok = true;
			for (int k = 0; k < 4; k ++) {
				ok = ok && (a[i + dx1[k]][j + dy1[k]] != 1);
			}
			if (ok) for (int k = 0; k < 4; k ++) {
				a[i + dx1[k]][j + dy1[k]] = 0;
			}

			ok = true;
			for (int k = 0; k < 5; k ++) {
				ok = ok && (a[i + dx2[k]][j + dy2[k]] != 1);
			}
			if (ok) for (int k = 0; k < 5; k ++) {
				a[i + dx2[k]][j + dy2[k]] = 0;
			}
		}
	}

	bool res = true;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (a[i][j] == 2) res = false;
		}
	}

	cout << (res ? "YES" : "NO");

	return 0;
}