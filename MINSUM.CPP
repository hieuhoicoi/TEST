#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("MINSUM.INP", "r", stdin);
    freopen("MINSUM.OUT", "w", stdout);
    long long a, b;
    cin >> a >> b;
    b *= a;
    unordered_map<int, int> gcd;
    unordered_map<int, int> nhan;
    int ans1 = 1;
    int ans2 = 1;
    for (long long i = 2; i <= a; i++)
    {
        if (a % i == 0)
        {
            int dem = 0;
            while (a % i == 0)
            {
                dem++;
                a /= i;
            }
            gcd[i] = dem;
        }
    }
    for (long long i = 2; i <= b; i++)
    {
        if (b % i == 0)
        {
            int dem = 0;
            while (b % i == 0)
            {
                dem++;
                b /= i;
            }
            nhan[i] = dem;
        }
    }
    bool flag = false;
    for (auto i : gcd)
    {
        if (i.second * 2 > nhan[i.first])
        {
            flag = true;
        }
        else
        {
            nhan[i.first] -= i.second * 2;
            ans1 *= i.first;
            ans2 *= i.first;
        }
    }
    if (flag == true)
    {
        cout << -1;
        return 0;
    }
    for (auto i : nhan)
    {
        if (i.second > 0)
        {
            if (ans1 < ans2)
                ans1 *= pow(i.first, i.second);
            else
                ans2 *= pow(i.first, i.second);
        }
    }
    cout << ans1 + ans2;
}