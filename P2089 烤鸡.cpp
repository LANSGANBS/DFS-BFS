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
const int N = 20;
int n;
int arr[N];  // 存临时方案
int res = 0; // 存方案数
int sum;
int mem[60000][N]; // 存所有方案

// x表示当前枚举到了哪一位，sum表示当前已经选了的调料的总质量
void dfs(int x, int sum)
{
    if (sum > n)
        return; // 剪枝
    if (x > 10)
    {
        if (sum == n)
        {
            res++;
            for (int i = 1; i <= 10; ++i)
            {
                mem[res][i] = arr[i];
            }
        }
        return;
    }
    for (int i = 1; i <= 3; ++i)
    {
        arr[x] = i;
        dfs(x + 1, sum + i);
        arr[x] = 0;
    }
}

void solve()
{
    cin >> n;
    dfs(1, 0);
    cout << res << endl;
    for (int i = 1; i <= res; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << mem[i][j] << " ";
        }
        cout << endl;
    }
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