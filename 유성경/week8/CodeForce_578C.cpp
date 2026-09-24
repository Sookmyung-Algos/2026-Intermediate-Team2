// CodeForce 578_C. Weakness and Poorness
#if 0
#include <iostream>
#include <vector>
using namespace std;

double get_weakness(double x, int n, const vector<double>& a)
{
    double maxS = 0;
    double minS = 0;
    double currMax = 0;
    double currMin = 0;

    for (int i = 0; i < n; ++i)
    {
        double val = a[i] - x;

        currMax += val;
        if (currMax < 0)
        {
            currMax = 0;
        }
        if (currMax > maxS)
        {
            maxS = currMax;
        }

        currMin += val;
        if (currMin > 0)
        {
            currMin = 0;
        }
        if (currMin < minS)
        {
            minS = currMin;
        }
    }

    double absMin = minS;

    if (absMin < 0)
    {
        absMin = -absMin;
    }

    if (maxS > absMin)
    {
        return maxS;
    }

    return absMin;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<double> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    double low = -10000.0;
    double high = 10000.0;

    for (int i = 0; i < 200; ++i)
    {
        double m1 = low + (high - low) / 3.0;
        double m2 = high - (high - low) / 3.0;

        double w1 = get_weakness(m1, n, a);
        double w2 = get_weakness(m2, n, a);

        if (w1 < w2)
        {
            high = m2;
        }
        else
        {
            low = m1;
        }
    }

    cout << fixed;
    cout.precision(12);
    cout << get_weakness(low, n, a) << "\n";

    return 0;
}
#endif