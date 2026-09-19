// CodeForce 525E. Anya and Cubes
#if 01
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long fact[20];
vector<long long> V1[26];
vector<long long> V2[26];

void DFS_1(int idx, int end, long long sum, int used_k, const vector<long long>& a)
{
    if (idx == end)
    {
        V1[used_k].push_back(sum);
        return;
    }

    DFS_1(idx + 1, end, sum, used_k, a);

    DFS_1(idx + 1, end, sum + a[idx], used_k, a);

    if (a[idx] <= 18)
    {
        DFS_1(idx + 1, end, sum + fact[a[idx]], used_k + 1, a);
    }
}

void DFS_2(int idx, int end, long long sum, int used_k, const vector<long long>& a)
{
    if (idx == end)
    {
        V2[used_k].push_back(sum);
        return;
    }

    DFS_2(idx + 1, end, sum, used_k, a);
    DFS_2(idx + 1, end, sum + a[idx], used_k, a);

    if (a[idx] <= 18)
    {
        DFS_2(idx + 1, end, sum + fact[a[idx]], used_k + 1, a);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fact[0] = 1;
    for (int i = 1; i <= 18; ++i)
    {
        fact[i] = fact[i - 1] * i;
    }

    int n, k;
    long long S;
    cin >> n >> k >> S;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int mid = n / 2;

    DFS_1(0, mid, 0, 0, a);
    DFS_2(mid, n, 0, 0, a);

    for (int i = 0; i <= k; ++i)
    {
        if (!V2[i].empty())
        {
            sort(V2[i].begin(), V2[i].end());
        }
    }

    long long ans = 0;

    for (int i = 0; i <= k; ++i)
    {
        for (size_t j = 0; j < V1[i].size(); ++j)
        {
            long long val = V1[i][j];
            long long target = S - val;

            if (target < 0)
            {
                continue;
            }

            for (int m = 0; m <= k - i; ++m)
            {
                if (!V2[m].empty())
                {
                    auto lower = lower_bound(V2[m].begin(), V2[m].end(), target);
                    auto upper = upper_bound(V2[m].begin(), V2[m].end(), target);
                    ans += (upper - lower);
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif