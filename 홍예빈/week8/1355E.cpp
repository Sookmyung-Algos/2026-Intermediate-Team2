// Codeforces 1355E - Restorer Distance
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll A, R, M;
    cin >> n >> A >> R >> M;

    vector<ll> h(n);
    for (ll& height : h) {
        cin >> height;
    }

    M = min(M, A + R);

    auto cost = [&](ll target) -> ll {
        ll need = 0;
        ll excess = 0;

        for (ll height : h) {
            if (height < target) {
                need += target - height;
            } else {
                excess += height - target;
            }
        }

        ll moved = min(need, excess);

        return moved * M
             + (need - moved) * A
             + (excess - moved) * R;
    };

    ll lo = *min_element(h.begin(), h.end());
    ll hi = *max_element(h.begin(), h.end());

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

    for (ll target = lo; target <= hi; ++target) {
        answer = min(answer, cost(target));
    }

    cout << answer << '\n';

    return 0;
}