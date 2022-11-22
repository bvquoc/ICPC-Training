#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n; cin >> n;
    vector <string> a(n);
    for (string &s: a) cin >> s;
    
    string mxStr = *max_element(a.begin(), a.end());
    int mi = atoi(mxStr.c_str());
    if (mxStr[0] == '0') {
        mi = 1;
        while (mxStr.size() > 1) mi *= 10, mxStr.pop_back();
    }

    int mx = 0;
    int numDigit = a[0].size();
    while (numDigit) {
        mx *= 10;
        mx += 9;
        numDigit--;
    }

    cout << mi << endl << mx;
    return 0;
}