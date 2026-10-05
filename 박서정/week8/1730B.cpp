#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<double> x(n), t(n);

        for (double& v : x) cin >> v;
        for (double& v : t) cin >> v;

        auto f = [&](double p) {
            double res = 0;

            for (int i = 0; i < n; i++)
                res = max(res, t[i] + abs(x[i] - p));

            return res;
            };

        double l = 0, r = 1e8;

        for (int i = 0; i < 200; i++) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;

            if (f(m1) <= f(m2))
                r = m2;
            else
                l = m1;
        }

        cout << fixed << setprecision(10) << (l + r) / 2 << '\n';
    }
}