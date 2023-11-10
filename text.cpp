#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll a[5], b[5], c[12], n;
ll dfs(int x, int y, int z, bool lead)
{
    if (x == 0)
        return y == 0;
    ll ans = 0;
    for (int i = 0; i <= a[z] && i <= x; i++)
    {
        if (z == 0 && lead && i > 0)
            continue; // Skip leading zero
        if ((lead && i == 0) || !lead)
            ans = (ans + dfs(x - i, (y + (i * z) % 3) % 3, z + 1, lead && i == 0)) % mod;
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    c[0] = 1;
    for (int i = 1; i <= 11; i++)
        c[i] = c[i - 1] * 5 % mod;
    while (T--)
    {
        for (int i = 0; i < 5; i++)
            cin >> a[i];
        cin >> n;
        cout << dfs(n, 0, 0, true) << endl;
    }
    return 0;
}
