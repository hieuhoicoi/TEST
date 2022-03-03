#include <bits/stdc++.h>
using namespace std;

int n;
int a[20][20], back[20];
bool b[20];
vector<int> tmp(20);
vector<int> ans(20);
int res = 1000000000;

void xuat()
{
    freopen("CUNGDIEN.INP", "r", stdin);
    freopen("CUNGDIEN.OUT", "w", stdout);
    int v = 0;
    for (int i = 1; i <= n; i += 1)
    {
        v += a[i][back[i]];
        tmp[i] = back[i];
    }
    if (v < res)
    {
        ans = tmp;
        res = v;
    }
}

void solve(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 0 && back[k - 1] - 1 != i && back[k - 1] + 1 != i)
        {
            back[k] = i;
            b[i] = 1;
            if (k == n)
            {
                xuat();
            }
            else
                solve(k + 1);
            b[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    solve(1);
    cout << res << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
}