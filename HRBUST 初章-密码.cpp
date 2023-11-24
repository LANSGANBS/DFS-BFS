#include <iostream>
#include <vector>

using namespace std;

void dfs(int pos, int current_number, vector<int> &counts, int n, int &result)
{
    if (pos == n)
    {
        if (current_number % 3 == 0)
        {
            result++;
        }
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (counts[i] > 0)
        {
            vector<int> new_counts = counts;
            new_counts[i] -= 1;
            int new_number = current_number * 10 + i;
            if (new_number == 0 && pos == 0)
            {
                dfs(pos + 1, new_number, new_counts, n, result);
            }
            else if (new_number != 0)
            {
                dfs(pos + 1, new_number, new_counts, n, result);
            }
        }
    }
}

int count_numbers(vector<int> &counts, int n)
{
    int result = 0;
    dfs(0, 0, counts, n, result);
    return result;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        vector<int> counts(5);
        for (int j = 0; j < 5; j++)
        {
            cin >> counts[j];
        }

        int n;
        cin >> n;

        int result = count_numbers(counts, n);
        cout << result << endl;
    }

    return 0;
}
