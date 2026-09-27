
// Codeforces 1730B - Meeting on the Line
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

        for (double& pos : x) cin >> pos;
        for (double& time : t) cin >> time;

        double lo = *min_element(x.begin(), x.end());
        double hi = *max_element(x.begin(), x.end());

        // 위치 pos에서 모든 사람이 모일 때까지 걸리는 시간
        auto f = [&](double pos) {
            double result = 0.0;

            for (int i = 0; i < n; ++i) {
                result = max(result, t[i] + abs(x[i] - pos));
            }

            return result;
        };

        for (int iter = 0; iter < 200; ++iter) {
            double m1 = lo + (hi - lo) / 3.0;
            double m2 = hi - (hi - lo) / 3.0;

            if (f(m1) > f(m2)) {
                lo = m1;
            } else {
                hi = m2;
            }
        }

        cout << (lo + hi) / 2.0 << '\n';
    }

    return 0;
}