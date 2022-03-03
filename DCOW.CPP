#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int tmp;
long long rs = 0;
int main()
{
    freopen("DCOW.INP", "r", stdin);
    freopen("DCOW.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }
    for (int i = 1; i <= 1000; i++)
    {
        if (a[i] > 0)
        {
            rs += (a[i] * (a[i] - 1) / 2);
        }
    }
    cout << rs;
}