#include <bits/stdc++.h>
#define endl '\n'
#define buff ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
/*
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize(3)
*/
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
const ll MAX_INT = 0x3f3f3f3f;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const ll CF = 2e5 + 9;
const ll mod = 1e9 + 7;
int vis[CF];
int n;

void dfs(int x)
{
    if (x == n + 1)
    {
        for (int c : vis)
            cout << c << ' ';
        cout << endl;
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
}

int main()
{
    buff;
    while (cin>>n)
    {
        memset(vis, 0, sizeof(vis));
        dfs(1);
    }
    return 0;
}