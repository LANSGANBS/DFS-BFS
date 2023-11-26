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
const int N = 1e5 + 7;
int n, m;
int arr[N];
int mars[N];
int vis[N];
int res = 0;
bool flag = 0;

void dfs(int x)
{
    if (flag)
    {
        return;
    }
    if (x > n)
    {
        res++;
        if (res == m + 1)
        {
            flag = 1;
            for (int i = 1; i <= n; i++)
            {
                cout << arr[i] << ' ';
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!res)
        {
            i = mars[x];
        }
        if (!vis[i])
        {
            vis[i] = 1;
            arr[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> mars[i];
    }
    dfs(1);
    // wout <<L" "<<endl;
    // cout << R"( )" << endl;
}

signed main()
{
    // setlocale(LC_ALL, "");
    buff;
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}