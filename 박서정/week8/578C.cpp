#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> a(n);
    for (auto& x : a) cin >> x;

    auto f = [&](double x) {
        double mx = 0, mn = 0;
        double curMax = 0, curMin = 0;

        for (double v : a) {
            v -= x;

            curMax = max(0.0, curMax + v);
            mx = max(mx, curMax);

            curMin = min(0.0, curMin + v);
            mn = min(mn, curMin);
        }

        return max(mx, -mn);
        };

    double l = -10000, r = 10000;

    for (int i = 0; i < 100; i++) {
        double m1 = (2 * l + r) / 3;
        double m2 = (l + 2 * r) / 3;

        if (f(m1) < f(m2))
            r = m2;
        else
            l = m1;
    }

    cout << fixed << setprecision(15) << f((l + r) / 2);
}