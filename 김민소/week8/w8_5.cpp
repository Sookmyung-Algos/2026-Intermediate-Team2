#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto cost = [&](double x) {
        double maxSum = 0.0;
        double minSum = 0.0;

        double curMax = 0.0;
        double curMin = 0.0;

        for (double v : a) {
            double value = v - x;

            curMax = max(0.0, curMax + value);
            maxSum = max(maxSum, curMax);

            curMin = min(0.0, curMin + value);
            minSum = min(minSum, curMin);
        }

        return max(maxSum, -minSum);
    };

    double left = -10000.0;
    double right = 10000.0;

    for (int iter = 0; iter < 200; iter++) {
        double m1 = left + (right - left) / 3.0;
        double m2 = right - (right - left) / 3.0;

        if (cost(m1) < cost(m2)) {
            right = m2;
        }
        else {
            left = m1;
        }
    }

    cout << fixed << setprecision(15);
    cout << cost((left + right) / 2.0) << '\n';

    return 0;
}