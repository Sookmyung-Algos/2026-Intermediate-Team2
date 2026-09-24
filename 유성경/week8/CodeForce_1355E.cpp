// CodeForce 1355_E. Restorer Distance
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long compute_cost(long long H, int N, long long A, long long R, long long M, const vector<long long>& h)
{
    long long adds = 0;
    long long rems = 0;

    for (int i = 0; i < N; ++i)
    {
        if (h[i] < H)
        {
            adds += (H - h[i]);
        }
        else if (h[i] > H)
        {
            rems += (h[i] - H);
        }
    }

    long long moves = min(adds, rems);

    return moves * M + (adds - moves) * A + (rems - moves) * R;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long A, R, M;
    cin >> N >> A >> R >> M;

    if (A + R < M)
    {
        M = A + R;
    }

    vector<long long> h(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> h[i];
    }

    long long low = 0;
    long long high = 1000000000LL;

    while (high - low > 2)
    {
        long long m1 = low + (high - low) / 3;
        long long m2 = high - (high - low) / 3;

        long long cost1 = compute_cost(m1, N, A, R, M, h);
        long long cost2 = compute_cost(m2, N, A, R, M, h);

        if (cost1 < cost2)
        {
            high = m2;
        }
        else
        {
            low = m1;
        }
    }

    long long ans = compute_cost(low, N, A, R, M, h);

    for (long long i = low + 1; i <= high; ++i)
    {
        long long current_cost = compute_cost(i, N, A, R, M, h);
        if (current_cost < ans)
        {
            ans = current_cost;
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif