#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < k; i++)
        {
            int x, y, l, r, u, d;
            cin >> x >> y >> l >> r >> u >> d;

            for (int j = x; j <= x + l; j++)
            {
                for (int p = max(1, y - u); p <= min(m, y + d); p++)
                {
                    grid[j][p] = 1;
                }
            }

            for (int j = x; j >= x - r; j--)
            {
                for (int p = max(1, y - u); p <= min(m, y + d); p++)
                {
                    grid[j][p] = 1;
                }
            }
        }

        // 使用DFS判断是否存在路径
        vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
        bool found = false;

        function<void(int, int)> dfs = [&](int x, int y)
        {
            if (x == n && y == m)
            {
                found = true;
                return;
            }

            visited[x][y] = 1;

            if (x + 1 <= n && !grid[x + 1][y] && !visited[x + 1][y])
            {
                dfs(x + 1, y);
            }
            if (y + 1 <= m && !grid[x][y + 1] && !visited[x][y + 1])
            {
                dfs(x, y + 1);
            }
        };

        dfs(1, 1);

        if (found)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }

    return 0;
}
