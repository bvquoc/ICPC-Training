#include <bits/stdc++.h>
#define file "Cipher"
#define pb push_back
#define fi first
#define se second
#define For(i, a, b) for (int i = a; i <= b; i++)
#define Dow(i, a, b) for (int i = a; i >= b; i--)
#define MASK(i) (1LL << (i))
#define BIT(i, a) (((a) >> (i)) & 1)
#define endl '\n'

using namespace std;

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
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

const int maxN = 5009;
typedef pair <int, int> ii;
int n, p, r, c;
char a[maxN][maxN];
string target[maxN];
struct Q {
    int l, r;
};
map<char, Q> S, L;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> p;
    cin >> n;
    string s; cin >> s;
    int check = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            check = 1;
            continue;
        }
        if (!check) {
            r = r * 10 + (int)(s[i] - '0');
        }
        else {
            c = c * 10 + (int)(s[i] - '0');
        }
    }
    char type;
    cin >> type;
    cin.ignore();
    for (int i = 1; i <= p; i++) {
        getline(cin, target[i]);
    }
    int u = 1, v = 1;
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        int check = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '<') {
                check = 1;
                continue;
            }
            if (s[j] == '>') {
                check = 0;
                continue;
            }
            if (check)
                continue;
            a[u][v] = s[j];
            v++;
            if (v > c) {
                v = 1;
                u++;
            }
            if (u > r)
                break;
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char t = a[i][j];
            if (S[t].l == 0 && S[t].r == 0) {
                S[t].l = i;
                S[t].r = j;
            }
            L[t].l = i;
            L[t].r = j;
        }
    }
    if (type == 'S') {
        for (int i = 1; i <= p; i++) {
            int check = 0, ok = 1;
            for (char x : target[i]) {
                if (S[x].l == 0 || S[x].r == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 1) {
                for (char x : target[i]) {
                    if (check)
                        cout << ",";
                    cout << S[x].l << "," << S[x].r;
                    check = 1;
                }
                cout << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
    else {
        for (int i = 1; i <= p; i++) {
            int check = 0, ok = 1;
            for (char x : target[i]) {
                if (L[x].l == 0 || L[x].r == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 1) {
                for (char x : target[i]) {
                    if (check)
                        cout << ",";
                    cout << L[x].l << "," << L[x].r;
                    check = 1;
                }
                cout << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
