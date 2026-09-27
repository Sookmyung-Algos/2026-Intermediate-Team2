#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    cout << fixed << setprecision(10);

    while (T--) {
        int n;
        cin >> n;

        vector<double> x(n), t(n);

        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }

        double left = 0;
        double right = 1e8;

        auto calc = [&](double pos) {
            double mx = 0;

            for (int i = 0; i < n; i++) {
                mx = max(mx, t[i] + abs(x[i] - pos));
            }

            return mx;
        };

        for (int iter = 0; iter < 100; iter++) {
            double m1 = (2 * left + right) / 3;
            double m2 = (left + 2 * right) / 3;

            if (calc(m1) < calc(m2)) {
                right = m2;
            } else {
                left = m1;
            }
        }

        cout << (left + right) / 2 << '\n';
    }

    return 0;
}