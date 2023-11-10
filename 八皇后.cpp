#include <bits/stdc++.h>
using namespace std;
int vis[15];
int ans[15];
int n;
int sum;

bool check(int x)
{
    for (int i = 1; i < x; i++)
    {
        if (x - i == abs(ans[x] - ans[i]))
            return true;
    }
    return false;
}
void dfs(int step)
{
    if (check(step - 1))
        return;
    if (step > n)
    {
        sum++;
        for (int i = 1; i <= n && sum <= 3; i++)
        {
            cout << ans[i] << " ";
            if (i == n)
                cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            ans[step] = i;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << sum;
    return 0;
}