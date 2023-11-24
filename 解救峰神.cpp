#include <bits/stdc++.h>
#define endl '\n'
#define buff ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
/*
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize(3)
*/
using namespace std;
#define ll long long
#define int ll
int n, m, x, y, p, q, ans, xx, yy;
int mp[107][107];
bool vis[107][107];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void dfs(int x, int y, int step)
{
    if (x == p && y == q)
    {
        if (step < ans)
        {
            ans = step;
        }
        return;
    }
    for (int i = 0; i <= 3; i++)
    {
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if (xx >= 0 && yy >= 0 && xx <= n && yy <= m && mp[xx][yy] != -1 && !vis[xx][yy])
        {
            vis[xx][yy] = 1;
            dfs(xx, yy, step + 1);
            vis[xx][yy] = 0;
        }
    }
}

void solve()
{
    // wout <<L" "<<endl;
    // cout << R"( )" << endl;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
            }
        }
        cin >> x >> y >> p >> q;
        memset(vis, 0, sizeof vis);
        ans = 1e9;
        dfs(x, y, 0);
        cout << ans << endl;
    }
}

signed main()
{
    // setlocale(LC_ALL, "");
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}