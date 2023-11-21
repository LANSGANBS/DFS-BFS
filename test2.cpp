#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int max_absolute_difference_sum(int n, int d, vector<int> &a)
{
    vector<vector<int>> dp(n + 1, vector<int>(d + 1, 0));

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= d; ++j)
        {
            for (int k = max(1, a[i - 1] - d); k <= min(1000, a[i - 1] + d); ++k)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(a[i - 1] - k));
            }
        }
    }

    int result = *max_element(dp[n].begin(), dp[n].end());
    return result;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int n, d;
        cin >> n >> d;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int result = max_absolute_difference_sum(n, d, a);
        cout << result << endl;
    }

    return 0;
}
