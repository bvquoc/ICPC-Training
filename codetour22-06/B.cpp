#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s;
int n, k;

signed main(void) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    #ifdef ziwok
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    cin >> s >> n >> k;

    { // check FAIL
        auto checkFAIL = [](char x) {
            int cur = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != x) {
                    if (cur == k)
                        return true;
                    cur = 0;
                    continue;
                }
                cur++;
                if (cur == k)
                    return true;
            }
            return false;
        };

        if (checkFAIL('#') || checkFAIL('*')) {
            cout << "FAIL";
            return 0;
        }
    }

    int curCheese = 0;
    int time = 0;
    for (int i = 0; i < s.size(); i++) {
        if (curCheese == n) {
            time += n;
            curCheese = 0;
        }

        if (s[i] == '*') {
            curCheese++;
        } else {
            curCheese = max(0, curCheese - 1);
        }
        time++;

        // cout << time << ' '<< curCheese <<endl;
    }

    cout << time;

    return 0;
}