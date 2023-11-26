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
int n, m;

void solve()
{
    cin >> n >> m;
    int arr[n + 7];
    for (int i = 1; i <= n; ++i)
        cin >> arr[i]; 
    for (int i = 1; i <= m; ++i)
        next_permutation(arr + 1, arr + 1 + n);
    for (int i = 1; i < n; ++i)
        cout << arr[i] << ' ';
    cout << arr[n];
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