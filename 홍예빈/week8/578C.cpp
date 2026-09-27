// Codeforces 578C - Weakness and Poorness
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    auto weakness = [&](double x) -> double {
        double prefix = 0.0;

        // S[0] = 0도 최솟값과 최댓값 계산에 포함
        double minPrefix = 0.0;
        double maxPrefix = 0.0;

        for (int v : a) {
            prefix += v - x;
            minPrefix = min(minPrefix, prefix);
            maxPrefix = max(maxPrefix, prefix);
        }

        return maxPrefix - minPrefix;
    };

    double lo = *min_element(a.begin(), a.end());
    double hi = *max_element(a.begin(), a.end());

    for (int iter = 0; iter < 200; ++iter) {
        double m1 = lo + (hi - lo) / 3.0;
        double m2 = hi - (hi - lo) / 3.0;

        if (weakness(m1) > weakness(m2)) {
            lo = m1;
        } else {
            hi = m2;
        }
    }

    double x = (lo + hi) / 2.0;

    cout << fixed << setprecision(15)
         << weakness(x) << '\n';

    return 0;
}