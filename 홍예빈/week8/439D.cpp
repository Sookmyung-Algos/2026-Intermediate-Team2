// Codeforces 439D - Devu and his Brother
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);

    for (ll& v : a) cin >> v;
    for (ll& v : b) cin >> v;

    ll lo = *min_element(a.begin(), a.end());
    ll hi = *max_element(b.begin(), b.end());

    // 이미 min(a) >= max(b)를 만족하는 경우
    if (lo >= hi) {
        cout << 0 << '\n';
        return 0;
    }

    auto cost = [&](ll x) {
        ll result = 0;

        for (ll v : a) {
            if (v < x) result += x - v;
        }

        for (ll v : b) {
            if (v > x) result += v - x;
        }

        return result;
    };

    while (hi - lo > 2) {
        ll m1 = lo + (hi - lo) / 3;
        ll m2 = hi - (hi - lo) / 3;

        if (cost(m1) > cost(m2)) {
            lo = m1;
        } else {
            hi = m2;
        }
    }

    ll answer = LLONG_MAX;

    for (ll x = lo; x <= hi; ++x) {
        answer = min(answer, cost(x));
    }

    cout << answer << '\n';

    return 0;
}