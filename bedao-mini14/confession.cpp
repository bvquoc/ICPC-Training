#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int T; cin >> T;
    string s;
    int n, k;

    while (T--) {
        cin >> n >> k;
        cin >> s;

        string s2 = s.substr(n/2 + (n & 1), n/2);
        string s1 = s2; 
        reverse(s1.begin(), s1.end());
        if (n & 1) s1 += s[n/2];
        string S = s1 + s2;

        s1 = s.substr(0, k); 
        sort(s1.begin(), s1.end());
        s2 = S.substr(0, k);
        sort(s2.begin(), s2.end());
        if (s1 == s2 && s.substr(k) == S.substr(k)) {
            cout << "Yes\n";
            cout << S << endl;
        } else cout << "No\n";
    }
    return 0;
}