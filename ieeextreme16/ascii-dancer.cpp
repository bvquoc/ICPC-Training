#include <bits/stdc++.h>
#define file "file"
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

const int maxN = 1;
typedef pair <int, int> ii;
char ans[10];
char change[10];
int ok[10];

void xuat() {
    for (int i = 0; i <= 6; i++)
        ok[i] = 0;
    if (!ok[1] && ans[1] == '(') {
        cout << ans[1];
        ok[1] = 1;
    }
    else
        cout << ' ';
    cout << ans[0];
    ok[2] = 1;
    if (!ok[3] && ans[3] == ')') {
        cout << ans[3];
        ok[3] = 1;
    }
    else
        cout << ' ';
    cout << endl;
    if (ok[1])
        cout << ' ';
    else {
        cout << ans[1];
        ok[1] = 1;
    }
    cout << ans[2];
    if (ok[3])
        cout << ' ';
    else {
        cout << ans[3];
        ok[3] = 1;
    }
    cout << endl;
    cout << ans[4] << ans[5] << ans[6];
    cout << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int Test; cin >> Test;
    while (Test--) {
        int dd = 0;
        change[0] = ans[0] = 'o';
        change[1] = ans[1] = '/';
        change[2] = ans[2] = '|';
        change[3] = ans[3] = '\\';
        change[4] = ans[4] = '/';
        change[5] = ans[5] = ' ';
        change[6] = ans[6] = '\\';
        int n; cin >> n;
        cin.ignore();
        while (n--) {
            string s;
            getline(cin, s);
            if (s[0] == 's' && s[1] == 'a' && s[2] == 'y' && s[3] == ' ') {
                for (int i = 4; i < s.size(); i++)
                    cout << s[i];
                cout << endl;
                continue;
            }
            if (dd == 0) {
                if (s[0] == 'l' && s[1] == 'e' && s[2] == 'f' && s[3] == 't'
                    && s[4] == ' ' && s[5] == 'h' && s[6] == 'a' && s[7] == 'n'
                    && s[8] == 'd' && s[9] == ' ' && s[10] == 't' && s[11] == 'o'
                    && s[12] == ' ' && s[13] == 'h' && s[14] == 'e' && s[15] == 'a'
                    && s[16] == 'd') {
                    ans[3] = ')';
                    xuat();
                    continue;
                }
                if (s[0] == 'l' && s[1] == 'e' && s[2] == 'f' && s[3] == 't'
                    && s[4] == ' ' && s[5] == 'h' && s[6] == 'a' && s[7] == 'n'
                    && s[8] == 'd' && s[9] == ' ' && s[10] == 't' && s[11] == 'o'
                    && s[12] == ' ' && s[13] == 'h' && s[14] == 'i' && s[15] == 'p')  {
                    ans[3] = '>';
                    xuat();
                    continue;
                }
                if (s[0] == 'l' && s[1] == 'e' && s[2] == 'f' && s[3] == 't'
                    && s[4] == ' ' && s[5] == 'h' && s[6] == 'a' && s[7] == 'n'
                    && s[8] == 'd' && s[9] == ' ' && s[10] == 't' && s[11] == 'o'
                    && s[12] == ' ' && s[13] == 's' && s[14] == 't' && s[15] == 'a'
                    && s[16] == 'r' && s[17] == 't')  {
                    ans[3] = '\\';
                    xuat();
                    continue;
                }
                if (s[0] == 'l' && s[1] == 'e' && s[2] == 'f' && s[3] == 't'
                    && s[4] == ' ' && s[5] == 'l' && s[6] == 'e' && s[7] == 'g' && s[8] == ' '
                    && s[9] == 'i' && s[10] == 'n')  {
                    ans[6] = '>';
                    xuat();
                    continue;
                }
                if (s[0] == 'l' && s[1] == 'e' && s[2] == 'f' && s[3] == 't'
                    && s[4] == ' ' && s[5] == 'l' && s[6] == 'e' && s[7] == 'g' && s[8] == ' '
                    && s[9] == 'o' && s[10] == 'u' && s[11] == 't')  {
                    ans[6] = '\\';
                    xuat();
                    continue;
                }
                if (s[0] == 'r' && s[1] == 'i' && s[2] == 'g' && s[3] == 'h'
                    && s[4] == 't' && s[5] == ' ' && s[6] == 'h' && s[7] == 'a' && s[8] == 'n'
                    && s[9] == 'd' && s[10] == ' ' && s[11] == 't' && s[12] == 'o'
                    && s[13] == ' ' && s[14] == 'h' && s[15] == 'e' && s[16] == 'a'
                    && s[17] == 'd')  {
                    ans[1] = '(';
                    xuat();
                    continue;
                }
                if (s[0] == 'r' && s[1] == 'i' && s[2] == 'g' && s[3] == 'h'
                    && s[4] == 't' && s[5] == ' ' && s[6] == 'h' && s[7] == 'a' && s[8] == 'n'
                    && s[9] == 'd' && s[10] == ' ' && s[11] == 't' && s[12] == 'o'
                    && s[13] == ' ' && s[14] == 'h' && s[15] == 'i' && s[16] == 'p')  {
                    ans[1] = '<';
                    xuat();
                    continue;
                }
                if (s[0] == 'r' && s[1] == 'i' && s[2] == 'g' && s[3] == 'h'
                    && s[4] == 't' && s[5] == ' ' && s[6] == 'h' && s[7] == 'a' && s[8] == 'n'
                    && s[9] == 'd' && s[10] == ' ' && s[11] == 't' && s[12] == 'o'
                    && s[13] == ' ' && s[14] == 's' && s[15] == 't' && s[16] == 'a'
                    && s[17] == 'r' && s[18] == 't')  {
                    ans[1] = '/';
                    xuat();
                    continue;
                }
                if (s[0] == 'r' && s[1] == 'i' && s[2] == 'g' && s[3] == 'h'
                    && s[4] == 't' && s[5] == ' ' && s[6] == 'l' && s[7] == 'e' && s[8] == 'g'
                    && s[9] == ' ' && s[10] == 'i' && s[11] == 'n')  {
                    ans[4] = '<';
                    xuat();
                    continue;
                }
                if (s[0] == 'r' && s[1] == 'i' && s[2] == 'g' && s[3] == 'h'
                    && s[4] == 't' && s[5] == ' ' && s[6] == 'l' && s[7] == 'e' && s[8] == 'g'
                    && s[9] == ' ' && s[10] == 'o' && s[11] == 'u' && s[12] == 't') {
                    ans[4] = '/';
                    xuat();
                    continue;
                }
                if (s[0] == 't' && s[1] == 'u' && s[2] == 'r' && s[3] == 'n') {
                    if (ans[4] == '/')
                        change[6] = '\\';
                    else
                        change[6] = '>';
                    if (ans[6] == '\\')
                        change[4] = '/';
                    else
                        change[4] = '<';
                    if (ans[1] == '/')
                        change[3] = '\\';
                    else {
                        if (ans[1] == '(')
                            change[3] = ')';
                        else
                            change[3] = '>';
                    }
                    if (ans[3] == '\\')
                        change[1] = '/';
                    else {
                        if (ans[3] == ')')
                            change[1] = '(';
                        else
                            change[1] = '<';
                    }
                    for (int i = 0; i <= 6; i++)
                        ans[i] = change[i];
                    xuat();
                    if (dd == 0)
                        dd = 1;
                    else
                        dd = 0;
                }
            }
            else {
                if (s[0] == 'l' && s[1] == 'e' && s[2] == 'f' && s[3] == 't'
                    && s[4] == ' ' && s[5] == 'h' && s[6] == 'a' && s[7] == 'n'
                    && s[8] == 'd' && s[9] == ' ' && s[10] == 't' && s[11] == 'o'
                    && s[12] == ' ' && s[13] == 'h' && s[14] == 'e' && s[15] == 'a'
                    && s[16] == 'd') {
                    ans[1] = '(';
                    xuat();
                    continue;
                }
                if (s[0] == 'l' && s[1] == 'e' && s[2] == 'f' && s[3] == 't'
                    && s[4] == ' ' && s[5] == 'h' && s[6] == 'a' && s[7] == 'n'
                    && s[8] == 'd' && s[9] == ' ' && s[10] == 't' && s[11] == 'o'
                    && s[12] == ' ' && s[13] == 'h' && s[14] == 'i' && s[15] == 'p')  {
                    ans[1] = '<';
                    xuat();
                    continue;
                }
                if (s[0] == 'l' && s[1] == 'e' && s[2] == 'f' && s[3] == 't'
                    && s[4] == ' ' && s[5] == 'h' && s[6] == 'a' && s[7] == 'n'
                    && s[8] == 'd' && s[9] == ' ' && s[10] == 't' && s[11] == 'o'
                    && s[12] == ' ' && s[13] == 's' && s[14] == 't' && s[15] == 'a'
                    && s[16] == 'r' && s[17] == 't')  {
                    ans[1] = '/';
                    xuat();
                    continue;
                }
                if (s[0] == 'l' && s[1] == 'e' && s[2] == 'f' && s[3] == 't'
                    && s[4] == ' ' && s[5] == 'l' && s[6] == 'e' && s[7] == 'g' && s[8] == ' '
                    && s[9] == 'i' && s[10] == 'n')  {
                    ans[4] = '<';
                    xuat();
                    continue;
                }
                if (s[0] == 'l' && s[1] == 'e' && s[2] == 'f' && s[3] == 't'
                    && s[4] == ' ' && s[5] == 'l' && s[6] == 'e' && s[7] == 'g' && s[8] == ' '
                    && s[9] == 'o' && s[10] == 'u' && s[11] == 't')  {
                    ans[4] = '/';
                    xuat();
                    continue;
                }
                if (s[0] == 'r' && s[1] == 'i' && s[2] == 'g' && s[3] == 'h'
                    && s[4] == 't' && s[5] == ' ' && s[6] == 'h' && s[7] == 'a' && s[8] == 'n'
                    && s[9] == 'd' && s[10] == ' ' && s[11] == 't' && s[12] == 'o'
                    && s[13] == ' ' && s[14] == 'h' && s[15] == 'e' && s[16] == 'a'
                    && s[17] == 'd')  {
                    ans[3] = ')';
                    xuat();
                    continue;
                }
                if (s[0] == 'r' && s[1] == 'i' && s[2] == 'g' && s[3] == 'h'
                    && s[4] == 't' && s[5] == ' ' && s[6] == 'h' && s[7] == 'a' && s[8] == 'n'
                    && s[9] == 'd' && s[10] == ' ' && s[11] == 't' && s[12] == 'o'
                    && s[13] == ' ' && s[14] == 'h' && s[15] == 'i' && s[16] == 'p')  {
                    ans[3] = '>';
                    xuat();
                    continue;
                }
                if (s[0] == 'r' && s[1] == 'i' && s[2] == 'g' && s[3] == 'h'
                    && s[4] == 't' && s[5] == ' ' && s[6] == 'h' && s[7] == 'a' && s[8] == 'n'
                    && s[9] == 'd' && s[10] == ' ' && s[11] == 't' && s[12] == 'o'
                    && s[13] == ' ' && s[14] == 's' && s[15] == 't' && s[16] == 'a'
                    && s[17] == 'r' && s[18] == 't')  {
                    ans[3] = '\\';
                    xuat();
                    continue;
                }
                if (s[0] == 'r' && s[1] == 'i' && s[2] == 'g' && s[3] == 'h'
                    && s[4] == 't' && s[5] == ' ' && s[6] == 'l' && s[7] == 'e' && s[8] == 'g'
                    && s[9] == ' ' && s[10] == 'i' && s[11] == 'n')  {
                    ans[6] = '>';
                    xuat();
                    continue;
                }
                if (s[0] == 'r' && s[1] == 'i' && s[2] == 'g' && s[3] == 'h'
                    && s[4] == 't' && s[5] == ' ' && s[6] == 'l' && s[7] == 'e' && s[8] == 'g'
                    && s[9] == ' ' && s[10] == 'o' && s[11] == 'u' && s[12] == 't') {
                    ans[6] = '\\';
                    xuat();
                    continue;
                }
                if (s[0] == 't' && s[1] == 'u' && s[2] == 'r' && s[3] == 'n') {
                    if (ans[4] == '/')
                        change[6] = '\\';
                    else
                        change[6] = '>';
                    if (ans[6] == '\\')
                        change[4] = '/';
                    else
                        change[4] = '<';
                    if (ans[1] == '/')
                        change[3] = '\\';
                    else {
                        if (ans[1] == '(')
                            change[3] = ')';
                        else
                            change[3] = '>';
                    }
                    if (ans[3] == '\\')
                        change[1] = '/';
                    else {
                        if (ans[3] == ')')
                            change[1] = '(';
                        else
                            change[1] = '<';
                    }
                    for (int i = 0; i <= 6; i++)
                        ans[i] = change[i];
                    xuat();
                    if (dd == 0)
                        dd = 1;
                    else
                        dd = 0;
                }
            }
        }
    }
    return 0;
}
