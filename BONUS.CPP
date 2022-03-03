#include <bits/stdc++.h>
using namespace std;

const int M = 100005;
const int N = M;
int m, n, h, w, a[M], b[N];

int main()
{
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    long long tmp;
    long long res = -1e9;
    cin >> m >> n >> w >> h;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        cin >> b[j];
    }
    int F[m + 5][n + 5];
    memset(F, 0, sizeof(F));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            F[i][j] = a[i] + b[j];
            F[i][j] += F[i][j - 1] + F[i - 1][j] - F[i - 1][j - 1];
            if (i >= w && j >= h)
            {
                tmp = F[i][j] - F[i - w][j] - F[i][j - h] + F[i - w][j - h];
                if (tmp > res)
                {
                    res = tmp;
                }
            }
        }
    }
    cout << res;
}