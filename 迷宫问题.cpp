// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
int arr[45][45], ans = -1;
int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};
int path[50], yes[50];
void dfs(int x, int y, int step)
{
    if (x == 4 && y == 4 && (step < ans || ans == -1))
    {
        path[step] = 4 * 5 + 4;
        ans = step;
        for (int i = 1; i <= ans; i++)
            yes[i] = path[i];
    }
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (xx >= 0 && xx < 5 && yy >= 0 && yy < 5 && arr[xx][yy] == 0)
        {
            arr[xx][yy] = 1;
            path[step] = x * 5 + y;
            dfs(xx, yy, step + 1);
            arr[xx][yy] = 0;
        }
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    dfs(0, 0, 1);
    for (int i = 1; i <= ans; i++)
    {
        cout << "(" << yes[i] / 5 << ", " << yes[i] % 5 << ")" << endl;
    }
}
