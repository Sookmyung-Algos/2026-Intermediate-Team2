// 정올 3642. 철도역 
#if 0
#include <iostream>
#include <vector>
using namespace std;

long long getCost(int P, int N, const vector<long long>& C, const vector<int>& X)
{
    long long cost = 0;

    for (int i = 0; i < N; ++i)
    {
        int dist = P - X[i];
        if (dist < 0)
        {
            dist = -dist;
        }

        cost += C[dist];
    }

    return cost;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L, N;
    cin >> L >> N;

    vector<long long> C(L + 1, 0);
    for (int i = 1; i <= L; ++i)
    {
        cin >> C[i];
    }

    vector<int> X(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> X[i];
    }

    int low = 0;
    int high = L;

    while (high - low > 2)
    {
        int m1 = low + (high - low) / 3;
        int m2 = high - (high - low) / 3;

        long long cost1 = getCost(m1, N, C, X);
        long long cost2 = getCost(m2, N, C, X);

        if (cost1 < cost2)
        {
            high = m2;
        }
        else
        {
            low = m1;
        }
    }

    long long ans = getCost(low, N, C, X);

    for (int i = low + 1; i <= high; ++i)
    {
        long long curr = getCost(i, N, C, X);

        if (curr < ans)
        {
            ans = curr;
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif
