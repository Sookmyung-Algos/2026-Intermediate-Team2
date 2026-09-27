#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    auto cost = [&](long long x) {
        long long result = 0;

        for (long long v : a) {
            if (v < x)
                result += x - v;
        }

        for (long long v : b) {
            if (v > x)
                result += v - x;
        }

        return result;
    };

    long long left = 1;
    long long right = 1e9;

    while (right - left > 3) {
        long long m1 = left + (right - left) / 3;
        long long m2 = right - (right - left) / 3;

        if (cost(m1) <= cost(m2))
            right = m2;
        else
            left = m1;
    }

    long long answer = LLONG_MAX;

    for (long long x = left; x <= right; x++) {
        answer = min(answer, cost(x));
    }

    cout << answer << '\n';

    return 0;
}