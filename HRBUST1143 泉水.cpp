#include <bits/stdc++.h>
#define endl '\n'
#define buff ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
const ll MAXN = 2e3 + 9;
ll n, m, p1, p2;
ll mp[MAXN][MAXN];
ll dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
ll vis[MAXN][MAXN];

ll dfs(ll x, ll y)
{
    vis[x][y] = 1;
    ll ans = 1;
    for (int i = 0; i <= 3; i++)
    {
        ll xx = x + dir[i][0];
        ll yy = y + dir[i][1];
        if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] == 1 || mp[xx][yy] > mp[p1][p2])
            continue;
        ans += dfs(xx, yy);
    }
    return ans;
}

void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    cout << dfs(p1, p2) << endl;
}

int main()
{
    while (cin >> n >> m >> p1 >> p2)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                vis[i][j] = 0;
        solve();
    }
    return 0;
}
