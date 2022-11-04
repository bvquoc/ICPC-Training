#include <iostream>
#include <deque>
#define int long long

#define INF 1e18
using namespace std;

int s, c;
int f[10005];
int r[10005];
int res[10005];

int32_t main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> s >> c >> r[0];
        deque<int> dq;
        for (int i = 1; i <= s; i++)
        {
            cin >> f[i] >> r[i];
            f[i] += f[i - 1];
            res[i] = INF;
        }
        res[0] = r[0] * c;
        dq.push_back(0);
        for (int i = 1; i <= s; i++)
        {
            while (dq.size() && f[i] - f[dq.front()] > c)
                dq.pop_front();
            for (int j = dq.front(); j < i; j++)
            {
                if (i == s)
                    res[i] = min(res[i], res[j]);
                else
                    res[i] = min(res[i], res[j] + 500 + ((f[i] - f[j]) * r[i]));
            }
            dq.push_back(i);
        }
        cout << res[s] << "\n";
    }
}