#include <bits/stdc++.h>
#define endl '\n'
#define buff ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define ll long long
#define int ll

struct student
{
    string name;
    int program, math, english;
    int total = 0;
};
student stu[507];

bool cmp(student a, student b)
{
    if (a.total == b.total)
    {
        return a.name < b.name;
    }
    else
        return a.total > b.total;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].name >> stu[i].program >> stu[i].math >> stu[i].english;
        stu[i].total = stu[i].program + stu[i].math + stu[i].english;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << stu[i].name << " " << stu[i].total << endl;
    }
}

signed main()
{
    buff;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}