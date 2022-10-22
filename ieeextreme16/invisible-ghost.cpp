#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define N 505
#define fi first
#define se second
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

const int lx[] = {1, 0, 0, -1}, ly[] = {0, -1, 1, 0};
const char dirChar[] = {'D', 'L', 'R', 'U'};

ii Pacman;
queue<ii> qu;
int numTest, dist[N][N], pDist[N][N], tr[N][N], row, col;
char ch[N][N];

void process() {
    cin >> numTest;

    int dem(0);
    while(numTest--) {
        cin >> row >> col;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                dist[i][j] = 0;
                pDist[i][j] = 0;
            }
        }

        while(qu.size())
            qu.pop();

        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                cin >> ch[i][j];
                if(ch[i][j] == 'G') {
                    qu.push({i, j});
                    dist[i][j] = 1;
                } else
                    if(ch[i][j] == 'P') {
                        Pacman = {i, j};
                    }
            }
        }

        while(qu.size()) {
            int x(qu.front().fi), y(qu.front().se);
            qu.pop();

            for (int id = 0; id < 4; ++id) {
                int u(x + lx[id]), v(y + ly[id]);
                if(u < 1 || v < 1 || u > row || v > col || ch[u][v] == 'X')
                    continue;

                if(!dist[u][v]) {
                    dist[u][v] = dist[x][y] + 1;
                    qu.push({u, v});
                }
            }
        }

        qu.push(Pacman);
        pDist[Pacman.fi][Pacman.se] = 1;

        while(qu.size()) {
            int x(qu.front().fi), y(qu.front().se);
            qu.pop();

            for (int id = 0; id < 4; ++id) {
                int u(x + lx[id]), v(y + ly[id]);
                if(u < 1 || v < 1 || u > row || v > col || ch[u][v] == 'X')
                    continue;

                if(!pDist[u][v]) {
                    pDist[u][v] = pDist[x][y] + 1;
                    tr[u][v] = id;
                    qu.push({u, v});
                }
            }
        }

        int res(0), x(0), y(0);
        bool ck(0);
        for (int u = 1; u <= row; ++u) {
            for (int v = 1; v <= col; ++v) {
                if(pDist[u][v] > 0) {
                    if(!dist[u][v]) {
                        ck = 1;
                        if(!x) {
                            x = u, y = v;
                        }
                    } else
                        if(pDist[u][v] < dist[u][v] && res < dist[u][v]) {
                            res = dist[u][v];
                            x = u, y = v;
                        }
                }
            }
        }

        cout << "Case #" << ++dem << ": ";
        if(ck) {
            cout << "INFINITE ";
        } else {
            cout << res - 2 << ' ';
        }

        stack<char> st;
        while(x != Pacman.fi || y != Pacman.se) {
            int id(tr[x][y]);
            st.push(dirChar[id]);
            x -= lx[id];
            y -= ly[id];
        }

        if(st.size()) {
            while(st.size()) {
                cout << st.top();
                st.pop();
            }
        } else {
            cout << "STAY";
        }

        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    process();
    return 0;
}