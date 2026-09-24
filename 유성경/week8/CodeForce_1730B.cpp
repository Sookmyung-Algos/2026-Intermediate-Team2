// CodeForce 1730_B. Meeting on the Line
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(6);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<long long> x(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> x[i];
        }

        vector<long long> t(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> t[i];
        }

        long long maxV = x[0] + t[0];
        long long minV = x[0] - t[0];

        for (int i = 1; i < n; ++i)
        {
            if (x[i] + t[i] > maxV)
            {
                maxV = x[i] + t[i];
            }

            if (x[i] - t[i] < minV)
            {
                minV = x[i] - t[i];
            }
        }

        cout << (double)(maxV + minV) / 2.0 << "\n";
    }

    return 0;
}
#endif