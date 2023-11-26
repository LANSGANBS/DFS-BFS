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

void solve()
{
    int n, W;
    cin >> n >> W;
    int hard2count[15] = {0};
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        hard2count[t] += 1;
    }
    int ans = 0, cur_sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (cur_sum + hard2count[i] > W)
        { // 到难度i的今天就学不了了
            ans += 1;
            cur_sum = hard2count[i];
        }
        else
        { // 学了这个难度今天还没饱和，继续看下一个
            cur_sum += hard2count[i];
        }
    }
    if (cur_sum > 0)
        ans += 1; // 还有剩下的，就再学一天
    cout << ans << endl;
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