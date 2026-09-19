// CodeForce 888E. Maximum Subsequence 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getSubset(int idx, int end, long long currS, long long m, 
    const vector<long long>& arr, vector<long long>& res)
{
    if (idx == end)
    {
        res.push_back(currS % m);
        return;
    }

    getSubset(idx + 1, end, currS, m, arr, res);
    getSubset(idx + 1, end, (currS + arr[idx]) % m, m, arr, res);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long m;
    cin >> n >> m;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        arr[i] %= m;
    }

    int mid = n / 2;
    vector<long long> A;
    vector<long long> B;

    getSubset(0, mid, 0, m, arr, A);
    getSubset(mid, n, 0, m, arr, B);

    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    long long max_val = 0;

    for (size_t i = 0; i < A.size(); ++i)
    {
        long long x = A[i];

        auto it = lower_bound(B.begin(), B.end(), m - x);

        if (it != B.begin())
        {
            auto prev_it = it;
            --prev_it;
            long long val = (x + *prev_it) % m;

            if (val > max_val)
            {
                max_val = val;
            }
        }

        long long val2 = (x + B.back()) % m;

        if (val2 > max_val)
        {
            max_val = val2;
        }
    }

    cout << max_val << "\n";

    return 0;
}
#endif