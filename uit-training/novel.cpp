#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n;
    string keyboard, s;
    cin >> n >> keyboard >> s;
    
    bool valid = false;
    for (char x: keyboard) {
        if (x == s[0]) {
            valid = true;
            break;
        }
    }
    if (!valid) {
        cout << "NO";
        return 0;
    }

    keyboard += keyboard[0];
    bool f[26][26];
    auto idx = [&](char x) -> size_t { return x - 'a'; };
    for (int i = 0; i + 1 < keyboard.size(); i++) 
        f[idx(keyboard[i])][idx(keyboard[i+1])] = true;

    bool res = true;
    for (int i = 1; i < s.size(); i++) {
        if (!f[idx(s[i-1])][idx(s[i])]) {
            res = false;
            break;
        }
    }
    cout << (res ? "YES" : "NO");
    return 0;
}