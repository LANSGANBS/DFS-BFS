#include <bits/stdc++.h>
#define endl '\n'
#define buff ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize(3)
using namespace std;
#define ll long long
#define int ll

struct node
{
    int x;
    int s;
};

int bfs(int x)
{
    int vis[50000];
    memset(vis, 0, sizeof(vis));
    queue<node> q;
    q.push(node{x, 0});
    vis[x] = 1;
    if (x == 0)
        return 0;
    while (!q.empty())
    {
        node t = q.front();
        q.pop();
        if (((t.x + 1) % 32768 == 0) || ((2 * t.x) % 32768 == 0))
            return t.s + 1;
        if (!vis[(t.x + 1) % 32768])
        {
            q.push(node{(t.x + 1) % 32768, t.s + 1});
            vis[(t.x + 1) % 32768] = 1;
        }
        if (!vis[(2 * t.x) % 32768])
        {
            q.push(node{(2 * t.x) % 32768, t.s + 1});
            vis[(2 * t.x) % 32768] = 1;
        }
    }
    return -1;
}

void solve()
{
    int x;
    cin >> x;
    cout << bfs(x) << " ";
    // wout <<L" "<<endl;
    // cout << R"( )" << endl;
}

signed main()
{
    // setlocale(LC_ALL, "");
    buff;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}