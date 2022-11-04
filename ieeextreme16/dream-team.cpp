#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

typedef pair<int, string> ii;

int bef, aft, res;

int S;
int A, B, C, D, E;
ii a[505], b[405], c[105], d[55], e[45];

bool Bu(string x, string y)
{
    for (int i = 0; i < min(x.length(), y.length()); i++)
    {
        if (x[i] < y[i])
            return 1;
        if (x[i] > y[i])
            return 0;
    }
    if (x.length() < y.length())
        return 1;
    return 0;
}

struct Data
{
    int Sum, i, j;
    bool operator<(const Data &x) const
    {
        if (this->Sum != x.Sum)
            return this->Sum < x.Sum;
        if (a[this->i].second != a[x.i].second)
            return Bu(a[this->i].second, a[x.i].second);
        return Bu(b[this->j].second, b[x.j].second);
    }
};

struct Data2
{
    int Sum, i, j, k;
    bool operator<(const Data2 &x) const
    {
        if (this->Sum != x.Sum)
            return this->Sum < x.Sum;
        if (c[this->i].second != c[x.i].second)
            return Bu(c[this->i].second, c[x.i].second);
        if (d[this->j].second != d[x.j].second)
            return Bu(d[this->j].second, d[x.j].second);
        return Bu(e[this->k].second, e[x.k].second);
    }
};
vector<Data> Fi;
vector<Data2> Se;
vector<Data> FF;
vector<Data2> SS;

int Search(int Su)
{
    int sol = -1;
    int l = 0;
    int r = Se.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (Se[mid].Sum <= Su)
        {
            sol = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return sol;
}

bool cmp(const ii &a, const ii &b)
{
    return (a.first < b.first || (a.first == b.first && Bu(a.second, b.second)));
}

void Upda(int i, int k)
{
    bef = i;
    aft = k;
    res = Fi[i].Sum + Se[k].Sum;
}

int32_t main()
{
    cin >> S;
    cin >> A;
    for (int i = 0; i < A; i++)
        cin >> a[i].second >> a[i].first;

    cin >> B;
    for (int i = 0; i < B; i++)
        cin >> b[i].second >> b[i].first;

    cin >> C;
    for (int i = 0; i < C; i++)
        cin >> c[i].second >> c[i].first;

    cin >> D;
    for (int i = 0; i < D; i++)
        cin >> d[i].second >> d[i].first;

    cin >> E;
    for (int i = 0; i < E; i++)
        cin >> e[i].second >> e[i].first;

    sort(a, a + A, cmp);
    sort(b, b + B, cmp);
    sort(c, c + C, cmp);
    sort(d, d + D, cmp);
    sort(e, e + E, cmp);

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < B; j++)
        {
            if (a[i].first + b[j].first > S)
                continue;
            FF.push_back(Data{a[i].first + b[j].first, i, j});
        }
    }

    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < D; j++)
        {
            for (int l = 0; l < E; l++)
            {
                if (c[i].first + d[j].first + e[l].first > S)
                    continue;
                SS.push_back(Data2{c[i].first + d[j].first + e[l].first, i, j, l});
            }
        }
    }

    sort(FF.begin(), FF.end());
    sort(SS.begin(), SS.end());
    Fi.push_back(FF[0]);
    for (int i = 1; i < FF.size(); i++)
        if (FF[i].Sum != Fi.back().Sum)
            Fi.push_back(FF[i]);
    Se.push_back(SS[0]);
    for (int i = 1; i < SS.size(); i++)
        if (SS[i].Sum != Se.back().Sum)
            Se.push_back(SS[i]);

    for (int i = 0; i < Fi.size(); i++)
    {
        int k = Search(S - Fi[i].Sum);
        if (k == -1)
            continue;
        if (Fi[i].Sum + Se[k].Sum == res)
        {
            if (Bu(a[Fi[i].i].second, a[Fi[bef].i].second))
                Upda(i, k);
            else if (a[Fi[i].i].second == a[Fi[bef].i].second)
            {
                if (Bu(b[Fi[i].j].second, b[Fi[bef].j].second))
                    Upda(i, k);
                else if (b[Fi[i].j].second == b[Fi[bef].j].second)
                {
                    if (Bu(c[Se[k].i].second, c[Se[aft].i].second))
                        Upda(i, k);
                    else if (c[Se[k].i].second == c[Se[aft].i].second)
                    {
                        if (Bu(d[Se[k].j].second, d[Se[aft].j].second))
                            Upda(i, k);
                        else if (d[Se[k].j].second == d[Se[k].j].second)
                        {
                            if (Bu(e[Se[k].k].second, e[Se[k].k].second))
                                Upda(i, k);
                        }
                    }
                }
            }
        }
        if (Fi[i].Sum + Se[k].Sum > res)
            Upda(i, k);
    }
    cout << a[Fi[bef].i].second << "\n"
         << b[Fi[bef].j].second << "\n"
         << c[Se[aft].i].second << "\n"
         << d[Se[aft].j].second << "\n"
         << e[Se[aft].k].second;
}
