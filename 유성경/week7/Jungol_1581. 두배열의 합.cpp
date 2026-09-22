// 정올 1581. 두배열의 합 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;
    cin >> t;

    int n;
    cin >> n;

    vector<long long> A(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    int m;
    cin >> m;

    vector<long long> B(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> B[i];
    }

    vector<long long> sumA;

    for (int i = 0; i < n; ++i)
    {
        long long sum = 0;

        for (int j = i; j < n; ++j)
        {
            sum += A[j];

            if (sum < t)
            {
                sumA.push_back(sum);
            }
            else
            {
                break;
            }
        }
    }

    sort(sumA.begin(), sumA.end());

    long long answer = 0;

    for (int i = 0; i < m; ++i)
    {
        long long sum = 0;

        for (int j = i; j < m; ++j)
        {
            sum += B[j];

            if (sum < t)
            {
                long long target = t - sum;
                auto upper = upper_bound(sumA.begin(), sumA.end(), target);
                auto lower = lower_bound(sumA.begin(), sumA.end(), target);
                answer += (upper - lower);
            }
            else
            {
                break;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
#endif