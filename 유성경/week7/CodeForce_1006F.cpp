// CodeForce 1006F. Xor-Paths
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int half;
long long k, ans;
long long a[20][20];
vector<long long> v[20][20];

void DFS_1(int r, int c, long long val, int steps)
{
    if (steps == half)
    {
        v[r][c].push_back(val);
        return;
    }

    if (r + 1 < n)
    {
        DFS_1(r + 1, c, val ^ a[r + 1][c], steps + 1);
    }

    if (c + 1 < m)
    {
        DFS_1(r, c + 1, val ^ a[r][c + 1], steps + 1);
    }
}

void DFS_2(int r, int c, long long val, int steps)
{
    if (steps == (n + m - 2) - half)
    {
        long long target = k ^ val ^ a[r][c];
        auto upper = upper_bound(v[r][c].begin(), v[r][c].end(), target);
        auto lower = lower_bound(v[r][c].begin(), v[r][c].end(), target);

        ans += (upper - lower);

        return;
    }

    if (r - 1 >= 0)
    {
        DFS_2(r - 1, c, val ^ a[r - 1][c], steps + 1);
    }

    if (c - 1 >= 0)
    {
        DFS_2(r, c - 1, val ^ a[r][c - 1], steps + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    half = (n + m - 2) / 2;

    DFS_1(0, 0, a[0][0], 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!v[i][j].empty())
            {
                sort(v[i][j].begin(), v[i][j].end());
            }
        }
    }

    DFS_2(n - 1, m - 1, a[n - 1][m - 1], 0);

    cout << ans << "\n";

    return 0;
}
#endif